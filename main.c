#include <stdio.h>
#include <time.h>

#include "wifi_server.h"
#include "save_data.h"
#include "computer_state.h"



int main( int argc, char **argv[])
{
	
	time_t current_time;
	int connected;

	current_time = time(NULL);
	struct tm stime = *localtime(&current_time);

	if (current_time == ((time_t)-1))
	{
		printf("failed to obtai the current time\n");
		return 0;
	}

	int socket_desc = 0;

	SAVE_DATA_init(stime); 
	socket_desc = WIFI_init();

	printf("Hello from main on pc\n");


	printf("Socket_desc = %d\n", socket_desc);

	computer_state_set(WAIT_FOR_DATA);


	while( ( WIFI_accept() ) )
	{
		connected = 1;
		while(connected)
		{
			switch( computer_state_get() ){
				/*case WAIT_FOR_CONNECTION:
					if (WIFI_connect())
					{
						printf("Set new data\n");
						computer_state_set(NEW_DATA);
					}*/
				case WAIT_FOR_DATA:
					//computer_state_set(NEW_DATA);
					if (WIFI_receive() > 0)
					{
						printf("Set new data\n");
						computer_state_set(NEW_DATA);
					}
					else
					{
						connected = 0;
						SAVE_DATA_info_discon();
					}
					break;

				case NEW_DATA:
					SAVE_DATA_add_val( );
					computer_state_set(WAIT_FOR_DATA);
					break;

				default:
					computer_state_set(WAIT_FOR_DATA);
					break;
			}
		}
	}
	
	//if (new_socket<0)
    //{
    //    printf("accept failed");
    //}

	return 0;
}