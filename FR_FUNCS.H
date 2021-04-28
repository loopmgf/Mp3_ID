//---------------
#ifndef FR_FUNCS_H
#define FR_FUNCS_H
//---------------
/******************************
Fr_funcs.h: Frame functions
******************************/
#include "ID3v2def.h"
/********************************************
Get_frame: Lee el tag del frame y devuelve
qu‚ frame es ó DONT_CARE si no es uno de
los frames buscados. Si el tag no empieza
con may£scula asume que se termino el ID3v2
y devuelve END_OF_ID3V2.
*********************************************/
int Get_frame(FILE *stream);
/************************************************
Get_frame_size: Lee el header del frame para
determinar el largo del frame en cuesti¢n
************************************************/
U_long Get_frame_size(FILE *stream);
/************************************************
Get_data: chequea que las primeras letras sean
caract‚res alfanum‚ricos, y los salt‚a si no lo
son. Copia la informaci¢n del frame a un arreglo
************************************************/
void Get_data(FILE *stream, U_long fsize, char *info);
#endif
//----------------