#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquestas.h"
#include "Musicos.h"
#include "Instrumentos.h"
#include "informes.h"

/** \brief Lista los elementos de dos arrays vinculados
* \param arrayA Musicos Array de Musicos
* \param arrayB Instrumentos Array de Instrumentos
* \param sizeI int Tamaño del arrayA
* \param sizeJ int Tamaño del arrayB
* \return int Return (-1) si Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int Informes_listarMusicos(Musicos arrayA[], Instrumentos arrayB[], int sizeI, int sizeJ)
{
    int retorno=-1;
    int i;
    int j;
    if(arrayA!=NULL && sizeI>=0 && arrayB!=NULL && sizeJ>=0)
    {
        for(i=0;i<sizeI;i++)
        {
            if(arrayA[i].isEmpty!=1)
            {
                instrumentos_buscarID(arrayB,sizeJ,arrayA[i].idInstrumentos,&j);


                printf("\n ID: %d  \nNombre: %s \nApellido: %s \nEdad: %d  \nNombre instrumento: %s \nTipo instrumento: ",
                       arrayA[i].idUnico,
                       arrayA[i].nombre,
                       arrayA[i].apellido,
                       arrayA[i].edad,
                       arrayB[j].nombre);
                        if(arrayB[j].tipo==1)
                            printf("Cuerdas");
                        else if(arrayB[j].tipo==2)
                            printf("Viento-madera");
                        else if(arrayB[j].tipo==3)
                            printf("Viento-metal");
                        else if(arrayB[j].tipo==4)
                            printf("Percusion");
                        else
                            printf("Desconocido");

            }
        }
        retorno=0;
    }
    return retorno;
}

int listar_orquesta(Orquestas array[], int size)
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
                printf("\n ID: %d\n Nombre: %s\n Lugar: %s\n Tipo: %d",
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
/*
int listar_musicosMenor(Musicos array[], int size)
{
    int retorno=-1;
    int i;
    int contadorSinfonica=0;
    int contadorFilarmonica=0;
    int contadorCamara=0;

    if (array!=NULL && size>0)
    {
        if(array[i].edad < 25)
        {
            for (i=0;i<=size;i++)
            {
                if (array[i].isEmpty==0)
                {
                    switch (array[i].tipo)
                    {
                    case 1:
                    contadorSinfonica++;
                    printf ("\nSINFONICA : Nombre de orquesta: %s",array[i].nombre);
                    break;
                    case 2:
                    contadorFilarmonica++;
                    printf ("\nFILARMONICA : Nombre de orquesta: %s",array[i].nombre);
                    break;
                    case 3:
                    printf ("\nCAMARA : Nombre de orquesta: %s",array[i].nombre);
                    contadorCamara++;
                    break;
                    }
                }
            }
        }
        printf ("\nCantidad de orquestas sinfonicas: %d",contadorSinfonica);
        printf ("\nCantidad de orquestas filarmonicas: %d",contadorFilarmonica);
        printf ("\nCantidad de orquestas camara: %d",contadorCamara);
        retorno=0;
    }
    return retorno;
}

int listar_orquestas(Orquestas array[], int size)
{
    int retorno=-1;
    int i;
    int contadorOrquesta=0;
    if (array!=NULL && size>0)
        if(array[].int cantidad= atoi(array[].nombre)<5)
        {
            for (i=0;i<=size;i++)
            {
                if (array[i].isEmpty==1)
                    continue;
                if (array[i].isEmpty==0)
                {
                    contadorOrquesta++;
                }
            }
            printf ("\nLa cantidad de orquestas en total es: %d \n",contadorOrquesta);
            retorno=0;
        }
        return retorno;
}

int listar_Instrumentos(Instrumentos array[], int size)
{
    int retorno=-1;
    int i;
    int contadorInstrumento=0;
    if (array!=NULL && size>0)
    {
        for (i=0;i<=size;i++)
        {
            if (array[i].isEmpty==1)
                continue;
            if (array[i].isEmpty==0)
            {
                contadorInstrumento++;
            }
        }
        printf ("\nLa cantidad de instrumentos en total es: %d \n",contadorInstrumento);
        retorno=0;
    }
    return retorno;
}

//orquestasCompleta(arrayOrquestas,arrayMusicos,CANTIDAD_ORQUESTAS,CANTIDAD_MUSICOS);


void print_orquesta_y_nombres(Orquestas* array[], int size)
{
    int i;
    int valor;
    //valor = atoi(array[].nombre);
    //if(valor < valor)
    for (i=0;i<=size;i++)
    {
        if (array[i].isEmpty==0)
        {
            printf ("\n********************************************");
            printf ("\nNombre de la orquesta: %s ",array[i].nombre);
            printf ("\nLugar de la orquesta: %s ",array[i].lugar);
            printf ("\nTipo de orquesta: %d",array[i].tipo);
            //printf ("\nId de la orquesta: %d ",arrayOrquesta[i].idOrquestas);
            //printf ("\nPosicion: %d ",i);
            //printf ("\nEstado : %d \n",arrayOrquesta[i].isEmpty);
        }
    }
}
//print_promedio_instrumentos(arrayInstrumentos,CANTIDAD_INSTRUMENTOS);
int promedio_cantidad_musicos_por_orquesta(Instrumentos arrayI[], Orquestas arrayO[], int sizeI, int sizeO)
{
    int retorno=-1;
    int i;
    int contadorMusico=0;
    int contadorOrquesta=0;
    float promedio=0;

    if (arrayI!=NULL && arrayO!=NULL && sizeI >0 && sizeO>0)
    {
        for (i=0;i<=sizeI;i++)
        {
            if (arrayI[i].isEmpty==1)
                continue;
            if (arrayI[i].isEmpty==0)
            {
                contadorMusico++;
            }
        }

        for (i=0;i<=sizeO;i++)
        {
            if (arrayO[i].isEmpty==1)
                continue;
            if (arrayO[i].isEmpty==0)
            {
                contadorOrquesta++;
            }
        }
        promedio=contadorMusico/contadorOrquesta;
        printf("\nEl promedio de instrumento por orquesta es: %2.f",promedio);
        retorno=0;
    }
    return retorno;
}
*/
/////////////////////////////////////////////////////
void MenuInformes()
{
    printf("\n\nMENU INFORMES\n");
    printf("--------------\n");
    printf("1 - INFORME A\n");
    printf("2 - INFORME B\n");
    printf("3 - INFORME C\n");
    printf("Elija opcion: ");
}
//////////////////////////////////////////////////////////////






