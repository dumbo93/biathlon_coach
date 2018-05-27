#ifndef COMPUTER_STATE_H_
#define COMPUTER_STATE_H_

typedef enum{wait_for_value, new_value}state_t;

char current_value;

void computer_state_set(state_t next_state);

state_t computer_state_get( void );


#endif
