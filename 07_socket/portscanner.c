#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_port = htons(80);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0)
        printf("[127.0.0.1] PORT 80 is OPEN\n");
    else
        printf("[127.0.0.1] PORT 80 is CLOSED\n");
    
    close(sock);
    return 0;
}
