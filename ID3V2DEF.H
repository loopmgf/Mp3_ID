/************************************
Definiciones y constantes para ID3v2
************************************/

#ifndef ID3V2DEF_H
#define ID3V2DEF_H


#define	MAX_FRAMES	6
#define MAX_CHAR	128	//tamaño maximo posible que le dimos a un frame del id3v2
#define	NAME_SIZE	4
#define SET_FLAG	1
#define RESET		0

enum eventos {TITLE,AUTOR,DISC,YEAR,COM,GENRE,DONT_CARE,END_OF_ID3V2};

typedef unsigned long U_long;

typedef struct{
	char byte3;
	char byte2;
	char byte1;
	char byte0;
}D_word;

typedef union{
	D_word dword;
	U_long sizelong;
}Size_reg;

#endif