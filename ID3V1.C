//-------------------
#include<stdio.h>
#include<string.h>
#include"ID3V1.H"
#include"ID3V1DEF.H"
//-------------------
void ID3v1(FILE* mp3, FILE* tag_file)
{
	/*Chequea por el formato ID3v1*/

	if( check_tag( mp3)==TAG_FOUND)
		id3v1_reader(mp3,tag_file); //Si lo tiene, lo analiza.
	else
		fprintf(tag_file,"\n ID3v1 not found");
}
//-------------------
int check_tag(FILE* source)
{
	char tag[MAX_TAG];	//String donde levantar  el TAG.

	/*Posiciona el puntero donde se encuentra el TAG*/

	fseek(source, TAG_POSITION, SEEK_END);

	get_tag( source, tag);	//Guarda el TAG en el string.

	/*Compara el tag encontrado para ver si corresponde
	con el formato ID3v1*/

	if( strcmp(tag,TAG)==TAG_FOUND)
		return(TAG_FOUND);
	else
	{       /*Si no corresponde, posiciona el puntero
		en el inicio*/

		fseek(source,0L,SEEK_SET);
		return(NO_TAG);
	}
}
//----------------------
void get_tag(FILE* source, char tag[])
{
	/*Toma los 3 caract‚res del TAG y
	los guarda en un arreglo*/
	int i;
	for(i=0; i<TAG_SIZE;i++)
		tag[i]=fgetc(source);

	tag[i]=NULL;
}
//----------------------
void id3v1_reader(FILE* source, FILE* tag_file)
{
	int field;

	fprintf( tag_file, "\n//---ID3v1 INFORMATION---//\n");

	/*Toma todos los campos pedidos y los guarda en el archivo de salida*/
	for( field=0; field<MAX_FIELD; field++)
	{

		/*S¡ el campo es ZERO o TRACK, lo saltea*/
		if (field!=ZERO && field!=TRACK)
		{
			copy_name( tag_file, field);	//Copia el nombre del campo correspondiente.
			copy_field( source, tag_file, field);	//Copia el campo correspondiente.
		}
		else
			skip_field( source, field);	//Saltea el campo en cuesti¢n.

	}

	fseek(source,0L,SEEK_SET);	/*posiciona el puntero en el inicio*/

}
//------------------------
void copy_name(FILE* tag_file, int field)
{
	char* field_names[]={"Nombre de la cancion","Autor de la cancion","Disco",//
				"A¤o","Comentario","separador","Pista","Genero"};

	/*Copia los nombres al archivo de salida*/
	fprintf( tag_file, "\n%s: ",field_names[field]);
}
//------------------------
void skip_field(FILE* source,int field)
{
	unsigned char size_table[MAX_FIELD]={S_TITLE,S_ARTIST,S_ALBUM,S_YEAR,S_COMMENT,S_ZERO,S_TRACK,S_GENRE};

	/*Mueve el puntero del archivo fuente desde la posicion actual + OFFSET*/
	fseek( source, size_table[field], SEEK_CUR);

}
//-------------------------
void copy_field(FILE* source,FILE* tag_file, int field)
{

	unsigned char size_table[MAX_FIELD]={S_TITLE,S_ARTIST,S_ALBUM,S_YEAR,S_COMMENT,S_ZERO,S_TRACK,S_GENRE};
	unsigned char bytes_cpy;
	int c;

	for( bytes_cpy=0; bytes_cpy<size_table[field]; bytes_cpy++)
	{
		c=fgetc( source);	//Caract‚r del archivo fuente

		/*Debido a que el g‚nero no se encuentra en formato ASCII*/
		if( field==GENRE)
			fprintf( tag_file, "%d", c);
		else
			fputc( c, tag_file);	//Copia el caract‚r al archivo de salida
	}
}
//-------------------------
