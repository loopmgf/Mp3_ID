//----------------
#include <stdio.h>
#include "contador.h"
//----------------
static unsigned int contador;
//----------------
void inc_cont(void)
{
	contador++;
}
//----------------
unsigned int leer_cont(void)
{
	return (contador);
}
//----------------
void reset_cont(void)
{
	contador=0;
}
//----------------
