#ifndef ID3V1DEF_H
#define ID3V1DEF_H

/*ID3v1 DEFINITIONS */
/*ID3v1 DEFINITIONS */

/*tag constants*/
#define TAG_POSITION	-128L
#define TAG		"TAG"
#define	TAG_FOUND	0
#define	NO_TAG		1
#define	MAX_TAG		4
#define	TAG_SIZE	3
//#define	NULL		0


/*field size*/
#define S_TITLE		30
#define S_ARTIST	30
#define S_ALBUM		30
#define S_YEAR		4
#define S_COMMENT	28
#define S_ZERO		1
#define S_TRACK		1
#define S_GENRE		1

/*field constants*/
enum field {TITLE,AUTOR,DISC,YEAR,COM,ZERO,TRACK,GENRE,MAX_FIELD};

/*status*/
#define	FILE_ERR	1
#define	OK		1

#endif