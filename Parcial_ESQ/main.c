#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquestas.h"
#include "Instrumentos.h"
#include "Musicos.h"
#define CANTIDAD_ORQUESTAS 50
#define CANTIDAD_INSTRUMENTOS 20
#define CANTIDAD_MUSICOS 1000

//#define 1-SINFONICA
//#define 2-FILARMONICA
//#define 3-CAMARA
//void init_contadorAux(aux_prestamos array[],int size);
//int prestamos_alta(Prestamos array[],Libros arrayB[],Autores arrayC[],int size,int sizeB,int sizeC,int* contadorID);
//--------------------------
int main()
{
    int opcion1;
    int opcion;
    int contadorIdorquestas=0;
    Orquestas arrayOrquestas[CANTIDAD_ORQUESTAS];
    orquestas_Inicializar(arrayOrquestas,CANTIDAD_ORQUESTAS);
    orquestas_mock(arrayOrquestas, CANTIDAD_ORQUESTAS, &contadorIdorquestas) ;
    //---------------------------------------------------------------
    /*
    int opcion2;
    int contadorIdlibros=0;
    Libros arrayLibros[CANTIDAD_LIBROS];
    libros_Inicializar(arrayLibros,CANTIDAD_LIBROS);
    libros_mock(arrayLibros, CANTIDAD_LIBROS, &contadorIdlibros);
    //------------------------printf("4 - Nuevo Telefono\n");--------------------------------------
    int opcion3;
    int contadorIdsocios = 0;
    Socios arraySocios[CANTIDAD_SOCIOS];
    socios_Inicializar(arraySocios,CANTIDAD_SOCIOS);
    socios_mock(arraySocios, CANTIDAD_SOCIOS, &contadorIdsocios);
    //--------------------------------------------------------------


    //--------------------------------------------------------------
    int opcion5;

    aux_prestamos arrayInformes[CANTIDAD_PRESTAMOS];
    */

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
                        case 1:
                            orquestas_alta(arrayOrquestas,CANTIDAD_ORQUESTAS,&contadorIdorquestas);
                            break;
                        case 2:
                            orquestas_listar(arrayOrquestas,CANTIDAD_ORQUESTAS);
                            orquestas_baja(arrayOrquestas,CANTIDAD_ORQUESTAS);
                            break;

                        case 3:
                            orquestas_ordenar(arrayOrquestas,CANTIDAD_ORQUESTAS);
                            orquestas_printPantalla(arrayOrquestas array,CANTIDAD_ORQUESTAS);
                            break;
                    }
                }while(opcion1 != 4);
                break;
            //----------------------------------------------------------------------------

            case 2:
                do
                {
                    MenuLibros();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion2);
                    switch(opcion2)
                    {
                        case 1:
                            libros_alta(arrayLibros,arrayAutores,CANTIDAD_LIBROS,CANTIDAD_AUTORES,&contadorIdlibros);
                            break;
                        case 2:
                            libros_listar(arrayLibros,CANTIDAD_LIBROS);
                            libros_baja(arrayLibros,CANTIDAD_LIBROS);
                            break;
                        case 3:
                            libros_listar(arrayLibros,CANTIDAD_LIBROS);
                            libros_modificar(arrayLibros,arrayAutores,CANTIDAD_LIBROS,CANTIDAD_AUTORES);
                            break;
                        case 4:
                            libros_ordenar(arrayLibros,CANTIDAD_LIBROS);
                            orquestas_printPantalla(arrayOrquestas array,CANTIDAD_ORQUESTAS);

                            break;
                    }
                }while(opcion2 != 5);
                break;
            //----------------------------------------------------------------------------

            case 3:
                do
                {
                    MenuSocios();
                    utn_getUnsignedInt("","\nError",1,sizeof(int),1,5,1,&opcion3);
                    switch(opcion3)
                    {
                        case 1:
                            socios_alta(arraySocios,CANTIDAD_SOCIOS,&contadorIdsocios);
                            break;

                        case 2:
                            socios_ordenar(arraySocios,CANTIDAD_SOCIOS);
                            socios_listar(arraySocios,CANTIDAD_SOCIOS);
                            break;
                    }
                }while(opcion3 != 3);
                break;
            //----------------------------------------------------------------------------

        }

    }while(opcion != 6);
    return 0;
}
