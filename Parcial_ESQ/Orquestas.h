#include "Musicos.h"
#ifndef ORQUESTAS_H_INCLUDED
#define ORQUESTAS_H_INCLUDED

#define TEXT_SIZE 20

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
int orquestas_alta(Orquestas array[], int size, int* contadorID);                          //cambiar orquestas
int orquestas_baja(Orquestas array[], int sizeArray, Musicos arrayB[],int sizeB);
int orquestas_listar(Orquestas array[], int size);
void MenuOrquestas();
void MenuOrquestasPrincipal();



