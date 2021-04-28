//-----------------------
#include <stdio.h>
#include "ID3v2.h"
#include	"ID3v2def.h"
#include	"Find_ID3.h"
#include "fr_funcs.h"
#include "contador.h"
//-----------------------
#define	DATA_OFFSET		0x2L   //offset desde el size del frame hasta el dato
//(2 bytes de flags)
#define	HEAD_OFFSET		0x7L  //offset desde donde termina ID3 hasta el
//primer frame(2 bytes de version y 4 de size)
//------------------------
void ID3v2(FILE *mp3, FILE*output)
{
	U_long f_size; //frame size
	int frame;     //nro de frame
	int flag=RESET;

	//Arreglo donde se guardara la info de id3v2:
	char Id3v2_info[MAX_FRAMES][MAX_CHAR]={{"Sin Info\n"},{"Sin Info\n"},{"Sin Info\n"},//
						   {"Sin Info\n"},{"Sin Info\n"},{"Sin Info\n"}};
	fseek(mp3,0L, SEEK_SET);


	while (flag != SET_FLAG)
	{
		if (Find_ID3(mp3) == NO_ID3v2)	 //Buscar string "ID3"
		{
			fprintf(output,"\n\n ID3v2 not found\n");
			return;
		}

		fseek(mp3,HEAD_OFFSET,SEEK_CUR); //Setea el puntero a la posici¢n del
												//primer frame
		while (leer_cont() < 6)	//Mientras no encuentre todos los campos requeridos
		{
			if ((frame=Get_frame(mp3))  == END_OF_ID3V2) //Si no hay mas frames
				break;                                    //sale del while

			else
			{
				f_size = Get_frame_size(mp3);       //Tama¤o del frame
				fseek(mp3, DATA_OFFSET, SEEK_CUR);  //Puntero a la info del frame

				if (frame != DONT_CARE)                     //Si necesito este frame
				{	Get_data(mp3,f_size,Id3v2_info[frame]);  //Tomo el dato del mismo
					flag= SET_FLAG;				//Encontro un frame que interesa
				}
				else
					fseek(mp3,f_size,SEEK_CUR);           //Sino lo salteo
			}
		}

		reset_cont();    //Reseteo contador

		if(flag == SET_FLAG)				//Si hay un frame para imprimir
		{
			copy_info_v2(output,Id3v2_info);       //Copio la info de ID3v2 al txt.
			flag=RESET;
			return;
		}
	}


	fseek(mp3,0L,SEEK_SET);	/*Posiciona el puntero en el inicio*/
}

//---------------------
/*********************************
copy_info_v2
**********************************/
void copy_info_v2(FILE* output, char info[][MAX_CHAR])
{
	int i,j;
	char* field_names[]={"Nombre de la cancion","Autor de la cancion","Disco",//
				"A¤o","Comentario","Genero"};

	fprintf( output,"\n\n//---ID3v2 INFORMATION---//\n");

	for(i=0 ; i < MAX_FRAMES ; i++)
	{
		fprintf(output, "\n%s: ",field_names[i]);
		for(j=0 ; info[i][j] != '\n' ; j++)
			fprintf(output, "%c",info[i][j]);
	}

	fprintf( output,"\n\n");
}
//-----------------------