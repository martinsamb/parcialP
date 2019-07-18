#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Entrega.h"       //Replace Entrega (tipo) y entrega (f)     campos: Cantidad + cantidad // Importe + importe // Tipo2 + tipo2
#include "utn.h"


/*
-entrega_new
-entrega_newParametros          //cambiar campos
-entrega_newBinario             //cambiar campos
-entrega_delete

-entrega_setIdStr
-entrega_setId
-entrega_getId

-entrega_setTipo
-entrega_getTipo

-entrega_setCantidadStr
-entrega_setCantidad
-entrega_getCantidad

-entrega_setImporteStr
-entrega_setImporte
-entrega_getImporte

-entrega_cmpId
-entrega_cmpName

-entrega_searchId
-entrega_searchMaxId

*/

/** \brief Reserva espacio en memoria para un Entrega
 *
 * \param void
 * \return Entrega*
 *
 */
Entrega* entrega_new(void)       //constructor         //nuevo Entrega
{
    return (Entrega*) malloc(sizeof(Entrega));
}

/** \brief Valida los campos y los carga en una variable Entrega
 *
 * \param idStr char*
 * \param tipoStr char*
 * \param cantidadStr char*
 * \param importeStr char*
 * \return Entrega*
 *
 */
Entrega* entrega_newParametros(char* idStr,char* fechaStr,char* numeroClienteStr, char* idProblemaStr,char* solucionStr)
{
    Entrega* retorno=NULL;
    Entrega* bufferP;

    if(idStr!=NULL && fechaStr!=NULL && numeroClienteStr!=NULL && idProblemaStr!=NULL && solucionStr != NULL)
    {
        bufferP=entrega_new();
        if(bufferP!=NULL)
        {
            if(!entrega_setIdStr(bufferP,idStr) &&
                !entrega_setFecha(bufferP,fechaStr) &&
                !entrega_setnumeroCliente(bufferP,numeroClienteStr) &&
                !entrega_setidProblema(bufferP,idProblemaStr)&&
                !entrega_setSolucion(bufferP,solucionStr)))
            {
                retorno=bufferP;
            }
            else
            {
                entrega_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Valida los campos y los carga en una variable Entrega
 *
 * \param entrega Entrega
 * \return Entrega*
 *
 *//*
Entrega* entrega_newBinario(Entrega entrega)
{
    Entrega* retorno=NULL;
    Entrega* bufferP;

    char arrayBuffers[3][STR_SIZE];

    sprintf(arrayBuffers[0],"%d",entrega.id);
    sprintf(arrayBuffers[1],"%d",entrega.cantidad);
    sprintf(arrayBuffers[2],"%d",entrega.importe);

    if(arrayBuffers[0]!=NULL && entrega.tipo!=NULL && arrayBuffers[1]!=NULL && arrayBuffers[2]!=NULL)
    {
        bufferP=entrega_new();
        if(bufferP!=NULL)
        {
            if(!entrega_setIdStr(bufferP,arrayBuffers[0]) &&
                !entrega_setTipo(bufferP,entrega.tipo) &&
                !entrega_setCantidadStr(bufferP,arrayBuffers[1]) &&
                !entrega_setImporteStr(bufferP,arrayBuffers[2]))
            {
                retorno=bufferP;
            }
            else
            {
                entrega_delete(bufferP);
            }
        }
    }
    return retorno;
}*/

/** \brief Libera el espacio reservado en memoria para un entrega
 *
 * \param this Entrega*
 * \return void
 *
 */
void entrega_delete(Entrega* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//********************************************************************************************************************
//Setter+getters


/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param id int
 * \return int
 *
 */
int entrega_setId(Entrega* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Entrega
 *
 * \param this Entrega*
 * \param id int*
 * \return int
 *
 */
int entrega_getId(Entrega* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param tipo char*
 * \return int
 *
 */
int entrega_setFecha(Entrega* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL && isValidName(fecha))       //puedo validar PLUS, REGULAR, GOLD
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Entrega
 *
 * \param this Entrega*
 * \param tipo char*
 * \return int
 *
 */
int entrega_getFecha(Entrega* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param cantidad int
 * \return int
 *
 */
int entrega_setnumeroCliente(Entrega* this,int numeroCliente)
{
    int retorno=-1;
    if(this!=NULL && numeroCliente>=0)
    {
        this->numeroCliente=numeroCliente;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Entrega
 *
 * \param this Entrega*
 * \param cantidad int*
 * \return int
 *
 */
int entrega_getnumeroCliente(Entrega* this,int* numeroCliente)
{
    int retorno=-1;
    if(this!=NULL && numeroCliente!=NULL)
    {
        *numeroCliente=this->numeroCliente;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param importe float
 * \return int
 *
 */
int entrega_setidProblema(Entrega* this,float idProblema)
{
    int retorno=-1;
    if(this!=NULL && idProblema>=0)
    {
        this->idProblema=idProblema;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Entrega
 *
 * \param this Entrega*
 * \param importe float*
 * \return int
 *
 */
int entrega_getidProblema(Entrega* this,float* idProblema)
{
    int retorno=-1;
    if(this!=NULL && idProblema!=NULL)
    {
        *idProblema=this->idProblema;
        retorno=0;
    }
    return retorno;
}

//*******************************************************************

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param importe float
 * \return int
 *
 */
int entrega_setSolucion(Entrega* this,float solucion)
{
    int retorno=-1;
    if(this!=NULL && solucion>=0)
    {
        this->solucion=solucion;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Entrega
 *
 * \param this Entrega*
 * \param importe float*
 * \return int
 *
 */
int entrega_getSolucion(Entrega* this,float* solucion)
{
    int retorno=-1;
    if(this!=NULL && solucion!=NULL)
    {
        *solucion=this->solucion;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param id char*
 * \return int
 *
 */
int entrega_setIdStr(Entrega* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=entrega_setId(this,atoi(id));
    }
    return retorno;
}
/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param id char*
 * \return int
 *
 */
int entrega_getIdStr(Entrega* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if(this!=NULL && id!=NULL)
    {
        entrega_getId(this, &bufferInt);
        sprintf(id, "%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}


/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param cantidad char*
 * \return int
 *
 */
int entrega_setnumeroClienteStr(Entrega* this,char* numeroCliente)
{
    int retorno=-1;
    if(this!=NULL && numeroCliente!=NULL && isValidNumber(numeroCliente))
    {
        retorno=entrega_setnumeroClienteStr(this,atoi(numeroCliente));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param id char*
 * \return int
 *
 */
int entrega_getnumeroClienteStr(Entrega* this,char* numeroCliente)
{
    int retorno=-1;
    int bufferInt;
    if(this!=NULL && numeroCliente!=NULL)
    {
        entrega_getnumeroCliente(this, &bufferInt);
        sprintf(numeroCliente, "%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param importe char*
 * \return int
 *
 */
int entrega_setidProblemaStr(Entrega* this,char* idProblema)
{
    int retorno=-1;
    if(this!=NULL && idProblema!=NULL && isValidFloatNumber(idProblema))
    {
        retorno=entrega_setImporte(this,atof(idProblema));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param id char*
 * \return int
 *
 */
int entrega_getidProblemaStr(Entrega* this,char* idProblema)
{
    int retorno=-1;
    int bufferInt;
    if(this!=NULL && idProblema!=NULL)
    {
        entrega_getidProblema(this, &bufferInt);
        sprintf(idProblema, "%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param importe char*
 * \return int
 *
 */
int entrega_setSolucionStr(Entrega* this,char* solucion)
{
    int retorno=-1;
    if(this!=NULL && solucion!=NULL && isValidFloatNumber(solucion))
    {
        retorno=entrega_setSolucion(this,atof(solucion));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Entrega
 *
 * \param this Entrega*
 * \param id char*
 * \return int
 *
 */
int entrega_getSolucionStr(Entrega* this,char* solucion)
{
    int retorno=-1;
    int bufferInt;
    if(this!=NULL && solucion!=NULL)
    {
        entrega_getSolucion(this, &bufferInt);
        sprintf(solucion, "%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

int soporte_problema1(void* this)
{
    int retorno = 0;
    int auxProblema;

    if(this != NULL)
    {
        entrega_getidProblema((Entrga*)this,&auxProblema);
        if(auxProblema == 1)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int soporte_problema2(void* this)
{
    int retorno = 0;
    int auxProblema;

    if(this != NULL)
    {
        entrega_getidProblema((Entrga*)this,&auxProblema);
        if(auxProblema == 2)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int soporte_problema3(void* this)
{
    int retorno = 0;
    int auxProblema;

    if(this != NULL)
    {
        entrega_getidProblema((Entrga*)this,&auxProblema);
        if(auxProblema == 3)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int soporte_problema4(void* this)
{
    int retorno = 0;
    int auxProblema;

    if(this != NULL)
    {
        entrega_getidProblema((Entrga*)this,&auxProblema);
        if(auxProblema == 4)
        {
            retorno = 1;
        }
    }
    return retorno;
}


int soporte_problema5(void* this)
{
    int retorno = 0;
    int auxProblema;

    if(this != NULL)
    {
        entrega_getidProblema((Entrga*)this,&auxProblema);
        if(auxProblema == 5)
        {
            retorno = 1;
        }
    }
    return retorno;
}



//*******************************************************************
/*
/** \brief Busca un ID y devuelve el indice
 *
 * \param pArrayList LinkedList*
 * \param valorBuscado int
 * \param index int*
 * \return int
 *
 */
 /*
int entrega_searchId(LinkedList* pArrayList, int valorBuscado, int* index)
{
    int retorno=-1;
    int i;
    int bufferID;
    int size=ll_len(pArrayList);
    Entrega* puntero=NULL;

    if(pArrayList!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            entrega_getId(puntero,&bufferID);

            if(valorBuscado==bufferID)
            {
                *index=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Compara dos ID
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
 /*
int entrega_cmpId(void* this1, void* this2)
{
    int retorno=-1;

    int bufferIdI;
    int bufferIdJ;

    if(this1!=NULL && this2!=NULL)
    {
        entrega_getId((Entrega*)this1,&bufferIdI);
        entrega_getId((Entrega*)this2,&bufferIdJ);
        if(bufferIdI==bufferIdJ)
            retorno=0;
        else if(bufferIdI>bufferIdJ)
            retorno=1;
        else if(bufferIdI<bufferIdJ)
            retorno=-1;
    }
    return retorno;
}

/** \brief Compara dos Nombres
 *
 * \param this1 void*
 * \param this2 void*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
 /*
int entrega_cmpTipo(void* this1, void* this2)          //el sort es generico asique se usa el puntero generico void
{
    int retorno=-1;

    char bufferI[STR_SIZE];
    char bufferJ[STR_SIZE];

    if(this1!=NULL && this2!=NULL)
    {
        entrega_getTipo((Entrega*)this1,bufferI);
        entrega_getTipo((Entrega*)this2,bufferJ);
        if(strcmp(bufferI,bufferJ)==0)
            retorno=0;
        if(strcmp(bufferI,bufferJ)>0)
            retorno=1;
        if(strcmp(bufferI,bufferJ)<0)
            retorno=-1;
    }
    return retorno;
}

/** \brief Compara el tipo con un criterio
 *
 * \param this1 void*
 * \param criterio char*
 * \return int (0) Si son iguales (1) Si el primero es mayor (-1) Si el primero es menor
 *
 */
 /*
int entrega_cmpCriterio(void* this1, char* criterio)
{
    int retorno=-1;
    char bufferTipo[STR_SIZE];

    if(this1!=NULL && criterio!=NULL)
    {
        entrega_getTipo((Entrega*)this1,bufferTipo);
        if(strcmp(bufferTipo,criterio)==0)
            retorno=0;
        if(strcmp(bufferTipo,criterio)>0)
            retorno=1;
        if(strcmp(bufferTipo,criterio)<0)
            retorno=-1;
    }
    return retorno;
}

/** \brief Busca el maximo ID
 *
 * \param pArrayList LinkedList*
 * \param maxID int*
 * \return int
 *
 */
 /*
int entrega_searchMaxId(LinkedList* pArrayList, int* maxID)
{
    int retorno=-1;
    Entrega* puntero=NULL;
    int size=ll_len(pArrayList);
    int i;
    int bufferId;
    int bufferMaxId=*maxID;

    if(pArrayList!=NULL && maxID!=NULL)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayList,i);
            if(puntero!=NULL)
            {
                entrega_getId(puntero,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        retorno=0;
    }
    return retorno;
}

