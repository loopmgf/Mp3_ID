//----------------------
#ifndef ERRORES.H
#define ERRORES.H
//----------------------
#define MINARG 3 //M¡nima cantidad de entradas.
#define OK 1
#define PARAMETERS 2      //Tipos de errores.
#define EXTENSION 3  //--/
//----------------------
int check_errors(int argc, char **argv);
//Funci¢n que chequea los errores, y devuelve un entero acorde al error encontrado.
//Devuelve OK si no encuentra ning£n error.
#endif
//----------------------