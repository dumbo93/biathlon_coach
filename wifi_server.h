#ifndef WIFI_SERVER_
#define WIFI_SERVER_

#include <arpa/inet.h>


int WIFI_init( void );
int WIFI_accept( int new_socket, int socket_desc , int c, struct sockaddr_in client );
void *connection_handler( int *socket_desc );


#endif