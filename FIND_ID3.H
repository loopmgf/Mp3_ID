//--------------
#ifndef FIND_ID3_H
#define FIND_ID3_H
//--------------
/************************
Find_ID3.h
************************/
#define	NO_ID3v2	0
#define	ID3v2_FOUND	1
/********************************************
Find_ID3: funci¢n que busca el tag "ID3" en *
el archivo apuntado por stream y devuelve   *
ID3v2_FOUND o NO_ID3v2 dependiendo de si lo *
encontr¢ o no.				    *
********************************************/
int Find_ID3(FILE*stream);
#endif
//-----------------