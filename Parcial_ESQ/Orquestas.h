#ifndef ORQUESTAS_H_INCLUDED
#define ORQUESTAS_H_INCLUDED

#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "ORQUESTAS X EL QUE QUIERAS(todo mayuscula)"
    "Orquestas x el que Quieras(primer letra en mayuscula)""orquestass x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
    char lugar[TEXT_SIZE];


}Orquestas;

#endif // ORQUESTAS_H_INCLUDED


int orquestas_Inicializar(Orquestas array[], int size);                                    //cambiar orquestas
int orquestas_buscarEmpty(Orquestas array[], int size, int* posicion);                    //cambiar orquestas
int orquestas_buscarID(Orquestas array[], int size, int valorBuscado, int* posicion);                    //cambiar orquestas
int orquestas_buscarInt(Orquestas array[], int size, int valorBuscado, int* posicion);                    //cambiar orquestas
int orquestas_buscarString(Orquestas array[], int size, char* valorBuscado, int* indice);                    //cambiar orquestas
int orquestas_alta(Orquestas array[], int size, int* contadorID);                          //cambiar orquestas
int orquestas_baja(Orquestas array[], int sizeArray);                                      //cambiar orquestas
int orquestas_bajaValorRepetidoInt(Orquestas array[], int sizeArray, int valorBuscado);
int orquestas_modificar(Orquestas array[], int sizeArray);                                //cambiar orquestas
int orquestas_ordenarPorDobleCriterio(Orquestas array[],int size, int orderFirst, int orderSecond);                                  //cambiar orquestas
int orquestas_listar(Orquestas array[], int size);
int orquestas_printPantalla(Orquestas array[],int size);                     //cambiar orquestas
void orquestas_mock(Orquestas arrayOrquestas[], int size,int *contadorId);                      //cambiar orquestas
void MenuOrquestas();
void MenuOrquestasPrincipal();
void MenuOrquestasModificacion();
int orquestas_ordenar(Orquestas array[],int size);



