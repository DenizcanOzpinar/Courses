#include<stdio.h>
#include<string.h>    //strlen
#include<stdlib.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
#include <time.h>
#include<pthread.h> //for threading , link with lpthread
#include <stdbool.h>

//Denizcan Ozpinar
//S014290

//after ten sec or 4 connection pls ignore enter message and press enter until u see message that it finished



int count = 0;
int sockets[4];

void *connection_handler(void *);

void *timeUp(void *);



int main(int argc, char *argv[]) {
    pthread_t hum[3];
    pthread_t timer[3];

    int socket_desc, new_socket, c, *new_sock;

    struct sockaddr_in server, client;
    char *message;



    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }


    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server.sin_port = htons(8888);


    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }
    puts("bind done");


    listen(socket_desc, 3);

    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);


    while ((new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {


        puts("Connection accepted");
        count++;


        printf("count = %d \n", count);
        new_sock = malloc(1);
        *new_sock = new_socket;


        if (count <= 2) {
            sockets[count] = new_socket;

            pthread_create(&hum[count], NULL, connection_handler, (void *) new_sock);
            printf("count = %d \n", new_socket);
            pthread_create(&timer[count], NULL, timeUp, (void *) new_sock);

            puts("Handler assigned");
        } else if (count == 3) {
            int ch = 1;

            sockets[count] = new_socket;
            pthread_create(&hum[3], NULL, connection_handler, (void *) new_sock);
            pthread_create(&timer[count], NULL, timeUp, (void *) new_sock);

        } else if (count == 4) {

            puts("count ==4");
            char tmp1[200];
            int read_size;
            char *message, client_message[2000];


           // read_size = recv(new_socket, client_message, 2000, 0);


            write(new_socket, "QUEUE", 15);
            client_message[0]='\0';
            memset(client_message,0,2000);
            for (int i = 0; i <2000 ; ++i) {
                client_message[i]=NULL;
            }

            puts("before close");
            count--;
            close(new_socket);


        } else {


        }

    }

    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }

    for (int j = 0; j < 4; ++j) {
        pthread_join(hum[j], NULL);
        pthread_join(timer[j], NULL);
    }

    return 0;
}


void *timeUp(void *socket_desc) {

    int sock = *(int *) socket_desc;
    puts("timeUp");
    while (count==3){

    }
    if(count!=3) {
        sleep(10);


        char tmp1[200];
        int read_size;
        char *message, client_message[2000];


        // read_size = recv(sock, client_message, 2000, 0);


        write(sock, "CLOSE", 15);
        client_message[0]='\0';
        memset(client_message,0,2000);
        for (int i = 0; i <2000 ; ++i) {
            client_message[i]=NULL;
        }

        puts("before close");


        for (int i = 0; i < 4; ++i) {
            if (sockets[i] == sock) {
                close(sock);

            }
        }
    }

}





void *connection_handler(void *socket_desc) {

    int ch = 1;
    while (count >= 3) {
        if (ch == 1) {
            puts("connection is in queue");
            ch++;

        }

    }


    double time_spent;
    int sock = *(int *) socket_desc;
    int read_size;
    char *message, client_message[2000];

    while (1) {
        read_size = recv(sock, client_message, 2000, 0);

        write(sock, client_message, strlen(client_message));
        client_message[0]='\0';
        memset(client_message,0,2000);
        for (int i = 0; i <2000 ; ++i) {
            client_message[i]=NULL;
        }


        if (read_size == 0) {
            puts("Client disconnected");
            fflush(stdout);
            count--;
            break;
        } else if (read_size == -1) {
            perror("recv failed");
            count--;
            break;
        }



        // free(socket_desc);
    }

}




