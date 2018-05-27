#include "computer_state.h"

state_t current_state;

void computer_state_set(state_t next_state)
{
	current_state = next_state;
}


state_t computer_state_get( void )
{
	return current_state;
}

