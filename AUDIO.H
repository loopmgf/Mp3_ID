//------------------
#ifndef AUDIO_H
#define AUDIO_H
//------------------
#include <stdio.h>
#define NIB 4
#define CERO 0
#define UNO 1
#define DOS 2
#define TRES 3
#define SYNC_FLAG 255
/*******************/
typedef struct
{
	unsigned int b0 	:1; //unused.
	unsigned int layer_bits	:2;
	unsigned int b3_b7 :5; //unused.

}LAYER; //Estructura tipo layer.
/*******************/
typedef union
{
	LAYER type;
	unsigned int buffered;
}S_LAYER;//Union entre la estructura y un entero para poder "llenarla" segun lo obtenido v¡a archivo.
/*******************/
typedef struct
{
	unsigned int b0_b1 	:2; //unused.
	unsigned int sampling_bits	:2;
	unsigned int bitrate_bits :4; //unused.

}BITRATE;
/*******************/
typedef union
{
	BITRATE type;
	unsigned int buffered;
}S_BITRATE;
/*******************/
typedef struct
{
	unsigned int b0_b5 	:6; //unused.
	unsigned int mode_bits :2;

}MODE;
/*******************/
typedef union
{
	MODE type;
	unsigned int buffered;
}S_MODE;
//---------------------
void audio_info(FILE *mp3, FILE *output);
#endif
//---------------------