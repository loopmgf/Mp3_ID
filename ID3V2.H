//--------------
#ifndef ID3V2_H
#define ID3V2_H
//--------------
/*********************
ID3v2.h
***********************/
/************************************************
ID3v2: busca el ID3v2 y, si lo encuentra, copia
los datos correspondientes en un arreglo.
************************************************/
void ID3v2(FILE *mp3, FILE*output);
/************************************************
copy_info_v2: toma el arreglo anterior y lo imprime
en el archivo de salida con el encabezado y el
nombre de los campos
************************************************/
void copy_info_v2(FILE* output, char info[][128]);
#endif
//--------------