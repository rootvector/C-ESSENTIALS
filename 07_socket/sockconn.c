#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int sock;

    //  creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0)
        perror("Socket creation failed!");

    printf("Socket Created");

    close(sock);
    return 0;
}
