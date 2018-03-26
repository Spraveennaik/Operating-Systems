#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
  char data[256] = "you have reached the server";
  char buffer[256];
  char buffer1[256];
  int server_socket;
  server_socket = socket(AF_INET,SOCK_DGRAM,0);
  
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9999);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address));
  socklen_t length = (sizeof(server_address));
  while(1)
  {
   recvfrom(server_socket,buffer,sizeof(buffer),0,(struct sockaddr *)&server_address,&length);
   printf("the client sent the data:");
   printf("%s\n",buffer);
   printf("enter the message to send to client:");
   scanf("%s",buffer1);
   sendto(server_socket,buffer1,sizeof(buffer1),0,(struct sockaddr *)&server_address,length); 
   getchar();
   }
}
