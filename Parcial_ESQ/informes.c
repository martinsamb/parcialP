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






