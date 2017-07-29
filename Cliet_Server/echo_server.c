#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_DATA 1024
int main(int argc, char **argv) {
	unsigned int len;
	int sock,sent, cli, data_len;
	struct sockaddr_in server, client;
	char data[MAX_DATA];

	if (argc < 2)
	{
		printf("Enter port number as argument\n");
		exit(-1);
	}
	if( (sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket:");
		exit(-1);
	}
	
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	
	bzero(&server.sin_zero, 8);
	len = sizeof(struct sockaddr_in);

	if ((bind(sock, (struct sockaddr *) &server, len)) == -1)
	{
		perror("bind:");
		exit(-1);
	}
	
		
	if ((listen(sock, 5)) == -1)
	{
		perror("listen: ");
		exit(-1);
	}

	while(1)
	{
		if( (cli = accept(sock, (struct sockaddr *)&client, &len)) == -1)
		{
			perror("accept:");
			exit(-1);
		}

		printf("New client connect form port = %d IP = %s\n",ntohs(client.sin_port), inet_ntoa(client.sin_addr));
		data_len = 1;

		while(data_len)
		{

			data_len = recv(cli, data, MAX_DATA, 0);

			if (data_len)
			{	
				send(cli, data, data_len, 0);
				data[data_len] = '\0';
				printf("Snet msg :%s",data);
			}
		}
	
			printf("Client disconnect\n");
			close(cli);
	}
	close(sock);

	return 0;

}
