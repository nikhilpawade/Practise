#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>
#define SIZE 1024

void send_file(FILE *fp, int sockfd){
  int n;
  char data[SIZE] = {0};
 
  while(fgets(data, SIZE, fp) != NULL) {
	printf("---> %s \n", data);
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, SIZE);
  }
}


int main(int argc, char *argv[]) {
	int clientSocket, res;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	FILE *fp;
	
	if (argc < 2) {
		printf("Enter file name to copy\n");
		return 0;
	}
	/*----------Create the Socket */
	clientSocket = socket(PF_INET,SOCK_STREAM,0);
	
	/*configure settings --------------*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");


	memset(serverAddr.sin_zero,'\0',sizeof(serverAddr.sin_zero));

	addr_size = sizeof(serverAddr);

	connect(clientSocket,(struct sockaddr*)&serverAddr,addr_size);

	/*-------------read the message --------------*/
	strcpy(buffer,argv[1]);

	fp = fopen(buffer, "r");
	
	if (fp == NULL) {
		printf("File is not present\n");
		return -1;
	}
	
	fseek(fp,0L,SEEK_END);

	res = ftell(fp);

//	fclose(fp);

	int len = strlen(buffer); 

	strcat(buffer, " ");
	char *num;
	asprintf(&num, "%d", res);
	strcat(buffer, num);


	printf("Data received %s %d\n",buffer, res);
	send(clientSocket,buffer,1024,0);

	bzero(buffer, SIZE);
	recv(clientSocket,buffer,1024,0);
	
	if (strncmp("Yes", buffer, 3) == 0) {
		printf("-----> test\n");
		fseek(fp, 0, SEEK_SET);
		bzero(buffer, SIZE);
		send_file(fp, clientSocket);
	}
	printf("-----> test  %s\n", buffer);
	fclose(fp);
	close(clientSocket);
	return 0;

}
