
// https://www.binarytides.com/socket-programming-c-linux-tutorial/
// Open a socket
// Bind to a address(and port).
// Listen for incoming connections.
// Accept connections
// Read/Send
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#include "wifi_server.h"
#include "computer_state.h"

int socket_desc, new_socket, c, *new_sock;
char *message;
struct sockaddr_in server, client; 
c = sizeof(struct sockaddr_in);



int WIFI_init( void )
{
    printf("hello from wifi_init\n");
    int accepted = 0;

    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    
    if (socket_desc == -1)
    {
        printf("Could not create socket");
        return 1;
    }


    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("bind failed\n");
        return 1;
    }
    printf("bind done\n");


    listen(socket_desc , 1);
    printf("wifi: started listening \n");

    printf("Waiting for incoming connections...\n");
    
    accepted = WIFI_accept( new_socket, socket_desc, c, client );

    return 0;
}



int WIFI_accept( int new_socket, int socket_desc, int c, struct sockaddr_in client )
{
    

    while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        printf("Connection accepted\n");
         
        //Reply to the client
        //message = "Hello Client , I have received your connection. And now I will assign a handler for you\n";
        //write(new_socket , message , strlen(message));
         
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;
         
        if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( sniffer_thread , NULL);
        printf("Handler assigned\n");
    }
    if (new_socket<0)
    {
        printf("accept failed");
    }
    return 0;
}



void *connection_handler( int *socket_desc )
{
    int sock = *(int*)socket_desc;
    int read_size;

    //Receive a message from client
    while( (read_size = recv(sock , &current_value , 2000 , 0)) > 0 )
    {
        //Send the message back to client
        printf("from connection handle %s \n", &current_value );
        //write(sock , client_message , strlen(client_message));
    }
     
    if(read_size == 0)
    {
        printf("Client disconnected\n\n");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        printf("recv failed\n");
    }
         
    //Free the socket pointer

    free(socket_desc);

    return 0;
}