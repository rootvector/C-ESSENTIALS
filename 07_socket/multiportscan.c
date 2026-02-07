#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv){
    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr("127.0.0.1");

    for(int port = 1; port < 1000; port++){
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0)
            printf("[127.0.0.1] PORT %d OPEN\n", port);

        close(sock);
    }

    return 0;
}
            
