#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()
{
    int client, server;
    int portNum = 1500;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    cout << "\n=> Socket server has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);


    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) 
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }

    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;

    listen(client, 5);

    while (server = accept(client,(struct sockaddr *)&server_addr,&size)) 
    {
        if (fork())
            continue;
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);
        cout << "=> Connected with the client!" << endl;
        cout << "\n=> Enter '\\exit' to end the connection\n" << endl;

        cout << "Client: ";
        recv(server, buffer, bufsize, 0);
        cout << buffer;

        do {
            cout << "\nServer: ";
            for (int i = 0; i < bufsize; i++) {
                if (buffer[i] >= 'a' && buffer[i] <= 'z')
                    buffer[i] -= 32;
            }
            cout << buffer << endl;
            send(server, buffer, bufsize, 0);

            cout << "Client: ";
            recv(server, buffer, bufsize, 0);
            if (strcmp(buffer, "\\exit") == 0)
                break;
            cout << buffer;
        } while (1);

        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
    }

    close(client);
    return 0;
}