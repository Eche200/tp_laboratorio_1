#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN_ArrayEmployees.h"
#include "Funciones.h"

/** \brief esta funcion recibe por parametro un array , un limiteDeArrayDeEmployee y un indice
 *el array es donde se  haran las operaciones , y la cantidad maxima de  empleados que puedo almacenar
 *con esos datos  mas el indice que nos pase , podemos  imprimir los datos que nos pide , promedio total,   suma total de sueldos y empleados con mas del sueño basico
 * \param Empleado arrayDeEmployee[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmployee cantidad maxima del array
 *\param limiteDeArrayDeEmployee obtiene un  id y buscamos en el array
 *\param indice de donde va a empezar a  buscar
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */


int UTN_imprimirTotalPromedioYEmployeeQueSuperanSalarioPromedio(Employee arrayDeEmployee[],  int limiteDeArrayDeEmployee, int indice)
{
    int retorno = -1;
    int i;
    float sumaTotalDeSalario = 0;
    float promedioDeSalario ;
    int contadorDeEmployeeMayorAlSalarioComun = 0 ;
    int contadorDeElementos = 0;
    if(arrayDeEmployee != NULL && limiteDeArrayDeEmployee > 0 && limiteDeArrayDeEmployee > indice && indice >= 0)
    {
        for( i = indice ; i < limiteDeArrayDeEmployee ; i++)
        {
            sumaTotalDeSalario = sumaTotalDeSalario + arrayDeEmployee[i].sueldo;
            contadorDeElementos ++;

        }
        if(contadorDeElementos != 0)
        {
            promedioDeSalario = sumaTotalDeSalario / contadorDeElementos;

        }
        for ( i = 0 ; i < limiteDeArrayDeEmployee ; i++)
        {
            if( arrayDeEmployee[i].sueldo > promedioDeSalario)
            {
                contadorDeEmployeeMayorAlSalarioComun++;
            }
        }
        printf("Suma total sueldo de empleados: %f\n" , sumaTotalDeSalario);
        printf("Promedio de salario total: %f\n" , promedioDeSalario);
        printf("hay %d empleados que tienen el sueldo mayor al promedio." , contadorDeEmployeeMayorAlSalarioComun);
        retorno=0;
    }
    return retorno;
}



/** \brief esta funcion recibe por parametro un array , un limiteDeArrayDeEmployee y un identificador unico
 *el array es donde se  haran las operaciones , y la cantidad maxima de  empleados que puedo almacenar
 *con esos datos  mas el ID que nos pase , podemos  saber si existe en el array y si existe lo podremos dar de baja.
 * \param Empleado arrayDeEmployee[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmployee cantidad maxima del array
 *\param idDePersonaABorrar obtiene un  id y buscamos en el array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */

