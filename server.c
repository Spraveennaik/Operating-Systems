#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
  char buffer[256];
  char buffer1[256];
  int server_socket;
  server_socket = socket(AF_INET,SOCK_STREAM,0);
  
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9909);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address));
  
  listen(server_socket,3);
  
  int client_socket;
  client_socket = accept(server_socket,NULL,NULL);
 // send(client_socket,data,sizeof(data),0);
  while(1)
  {
   recv(client_socket,buffer,sizeof(buffer),0);
   printf("the client sent the data:");
   printf("%s\n",buffer);
   printf("enter the message to send to client:");
   scanf("%s",buffer1);
   send(client_socket,buffer1,sizeof(buffer1),0); 
   getchar();
   }
}
