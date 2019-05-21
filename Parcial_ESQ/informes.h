#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{
  int contador;
  char auxFecha[9];

}aux_prestamos;




#endif // INFORMES_H_INCLUDED

int Informes_listarMusicos(Musicos arrayA[], Instrumentos arrayB[], int sizeI, int sizeJ);
void MenuInformes();

