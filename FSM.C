//-----------------
#include "fsm.h"
//-----------------
STATE *fsm(STATE *p2tabla,BYTE evento_actual)
{
		while (p2tabla -> evento != evento_actual
			&& p2tabla -> evento != FIN_TABLA)
		p2tabla++;
		(p2tabla -> p_rut_accion) ();          /*Rutina de acci¢n correspondiente*/
		p2tabla=p2tabla -> prx_estado;   /*Siguiente estado*/

		return(p2tabla);
}
//-----------------