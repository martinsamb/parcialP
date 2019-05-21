#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED

#define TEXT_SIZE 20

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

}Musicos;


#endif // MUSICOS_H_INCLUDED

int musicos_Inicializar(Musicos array[], int size);                                    //cambiar musicos
int musicos_buscarEmpty(Musicos array[], int size, int* posicion);                    //cambiar musicos
int musicos_buscarID(Musicos array[], int size, int valorBuscado, int* posicion);                    //cambiar musicos
int musicos_alta(Musicos array[], int size, int* contadorID);                          //cambiar musicos
int musicos_baja(Musicos array[], int sizeArray);                                      //cambiar musicos
int musicos_bajaValorRepetidoInt(Musicos array[], int sizeArray, int valorBuscado);
int musicos_modificar(Musicos array[], int sizeArray);                                //cambiar musicos
int musicos_listar(Musicos array[], int size);                      //cambiar musicos
void MenuMusicos();
void MenuMusicosPrincipal();
void MenuMusicosModificacion();



