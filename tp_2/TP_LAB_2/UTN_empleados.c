#include <stdio_ext.h>
#include <stdlib.h>
#include "UTN_empleados.h"
#include "Funciones.h"
//funcion para señalar indices.
//listar empleados



int UTN_imprimirTotalPromedioYEmpleadosQueSuperanSalarioPromedio(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados, int indice)
{
    int retorno = 0;
    int i;
    float sumaTotalDeSalario = 0;
    float promedioDeSalario ;
    int contadorDeEmpleadosMayorAlSalarioComun = 0 ;
    int contadorDeElementos = 0;
    if(arrayDeEmpleados != NULL && limiteDeArrayDeEmpleados > 0 && limiteDeArrayDeEmpleados > indice && indice >= 0)
    {

        for( i = 0 ; i < limiteDeArrayDeEmpleados ; i++)
        {
            sumaTotalDeSalario = sumaTotalDeSalario + arrayDeEmpleados[i].sueldo;
            contadorDeElementos ++;

        }


        if(contadorDeElementos != 0)
        {
            promedioDeSalario = sumaTotalDeSalario / contadorDeElementos;

        }



        for ( i = 0 ; i < limiteDeArrayDeEmpleados ; i++)
        {
            if( arrayDeEmpleados[i].sueldo > promedioDeSalario)
            {
                contadorDeEmpleadosMayorAlSalarioComun++;
            }
        }
        printf("Suma total sueldo de empleados: %f\n" , sumaTotalDeSalario);
        printf("Promedio de salario total: %f\n" , promedioDeSalario);
        printf("hay %d empleados que tienen el sueldo mayor al promedio." , contadorDeEmpleadosMayorAlSalarioComun);


    }



    return retorno;
}





int UTN_darDeBajaAEmpleado(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados, int idDePersonaABorrar)
{
    int retorno = -1;
    int i;
    if(arrayDeEmpleados != NULL && limiteDeArrayDeEmpleados > 0 && idDePersonaABorrar)
    {
        for( i = 0; i < limiteDeArrayDeEmpleados ; i++)
        {
            if(arrayDeEmpleados[i].id == idDePersonaABorrar && arrayDeEmpleados[i].isEmpty == 0)
            {
                arrayDeEmpleados[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
        if( retorno != 0 )
        {
            printf("el id ingresado no correspondo a un usuario en alta");
        }
    }
    return retorno;
}





int UTN_modificarEmpleado(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados, int idDePersonaAModificar)
{
    int retorno = -1;
    int i;
    int opcionDeModificacion;
    if(arrayDeEmpleados != NULL && limiteDeArrayDeEmpleados > 0 && idDePersonaAModificar > 0)
    {
        for( i = 0; i < limiteDeArrayDeEmpleados ; i++)
        {
            if(arrayDeEmpleados[i].id == idDePersonaAModificar)
            {
                printf("que dato desea modificar?\n1-Nombre.\n2-Apellido.\n3-Sueldo.\n4-Sector.");
                scanf("%d", &opcionDeModificacion);

                switch(opcionDeModificacion)
                {
                case 1:
                    printf("\ningrese el nuevo nombre del empleado");
               //hay que usar fget y usar strncpy
                    scanf("%s" , arrayDeEmpleados[i].nombre);
                    break;
                case 2:
                    printf("\ningrese el nuevo apellido del empleado");
                    //hay que usar fget y usar strncpy
                    scanf("%s" , arrayDeEmpleados[i].apellido);

                    break;
                case 3:
                    printf("\ningrese el nuevo sueldo del empleado");
               //hay que usar fget y usar strncpy
                    scanf("%f" , &arrayDeEmpleados[i].sueldo);
                    break;
                case 4:
                    printf("\ningrese el nuevo sector del empleado");
               //hay que usar fget y usar strncpy
                    scanf("%d" , &arrayDeEmpleados[i].sector);
                    break;
                default:
                    printf("te equivocaste de opcion");
                    break;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int UTN_inicializarArray(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados)
{
    int retorno =-1;
    int i;

    if(arrayDeEmpleados != NULL && limiteDeArrayDeEmpleados > 0)
    {
        for(i = 0; i < limiteDeArrayDeEmpleados ; i++)
        {
            arrayDeEmpleados[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}




int UTN_altaDeEmpleado(Empleado arrayDeEmpleados[], int limiteDeArrayDeEmpleados)
{
    int retorno = -1;
    int i;

    if(arrayDeEmpleados != NULL && limiteDeArrayDeEmpleados > 0)
    {
        for( i = 0; i < limiteDeArrayDeEmpleados ; i++)
        {
            if(arrayDeEmpleados[i].isEmpty == 1)
            {
                printf("\ningrese nombre del empleado");
               //hay que usar fget y usar strncpy
                scanf("%s" , arrayDeEmpleados[i].nombre);
                printf("\ningrese apellido del empleado");
               //hay que usar fget y usar strncpy
                scanf("%s" , arrayDeEmpleados[i].apellido);

                printf("\ningrese el sueldo del empleado");
               //hay que usar fget y usar strncpy
                scanf("%f" , &arrayDeEmpleados[i].sueldo);

                printf("\ningrese sector del empleado");
               //hay que usar fget y usar strncpy
                scanf("%d" , &arrayDeEmpleados[i].sector);

                arrayDeEmpleados[i].id = UTN_obtenerSiguienteId();
                arrayDeEmpleados[i].isEmpty = 0;
                retorno = 0;
                break;

            }
        }
    }



    return retorno;
}





int  UTN_obtenerSiguienteId()
{
    static int idEmpleado=0;
    idEmpleado++;
    return idEmpleado;
}
