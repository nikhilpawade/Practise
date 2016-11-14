#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
main() {
	int welcomeSocket,newSocket;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;


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
	strcpy(buffer,"Hellow World\n");
	send(newSocket,buffer,13,0);
	return 0;
	

}
