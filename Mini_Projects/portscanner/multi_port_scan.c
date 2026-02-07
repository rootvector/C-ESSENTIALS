#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define TIMEOUT 2

int scan_port(const char *ip, int port){
	int sock;
	struct sockaddr_in target;
	struct timeval timeout;

	/* Create socket */

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		perror("Error: while making a socket connection");
		return -1;
	}

	/* Set timeout */
	timeout.tv_sec = TIMEOUT;
	timeout.tv_usec = 0;
	setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

	/* Prepare target */
	target.sin_family = AF_INET;
	target.sin_port = htons(port);
	target.sin_addr.s_addr = inet_addr(ip);

	/* Try to connect */
	if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
		close(sock);
		return 1;		// OPEN 
	} else { 
		close(sock);
		return 0;		// CLOSED / FILTERED
	}
}


int main() {
	const char *target_ip = "127.0.0.1";
	int start_port = 0;
	int end_port = 100;

	printf("==========================================================\n");
	printf("\tSCANNING %s PORTS %d-%d\n\n", target_ip, start_port, end_port);

	for(int port = start_port; port <= end_port; port++) {
		int result = scan_port(target_ip, port);

		if(result == 1)
			printf("[+] [OPEN ] Port %d\n", port);
		else
			printf("[-] [CLOSED] Port %d\n", port);

	}

	return 0;
}

