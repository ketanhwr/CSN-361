#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <ip-address> <port>" << endl;
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    char host[1024];
    char service[20];

    getnameinfo((struct sockaddr*)&address, sizeof address, host, sizeof host, service, sizeof service, 0);

    cout << "Host: " << host << endl;
    cout << "Service: " << service << endl;

    return 0;
}
