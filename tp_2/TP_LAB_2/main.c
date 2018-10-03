#include <stdio_ext.h>
#include <stdlib.h>
#include "UTN_ArrayEmployees.h"
#include "Funciones.h"

int main()
{

    Employee arrayDeEmployee[CANTIDADDEMPLEADOS];

    char bufferParaNombre[CANTIDADPARABUFFER];
    char bufferParaApellido[CANTIDADPARABUFFER];
    char bufferParaSueldo[CANTIDADPARABUFFER];
    char bufferParaSector[CANTIDADPARABUFFER];
    int id = UTN_obtenerSiguienteId();

    char opcionDelUsuario[2];
    int  opcion;
    char continuarDelUsuario[2];
    int continuar = 1;

    int devolucion ;

    printf("Bienvenido al programada , siga las instrucciones para realizar operaciones.\n");
    UTN_initEmployees(arrayDeEmployee,0,CANTIDADDEMPLEADOS);
    do
    {
        printf("Ingrese una opcion para operar.\n1-Agregar un Empleado.\n2-Modificar un empleado.\n3-Borrar un empleado.\n4-Listar empleados.\n");
        if(utn_getString(opcionDelUsuario,2) == 0 && utn_isValidInt(opcionDelUsuario,2) == 1 )
        {
            opcion = atoi(opcionDelUsuario);
            switch(opcion)
            {
            case 1:
                system("clear");
                devolucion = UTN_addEmployee(arrayDeEmployee,0,CANTIDADDEMPLEADOS,id,bufferParaNombre,bufferParaApellido,bufferParaSueldo,bufferParaSector);
                if(devolucion == 0)
                {
                    printf("SE AGREGO CORRECTAMENTE  al empleado.\n\n");
                }else
                {
                    system("clear");
                    printf("ERROR !,no se pudo agregar correctamente al empleado.\n\n");
                }
                break;
            case 2:
                if(arrayDeEmployee[0].id == 1)
                {
                    system("clear");
                    devolucion = UTN_modificarEmployee(arrayDeEmployee,0,CANTIDADDEMPLEADOS,1);//se me desconfiguro el coeblock , no reconoce el valor de retornod e fgets ni de system , no puedo probar cosas, asi que no puedo arreglar el tema de tomar por teclado... el ultimo parametro es el que cambia que son los ID
                    if(devolucion == 0)
                    {
                        printf("los datos se modificaron correctamente \n\n");
                    }else
                    {
                        system("clear");
                        printf("ERROR! , no se pudo modificar la usuario\n\n");
                    }

                }
                break;
            case 3:
                if(arrayDeEmployee[0].id == 1)
                {
                    system("clear");
                    devolucion = UTN_removeEmployee(arrayDeEmployee,0,CANTIDADDEMPLEADOS,1);//se me desconfiguro el coeblock , no reconoce el valor de retornod e fgets ni de system , no puedo probar cosas, asi que no puedo arreglar el tema de tomar por teclado... el ultimo parametro es el que cambia que son los ID
                    if(devolucion == 0)
                    {
                        printf("el usuario fue dado de baja.\n\n");

                    }else
                    {
                        system("clear");
                        printf("ERROR al dar de baja al usuario.\n\n");
                    }
                }
                break;

            case 4:
                if(arrayDeEmployee[0].id == 1)
                {
                    system("clear");
                    devolucion = UTN_sortEmployees(arrayDeEmployee,CANTIDADDEMPLEADOS,0);
                    if(devolucion == 0)
                    {
                        printf("\n\n\n\n\n\n");
                        devolucion = UTN_imprimirTotalPromedioYEmployeeQueSuperanSalarioPromedio(arrayDeEmployee,CANTIDADDEMPLEADOS,0);
                        printf("\n\n\n\n\n\n");

                    }
                }
                break;
            default:
                printf( "opcion incorrecta");
                break;

            }


        }




        printf("Desea Continuar haciendo operaciones? <1 para si / cualquier numero para no>.\n");

        if(utn_getString(continuarDelUsuario,2) == 0 && utn_isValidInt(continuarDelUsuario,2) == 1 )
        {
            continuar = atoi(continuarDelUsuario);

        }else
        {
            continuar = 3;

        }
        system("clear");
    }while(continuar == 1);
    if(arrayDeEmployee[0].isEmpty == 0){

    printf("%s\n\n",arrayDeEmployee[0].nombre);
    printf("\n%d\n", arrayDeEmployee[0].isEmpty);
    printf("\n%d\n", arrayDeEmployee[0].id);
    }

    printf("ADIOS , BUEN DIA\n\n\n");


    return 0;
}
