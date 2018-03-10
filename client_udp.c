#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
  int sockid = socket(AF_INET,SOCK_DGRAM,0);
  char data[256];
  char buffer[256];
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9999);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  socklen_t length=sizeof(server_address);
  
  while(1)
  {
  printf("enter the message to send : ");
  scanf("%s",buffer);
  sendto(sockid,buffer,sizeof(buffer),0,(struct sockaddr *)&server_address,length); 
  recvfrom(sockid,data,sizeof(data),0,(struct sockaddr *)&server_address,&length);
  printf("the server sent the data : %s\n",data);
  //getchar();
  }
  return 0;
}  
