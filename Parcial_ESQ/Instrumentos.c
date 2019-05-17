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
* \param array fantasma Array of fantasma
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int fantasma_Inicializar(Fantasma array[], int size)                                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion)                    //cambiar fantasma
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
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarID(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
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
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarInt(Fantasma array[], int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].varInt==valorBuscado)                                                   //cambiar campo varInt
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int fantasma_buscarString(Fantasma array[], int size, char* valorBuscado, int* indice)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].varString,valorBuscado)==0)                                        //cambiar campo varString
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int fantasma_alta(Fantasma array[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,10,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("\ngetName: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("\ngetTexto: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(Fantasma array[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_bajaValorRepetidoInt(Fantasma array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].varInt=0;                                                               //cambiar campo varInt
                array[i].varFloat=0;                                                             //cambiar campo varFloat
                strcpy(array[i].varString,"");                                                   //cambiar campo varString
                strcpy(array[i].varLongString,"");                                               //cambiar campo varLongString
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int fantasma_modificar(Fantasma array[], int sizeArray)                                //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       MenuFantasmaModificacion();

                utn_getUnsignedInt("","\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getUnsignedInt("Int: ","\nError\n",1,sizeof(int),1,10,1,&array[posicion].varInt);            //mensaje + cambiar campo varInt
                        break;
                    case 2:
                        utn_getFloat("Float: ","\nError\n",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
                        break;
                    case 3:
                        utn_getName("Text1: ","\nError\n",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
                        break;
                    case 4:
                        utn_getTexto("Text2: ","\nError\n",1,TEXT_SIZE,1,array[posicion].varLongString);             //mensaje + cambiar campo varLongString
                        break;
                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!=6);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenarPorDobleCriterio(Fantasma array[],int size, int orderFirst, int orderSecond)                              //cambiar fantasma
{
    int retorno=-1;
    int i;
    Fantasma buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].varString,array[i+1].varString) < 0) && orderFirst) ||
                    ((strcmp(array[i].varString,array[i+1].varString) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].varString,array[i+1].varString) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int fantasma_listar(Fantasma array[], int size)                      //cambiar fantasma
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
                printf("\n---------------------------------------\n");
                printf("\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                       array[i].idUnico,array[i].varInt,array[i].varFloat,array[i].varString,array[i].varLongString);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int fantasma_ordenar(Fantasma array[],int size)
{
   int i,j;
   int retorno;
   Fantasma buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(array[i].varLongString,array[j].varLongString)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
           else if(strcmp(array[i].varString,array[j].varString)> 0)
           {
               buffer = array[i];
               array[i] = array[j];
               array[j] = buffer;
               retorno = 0;
           }
       }
   }
   return retorno;
}

void fantasma_mock(Fantasma arrayFantasma[], int size,int *contadorId)                      //cambiar fantasma
{
    //*******************************************************************
    int aux = 0;
    arrayFantasma[0].idUnico=0;
    arrayFantasma[0].isEmpty=0;
    arrayFantasma[0].varInt=20;
    arrayFantasma[0].varFloat=30;
    strcpy(arrayFantasma[0].varLongString,"CCCCC");
    strcpy(arrayFantasma[0].varString,"CCCCC");
    *contadorId =++ aux;

    arrayFantasma[1].idUnico=1;
    arrayFantasma[1].isEmpty=0;
    arrayFantasma[1].varInt=21;
    arrayFantasma[1].varFloat=40;
    strcpy(arrayFantasma[1].varLongString,"AAAAA");
    strcpy(arrayFantasma[1].varString,"AAAAA");
    *contadorId =++ aux;

    arrayFantasma[2].idUnico=2;
    arrayFantasma[2].isEmpty=0;
    arrayFantasma[2].varInt=22;
    arrayFantasma[2].varFloat=20;
    strcpy(arrayFantasma[2].varLongString,"BBBBB");
    strcpy(arrayFantasma[2].varString,"CCCCCC");
    *contadorId =++ aux;

    arrayFantasma[3].idUnico=3;
    arrayFantasma[3].isEmpty=0;
    arrayFantasma[3].varInt=23;
    arrayFantasma[3].varFloat=10;
    strcpy(arrayFantasma[3].varLongString,"BBBBB");
    strcpy(arrayFantasma[3].varString,"BBBBBB");

}
//////////////////////////////////
void MenuFantasma()
{
    printf("\n\nMENU SUBMENU\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Listar\n");
    printf("5 - Listar ordenado\n");
    printf("6 - SALIR\n");
    printf("Elija opcion: ");
}

void MenuFantasmaPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - struct1\n");
    printf("2 - struct2\n");
    printf("3 - struct3\n");
    printf("4 - struct4\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
////////////////////////////////////
void MenuFantasmaModificacion()
{
    printf("\n\nMENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - int\n");
    printf("2 - float\n");
    printf("3 - text1\n");
    printf("4 - text2\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}