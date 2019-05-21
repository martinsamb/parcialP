#ifndef INSTRUMENTOS_H_INCLUDED
#define INSTRUMENTOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;

}Instrumentos;

#endif // INSTRUMENTOS_H_INCLUDED

int instrumentos_Inicializar(Instrumentos array[], int size);                                    //cambiar instrumentos
int instrumentos_buscarEmpty(Instrumentos array[], int size, int* posicion);                    //cambiar instrumentos
int instrumentos_buscarID(Instrumentos array[], int size, int valorBuscado, int* posicion);                    //cambiar instrumentos
int instrumentos_alta(Instrumentos array[], int size, int* contadorID);                          //cambiar instrumentos
int instrumentos_listar(Instrumentos array[], int size);                      //cambiar instrumentos
void MenuInstrumentos();
void MenuInstrumentosPrincipal();




