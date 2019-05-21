#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Instrumentos.h"

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array instrumentos Array of instrumentos
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int instrumentos_Inicializar(Instrumentos array[], int size)                                    //cambiar instrumentos
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
* \param array instrumentos Array de instrumentos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion)                    //cambiar instrumentos
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
* \param array instrumentos Array de instrumentos
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion)                    //cambiar instrumentos
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
* \param array instrumentos Array de instrumentos
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int instrumentos_alta(Instrumentos array[], int size, int* contadorID)                          //cambiar instrumentos
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(instrumentos_buscarEmpty(array,size,&posicion)==-1)                          //cambiar instrumentos
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if(utn_getTexto("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre)== 0 &&
               utn_getUnsignedInt("\nTipo: ","\nError",1,sizeof(int),1,10,1,&array[posicion].tipo)== 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;                                                       //campo ID
                array[posicion].isEmpty=0;
                printf("\nID: %d",array[posicion].idUnico);
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
//Listar
/** \brief Lista los elementos de un array
* \param array instrumentos Array de instrumentos
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int instrumentos_listar(Instrumentos array[], int size)                      //cambiar instrumentos
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
                printf("\n ID: %d\n Nombre: %s\n Tipo: ",
                       array[i].idUnico,array[i].nombre);
                       if(array[i].tipo == 1)
                            printf("Cuerdas");
                       else if(array[i].tipo == 2)
                            printf("Viento Madera");
                       else if(array[i].tipo == 3)
                            printf("Viento Metal");
                       else if(array[i].tipo == 4)
                            printf("Percusion");
                       else
                            printf("Desconocido");
            }
        }
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////
void MenuInstrumentos()
{
    printf("\n\nMENU INSTRUMENTOS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Listar\n");
    printf("3 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuInstrumentosPrincipal()
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

