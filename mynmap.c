#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
if(argc != 2){
printf("usage: %s <IP>", argv[0]);
exit(0);
}

const char *ip = argv[1];

struct sockaddr_in data;
memset(&data, 0, sizeof(data));
data.sin_family = AF_INET;
data.sin_addr.s_addr = inet_addr(ip);

printf("[ -------DETAILS------- ]\n");

int port;
for(port = 1; port <= 1024; ++port){
int sockethndl = socket(AF_INET, SOCK_STREAM, 0);
data.sin_port = htons(port);
if(connect(sockethndl, (struct sockaddr*)&data, sizeof(data)) == 0){
printf("    PORT %d/tcp OPEN\n", port);
close(sockethndl);
}
else{
close(sockethndl);
}
usleep(1000);
}

return 0;
}
