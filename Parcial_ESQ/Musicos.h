#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED

#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "MUSICOS X EL QUE QUIERAS(todo mayuscula)"
    "Musicos x el que Quieras(primer letra en mayuscula)""musicoss x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int edad;
    char apellido[TEXT_SIZE];
    int idOrquestas;
    int idInstrumentos;
    int fecha;

}Musicos;


#endif // MUSICOS_H_INCLUDED

int musicos_Inicializar(Musicos array[], int size);                                    //cambiar musicos
int musicos_buscarEmpty(Musicos array[], int size, int* posicion);                    //cambiar musicos
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar musicos
int musicos_buscarInt(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar musicos
int musicos_buscarString(Musicos array[], int size, char* valorBuscado, int* indice);                    //cambiar musicos
int musicos_alta(Musicos array[], int size, int* contadorID);                          //cambiar musicos
int musicos_baja(Musicos array[], int sizeArray);                                      //cambiar musicos
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado);
int musicos_modificar(Musicos array[], int sizeArray);                                //cambiar musicos
int musicos_ordenarPorDobleCriterio(Musicos array[],int size, int orderFirst, int orderSecond);                                  //cambiar musicos
int musicos_listar(Musicos array[], int size);                      //cambiar musicos
void musicos_mock(Musicos arrayMusicos[], int size,int *contadorId);                      //cambiar musicos
void MenuMusicos();
void MenuMusicosPrincipal();
void MenuMusicosModificacion();
int musicos_ordenar(Musicos array[],int size);



