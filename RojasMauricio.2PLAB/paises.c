#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "paises.h"

//Menu ABM
int menu ()
{
    int opcion;
    system("cls");
    printf ("Gestion de vacunas\n\n");
    printf("1. Cargar los datos de los paises desde el archivo vacunas.csv (modo texto): \n");
    printf("2. Listar paises\n");
    printf("3. Asignar Valores\n");
    printf("4. Paises exitosos\n");
    printf("5. Paises al horno\n");
    printf("6. Ordenar\n");
    printf("7. Pais mas castigado\n");
    printf("8. Salir\n");
    printf ("Ingrese opcion: ");

    scanf ("%d", &opcion);
    return opcion;
}


//Constructores
ePais* pais_new()
{

    ePais* newPais =(ePais*) malloc(sizeof(ePais));
    if(newPais!=NULL)
    {
        newPais->id=0;
        strcpy(newPais->nombre,"");
        newPais->vac1dosis=0;
        newPais->vac2dosis=0;
        newPais->sinVacunar=0;
    }
    return newPais;
}


ePais* pais_newParametros(int id,char* nombre,int vac1dosis, int vac2dosis, int sinVacunar)
{
    ePais* auxPais=pais_new();

    if(auxPais!=NULL)
    {

        if(pais_setId(auxPais,id) &&
                pais_setVacuna2(auxPais, vac2dosis) &&
                pais_setNombre(auxPais,nombre) &&
                pais_setVacuna1(auxPais,vac1dosis)&&
                pais_setSinVacunar(auxPais,sinVacunar))
        {

            printf("Carga exitosa\n");
        }
        else
        {
            free(auxPais);
            auxPais = NULL;
        }
    }

    return auxPais;
}

//Destructor
int employee_delete(ePais* pais)
{
    int todoOk=0;
    if(pais !=NULL)
    {
        free (pais);
        todoOk=1;
    }
    return todoOk;
}


//Setters
int pais_setId(ePais* pais,int id)
{
    int todoOk=0;
    if(pais != NULL && id > 0)
    {
        pais->id=id;
        todoOk=1;
    }
    return todoOk;
}

int pais_setNombre(ePais* pais, char* nombre)
{
    int todoOk=0;
    if (pais!=NULL && nombre!=NULL && strlen(nombre)>=1 && strlen(nombre)<25)
    {
        strcpy(pais->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}

int pais_setVacuna1(ePais* pais,int vac1dosis)
{
    int todoOk=0;
    if(pais != NULL && vac1dosis >= 0)
    {
        pais->vac1dosis=vac1dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_setVacuna2(ePais* pais,int vac2dosis)
{
    int todoOk=0;
    if(pais != NULL && vac2dosis >= 0)
    {
        pais->vac2dosis=vac2dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_setSinVacunar(ePais* pais,int sinVacunar)
{
    int todoOk=0;
    if(pais != NULL && sinVacunar >= 0)
    {
        pais->sinVacunar=sinVacunar;
        todoOk=1;
    }
    return todoOk;
}


//Getters
int pais_getId(ePais* pais,int* pId)
{
    int todoOk=0;
    if(pais != NULL && pId != NULL)
    {
        *pId=pais->id;
        todoOk=1;
    }
    return todoOk;
}

int pais_getNombre(ePais* pais, char* pNombre)
{
    int todoOk=0;
    if (pais!=NULL && pNombre!=NULL)
    {
        strcpy(pNombre, pais->nombre);
        todoOk=1;
    }
    return todoOk;
}

int pais_getVacuna1(ePais* pais,int* vac1dosis)
{
    int todoOk=0;
    if(pais != NULL && vac1dosis != NULL)
    {
        *vac1dosis=pais->vac1dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_getVacuna2(ePais* pais,int* vac2dosis)
{
    int todoOk=0;
    if(pais != NULL && vac2dosis != NULL)
    {
        *vac2dosis=pais->vac2dosis;
        todoOk=1;
    }
    return todoOk;
}

int pais_getSinVacunar(ePais* pais,int* sinVacunar)
{
    int todoOk=0;
    if(pais != NULL && sinVacunar != NULL)
    {
        *sinVacunar=pais->sinVacunar;
        todoOk=1;
    }
    return todoOk;
}


//Buscar Libre empleado
int buscarLibreEmpleado(ePais** pais, int sizeEmp, int* pIndice)
{
    int retorno=0;
    *pIndice = -1;
    if(pais!=NULL && sizeEmp>0 && pIndice!=NULL)
    {
        for(int i=0; i<sizeEmp; i++)
        {
            if(*(pais+i)==NULL)
            {
                *pIndice=i;
                break;
            }
        }
        retorno=1;
    }
    return retorno;
}




//Mostrar empleado (uno)
void mostrarPais(LinkedList* pArrayListEmployee, int index)
{

    ePais* auxPais;
    auxPais = (ePais*)ll_get(pArrayListEmployee,index);

    printf("%d   %10s              %5d             %5d             %5d\n",
           auxPais->id,
           auxPais->nombre,
           auxPais->vac1dosis,
           auxPais->vac2dosis,
           auxPais->sinVacunar);

}


int comparaEmployees(void* pEmployeeA,void* pEmployeeB)
{
    if(((ePais*)pEmployeeA)->vac2dosis > ((ePais*)pEmployeeB)->vac2dosis)
    {
        return 1;
    }
    if(((ePais*)pEmployeeA)->vac2dosis <
            ((ePais*)pEmployeeB)->vac2dosis)
    {
        return -1;
    }
    return 0;
}


void* asignarEstadisticas(void* pais){
    ePais* auxPais = NULL;
    if(pais != NULL){
        auxPais = (ePais*) pais;
        auxPais->vac1dosis = rand() % (60 - 1 +1) + 1;
        auxPais->vac2dosis = rand() % (40 - 1 +1) + 1;
        auxPais->sinVacunar = 100 - (auxPais->vac1dosis + auxPais->vac2dosis);
    }
    return auxPais;
}



int sonPaisesExitosos(void* pais){
    int todoOk = 0;
    ePais* Pais1 = NULL;
    if(pais != NULL){
        Pais1 = (ePais*) pais;
        if(Pais1->vac2dosis > 30){
            todoOk = 1;
        }
    }
    return todoOk;
}


int sonPaisesAlHorno(void* pais){
    int todoOk = 0;
    ePais* Pais1 = NULL;
    if(pais != NULL){
        Pais1 = (ePais*) pais;
        if(Pais1->sinVacunar > ( Pais1->vac1dosis + Pais1->vac2dosis ) ){
            todoOk = 1;
        }
    }
    return todoOk;
}


int ordenarPorVacunacion(void* oneCountry,void* twoCountry){
    int todoOk = 0;
    ePais* onePais = NULL;
    ePais* twoPais = NULL;
    if(oneCountry != NULL && twoCountry != NULL){
        onePais = (ePais*) oneCountry;
        twoPais = (ePais*) twoCountry;
        if(onePais->vac1dosis > twoPais->vac1dosis){
            todoOk = 1;
        }else{
            todoOk = -1;
        }
    }

    return todoOk;
}
