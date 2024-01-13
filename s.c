#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
  int sock0;
  struct sockaddr_in addr;
  struct sockaddr_in client;
  socklen_t len;
  int sock;

  sock0=socket(AF_INET, SOCK_STREAM, 0);
  addr.sin_family=AF_INET;
  addr.sin_port=htons(12345);
  addr.sin_addr.s_addr=INADDR_ANY;
  addr.sin_len=sizeof(addr);

  bind(sock0, (struct sockaddr*) &addr, sizeof(addr));
  printf("listen\n");fflush(stdout);
  listen(sock0, 5);

  len=sizeof(client);
  printf("accept\n");fflush(stdout);
  sock=accept(sock0, (struct sockaddr *)&client, &len);
  write(sock, "HELLO", 5);

  close(sock);
  close(sock0);
  return 0;
}
