#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#define SIZE 1024

void write_file(int sockfd, char *file_name){
  int n;
  FILE *fp;
  char buffer[SIZE];
 
  fp = fopen(filename, "w");
  while (1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}


main() {
	int welcomeSocket,newSocket, res, copy_file = 1;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	char file_name[64], size[8], resp;
	FILE *fp;

	welcomeSocket = socket(PF_INET,SOCK_STREAM,0);
	
	/*-----Configure setting of the server address struct--------*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof(serverAddr.sin_zero));
	
	/*------------ Bind the address struct to the socket -------*/
	bind(welcomeSocket, (struct sockaddr *)&serverAddr,sizeof(serverAddr));
	
	/*-----------Listen on the socket, with 5 max connection requests queued-----*/
	if(listen(welcomeSocket,5)==0) {
		printf("Listenning\n");
	} else {
		printf("Error\n");
	}

	/*--------------Accept call creates a new socket for incoming connection-----------*/
	addr_size = sizeof(serverStorage);
	newSocket = accept(welcomeSocket,(struct sockaddr *)&serverStorage,&addr_size);

	/*-------------Send message to the socket of the incoming connectio-----------*/
//	strcpy(buffer,"Hellow World\n");
//	send(newSocket,buffer,13,0);
	recv(newSocket,buffer,1024,0);

	char * token = strtok(buffer, " ");
	strcpy(file_name, token);
	token = strtok(NULL, " ");
	strcpy(size, token);
/*
	while( token != NULL ) {
		printf( " %s\n", token ); //printing each token
		token = strtok(NULL, " ");
	}
*/

	fp = fopen(file_name, "r");

        if (fp != NULL) {
		fseek(fp,0L,SEEK_END);
		res = ftell(fp);

		fclose(fp);
		if (res == atoi(size)) {
			printf("File %s is present and size is also same\n", file_name);
		} else {
			printf("File %s is present but size is different\n", file_name);
		}
		printf("Do we need to copy this file: y/n\n");
		scanf("%c", &resp);
		if (resp != 'y' || resp != 'Y') {
			copy_file = 0;
		}
        }
	if (copy_file) {
		newSocket = accept(welcomeSocket,(struct sockaddr *)&serverStorage,&addr_size);
  		write_file(newSocket, file_name);		
	}
	printf("--> %c \n", resp);
	
        printf("File name: %s size: %s\n",file_name, size);
	return 0;
	

}
