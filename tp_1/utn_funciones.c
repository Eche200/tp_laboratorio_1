#include <stdio_ext.h>
#include <stdlib.h>
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
        __fpurge(stdin);
        printf("%s \n",mensaje);
        if(scanf("%d",&auxNumero)!=1 || utn_validarInt(auxNumero,minimo,maximo)!=0){
            system("clear");
            printf("%s\n",mensajeError);
            reintentos--;
        }else{
            *pResultado=auxNumero;
            system("clear");
            break;
        }
        if(reintentos==0){
            system("clear");
            printf("Pasaste el limite de intentos.Te devolveremos al menu para que elegir otra operacion.\n\n");
            retorno=-1;
        }
    }while(reintentos>0);
    return retorno;
}






int utn_calcularSuma(int* pOperadorUno, int* pOperadorDos, int* pResultadoSuma ){
    int retorno=0;
    *pResultadoSuma=(*pOperadorUno)+(*pOperadorDos);
    return retorno;
}


int utn_calcularResta(int* pOperadorUno, int* pOperadorDos, int* pResultadoResta ){
    int retorno=0;
    *pResultadoResta=(*pOperadorUno)-(*pOperadorDos);
    return retorno;
}


int utn_calcularDivision(int* pOperadorUno, int* pOperadorDos, int* pResultadoDivision ){
    int retorno=-1;
    if(pOperadorDos!=0){
        *pResultadoDivision=(*pOperadorUno) / (*pOperadorDos);
        retorno=0;
    }
    return retorno;
}


int utn_calcularMultiplicacion(int* pOperadorUno, int* pOperadorDos, int* pResultadoMultiplicacion ){
    int retorno=0;
    *pResultadoMultiplicacion=(*pOperadorUno) * (*pOperadorDos);
    return retorno;
}


int utn_calcularFactorial(int* pOperadorUno,int* pOperadorDos,long* pResultadoFactorialPrimerOperador, long* pResultadoFactorialSegundoOperador ){
    int retorno=0;
    int auxOperadorUno=*pOperadorUno;
    int auxOperadorDos=*pOperadorDos;
    long auxParaResultadoFactorial=1;
    if(auxOperadorUno>0){
        for(int i=auxOperadorUno;i>=1;i--){
            auxParaResultadoFactorial=auxParaResultadoFactorial*i;
            if(i==1){
                *pResultadoFactorialPrimerOperador=auxParaResultadoFactorial;
                auxParaResultadoFactorial=1;
            }
        }
    }
    if(auxOperadorDos>0){
        for(int i=auxOperadorDos;i>=1;i--){
            auxParaResultadoFactorial=auxParaResultadoFactorial*i;
            if(i==1){
                *pResultadoFactorialSegundoOperador=auxParaResultadoFactorial;
            }
        }
    }
    return retorno;
}
int utn_listarResultados(int* pOperadorUno, int* pOperadorDos, int* pResultadoDeLaSuma  , int* pResultadoDeLaResta, int* pResultadoDeLaDivision,int* pResultadoDeLaMultiplicacion,
                     long* pResultadoDelFactorialPrimerOperador ,long* pResultadoDelFactorialSegundoOperador){


    int retorno=0;
    printf("el resultado de la suma entre %d y %d , es igual a %d .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaSuma);
    printf("el resultado de la resta entre %d y %d , es igual a %d .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaResta);
    if(*pOperadorDos!=0){
        printf("el resultado de la division entre %d y %d , es igual a %d .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaDivision);
    }else{
        printf("no se pudo realizar la division. el segundo operador es 0 .\n");
    }
    if((*pOperadorUno==0 && *pOperadorDos==0)||(*pOperadorUno==0 || *pOperadorDos==0)){
        printf("el resultado de la multiplicacion entre %d y %d , es igual a 0 .\n",*pOperadorUno,*pOperadorDos);
    }else{
        printf("el resultado de la multiplicacion entre %d y %d , es igual a %d .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaMultiplicacion);

    }
    if(*pOperadorUno>0){
        printf("el resultado del factorial %d , es igual a %ld .\n",*pOperadorUno,*pResultadoDelFactorialPrimerOperador);
    }else{
        printf("no se pudo realizar el factorial de %d .\n",*pOperadorUno);
    }
    if(*pOperadorDos>0){
        printf("el resultado del factorial %d , es igual a %ld .\n",*pOperadorDos,*pResultadoDelFactorialSegundoOperador);
    }else{
        printf("no se pudo realizar el factorial de %d .\n \n",*pOperadorDos);
    }


    return retorno;
}



void utn_showMenu(){
    //variables
    int numeroDeOpcionIngresado;
    int operadorNumeroUno=0;
    int operadorNumeroDos=0;
    int resultadoDeLaSuma;
    int resultadoDeLaResta;
    int resultadoDeLaDivision;
    int resultadoDeLaMultiplicacion;
    long resultadoDelFactorialPrimerOperador;
    long resultadoDelFactorialSegundoOperador;
    int errorAlElegir=0;
    //intro del menu
    do{
        if(utn_getNumero(&numeroDeOpcionIngresado,
                         "ingrese un numero para elegir una opcion.\n1.Ingrese primer operador.\n2.Ingrese segundo operador.\n3.calcular todas las funciones.\n4.Informar resultados.\n5.Salir",
                         "Error,ingrese un numero correcto",0,6,3)==0){
                             switch(numeroDeOpcionIngresado){
                                case 1:
                                    system("clear");
                                    utn_getNumero(&operadorNumeroUno,"Ingrese el primer operador","Error,ingrese un numero correcto",0,999,3);
                                    break;
                                case 2:
                                    system("clear");
                                    utn_getNumero(&operadorNumeroDos,"Ingrese el segundo operador","Error,ingrese un numero correcto",0,999,3);
                                    break;
                                case 3:
                                    if(operadorNumeroUno==0 && operadorNumeroDos==0 ){
                                        system("clear");
                                        utn_calcularSuma(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaSuma);
                                        utn_calcularResta(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaResta);
                                        utn_calcularMultiplicacion(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaMultiplicacion);
                                        break;
                                    }else if(operadorNumeroUno==0||operadorNumeroDos==0){
                                        system("clear");
                                        utn_calcularSuma(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaSuma);
                                        utn_calcularResta(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaResta);
                                        utn_calcularMultiplicacion(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaMultiplicacion);
                                        utn_calcularFactorial(&operadorNumeroUno,&operadorNumeroDos,&resultadoDelFactorialPrimerOperador,&resultadoDelFactorialSegundoOperador);
                                        break;
                                    }
                                    else{
                                        system("clear");
                                        utn_calcularSuma(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaSuma);
                                        utn_calcularResta(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaResta);
                                        utn_calcularDivision(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaDivision);
                                        utn_calcularMultiplicacion(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaMultiplicacion);
                                        utn_calcularFactorial(&operadorNumeroUno,&operadorNumeroDos,&resultadoDelFactorialPrimerOperador,&resultadoDelFactorialSegundoOperador);
                                        break;
                                    }
                                case 4:
                                    system("clear");
                                    utn_listarResultados(&operadorNumeroUno,&operadorNumeroDos,&resultadoDeLaSuma,&resultadoDeLaResta,
                                                         &resultadoDeLaDivision,&resultadoDeLaMultiplicacion,&resultadoDelFactorialPrimerOperador,&resultadoDelFactorialSegundoOperador);
                                    break;
                                default:
                                    system("clear");
                                    printf("Adios.");
                                    errorAlElegir=1;
                                    break;
                             }
        }else{
            errorAlElegir=1;
        }
    }while(errorAlElegir==0);
}
