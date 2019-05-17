#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED

#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "INSTRUMENTOS X EL QUE QUIERAS(todo mayuscula)"
    "Instrumentos x el que Quieras(primer letra en mayuscula)""instrumentoss x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;

}Instrumentos;

#endif // INSTRUMENTOS_H_INCLUDED

int instrumentos_Inicializar(Instrumentos array[], int size);                                    //cambiar instrumentos
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarInt(Instrumentos array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarString(Instrumentos array[], int size, char* valorBuscado, int* indice);                    //cambiar instrumentos
int instrumentos_alta(Instrumentos array[], int size, int* contadorID);                          //cambiar instrumentos
int instrumentos_baja(Instrumentos array[], int sizeArray);                                      //cambiar instrumentos
int instrumentos_bajaValorRepetidoInt(Instrumentos array[], int sizeArray, int valorBuscado);
int instrumentos_modificar(Instrumentos array[], int sizeArray);                                //cambiar instrumentos
int instrumentos_ordenarPorDobleCriterio(Instrumentos array[],int size, int orderFirst, int orderSecond);                                  //cambiar instrumentos
int instrumentos_listar(Instrumentos array[], int size);                      //cambiar instrumentos
void instrumentos_mock(Instrumentos arrayInstrumentos[], int size,int *contadorId);                      //cambiar instrumentos
void MenuInstrumentos();
void MenuInstrumentosPrincipal();
void MenuInstrumentosModificacion();
int instrumentos_ordenar(Instrumentos array[],int size);




