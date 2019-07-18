#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "soporte.h"
#include "parser.h"
#include "validaciones.h"

/** \brief Carga los datos de las entregas desde el archivo data (modo texto).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListSoportes LinkedList* puntero al array de entregas.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListSoportes es NULL,
                    0 si logra cargar los datos.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListSoportes)
{
    int ret = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListSoportes != NULL)
    {
        pFileAux = fopen(path, "r");
        if(pFileAux != NULL)
        {
            if(!parser_SoporteFromText(pFileAux, pArrayListSoportes))
            {
                printf("\tCARGA EXITOSA!\n");
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Listar entregas
 *
 * \param pArrayListSoportes LinkedList* puntero al array de entregas.
 * \return int ret -1 si no puede mostar toda la lista de los entregas,
                    0 si logra mostar toda la lista de los entregas.
 *
 */
int controller_ListSoporte(LinkedList* pArrayListSoportes)
{
    int ret = -1;
    Soporte * pSoporte = NULL;
    int bufferId;
    char bufferFecha[400];
    int bufferNumero;
    int bufferProblema;
    char bufferSolucion[400];

    for(int i=0; i<ll_len(pArrayListSoportes); i++)
    {
        pSoporte = ll_get(pArrayListSoportes, i);
        if(pSoporte != NULL)
        {
            if(!soporte_getId(pSoporte, &bufferId))
            {
                printf("ID:%d ",bufferId);
            }
            if(!soporte_getfecha(pSoporte, bufferFecha))
            {
                printf("FECHA:%s ", bufferFecha);
            }
            if(!soporte_getNumero(pSoporte, &bufferNumero))
            {
                printf("CLIENTE N:%d ", bufferNumero);
            }
            if(!soporte_getProblema(pSoporte, &bufferProblema))
            {
                if(bufferProblema == 1)
                {
                    printf("PROBLEMA:No enciende PC ");
                }
                if(bufferProblema == 2)
                {
                    printf("PROBLEMA:No funciona mouse ");
                }
                if(bufferProblema == 3)
                {
                    printf("PROBLEMA:No funciona teclado ");
                }
                if(bufferProblema == 4)
                {
                    printf("PROBLEMA:No hay internet ");
                }
                if(bufferProblema == 5)
                {
                    printf("PROBLEMA:No funciona telefono ");
                }
            }
            if(!soporte_getSolucion(pSoporte, bufferSolucion))
            {
                printf("SOLUCION:%s\n", bufferSolucion);
            }
            ret = 0;

        }
    }
    return ret;
}






/** \brief Guarda los datos de las entregas en el archivo informes.txt (modo texto).
 *
 * \param path char* puntero al archivo a guardar
 * \param pArrayListSoportes LinkedList* puntero al array de entregas.
 * \return int ret -1 si el puntero si no puede guardar los datos,
 *                  0 si logra guardar los datos.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListSoporte)
{
    int ret = -1;
    FILE* pFileAux = NULL;


    LinkedList* problema = ll_newLinkedList();
    int auxProblema;
    printf("\n\t\tingrese numero del problema: ");
    scanf("\n%d",&auxProblema);


    if(path != NULL && pArrayListSoporte != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            if(auxProblema == 1)
            {
                problema = ll_filter(pArrayListSoporte, soporte_problema1);
            }
            if(auxProblema == 2)
            {
                problema = ll_filter(pArrayListSoporte, soporte_problema2);
            }
            if(auxProblema == 3)
            {
                problema = ll_filter(pArrayListSoporte, soporte_problema3);
            }
            if(auxProblema == 4)
            {
                problema = ll_filter(pArrayListSoporte, soporte_problema4);
            }
            if(auxProblema == 5)
            {
                problema = ll_filter(pArrayListSoporte, soporte_problema5);
            }

            for(int i =0; i<ll_len(problema); i++)
            {
                problema = ll_get(problema, i);
                if(problema != NULL)
                {
                    //fprintf(pFileAux, );
                    ret = 0;
                }
            }
            fclose(pFileAux);
        }


    }
    return ret;
}



