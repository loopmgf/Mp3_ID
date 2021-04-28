//----------------
#include "flag.h"
//----------------
static int flag;
//----------------
void reset_flag(void)
{
	flag=0;
}
//----------------
void set_flag(void)
{
	flag=FLAG_SET;
}
//----------------
int read_flag(void)
{
	return (flag);
}
//----------------