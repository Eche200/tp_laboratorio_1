#ifndef UTN_ARRAYEMPLOYEES_H_INCLUDED
#define UTN_ARRAYEMPLOYEES_H_INCLUDED

#define CANTIADDECARACTERESMAXIMOSPARANOMBRE 51
#define CANTIADDECARACTERESMAXIMOSPARAAPELLIDO 51
#define CANTIDADDEMPLEADOS 1000
#define CANTIDADPARABUFFER 3000

typedef struct sEmployee
{
    int id;
    char nombre[CANTIADDECARACTERESMAXIMOSPARANOMBRE];
    char apellido[CANTIADDECARACTERESMAXIMOSPARAAPELLIDO];
    float sueldo;
    int sector;
    int isEmpty;


}Employee;


int UTN_obtenerSiguienteId();

int UTN_addEmployee(Employee arrayDeEmployee[],int indice, int limiteDeArrayDeEmployee,int id, char* name,char*

lastName,char* salary,char* sector);

int UTN_initEmployees(Employee arrayDeEmployee[],int indice, int limiteDeArrayDeEmployee);

int UTN_modificarEmployee(Employee arrayDeEmployee[], int indice, int limiteDeArrayDeEmployee, int idDePersonaAModificar);

int UTN_removeEmployee(Employee arrayDeEmployee[],int indice , int limiteDeArrayDeEmployee, int idDePersonaABorrar);

int UTN_imprimirTotalPromedioYEmployeeQueSuperanSalarioPromedio(Employee arrayDeEmployee[], int limiteDeArrayDeEmployee, int indice);

int UTN_sortEmployees(Employee arrayDeEmployee[], int limite , int indice);

int printEmployees(Employee arrayDeEmployee[],int indice, int limite);

int findEmployeeById(Employee arrayDeEmployee[],int indice, int limite,int id);

#endif // UTN_ARRAYEMPLOYEES_H_INCLUDED
