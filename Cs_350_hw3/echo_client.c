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
        printf("Socket is failed to connect");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );


    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed.");
        return 1;
    }

    puts("Connected \n");
    puts("Welcome, you can start chatting");

    while(1)
    {

        printf("Enter message: ");
        fgets(message, sizeof(message),stdin);



        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }

        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
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