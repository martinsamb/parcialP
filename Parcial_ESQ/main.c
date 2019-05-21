#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquestas.h"
#include "Instrumentos.h"
#include "Musicos.h"
#include "informes.h"

#define CANTIDAD_ORQUESTAS 50
#define CANTIDAD_INSTRUMENTOS 20
#define CANTIDAD_MUSICOS 1000

int cargarDatos(Instrumentos arrayInstrumentos[], Musicos arrayMusicos[], Orquestas arrayOrquestas[], int *contadorIdOrquestas, int *contadorIdInstrumentos, int *contadorIdMusicos);
int main()
{
    int opcion;

    int opcion1;
    int contadorIdorquestas = 0;
    int flagOrquestas = 0;
    Orquestas arrayOrquestas[CANTIDAD_ORQUESTAS];
    orquestas_Inicializar(arrayOrquestas,CANTIDAD_ORQUESTAS);

    //---------------------------------------------------------------

    int opcion2;
    int contadorIdmusicos=0;
    int flagMusicos = 0;
    Musicos arrayMusicos[CANTIDAD_MUSICOS];
    musicos_Inicializar(arrayMusicos,CANTIDAD_MUSICOS);

    //----------------------------------------------------------------
    int opcion3;
    int contadorIdinstrumentos = 0;
    int flagInstrumentos = 0;
    Instrumentos arrayInstrumentos[CANTIDAD_INSTRUMENTOS];
    instrumentos_Inicializar(arrayInstrumentos,CANTIDAD_INSTRUMENTOS);

    //--------------------------------------------------------------

    cargarDatos(arrayInstrumentos,arrayMusicos,arrayOrquestas,&contadorIdorquestas,&contadorIdinstrumentos,&contadorIdmusicos);
    do
    {
        MenuOrquestasPrincipal();
           utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion);
        switch(opcion)
        {
            //------------------------------------------------------------------------
            case 1:
                do
                {
                    MenuOrquestas();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion1);
                    switch(opcion1)
                    {
                        case 1://alta orquests
                            if(orquestas_alta(arrayOrquestas,CANTIDAD_ORQUESTAS,&contadorIdorquestas)== 0)
                                flagOrquestas = 1;
                            break;
                        case 2://baja orquesta
                            if(flagOrquestas == 0)
                            {
                                printf("\nNo se ha dado de alta ninguna Orquestas");
                            }
                            else
                            orquestas_baja(arrayOrquestas,CANTIDAD_ORQUESTAS,arrayMusicos,CANTIDAD_MUSICOS);
                            break;

                        case 3:// listar orquesta
                            if(flagOrquestas == 0)
                            {
                                printf("\nNo se ha dado del alta ninguna orquesta");
                            }
                            else
                                orquestas_listar(arrayOrquestas,CANTIDAD_ORQUESTAS);
                            break;
                    }
                }while(opcion1 != 4);
                break;
            //----------------------------------------------------------------------------

            case 2:
                do
                {
                    MenuMusicos();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion2);
                    switch(opcion2)
                    {
                        case 1://alta musicos
                            if(musicos_alta(arrayMusicos,CANTIDAD_MUSICOS,&contadorIdmusicos)== 0)
                                flagMusicos == 1;
                            break;
                        case 2://Modificar musicos
                            if(flagMusicos == 0)
                            {
                                printf("\nNo se ha dado de alta ningun musico");
                            }
                            else
                                musicos_modificar(arrayMusicos,CANTIDAD_MUSICOS);
                            break;
                        case 3://baja musicos
                            if(flagMusicos == 0)
                            {
                                printf("\nNo se ha dado de alta ningun musico");
                            }
                            else
                                musicos_baja(arrayMusicos,CANTIDAD_MUSICOS);
                            break;
                        case 4://listar musicos
                            if(flagMusicos == 0)
                            {
                                printf("\nNo se ha dado de alta ningun musico");
                            }
                            else
                                Informes_listarMusicos(arrayMusicos, arrayInstrumentos, CANTIDAD_MUSICOS, CANTIDAD_INSTRUMENTOS);
                            break;
                    }
                }while(opcion2 != 5);
                break;
            //----------------------------------------------------------------------------

            case 3:
                do
                {
                    MenuInstrumentos();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion3);
                    switch(opcion3)
                    {
                        case 1://alta instrumentos
                            if(instrumentos_alta(arrayInstrumentos,CANTIDAD_INSTRUMENTOS,&contadorIdinstrumentos)==0)
                                flagInstrumentos = 1;
                            break;

                        case 2://listar instrumentos
                            if(flagInstrumentos == 0)
                            {
                                printf("\nNo se ha dado de alta ningun instrumento");
                            }
                            else
                                instrumentos_listar(arrayInstrumentos,CANTIDAD_INSTRUMENTOS);
                            break;
                    }
                }while(opcion3 != 3);
                break;
            //----------------------------------------------------------------------------
        }

    }while(opcion != 4);
    return 0;
}
int cargarDatos(Instrumentos arrayInstrumentos[], Musicos arrayMusicos[], Orquestas arrayOrquestas[], int *contadorIdOrquestas, int *contadorIdInstrumentos, int *contadorIdMusicos)
{
    int i=0;
    //musico
    arrayMusicos[i].isEmpty=0;
    arrayMusicos[i].idUnico=*contadorIdMusicos;
    arrayMusicos[i].edad=45;
    arrayMusicos[i].idOrquestas=*contadorIdOrquestas;
    arrayMusicos[i].idInstrumentos=*contadorIdInstrumentos;
    strcpy(arrayMusicos[i].nombre,"Federico");
    strcpy(arrayMusicos[i].apellido,"Chopin");
    (*contadorIdMusicos)++;

    //orquesta
    arrayOrquestas[i].isEmpty=0;
    arrayOrquestas[i].idUnico=*contadorIdOrquestas;
    arrayOrquestas[i].tipo=1;
    strcpy(arrayOrquestas[i].nombre,"Sinfonica Buenos Aires");
    strcpy(arrayOrquestas[i].lugar,"Buenos Aires");
    (*contadorIdOrquestas)++;

    //instrumento
    arrayInstrumentos[i].isEmpty=0;
    arrayInstrumentos[i].idUnico=*contadorIdInstrumentos;
    arrayInstrumentos[i].tipo=1;
    strcpy(arrayInstrumentos[i].nombre,"Violin");
    (*contadorIdInstrumentos)++;

    i++;
    //musico
    arrayMusicos[i].isEmpty=0;
    arrayMusicos[i].idUnico=*contadorIdMusicos;
    arrayMusicos[i].edad= 32;
    arrayMusicos[i].idOrquestas=*contadorIdOrquestas;
    arrayMusicos[i].idInstrumentos=*contadorIdInstrumentos;
    strcpy(arrayMusicos[i].nombre,"Sebastian");
    strcpy(arrayMusicos[i].apellido,"Bach");
    (*contadorIdMusicos)++;

    //orquesta
    arrayOrquestas[i].isEmpty=0;
    arrayOrquestas[i].idUnico=*contadorIdOrquestas;
    arrayOrquestas[i].tipo=2;
    strcpy(arrayOrquestas[i].nombre,"Sinfonica Juventus Lirica");
    strcpy(arrayOrquestas[i].lugar,"Cordoba");
    (*contadorIdOrquestas)++;

    //instrumento
    arrayInstrumentos[i].isEmpty=0;
    arrayInstrumentos[i].idUnico=*contadorIdInstrumentos;
    arrayInstrumentos[i].tipo=3;
    strcpy(arrayInstrumentos[i].nombre,"Clarinete");
    (*contadorIdInstrumentos)++;
    return 0;
}
