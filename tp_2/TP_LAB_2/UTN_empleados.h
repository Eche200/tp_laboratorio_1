#ifndef UTN_EMPLEADOS_H_INCLUDED
#define UTN_EMPLEADOS_H_INCLUDED
#define CANTIADDECARACTERESMAXIMOSPARANOMBRE 51
#define CANTIADDECARACTERESMAXIMOSPARAAPELLIDO 51

typedef struct sEmpleado
{
    int id;
    char nombre[CANTIADDECARACTERESMAXIMOSPARANOMBRE];
    char apellido[CANTIADDECARACTERESMAXIMOSPARAAPELLIDO];
    float sueldo;
    int sector;
    int isEmpty;


}Empleado;


int  UTN_obtenerSiguienteId();
int UTN_altaDeEmpleado(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados);
int UTN_inicializarArray(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados);
int UTN_modificarEmpleado(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados, int idDePersonaAModificar);
int UTN_darDeBajaAEmpleado(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados, int idDePersonaABorrar);
int UTN_imprimirTotalPromedioYEmpleadosQueSuperanSalarioPromedio(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados, int indice);

#endif // UTN_EMPLEADOS_H_INCLUDED
