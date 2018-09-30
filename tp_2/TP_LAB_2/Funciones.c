#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_empleados.h"
#include "Funciones.h"

/*
necesito un array , luego la variable i es para el iterador que recorre el array
luego pos es para  guardar la posicion actual , y aux para guardar el numero mayor
y hacer el intercambio
*/

int Func_ordenamientoPorInsercionParaInt(Empleado arrayDeEmpleados[], int limite ,int indice)
{
    int retorno = -1;
    int i;
    int posicion;
    int auxDeid;
    for(i = indice ; i < limite ; i++)
    {
        //guardamos la posicion en i la que estamos actualmente
        posicion = i;
        //guardamos el elemento que esta en es posicion. sea int o char o lo que sea
        auxDeid = arrayDeEmpleados[i].id;
        // si el numero (en este caso) actual es menor al de su izquierda , se cambia
        // si la posicion es mayor a 0 tambien , entonces se crea el intercambio.
        while(posicion > 0 && auxDeid < arrayDeEmpleados[posicion - 1].id)
        {
            arrayDeEmpleados[posicion].id = arrayDeEmpleados[posicion - 1].id;
            posicion--;
        }
        arrayDeEmpleados[posicion].id = auxDeid;
    }
    return retorno;
}


int Func_ordenamientoPorInsercionParaChar(Empleado arrayDeEmpleados[], int limite , int indice)
{
    int retorno = 0;
    int i;
    char auxDeNombreDelEmpleado[51];
    int posicion;
    for ( i = indice ; i < limite ; i++)
    {
        posicion = i;
        strncpy(auxDeNombreDelEmpleado , arrayDeEmpleados[i].nombre , CANTIADDECARACTERESMAXIMOSPARANOMBRE);
        while( i > 0 && strcmp(auxDeNombreDelEmpleado , arrayDeEmpleados[posicion - 1].nombre)<0)
        {
            strncpy(arrayDeEmpleados[posicion].nombre , arrayDeEmpleados[posicion - 1].nombre, 51);
            posicion--;
        }
        strncpy(arrayDeEmpleados[posicion].nombre,auxDeNombreDelEmpleado,CANTIADDECARACTERESMAXIMOSPARANOMBRE);
    }
    return retorno;
}
