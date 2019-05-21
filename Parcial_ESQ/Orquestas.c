#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquestas.h"
#include "Musicos.h"
#include "Instrumentos.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquestas Array of orquestas
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquestas_Inicializar(Orquestas array[], int size)                                    //cambiar orquestas
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquestas Array de orquestas
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquestas_buscarEmpty(Orquestas array[], int size, int* posicion)                    //cambiar orquestas
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array orquestas Array de orquestas
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquestas_buscarID(Orquestas array[], int size, int valorBuscado, int* posicion)                    //cambiar orquestas
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquestas Array de orquestas
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquestas_alta(Orquestas array[], int size, int* contadorID)                          //cambiar orquestas
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquestas_buscarEmpty(array,size,&posicion)==-1)                          //cambiar orquestas
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getTexto("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre) == 0 &&
               utn_getTexto("\nLugar: ","nError",1,TEXT_SIZE,1,array[posicion].lugar)== 0 &&
               utn_getUnsignedInt("\nTipo: ","\nError",1,sizeof(int),1,10,1,&array[posicion].tipo)== 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;

                printf("\n ID: %d",array[posicion].idUnico);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquestas Array de orquestas
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquestas_baja(Orquestas array[], int sizeArray, Musicos arrayB[],int sizeB)                                      //cambiar orquestas
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        orquestas_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(orquestas_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].tipo=0;                                                               //cambiar campo varInt
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");

            musicos_bajaValorRepetidoInt(arrayB,sizeB,id);

            retorno=0;
        }
    }
    return retorno;
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquestas Array de orquestas
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquestas_listar(Orquestas array[], int size)                      //cambiar orquestas
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                printf("\n---------------------------------------\n");
                printf("\n ID: %d\n Nombre: %d\n Lugar: %s\n Tipo: %d",
                    array[i].idUnico,
                    array[i].nombre,
                    array[i].lugar);
                    if(array[i].tipo == 1)
                        printf("Sinfonica");
                    else if(array[i].tipo == 2)
                        printf("Filarmonica");
                    else if(array[i].tipo == 3)
                        printf("Camara");
                    else
                        printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////
void MenuOrquestas()
{
    printf("\n\nMENU ORQUESTAS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - listar\n");
    printf("4 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuOrquestasPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Orquestas\n");
    printf("2 - Musicos\n");
    printf("3 - Instrumentos\n");
    printf("4 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
