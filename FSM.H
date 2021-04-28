#ifndef FSM_H
#define FSM_H


#include "typedefs.h"
#define FIN_TABLA		0xFF

	typedef struct tabla_estado STATE;

	struct tabla_estado
	{
		BYTE evento;
		STATE *prx_estado;
		void (*p_rut_accion)();
	};

// Interfaz
STATE* fsm(STATE *p2tabla,BYTE evento_actual);

#endif