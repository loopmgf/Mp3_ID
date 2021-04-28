//---------------------
#include <stdio.h>
#include "fsm.h"
#include "id3v2tab.h"
#include "flag.h"
//---------------------

	extern STATE estado_0[];
	extern STATE estado_1[];
	extern STATE estado_2[];
	extern STATE encontrado;

	static STATE *p2state=NULL;

/*** Prototipos ***/

	void do_nothing(void);
	void seq_ID3(void);

/*** Tablas de estado ***/

	/*--estado 0--*/
	static STATE estado_0[]=
	{
		{'I',estado_1,do_nothing},
		{FIN_TABLA,estado_0,do_nothing},
	};

	/*--estado 1--*/
	static STATE estado_1[]=
	{
		{'I',estado_1,do_nothing},
		{'D',estado_2,do_nothing},
		{FIN_TABLA,estado_0,do_nothing},
	};

	/*--estado 2--*/
	static STATE estado_2[]=
	{
		{'I',estado_1,do_nothing},
		{'3',estado_0,seq_ID3},
		{FIN_TABLA,estado_0,do_nothing},
	};

/*** Rutinas de acci¢n ***/
//------------------
void do_nothing(void)
{
}
//------------------
void seq_ID3(void)
{
	set_flag();
}
//------------------
/*** Interfaz ***/
STATE * get_state(void)
{
	return (p2state);
}
//------------------
void set_init_state(void)
{
	p2state=estado_0;
}
//------------------
void store_state(STATE *p2new_state)
{
	p2state=p2new_state;        //Set state
}
//------------------


