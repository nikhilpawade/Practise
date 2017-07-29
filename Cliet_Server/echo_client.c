#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFFER 1024

int main(int argc, char **argv) {
	unsigned int len,len1;
	int sock,sent, cli, data_len;
	struct sockaddr_in server;
	char input[BUFFER];
	char output[BUFFER];

	if (argc < 3) {
		printf("Enter IP and Port\n");
		exit(-1);
	}
	if( (sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket:");
		exit(-1);
	}
	
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_addr.s_addr = INADDR_ANY;
	
	bzero(&server.sin_zero, 8);
	len = sizeof(struct sockaddr_in);

	

	if ((connect(sock, (struct sockaddr *) &server, len)) == -1)
	{
		perror("bind:");
		exit(-1);
	}
	
	while(1)
	{
		fgets(input, BUFFER, stdin);
		send(sock, input, strlen(input), 0);
		
		len = recv(sock, output, BUFFER, 0);
		output[len1] = '\0';
		printf("%s",output);
	}
	close(sock);
}
