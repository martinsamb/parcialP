#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "soporte.h"

/** \brief Parsea los datos de las ventas desde el archivo (modo texto).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListSoporte LinkedList* puntero al array de soportes.
* \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListSoporte es NULL,
                   0 si logro parsear el archivo.
 *
 */
int parser_SoporteFromText(FILE* pFile, LinkedList* pArrayListSoporte)
{
    int ret = -1;
    char bufferId[400];
    char bufferFecha[400];
    char bufferNumero[400];
    char bufferProblema[400];
    char bufferSolucion[400];
    Soporte* pAuxSoporte;

    if(pFile != NULL && pArrayListSoporte != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFecha,bufferNumero,bufferProblema,bufferSolucion);
            pAuxSoporte = soporte_newParametros(bufferId,bufferFecha,bufferNumero,bufferProblema,bufferSolucion);
            if(pAuxSoporte != NULL)
            {
                ll_add(pArrayListSoporte, pAuxSoporte);
                printf("%d", ll_len(pArrayListSoporte));
                ret = 0;
            }
        }
        fclose(pFile);
        //printf("%d", ll_len(pArrayListSoporte));
    }
    return ret;
}
