//------------------
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "fr_funcs.h"
#include "contador.h"
//------------------
/*****************************
Get_frame: determina qu‚ tipo de frame es.
******************************/
int Get_frame(FILE *stream)
{
	//arreglo con los strings de los frames buscados
	char *id3_info[MAX_FRAMES]={{"TIT2"},{"TPE1"},{"TALB"},{"TYER"},{"COMM"},{"TCON"}};
	//arreglo con los nros de evento
	int events[MAX_FRAMES]={TITLE,AUTOR,DISC,YEAR,COM,GENRE};
	//arreglo donde se guardara el frame tomado del archivo
	char fr_name[NAME_SIZE+1];
	int event;
	int i;

	fread(&fr_name, sizeof(char), 4, stream);
	fr_name[NAME_SIZE] = '\0';


	if(isupper(fr_name[0]) == 0)  //S¡ el primer caract‚r
	{                             //del nombre del frame
		event = END_OF_ID3V2;      //no es una letra may£scula,
		return event;              //devuelve END_OF_ID3V2.
	}


	for(i=0 ; i<6 ; i++)
	{
		if (strcmp(fr_name,id3_info[i]) == 0)
		{
			event = events[i];
			inc_cont();   //Cuenta cant de frames utiles encontrados.
			break;
		}
		else
			event = DONT_CARE;
	}

	return event;
}
//------------------
/*************************************************
Get_frame_size: Calc£la el largo del frame.
*************************************************/
U_long Get_frame_size(FILE *stream)
{
	Size_reg l_size;
	U_long fsize;

	fread(&l_size, sizeof(Size_reg), 1, stream);

	fsize = l_size.dword.byte0+(l_size.dword.byte1)*2^8+(l_size.dword.byte2)*2^16+(l_size.dword.byte3)*2^24;

	return fsize;
}
//-------------------
/*********************************
Get_data: toma la informaci¢n
**********************************/
void Get_data(FILE *stream, U_long fsize, char *info)
{
	char *p2data;
	char c;
	int i;

	for(i=0 ; i<fsize ; i++)              //Ignora si las primeras
		if(isalnum(c=fgetc(stream)) != 0)  //letras del tag no son
			{                               //alfanumericas
				i++;                         //i=nro de bytes ignorados.
				break;
			}
	p2data=(char *)calloc(fsize-i,sizeof(char));
	*p2data=c;

	fread(p2data+1,sizeof(char),fsize-i,stream);
	*(p2data+(fsize-i+1)) = '\n';

	for (i=0 ; p2data[i]!='\n' ; i++)  //Copia la info tomada al
		info[i] = p2data[i];            //arreglo, terminandolo en \n.
	info[i] = '\n';
	free(p2data);
}
//--------------------