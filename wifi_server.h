#ifndef WIFI_SERVER_
#define WIFI_SERVER_

#include <arpa/inet.h>

int WIFI_init( void );
int WIFI_accept( void );
int WIFI_receive( void );
int WIFI_connect( void );
void *connection_handler( int *socket_desc );


#endif