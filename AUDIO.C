//--------------------------
#include <io.h>
#include "audio.h"
//-------------------
static void wait_for_sync(FILE *mp3, unsigned char *audio_header);
//Busca el Syncword en el archivo de entrada.
static void get_layer(unsigned char layer_and_garbage, int *layer_type,FILE *output);
//Filtra el layer obtenido del archivo e imprime la informaci¢n en el archivo de salida.
static void get_bitrate_and_sampling(int layer_type,unsigned char bitrate_samp,FILE *output);
//Filtra el bitrate y la frecuencia de sampleo e imprime la informaci¢n en el archivo de salida.
static void get_mode(unsigned char mode_and_garbage,FILE *output);
//Filtra el modo obtenido del archivo e imprime la informaci¢n en el archivo de salida.
//---------------------
void audio_info(FILE *mp3, FILE *output)
{
	unsigned char audio_header[3];
	int i,layer_type;

	wait_for_sync(mp3,audio_header);

	fprintf(output,"\n\n//---AUDIO INFORMATION---//\n");
	fprintf(output,"\nDebugged pattern (without first byte of syncword): ");
	for(i=0;i<3;i++)
		fprintf(output,"%x ",audio_header[i]); //--->Debug
	fprintf(output,"\n\n");

	get_layer(audio_header[0],&layer_type,output);
	get_bitrate_and_sampling(layer_type,audio_header[1],output);
	get_mode(audio_header[2],output);

}
//-----------------------------
void wait_for_sync(FILE *mp3, unsigned char *audio_header)
{
	int sync;
	unsigned char temp;
	while((sync=fgetc(mp3))!=EOF)
	{
		if (sync==SYNC_FLAG)
		{
			temp=fgetc(mp3);//-->Guardo el siguiente byte en el temporal.
			audio_header[0]=temp;//-->Lo guardo en el arreglo.
			temp=temp>>NIB;//-->Shifteo hasta quedarme con el primer nibble (resto de syncword a testear).
			if((temp&0xf!=0xf)&&(temp&0xf!=0xe))//-->Si no es un nibble v lido.
				fseek(mp3,-1,SEEK_CUR);//Vuelvo 1 byte hacia atr s y sigo buscando el syncword.
			else
			{
				audio_header[1]=fgetc(mp3);//De lo contrario guardo los valores del header.
				audio_header[2]=fgetc(mp3);
				break;
			}
		}
	}
}
//--------------------------------
void get_layer(unsigned char layer_and_garbage, int *layer_type,FILE *output)
{
	S_LAYER layer;
	layer.buffered=layer_and_garbage;//"lleno" la estructura.
	if((layer.type.layer_bits)==UNO)
	{
		fprintf(output,"Layer: 3\n");   //Parseo datos.
		*layer_type=3;
	}
	else
	{
		if((layer.type.layer_bits)==DOS)
		{
			fprintf(output,"Layer: 2\n");
			*layer_type=2;
		}
		else
		{
			if((layer.type.layer_bits)==TRES)
			{
				fprintf(output,"Layer: 1\n");
				*layer_type=1;

			}
		}
	}
}
//------------------------------------------
void get_bitrate_and_sampling(int layer_type,unsigned char bitrate_samp,FILE *output)
{
	S_BITRATE bitrate;
	int bitrate_array[][14]=
	{{32,64,96,128,160,192,224,256,288,320,352,384,416,448}, //layer 1, fila 0.
	{32,48,56,64,80,96,112,128,160,192,224,256,320,384},     //layer 2, fila 1.
	{32,40,48,56,64,80,96,112,128,160,192,224,256,320}};     //layer 3, fila 2.
	bitrate.buffered=bitrate_samp;
	fprintf(output,"Bitrate= %d kbps\n",bitrate_array[layer_type-1][(bitrate.type.bitrate_bits)-1]);

	if((bitrate.type.sampling_bits)==CERO)
		fprintf(output,"Frecuencia de sampleo= 44.1 Khz\n");
	else
	{
		if((bitrate.type.sampling_bits)==UNO)
			fprintf(output,"Frecuencia de sampleo= 48 Khz\n");
		else
		{
			if((bitrate.type.sampling_bits)==DOS)
				fprintf(output,"Frecuencia de sampleo= 32 Khz\n");
		}
	}
}
//-------------------------
void get_mode(unsigned char mode_and_garbage, FILE *output)
{
	S_MODE mode;
	mode.buffered=mode_and_garbage;
	if(mode.type.mode_bits==CERO)
		fprintf(output,"Modo: Stereo\n");
	else
	{
		if(mode.type.mode_bits==UNO)
			fprintf(output,"Modo: Joint stereo\n");
		else
		{
			if(mode.type.mode_bits==DOS)
				fprintf(output,"Modo: Dual channel\n");
			else
			{
				if(mode.type.mode_bits==TRES)
					fprintf(output,"Modo: Mono\n");
			}
		}
	}
}
//-------------------
















