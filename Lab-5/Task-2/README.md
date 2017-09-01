### Task

Write a simple WWW client program in C/C++ to do the following activites:

- From the command line, read (1) the URL from which you can extract the nameof the remote WWW server and the file to retrieve and (2) the server port number. Create a socket that is connected to the server machine at the specified port (e.g. HTTP port 80)

- Send a request to the WWW server using the HTTP protocol format. This will look something like this `GET /index.html HTTP/1.0\n\n`

- Read all the data from the HTTp connection and write it to a temporary file created in your WWW cache (e.g. /tmp/your/loginname) on the local host

- Span an external viewer (fork/exec) to display the file. You can determine the type of viewer by service-side MIME content type information. Your client can simple parse this information and use it to determine which viewer to spawn.
