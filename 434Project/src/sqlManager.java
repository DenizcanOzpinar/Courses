import java.sql.*;

public class sqlManager {
    //singelton pattern
    private static final sqlManager instance = new sqlManager();

    public static String getState() {
        return state;
    }

    private static String state;

    private sqlManager(){}
    public static sqlManager getInstance(){
        return instance;
    }


    public static Connection DBConnection(Context context){

        context = new Context();

        dbStartState starting = new dbStartState();
        starting.doAction(context);
        state = context.getState().toString();


        Connection conn = null;
        String dbName = "cs434DataBase";
        String serverip="25.92.17.33";
        String serverport="1433";
        String url = "jdbc:sqlserver://"+serverip+"\\SQLEXPRESS:"+serverport+";databaseName="+dbName+"";
        String driver = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
        String databaseUserName = "sa";
        String databasePassword = "123456789";
        try {

            Class.forName(driver).newInstance();
            conn = DriverManager.getConnection(url, databaseUserName, databasePassword);


            System.out.println("success");
            dbState startState = new dbState();
            startState.doAction(context);
            state = context.getState().toString();
            return conn;

        } catch (Exception e) {
            dbStopState stopState = new dbStopState();
            e.printStackTrace();
            stopState.doAction(context);
            state = context.getState().toString();
        }

        return conn;
    }






}
