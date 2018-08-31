#include <stdio.h>
#include <stdlib.h>

//menu

void utn_showMenu(){
    //variables
    int numeroDeOpcionIngresado;
    int operadorNumeroUno;
    int operadorNumeroDos;
    int resultadoDeLaSuma;
    int resultadoDeLaResta;
    int resultadoDeLaDivision;
    int resultadoDeLaMultiplicacion;
    int resultadoDelFactorialPrimerOperador;
    int resultadoDelFactorialSegundoOperador;

    //intro del menu
    if(utn_getNumero(&numeroDeOpcionIngresado,
                     "ingrese un numero para elegir una opcion.\n1.Ingrese 1° operador.\n2.Ingrese 2° operador.\n3.calcular todas las funciones.\n4.Informar resultados.\n5.Salir",
                     "Error,ingrese un numero correcto",1,5,3)==0){

                         switch(numeroDeOpcionIngresado){
                            case 1:
                                utn_getNumero(&operadorNumeroUno,"Ingrese el 1° operador","Error,ingrese un numero correcto",0,999,3);
                                break;
                            case 2:
                                utn_getNumero(&operadorNumeroDos,"Ingrese el 2° operador","Error,ingrese un numero correcto",0,999,3);
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            default:
                                printf("Error , su numero no es correcto.");
                                break;
                         }
    }
}



/**
*\brief le paso por parametro un  numero que tome con la funcion getNumero y verifico si es un numero valido.
*\param auxNumero , es el numero a evaluar si es correcto.
*\param min , es el numero minimo que aceptamos como parametro
*\param max , es el numero maximo que  acpetamos como parametro
*\return retorna 0 si esta todo bien , -1 si hubo error
*/
int utn_validarInt(int auxNumero,int min , int max){
    int retorno=0;
    if(auxNumero<=min || auxNumero>=max){
        retorno=-1;
    }
    return retorno;
}
/**
*\brief toma un numero , verifica si es un numero y si es valido , si no es valido  tiene 3 intentos  y sale de la funcion.
*\param pResultado , es un puntero a una variable .
*\param mensaje, mensaje para  indicar que debe ingresar  un numero.
*\param mensajeError , es el mensaje  que aparece i hay un error.
*\param minimo, es el  minimo numero que vamos a permitir que se lo pasaremos a la funcion validarNumero.
*\param max , es el  maximo numero que vamos a permitir que se lo pasaremos a la funcion validarNumero.
*\param reintentos , es  el numero de intentos que va a tener  el usuario para equivocarnos.
*\return retorna 0 si esta todo bien , -1 si hubo error.
*/
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
    int retorno=0;
    int auxNumero;
    do{
        //__fpurge(stdin); CUANDO ESTE EN LINUX BORRAR LO DE ABAJO Y DEJAR ESTO
        fflush( stdin );
        printf("%s \n",mensaje);
        if(scanf("%d",&auxNumero)!=1 || utn_validarInt(auxNumero,minimo,maximo)!=0){
            system("clear");
            printf("%s\n",mensajeError);
            reintentos--;
        }else{
            *pResultado=auxNumero;
            break;
        }
        if(reintentos==0){
            system("clear");
            printf("Pasaste el limite de intentos, ADIOS.");
            retorno=-1;
        }
    }while(reintentos>0);
    return retorno;
}





int calcularSuma(int* pOperadorUno, int* pOperadorDos, int* pResultadoSuma ){
    int retorno=0;
    *pResultadoSuma=pOperadorUno+pOperadorDos;
    return retorno;
}

int calcularResta(int* pOperadorUno, int* pOperadorDos, int* pResultadoResta ){
    int retorno=0;
    *pResultadoResta=pOperadorUno+pOperadorDos;
    return retorno;
}

int calcularDivision(int* pOperadorUno, int* pOperadorDos, int* pResultadoDivision ){
    int retorno=-1;
    if(pOperadorDos>0){
        *pResultadoDivision=pOperadorUno+pOperadorDos;
        retorno=0;
    }
    return retorno;
}

int calcularMultiplicacion(int* pOperadorUno, int* pOperadorDos, int* pResultadoMultiplicacion ){
    int retorno=0;
    *pResultadoMultiplicacion=pOperadorUno+pOperadorDos;
    return retorno;
}

int calcularFactorial(int* pOperadorUno,int* pOperadorDos,int* pResultadoFactorialPrimerOperador, int* pResultadoFactorialPrimerOperador ){
    int retorno=-1;


    return retorno;
}
