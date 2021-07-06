#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "Controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    ePais* auxPais;
    int cant;
    char nombre[40];
    char id[40];
    char vac1dosis[40];
    char vac2dosis[40];
    char sinVacunar[40];
    int status=0;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,vac1dosis,vac2dosis,sinVacunar);

    do
    {
        cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,vac1dosis,vac2dosis,sinVacunar);

        if(cant<5)
        {
            break;
        }

        auxPais=pais_newParametros(incrementarId(pArrayListEmployee), nombre, atoi(vac1dosis), atoi(vac2dosis),atoi(sinVacunar));
        if(auxPais!=NULL)
        {
            ll_add(pArrayListEmployee, auxPais);
            status++;
            printf("%d\n", status);
        }
        else
        {
            printf("Error generando nuevo empleado\n");
        }
    }
    while(feof(pFile)==0);
    fclose(pFile);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    ePais* auxPais;

    int status=1;
    int len=ll_len(pArrayListEmployee);

    pFile=fopen("data.bin", "rb");
    if(pFile!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxPais=(ePais*) malloc(sizeof(ePais));
            fread(auxPais, sizeof(ePais), 1, pFile);
            ll_add(pArrayListEmployee, auxPais);
        }
    }else{
        status=0;
    }

    fclose(pFile);

    return status;
}
