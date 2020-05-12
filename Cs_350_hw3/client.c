#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Socket could not be created");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );


    while  (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed.");
        return 1;
    }

    puts("Connected\n");
    puts("Welcome, you can start to chat :3");

    while(1)
    {

        printf("Enter message: ");
        message[0]='\0';
        memset(message,0,2000);
        for (int i = 0; i <2000 ; ++i) {
            message[i]=NULL;
        }
        fgets(message, sizeof(message),stdin);

        if ( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }

        if (recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }

        if (strcmp(server_reply,"CLOSE")==0){
            puts("Disconnected");
            return 0;
        }
        if (strcmp(server_reply,"QUEUE")==0){
            puts("There is to many people in the line pls try agin later :3");
            return 0;
        }

        printf("Server Reply: %s\n", server_reply);
        server_reply[0]='\0';
        memset(server_reply,0,2000);
        for (int i = 0; i <2000 ; ++i) {
            server_reply[i]=NULL;
        }
    }

    close(sock);
    return 0;
}