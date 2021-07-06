#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "Controller.h"




int incrementarId(LinkedList* this)
{
    int tam=ll_len(this);
    return tam+=1;
}


/** \brief Carga los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 todoOk / 0 error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f = fopen(path,"r");

    if(f!=NULL && path!= NULL && pArrayListEmployee!= NULL)
    {
        todoOk=1;
        parser_EmployeeFromText(f, pArrayListEmployee);
    }
    else
    {
        printf("No se pudo abrir el archivo texto.\n");
    }

    return todoOk;
}

int controller_ListPaises(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {

        int flagPaises=0;
        int tam = ll_len(pArrayListEmployee);
        if(tam>0)
        {
            printf("      LISTA DE PAISES\n");
            printf("Id         Nombre         PrimerDosis      SegundaDosis       SinVacunar\n");

            for(int i=0; i<tam; i++)
            {
                mostrarPais(pArrayListEmployee, i);
                flagPaises=1;
                todoOk=1;
            }
            if(flagPaises==0)
            {
                printf("No hay paises cargados por el momento\n");
            }
            printf("\n");
        }
    }
    return todoOk;
}

/** \brief Ordenar paises
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {
        int order=ll_sort(pArrayListEmployee,comparaEmployees,0);
        if(order==0 || order==1)
        {
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief Guarda los datos de los paises en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    FILE* f = fopen(path,"w");

    if(f==NULL || path== NULL || pArrayListEmployee== NULL)
    {
        printf("No se pudo guardar el archivo texto.\n");
    }else{

    ePais* auxPais;
    int cant;
    fprintf(f,"Id   Nombre      PrimerDosis    SegundaDosis     SinVacunar\n");
    cant=ll_len(pArrayListEmployee);
    for(int i=0; i<cant; i++)
    {
        auxPais=(ePais*) ll_get(pArrayListEmployee, i);

        fprintf(f,"%d,%10s,%d,%d, %d\n",auxPais->id,auxPais->nombre,auxPais->vac1dosis,auxPais->vac2dosis, auxPais->sinVacunar);

    }
    todoOk=1;

    }
    fclose(f);
    return todoOk;
}



