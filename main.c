#include <stdio.h>
#include <time.h>

#include "wifi_server.h"
#include "save_data.h"
#include "computer_state.h"



int main( int argc, char **argv[])
{
	/*
	time_t current_time;

	current_time = time(NULL);
	struct tm stime = *localtime(&current_time);

	if (current_time == ((time_t)-1))
	{
		printf("failed to obtai the current time");
		return 0;
	}

	//int socket_desc = 0;

	SAVE_DATA_init(stime); */
	int socket_desc = 0;
	socket_desc = WIFI_init();

	printf("Hello from main on pc\n");


	printf("Socket_desc = %d\n", socket_desc);

	if (socket_desc)
	{
		printf("Connected");
	}

	while(1)
	{

	}


	return 0;
}
