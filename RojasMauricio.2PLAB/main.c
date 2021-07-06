#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "Controller.h"

//Parcial Mauricio Rojas 1G

//Disculpe si hay codigo que habla de "empleados", use como guia el tp3 y no llegue a refactorizar todo.

int main()
{
    char nameDownload[15];
    int option = 0;
    srand(time(NULL));

    LinkedList* listado = ll_newLinkedList();

    int flagIng = 0;
    LinkedList* paises = NULL;
    LinkedList* paisesExitosos = NULL;
    LinkedList* paisesAlHorno=NULL;

    do
    {
        switch(menu())
        {
        case 1:

            printf("Ingrese nombre del archivo a subir (vacunas.csv): ");
            fflush(stdin);
            scanf(" %s",nameDownload);


            controller_loadFromText(nameDownload,listado);
            flagIng=1;
            break;

        case 2:
            if(ll_len(listado)>0)
            {

                if(controller_ListPaises(listado))
                {
                    printf("Paises mostrados con exito\n");
                }
                else
                {
                    printf("Error al mostrar paises\n");
                }
            }
            else
            {
                printf("No hay paises cargados al momento\n");

            }
            break;

        case 3:
            //asignar valores
            paises = ll_map(listado,asignarEstadisticas);
            if(paises != NULL && flagIng)
            {
                ll_deleteLinkedList(listado);
                controller_ListPaises(paises);
            }
            break;
        case 4:
            paisesExitosos = ll_filter(paises,sonPaisesExitosos);
            printf("Genere un nombre para el archivo csv descargable: ");
            fflush(stdin);
            scanf("%s",nameDownload);
            controller_saveAsText(nameDownload,paisesExitosos);
            controller_ListPaises(paisesExitosos);

            break;
        case 5:
            paisesAlHorno = ll_filter(paises,sonPaisesAlHorno);
            printf("Genere un nombre para el archivo csv descargable: ");
            fflush(stdin);
            scanf("%s",nameDownload);
            controller_saveAsText(nameDownload,paisesAlHorno);
            controller_ListPaises(paisesAlHorno);

            break;
        case 6:

            ll_sort(paises,ordenarPorVacunacion,0);
            controller_ListPaises(paises);

            break;
        case 7:

            break;
        case 8:
            option=8;
            break;
        }



        system("pause");

    }
    while(option != 8);
    return 0;
}

