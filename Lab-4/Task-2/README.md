### Task

Implement a chat server for the following scenario:

A chat server is an application that enables conversation between multiple chat clients. It maintains a set of chat rooms/groups. Chat clients connect to the chat server and make a request to join a group. The chat server may reject the request if the number of clients already in the group exceeds the maximum allowed in that group. If the request is accepted, that client is made part of the group. All the clients that are part of a group receive all the messages transmitted by any member of the group. The chat server facilitates this group communication. A chat client reads the text typed by a user and sends it to the chat server. It is the responsibility of that chat server to rely that message to all other members of the corresponding group.

### Compiling

1. Install `make` and run `cd src; make all`.

2. Start the server using `./server <port>` and client using `./client <ip-address> <port>`
