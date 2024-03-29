#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
  struct sockaddr_in server;
  int sock;
  char buf[32];
  int n;

  sock=socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0){
    printf("socket failed\n");
    return 1;
  }else{
    printf("socket creation succeeded:%d\n",sock);
  }

  server.sin_family=AF_INET;
  server.sin_port=htons(12345);
  server.sin_addr.s_addr=inet_addr("127.0.0.1");

  connect(sock, (struct sockaddr *)&server, sizeof(server));

  memset(buf,0,sizeof(buf));
  n= read(sock,buf,sizeof(buf));
  printf("%d, %s\n", n, buf);

  close(sock);

  return 0;
}
