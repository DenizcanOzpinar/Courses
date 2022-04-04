import datetime
import glob
import os
import boto3
import mysql.connector
from secrets import access_key, secret_access_key, password, database, host, user


def datematch(LC, DB):
    if LC == DB:
        return 'EQ'
    elif LC >= DB:
        return 'LC'
    return 'DB'


def dateCheker(lfile, myresult):
    file_date = modification_date(lfile)

    time_no_point = str(file_date).split(" ")
    lc_date = time_no_point[0].split("-")
    lc_year = lc_date[0]
    lc_mon = lc_date[1]
    lc_day = lc_date[2]
    lc_time = time_no_point[1].split(".")
    lc_time_no_point = lc_time[0].split(":")
    lc = datetime.datetime(int(lc_year), int(lc_mon), int(lc_day), int(lc_time_no_point[0]), int(lc_time_no_point[1]),
                           int(lc_time_no_point[2]))

    for x in myresult:
        val = str(x[0])
        conval = val.split(" ")
        year_mon_day = conval[0].split("-")
        year = year_mon_day[0]
        mon = year_mon_day[1]
        day = year_mon_day[2]
        time = conval[1].split(".")
        newtime = str(time[0]).split(":")

        db = datetime.datetime(int(year), int(mon), int(day), int(newtime[0]), int(newtime[1]), int(newtime[2]))

        if datematch(lc, db) == 'EQ':
            return False
        elif datematch(lc, db) == 'DB':
            return False
        else:
            return True


def modification_date(filename):
    t = os.path.getmtime(filename)
    return datetime.datetime.fromtimestamp(t)


def send(directory):
    mydb = mysql.connector.connect(
        host=host,
        user=user,
        password=password,
        database=database
    )

    mycursor = mydb.cursor()


    os.chdir(directory)
    for file in glob.glob("*.*"):
        num = ""
        file_name = str(file)
        file_date = modification_date(file)
        file_location = directory
        get_id = "SELECT date FROM files WHERE name = '" + file_name + "' LIMIT 1 "

        mycursor.execute(get_id)
        myresult = mycursor.fetchall()

        for x in myresult:
            if x[0] != "":
                num = x[0]

        addquary = "INSERT INTO files (name,date ,location) SELECT * FROM (SELECT ' " + str(file_name) + " ',' " + str(
            file_date) + " ',' " + str(file_location) + " ') AS tmp WHERE NOT EXISTS (SELECT name FROM files WHERE name = ' " + str(file_name) + " ') LIMIT 1 "

        if num == "":
            mycursor.execute(addquary)
            mydb.commit()
            send_files(directory, file_name)

        else:
            if dateCheker(file, myresult):
                update_quarry = "UPDATE files SET date = '" + str(
                    file_date) + "', location ='" + file_location + "' WHERE name = '" + file_name + "'"
                mycursor.execute(update_quarry)
                mydb.commit()
                print(mycursor.rowcount, "updated record inserted.")
                send_files(directory, file_name)
            else:
                print("optimal file is already uploaded")

    mydb.close()


def download_s3_folder(s3_folder, local_dir=None):
    #connecting to s3 service
    client = boto3.resource('s3', aws_access_key_id=access_key, aws_secret_access_key=secret_access_key)
    #bucketname
    bucket = client.Bucket('yourbucket')
    for obj in bucket.objects.filter(Prefix=s3_folder):
        target = obj.key if local_dir is None \
            else os.path.join(local_dir, os.path.relpath(obj.key, s3_folder))
        if not os.path.exists(os.path.dirname(target)):
            os.makedirs(os.path.dirname(target))
        if obj.key[-1] == '/':
            continue
        bucket.download_file(obj.key, target)

def send_files(directory, filename):
    client = boto3.client('s3', aws_access_key_id=access_key, aws_secret_access_key=secret_access_key)

    os.chdir(directory)
    for file in glob.glob("*.*"):
        if file == filename:
            dir = str(directory)
            upload_file_bucket = 'yourbucket'
            upload_file_key = dir + str(file)
            client.upload_file(file, upload_file_bucket, upload_file_key)

    print('upload completed')
