//-----------------
#ifndef typedefs.h
#define typedefs.h
//-----------------
typedef unsigned char BYTE;
typedef unsigned int WORD;
/******************/
typedef struct
{
	WORD b0	:1;
	WORD b1	:1;
	WORD b2	:1;
	WORD b3	:1;
	WORD b4	:1;
	WORD b5	:1;
	WORD b6	:1;
	WORD b7	:1;
}
BITS;
/*******************/
typedef struct
{
	WORD lo	:4;
	WORD hi	:4;
}
NIBBLE;
/*******************/
typedef union
{
	BITS bits;
	NIBBLE nibble;
	BYTE byte;
}
MYBYTE;
#endif
//------------------