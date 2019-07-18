#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "soporte.h"
#include "validaciones.h"
#include "LinkedList.h"



/** \brief Reserva espacio en memoria para un soporte
 * \param void vacio
 * \return Soporte* un puntero al espacio reservado para cargar un soporte
 */
Soporte* soporte_new(void)
{
    return (Soporte*) malloc(sizeof(Soporte));
}

/** \brief Valida los elementos que contiene una soporte y los carga en una variable Soporte
 *
 * \param idStr char* id del soporte.
 * \param tipoStr char* tipo  de la soporte.
 * \param cantidadStr char* cantidad del soporte.
 * \param importeStr char* importe del soporte.
 * \return Soporte* pAuxSoporte, devuelve - NULL si puntero a idStr/tipoStr/cantidadStr/importeStr NULL,
 *                               devuelve - puntero si valido sus elementos.
 *
 */
Soporte* soporte_newParametros(char* idStr,char* fechaStr,char* numeroStr, char* problemaStr, char* solucionStr)
{
    Soporte* pSoporte = soporte_new();
    Soporte* retorno = NULL;

    if(pSoporte != NULL && idStr != NULL && fechaStr != NULL && numeroStr != NULL && problemaStr != NULL && solucionStr != NULL)
    {
        if(!soporte_setIdStr(pSoporte, idStr) &&
                !soporte_setFecha(pSoporte, fechaStr) &&
                !soporte_setNumeroStr(pSoporte, numeroStr) &&
                !soporte_setProblemaStr(pSoporte, problemaStr)&&
                !soporte_setSolucion(pSoporte, solucionStr))
        {

            retorno = pSoporte;
        }
        else
        {
            soporte_delete(pSoporte);
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para una soporte.
 *
 * \param Soporte* this puntero a la soporte
 * \return int retorno -1 si this NULL,
 *                     0 si logro liberar el espacio reservado.
 *
 */
void soporte_delete(Soporte* this)
{
    if(this != NULL)
    {
        return free(this);
    }
}

/** \brief Valida el elemento id de la soporte y lo carga en la estructura Soporte
 *
 * \param this Soporte* puntero a la soporte
 * \param id int id del soporte
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 *
 */
int soporte_setId(Soporte* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0 )
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un soporte.
 *
 * \param this Soporte* puntero a soporte.
 * \param resultado int* id de Soporte
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 *
 */
int soporte_getId(Soporte* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int soporte_setFecha(Soporte* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL && fecha != NULL && validFecha(fecha))
    {
        strcpy(this->fecha,fecha);
        retorno = 0;
    }
    return retorno;
}

int soporte_getfecha(Soporte* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->fecha);
        retorno = 0;
    }
    return retorno;
}

int soporte_setNumero(Soporte* this,int numero)
{
    int retorno = -1;
    if(this != NULL && numero >= 0)
    {
        this->numero = numero;
        retorno = 0;
    }
    return retorno;
}

int soporte_getNumero(Soporte* this,int* numero)
{
    int retorno = -1;
    if(this != NULL && numero != NULL)
    {
        *numero = this->numero;
        retorno = 0;
    }
    return retorno;
}

int soporte_setProblema(Soporte* this,int problema)
{
    int retorno = -1;
    if(this != NULL && problema >= 0)
    {
        this->problema = problema;
        retorno = 0;
    }
    return retorno;
}

int soporte_getProblema(Soporte* this,int* problema)
{
    int retorno = -1;
    if(this != NULL && problema != NULL)
    {
        *problema = this->problema;
        retorno = 0;
    }
    return retorno;
}

int soporte_setSolucion(Soporte* this,char* solucion)
{
    int retorno = -1;
    if(this != NULL && solucion != NULL /*&& validSoluc(solucion)*/)
    {
        strcpy(this->solucion,solucion);
        retorno = 0;
    }
    return retorno;
}

int soporte_getSolucion(Soporte* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->solucion);
        retorno = 0;
    }
    return retorno;
}

int soporte_setIdStr(Soporte* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && validNumber(id))//Validar que lo que recibe es un numero.
    {
        retorno = soporte_setId(this,atoi(id));
    }
    return retorno;
}

int soporte_getIdStr(Soporte* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        soporte_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int soporte_setNumeroStr(Soporte* this, char* numero)
{
    int retorno = -1;
    if(this != NULL && numero != NULL && validNumber(numero))//Validar que lo que recibe es un numero.
    {
        retorno = soporte_setNumero(this,atoi(numero));
    }
    return retorno;
}

int soporte_getNumeroStr(Soporte* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        soporte_getNumero(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int soporte_setProblemaStr(Soporte* this, char* problema)
{
    int retorno = -1;
    if(this != NULL && problema != NULL && validNumber(problema))//Validar que lo que recibe es un numero.
    {
        retorno = soporte_setProblema(this,atoi(problema));
    }
    return retorno;
}

int soporte_getProblemaStr(Soporte* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        soporte_getProblema(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int soporte_problema1 (void* this)
{
    int ret = 0;
    int auxProblema;

    if(this!= NULL)
    {
        soporte_getProblema((Soporte*)this, &auxProblema);
        if(auxProblema==1)
        {
            ret=1;
        }
    }
    return ret;
}
int soporte_problema2 (void* this)
{
    int ret = 0;
    int auxProblema;

    if(this!= NULL)
    {
        soporte_getProblema((Soporte*)this, &auxProblema);
        if(auxProblema==2)
        {
            ret=1;
        }
    }
    return ret;
}
int soporte_problema3 (void* this)
{
    int ret = 0;
    int auxProblema;

    if(this!= NULL)
    {
        soporte_getProblema((Soporte*)this, &auxProblema);
        if(auxProblema==3)
        {
            ret=1;
        }
    }
    return ret;
}
int soporte_problema4 (void* this)
{
    int ret = 0;
    int auxProblema;

    if(this!= NULL)
    {
        soporte_getProblema((Soporte*)this, &auxProblema);
        if(auxProblema==4)
        {
            ret=1;
        }
    }
    return ret;
}
int soporte_problema5 (void* this)
{
    int ret = 0;
    int auxProblema;

    if(this!= NULL)
    {
        soporte_getProblema((Soporte*)this, &auxProblema);
        if(auxProblema==5)
        {
            ret=1;
        }
    }
    return ret;
}

