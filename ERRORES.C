//-----------------------
#include <stdio.h>
#include <string.h>
#include "errores.h"
//-----------------------
static int count_parameters(int argc);
static int check_extension(int argc,char **argv);
//-----------------------
int check_errors(int argc, char **argv)
{
	int error_type;
	if((error_type=count_parameters(argc))==PARAMETERS)
		return error_type;
	error_type=check_extension(argc,argv);
	return error_type;
}
//-----------------------
int count_parameters(int argc)
{
	int error;
	if(argc<MINARG)
		error=PARAMETERS;
	else
		error=OK;
	return error;
}
//-----------------------
int check_extension(int argc,char **argv)
{
	int temp,error;
	error=OK;
	for(temp=argc-2;temp!=0;temp--)
	{
		if(strstr(argv[temp], ".mp3")==NULL)
		{
			error=EXTENSION;
			break;
		}

	}
	return error;
}
//-----------------------