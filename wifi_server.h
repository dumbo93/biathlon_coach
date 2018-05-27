#ifndef WIFI_SERVER_
#define WIFI_SERVER_

#include <arpa/inet.h>

int WIFI_init( void );
int WIFI_create_socket( int socket_desc );
void WIFI_bin_socket( int socket_desc, struct sockaddr_in server  );
void WIFI_listen( int socket_desc );
int WIFI_accept( int new_socket, int socket_desc, int c, struct sockaddr_in client );
void WIFI_write( int new_socket, char *message );
void *connection_handler( void *socket_desc );


#endif