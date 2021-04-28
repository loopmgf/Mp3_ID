//-------------------
#include <stdio.h>
#include "ID3v2.h"
#include "ID3v1.h"
#include "audio.h"
#include "typedefs.h"
#include "errores.h"
//-------------------
static void report_error(int type);
//-------------------
int main(int argc, char* argv[])
{
	FILE *mp3;
	FILE *output;
	int i,error_type;

	if((error_type=check_errors(argc,argv))==OK)
	{
		if ((output = fopen(argv[argc-1], "wt")) == NULL) //abre o crea el ultimo
		{                                                 //archivo invocado
			fprintf(stderr, "Cannot open output file%s.\n",argv[argc-1]);
			return 1;
		}

		for(i=1 ; i < (argc-1) ;i++)           //abre todos los archivos mp3
		{
			if ((mp3 = fopen(argv[i], "rb")) == NULL)
			{
				fprintf(output, "\nCannot open input file %s\n",argv[i]);
				continue;
			}

			fprintf(output,"\n//---MP3: %s---//\n",argv[i]);

			audio_info(mp3,output);
			ID3v1(mp3,output);
			ID3v2(mp3,output);

			fclose(mp3); //cierra el archivo mp3 actual
		}

		fclose(output);   //cierra el archivo de salida
	}
	else
		report_error(error_type);

	return 0;
}
//---------------------
void report_error(int type)
{
	switch(type)
	{
		case PARAMETERS:	printf("Error: Pocos par metros ingresados.");
							break;

		case EXTENSION:		printf("Error: Verifique la extensi¢n de los archivos mp3");
							break;
	}
}
//----------------------
