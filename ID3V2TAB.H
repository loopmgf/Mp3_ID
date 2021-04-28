#ifndef ID3V2TAB_H
#define ID3V2TAB_H

/***************************************************
Prototipos de las funciones para la fsm de FIND_ID3
***************************************************/

void set_init_state(void);
STATE *get_state(void);
void store_state(STATE *);

#endif