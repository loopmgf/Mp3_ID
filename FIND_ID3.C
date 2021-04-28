//-------------------
#include <stdio.h>
#include "Find_ID3.h"
#include "fsm.h"
#include "id3v2tab.h"
#include "flag.h"
//-------------------
int Find_ID3(FILE* stream)
{
	int dato;

	set_init_state(); //Inicializo la fsm con el estado inicial.
	reset_flag();


	while( read_flag() != FLAG_SET && (dato=fgetc(stream)) != EOF )
		store_state(fsm(get_state(),(BYTE)dato));  //Paso el dato a la m q de estados.

	if(dato == EOF)   //Si sali¢ del while por EOF => no hay ID3.
		return NO_ID3v2;

	else               //Si se sete¢ el flag => ID3 encontrado.
	{
		reset_flag();
		return ID3v2_FOUND;
	}
}
//-------------------


