#include <stdio.h>
#include <time.h>

#include "save_data.h"
#include "computer_state.h"

char logfile_name[32] = "logfile_";
// file pointer to hold the referance to the file
FILE *fp;

void SAVE_DATA_init(struct tm stime)
{
	stime.tm_mon = stime.tm_mon +1;
	stime.tm_year = stime.tm_year - 100;

	file_name_set(stime.tm_mday);
	file_name_set(stime.tm_mon);
	file_name_set(stime.tm_year);

	strcat(logfile_name, "_");

	file_name_set(stime.tm_hour);
	file_name_set(stime.tm_min);


	fp = fopen(logfile_name, "w");

	fprintf(fp, "sensor_name");
	fprintf(fp, "--");
	fprintf(fp, "sensor_time");
	fprintf(fp, "\n\n");

	fclose(fp);
	printf("hello from save_data_init\n");
}


void file_name_set( int time_value )
{
	if (time_value < 10)
	{
		strcat(logfile_name, "0");
	}
	char add_int[4];
	sprintf(add_int, "%d", time_value);
	strcat(logfile_name, add_int);
}


void SAVE_DATA_add_val( void )
{
	fp = fopen(logfile_name, "a");

	fprintf(fp, "%s", &current_value);

	fprintf(fp, "\n");

	fclose(fp);

}