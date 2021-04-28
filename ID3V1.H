//-------------
#ifndef ID3V1_H
#define ID3V1_H
//-------------
/************
---ID3V1.H---
************/
/*********************************************************
ID3v1: Anal¡za el archivo en busca del formato id3v1, si
lo encuentra lo copia a un archico de salida.
Recibe como parametros el archivo de mp3 y el de salida.
*********************************************************/
void ID3v1(FILE* mp3, FILE* tag_file);
/*********************************************************
check_tag: Verif¡ca si encuentra el tag de ID3v1 en el
archivo indicado, si lo encuentra devuelve TAG_FOUND, de
lo contrario NO_TAG.
*********************************************************/
int check_tag(FILE* source);
/*********************************************************
get_tag: Toma del archivo fuente el tag, y lo guarda en el
arreglo correspondiente.
*********************************************************/
void get_tag(FILE* source, char tag[]);
/*********************************************************
id3v1_reader: Anal¡za los campos de ID3v1 del archivo
fuente, y los copia al archivo de salida.
*********************************************************/
void id3v1_reader(FILE* source, FILE* tag_file);
/*********************************************************
copy_name: Copia el nombre del campo correspondiente al
archivo de salida.
*********************************************************/
void copy_name(FILE* tag_file, int field);
/*********************************************************
skip_field: Salt‚a el campo indicado del archivo fuente.
*********************************************************/
void skip_field(FILE* source,int field);
/*********************************************************
copy_field: Copia el campo indicado del archivo fuente al
archivo de salida.
*********************************************************/
void copy_field(FILE* source,FILE* tag_file, int field);
#endif
//-----------------