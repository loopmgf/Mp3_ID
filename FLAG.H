//-------------
#ifndef FLAG_H
#define FLAG_H
//-------------
#define	FLAG_SET	1
/********************************************
reset_flag: Funci¢n que resetea el flag	que *
esta como objeto en flag.c		    *
********************************************/
void reset_flag(void);
/********************************************
reset_flag: Funci¢n que pone el flag, que   *
est  como objeto en falg.c, en FLAG_SET	    *
********************************************/
void set_flag(void);
/********************************************
reset_flag: Funci¢n que devuelve el estado  *
del flag que esta como objeto en flag.c     *
********************************************/
int read_flag(void);
#endif
//-------------