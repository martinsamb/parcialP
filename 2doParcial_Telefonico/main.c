#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "soporte.h"
#include "parser.h"

int main()
{
    //printf("Hello world!\n");



    LinkedList* listaSoporte = ll_newLinkedList();

    controller_loadFromText("data.csv", listaSoporte);
    controller_ListSoporte(listaSoporte);

    //controller_saveAsText("informe.csv", listaSoporte);


    return 0;
}
