#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{
  int contador;
  char auxFecha[9];

}aux_prestamos;




#endif // INFORMES_H_INCLUDED
void MenuInformes();
void InformeA(Prestamos array[],aux_prestamos arrayB[],int size,int *contador);

