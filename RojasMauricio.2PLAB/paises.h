#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED



typedef struct
{
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
} ePais;


ePais* pais_new();
ePais* pais_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo, int otro);
int employee_delete(ePais* pais);

int pais_setId(ePais* pais,int id);
int pais_getId(ePais* pais,int* pId);

int pais_setNombre(ePais* pais, char* nombre);
int pais_getNombre(ePais* pais, char* pNombre);

int pais_setVacuna1(ePais* pais,int vac1dosis);
int pais_getVacuna1(ePais* pais,int* vac1dosis);

int pais_setVacuna2(ePais* pais,int vac2dosis);
int pais_getVacuna2(ePais* pais,int* vac2dosis);

int pais_setSinVacunar(ePais* pais,int sinVacunar);
int pais_getSinVacunar(ePais* pais,int* sinVacunar);


#endif // employee_H_INCLUDED

//Menu ABM
int menu ();

int menuModificaciones ();


int buscarLibreEmpleado(ePais** eEmployee, int sizeEmp, int* pIndice);


void mostrarPais(LinkedList* pArrayListEmployee, int index);

int comparaEmployees(void* pEmployeeA,void* pEmployeeB);

void* asignarEstadisticas(void* pais);

int sonPaisesExitosos(void* pais);

int sonPaisesAlHorno(void* pais);

int ordenarPorVacunacion(void* oneCountry,void* twoCountry);



