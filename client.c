#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
  int sockid = socket(AF_INET,SOCK_STREAM,0);
  char data[256];
  char buffer[256];
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9909);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  int connection_status = connect(sockid , (struct sockaddr *) &server_address, sizeof(server_address));
  
  if(connection_status == -1)
  printf("there was an error making a connection to server\n");
  else
  printf("connection is established successfully\n");
  
  
  while(1)
  {
  printf("enter the message to send : ");
  scanf("%s",buffer);
  send(sockid, buffer,sizeof(buffer),0);
  recv(sockid , data, sizeof(data), 0);  
  printf("the server sent the data : %s\n",data);
  getchar();
  }
  return 0;
}  
