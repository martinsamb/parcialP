#ifndef ENTREGA_H_INCLUDED
#define ENTREGA_H_INCLUDED

#define STR_SIZE 20

typedef struct                          //Replace Entrega (tipo) y entrega (f)     campos: Cantidad + cantidad // Importe + importe // Cantidad2 + tipo2
{
    int id;
    char fecha[STR_SIZE];
    int numeroCliente;
    int idProblema;
    char solucion[STR_SIZE]
}Entrega;


Entrega* entrega_new(void);       //constructor         //nuevo Entrega
Entrega* entrega_newParametros(char* idStr,char* fechaStr,char* numeroClienteStr, char* idProblemaStr,char* solucionStr);
void entrega_delete(Entrega* this);
int entrega_setId(Entrega* this,int id);
int entrega_getId(Entrega* this,int* id);
int entrega_setFecha(Entrega* this,char* fecha);
int entrega_getFecha(Entrega* this,char* fecha);
int entrega_setnumeroCliente(Entrega* this,int numeroCliente);
int entrega_getnumeroCliente(Entrega* this,int* numeroCliente);
int entrega_setidProblema(Entrega* this,float idProblema);
int entrega_getidProblema(Entrega* this,float* idProblema);
int entrega_setSolucion(Entrega* this,float solucion);
int entrega_getSolucion(Entrega* this,float* solucion);
int entrega_setIdStr(Entrega* this,char* id);
int entrega_getIdStr(Entrega* this,char* id);
int entrega_setnumeroClienteStr(Entrega* this,char* numeroCliente);
int entrega_getnumeroClienteStr(Entrega* this,char* numeroCliente);
int entrega_setidProblemaStr(Entrega* this,char* idProblema);
int entrega_getidProblemaStr(Entrega* this,char* idProblema);
int entrega_setSolucionStr(Entrega* this,char* solucion);
int entrega_getSolucionStr(Entrega* this,char* solucion);
int soporte_problema1(void* this);
int soporte_problema2(void* this);
int soporte_problema3(void* this);
int soporte_problema4(void* this);
int soporte_problema5(void* this);




#endif // ENTREGA_H_INCLUDED
