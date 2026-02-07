#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(){
	int sock;
	struct sockaddr_in target;

	/* Create Socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		perror("Socket");
		return 1;
	}

	/* Prepare target address */
	target.sin_family = AF_INET;
	target.sin_port = htons(80);		//port 80
	target.sin_addr.s_addr = inet_addr("8.8.8.8");	// Google DNS
												
	/* Try to connect */
	if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
		printf("Port 80 is OPEN\n");
	} else {
		printf("Port 80 is CLOSED\n");
	}

	/* Close socket */
	close(sock);
	
	return 0;
}