int UTN_removeEmployee(Employee arrayDeEmployee[], int indice , int limiteDeArrayDeEmployee, int idDePersonaABorrar)
{
    int retorno = -1;
    int i;
    if(arrayDeEmployee != NULL && limiteDeArrayDeEmployee > 0 && indice < limiteDeArrayDeEmployee  && idDePersonaABorrar > 0)
    {

        for( i = indice; i < limiteDeArrayDeEmployee ; i++)
        {
            if(arrayDeEmployee[i].id == idDePersonaABorrar && arrayDeEmployee[i].isEmpty == 0)
            {
                arrayDeEmployee[i].isEmpty = 1;
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

/** \brief esta funcion recibe por parametro un array , un limiteDeArrayDeEmployee y un identificador unico
 *el array es donde se  haran las operaciones , y la cantidad maxima de  empleados que puedo almacenar
 *con esos datos  mas el ID que nos pase , podemos  saber si existe en el array y si existe lo podremos modificar.
 * \param Empleado arrayDeEmployee[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmployee cantidad maxima del array
 *\param idDePersonaAModificar obtiene un  id y buscamos en el array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */



int UTN_modificarEmployee(Employee arrayDeEmployee[],int indice , int limiteDeArrayDeEmployee, int idDePersonaAModificar)
{
    int retorno = -1;
    int i;
    char opcion[2];
    int opcionDeModificacion;
    char bufferParaNombre[CANTIDADPARABUFFER];
    char bufferParaApellido[CANTIDADPARABUFFER];
    char bufferParaSueldo[CANTIDADPARABUFFER];
    char bufferParaSector[CANTIDADPARABUFFER];
    if(arrayDeEmployee != NULL && limiteDeArrayDeEmployee > 0 && indice < limiteDeArrayDeEmployee && idDePersonaAModificar > 0)
    {
        for( i = indice; i < limiteDeArrayDeEmployee ; i++)
        {
            if(arrayDeEmployee[i].id == idDePersonaAModificar && arrayDeEmployee[i].isEmpty == 0)
            {
                printf("que dato desea modificar?\n1-Nombre.\n2-Apellido.\n3-Sueldo.\n4-Sector.\n");
                if(utn_getString(opcion,2) == 0 && utn_isValidInt(opcion ,2 ) == 1)
                {
                    opcionDeModificacion = atoi(opcion);
                }
                switch(opcionDeModificacion)
                {
                case 1:
                    printf("\ningrese el nuevo nombre del empleado\n");
                    if(utn_getString(bufferParaNombre , CANTIDADPARABUFFER) == 0 && utn_isValidNombre(bufferParaNombre , CANTIDADPARABUFFER) == 1 )
                    {
                        strncpy(arrayDeEmployee[i].nombre , bufferParaNombre , 51);
                        retorno = 0;
                        break;
                    }else
                    {
                        printf("ERROR , NO ES UN NOMBRE VALIDO.\n\n\n");
                        break;
                    }
                case 2:
                    printf("\ningrese el nuevo apellido del empleado\n");
                    if(utn_getString(bufferParaApellido , CANTIDADPARABUFFER) == 0 && utn_isValidNombre(bufferParaApellido , CANTIDADPARABUFFER) == 1 )
                    {
                        strncpy(arrayDeEmployee[i].apellido , bufferParaApellido , 51);
                        retorno = 0;
                        break;
                    }else
                    {
                        printf("ERROR , NO ES UN APELLIDO VALIDO.\n\n\n");
                        break;
                    }
                case 3:
                    printf("\ningrese el nuevo sueldo del empleado\n");
                    if(utn_getString(bufferParaSueldo , CANTIDADPARABUFFER) == 0 && utn_isValidFloat(bufferParaSueldo , CANTIDADPARABUFFER) == 1 )
                    {
                        arrayDeEmployee[i].sueldo = atof(bufferParaSueldo);
                        retorno = 0;
                        break;
                    }else
                    {
                        printf("ERROR , NO ES UN NUMERO DE SALARIO VALIDO.\n\n\n");
                        break;
                    }
                case 4:
                    printf("\ningrese el nuevo sector del empleado\n");
                    if(utn_getString(bufferParaSector,CANTIDADPARABUFFER) == 0 && utn_isValidInt(bufferParaSector ,CANTIDADPARABUFFER ) == 1)
                    {
                        arrayDeEmployee[i].sector = atoi(bufferParaSector);
                        retorno = 0;
                        break;
                    }else
                    {
                        printf("ERROR , NO ES UN NUMERO DE SALARIO VALIDO.\n\n\n");
                        break;
                    }
                default:
                    printf("te equivocaste de opcion\n");
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief esta funcion recibe por parametro un array y un limite
 *el array es donde se  haran las operaciones , y la cantidad maxima de  empleados que puedo almacenar
 *inicializo todos  empleados del array poniendo el atributo .isEmpty en 1 para indicar  que esta vacio tambien ponemos el ID en -1 , para que luego al dar de alta a un empleado
 * podamos evaluar , no solo  si esta de baja sino que  jamas se cargara un dato en el , ya que no debemos borrar nunca a nadie , solo dar de baja.
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int UTN_initEmployees(Employee arrayDeEmployee[],int indice, int limiteDeArrayDeEmployee)
{
    int retorno =-1;
    int i;

    if(arrayDeEmployee != NULL && limiteDeArrayDeEmployee > 0)
    {
        for(i = indice; i < limiteDeArrayDeEmployee ; i++)
        {
            arrayDeEmployee[i].isEmpty = 1;
            arrayDeEmployee[i].id = -1;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief esta funcion recibe por parametro un array y un limite
 *el array es donde se  haran las operaciones , y el limite la cantidad maxima de  empleados que puedo almacenar
 *le pasaremos un nombre, apellido , saldo , sector ,  y daremos de alta un empleado y le pondremos un ID UNICO y pondremos que isEmpty es 0 porque esta lleno
 *buscaremos que en el array haya un lugar donde el isEmpty este en 1 (osea vacio) pero tambien el ide sea -1 , ya que puede estar dado de baja , pero no hay que borrarlo
 * sino que solo darlo de baja , por eso buscamos tambien el ID -1
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int UTN_addEmployee(Employee arrayDeEmployee[],int indice ,int limiteDeArrayDeEmployee,int id, char* name,char*
lastName,char* salary,char* sector)
{
    int retorno = -1;
    int i;
    __fpurge(stdin);

    if(arrayDeEmployee != NULL && limiteDeArrayDeEmployee > 0)
    {
        for( i = indice; i < limiteDeArrayDeEmployee ; i++)
        {
            if(arrayDeEmployee[i].isEmpty == 1 && arrayDeEmployee[i].id == -1)
            {
                __fpurge(stdin);
                printf("\ningrese nombre del empleado\n");
                if(utn_getString(name , CANTIDADPARABUFFER) == 0 && utn_isValidNombre(name , CANTIDADPARABUFFER) == 1 )
                {
                    __fpurge(stdin);
                    printf("\ningrese apellido del empleado\n");
                    if(utn_getString(lastName , 51) == 0 && utn_isValidNombre(lastName , CANTIDADPARABUFFER) == 1)
                    {
                        __fpurge(stdin);
                        printf("\ningrese el sueldo del empleado\n");
                        if(utn_getString(salary,CANTIDADPARABUFFER) == 0 && utn_isValidFloat(salary , CANTIDADPARABUFFER) == 1)
                        {
                            __fpurge(stdin);
                            printf("\ningrese sector del empleado\n");
                            if(utn_getString(sector,CANTIDADPARABUFFER) == 0 && utn_isValidInt(sector ,CANTIDADPARABUFFER ) == 1)
                            {
                                __fpurge(stdin);
                                arrayDeEmployee[i].id = id;
                                arrayDeEmployee[i].isEmpty = 0;
                                strncpy(arrayDeEmployee[i].nombre , name ,CANTIDADPARABUFFER);
                                strncpy(arrayDeEmployee[i].apellido , lastName,CANTIDADPARABUFFER );
                                arrayDeEmployee[i].sueldo = atof(salary);
                                arrayDeEmployee[i].sector = atoi(sector);
                                retorno = 0;
                                break;
                            }
                        }
                    }
                }
            }

        }
    }
    return retorno;
}


/** \brief no recibe parametros , lo que haces es crear  una variable permanente que se autoincrementa cada vez que la llamamos y nos devuelve el proximo ID
 * \return devuelve el siguiente ID
 *
 */


int  UTN_obtenerSiguienteId()
{
    static int idEmpleado=0;
    idEmpleado++;
    return idEmpleado;
}



/** \brief esta funcion recibe por parametro un array , un limite y un indice
 *el array es donde se  haran las operaciones , y el limite la cantidad maxima de  empleados que puedo almacenar
 *pasaremos el array  y con ello le diremos donde empezar a ORDENAR hasta que punto , y  los ordenara de menor a mayor por nombre y si son iguales de nombres, entrara el
 *segundo criterio que es el sector
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 *\param indice , de donde empezar a ordenar
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */



int UTN_sortEmployees(Employee arrayDeEmployee[], int limite , int indice)
{
    int retorno = 0;
    int i;
    char auxDeNombreDelEmployee[51];
    int posicion;
    for ( i = indice ; i < limite ; i++)
    {
        posicion = i;
        strncpy(auxDeNombreDelEmployee, arrayDeEmployee[i].nombre , 51);
        while( i > 0 && strcmp(auxDeNombreDelEmployee, arrayDeEmployee[posicion - 1].nombre)<0)
        {
            strncpy(arrayDeEmployee[posicion].nombre , arrayDeEmployee[posicion - 1].nombre, 51);

            if(strcmp(auxDeNombreDelEmployee, arrayDeEmployee[posicion - 1].nombre) == 0)
            {
                while(arrayDeEmployee[posicion].sector < arrayDeEmployee[posicion - 1].sector && strcmp(auxDeNombreDelEmployee , arrayDeEmployee[posicion - 1].nombre) == 0 )
                {
                    strncpy(arrayDeEmployee[posicion].nombre , arrayDeEmployee[posicion - 1].nombre, 51);
                    posicion--;
                }
            }

        }
        strncpy(arrayDeEmployee[posicion].nombre,auxDeNombreDelEmployee,CANTIADDECARACTERESMAXIMOSPARANOMBRE);
    }
    return retorno;
}



/** \brief esta funcion recibe por parametro un array , indice y un limite
 *el array es donde se  haran las operaciones , y el indice y el limite para saber de donde hasta donde recorrer
 *pasaremos el array  y lo que haremos sera  imprimir desde el principio al limite para que  nos imprima  en forma de tabla todos los  contactos de un  array
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 *\param indice , de donde empezar a ordenar
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */



int printEmployees(Employee arrayDeEmployee[], int indice ,  int limite )
{
    int retorno = -1;
    int i;

    if(arrayDeEmployee != NULL && limite > 0 )
    {
        for( i = indice ; i < limite ; i++)
        {
            if( arrayDeEmployee[i].isEmpty == 0)
            {
                printf("%d\t%s\t%s\t%.2f\t%d", arrayDeEmployee[i].id ,arrayDeEmployee[i].nombre, arrayDeEmployee[i].apellido, arrayDeEmployee[i].sueldo, arrayDeEmployee[i].sector);
                printf("\n");
            }

        }
        retorno = 0;
    }



    return retorno;
}


/** \brief esta funcion recibe por parametro un array , indice , un limite y id
 *el array es donde se  haran las operaciones ,  el indice y el limite para saber de donde hasta donde recorrer y el ID es para saber a quien estabamos buscando
 *pasaremos el array  y lo que haremos sera buscar desde el principio al limite el indice que le pasamos y nos devolvera la posicion del array donde esta
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 *\param indice , de donde empezar a ordenar
 *\param id , es el id que pasaremos para saber en que posicion esta
 * \return retornaremos el numero de la posicion donde esta la persona con ese ID dentro del array
 *
 */

int findEmployeeById(Employee arrayDeEmployee[],int indice , int limite,int id)
{
    int retorno = -1;
    int i;

    if( arrayDeEmployee !=NULL && limite > 0 && id > -1)
    {
        for( i = 0 ; i < limite ; i++ )
        {
            if(arrayDeEmployee[i].id == id)
            {
                retorno = i;
                break;
            }

        }

    }

    return retorno;


}
