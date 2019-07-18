#ifndef SOPORTE_H_INCLUDED
#define SOPORTE_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char fecha[128];
    int numero;
    int problema;
    char solucion[128];

}Soporte;

Soporte* soporte_new(void);
Soporte* soporte_newParametros(char* idStr,char* fechaStr,char* numeroStr, char* problemaStr, char* solucionStr);
void soporte_delete(Soporte* this);

int soporte_setId(Soporte* this,int id);
int soporte_getId(Soporte* this,int* id);

int soporte_setFecha(Soporte* this,char* fecha);
int soporte_getfecha(Soporte* this,char* resultado);

int soporte_setNumero(Soporte* this,int numero);
int soporte_getNumero(Soporte* this,int* numero);

int soporte_setProblema(Soporte* this,int problema);
int soporte_getProblema(Soporte* this,int* problema);

int soporte_setSolucion(Soporte* this,char* solucion);
int soporte_getSolucion(Soporte* this,char* resultado);

int soporte_setIdStr(Soporte* this, char* id);
int soporte_getIdStr(Soporte* this, char* resultado);

int soporte_setNumeroStr(Soporte* this, char* numero);
int soporte_getNumeroStr(Soporte* this, char* resultado);

int soporte_setProblemaStr(Soporte* this, char* problema);
int soporte_getProblemaStr(Soporte* this, char* resultado);

int soporte_problema1 (void* this);
int soporte_problema2 (void* this);
int soporte_problema3 (void* this);
int soporte_problema4 (void* this);
int soporte_problema5 (void* this);

#endif // SOPORTE_H_INCLUDED
