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
/**
*\brief le paso por parametro dos operadores (previamente evaluados que sean correctos) y hace una suma de ellos.
*\param pOperadorUno, es el primer numero el cual al final se sumara con el otro numero.
*\param pOperadorDos, es el segundo numero el cual al final se sumara con el otro numero.
*\param pResultadoSuma , es la variable donde se guardara el resultado de la suma final.
*\return retorna 0 si esta todo bien.
*/
int utn_calcularSuma(int* pOperadorUno, int* pOperadorDos, int* pResultadoSuma ){
    int retorno=0;
    *pResultadoSuma=(*pOperadorUno)+(*pOperadorDos);
    return retorno;
}
/**
*\brief le paso por parametro dos operadores (previamente evaluados que sean correctos) y hace una resta de ellos.
*\param pOperadorUno, es el primer numero el cual al final se restara con el otro numero.
*\param pOperadorDos, es el segundo numero el cual al final se restara con el otro numero.
*\param pResultadoResta , es la variable donde se guardara el resultado de la resta final.
*\return retorna 0 si esta todo bien.
*/
int utn_calcularResta(int* pOperadorUno, int* pOperadorDos, int* pResultadoResta ){
    int retorno=0;
    *pResultadoResta=(*pOperadorUno)-(*pOperadorDos);
    return retorno;
}
/**
*\brief le paso por parametro dos operadores (previamente evaluados que sean correctos) y hace una division de ellos si es que se puede realizar la division.
*\param pOperadorUno, es el primer numero el cual al final se dividira con el otro numero.
*\param pOperadorDos, es el segundo numero el cual al final se dividira con el otro numero.
*\param pResultadoDivision , es la variable donde se guardara el resultado de la division final.
*\return retorna 0 si esta todo bien , si retorna -1 es porque el segundo operador es 0.
*/
int utn_calcularDivision(int* pOperadorUno, int* pOperadorDos, float* pResultadoDivision ){
    int retorno=-1;
    if(pOperadorDos!=0){
        *pResultadoDivision=(float)(*pOperadorUno) / (*pOperadorDos);
        retorno=0;
    }
    return retorno;
}
/**
*\brief le paso por parametro dos operadores (previamente evaluados que sean correctos) y hace una multiplicacion de ellos.
*\param pOperadorUno, es el primer numero el cual al final se multiplicara con el otro numero.
*\param pOperadorDos, es el segundo numero el cual al final se multiplicara con el otro numero.
*\param pResultadoMultiplicacion , es la variable donde se guardara el resultado de la multiplicacion final.
*\return retorna 0 si esta todo bien.
*/
int utn_calcularMultiplicacion(int* pOperadorUno, int* pOperadorDos, int* pResultadoMultiplicacion ){
    int retorno=0;
    *pResultadoMultiplicacion=(*pOperadorUno) * (*pOperadorDos);
    return retorno;
}
/**
*\brief le paso por parametro dos operadores (previamente evaluados que sean correctos) y hace el factorial de ellos , si es posible.
*\param pOperadorUno, es el primer numero el cual al final se realizara el factorial.
*\param pOperadorDos, es el segundo numero el cual al final se realizara el factorial.
*\param pResultadoFactorialPrimerOperador , es la variable donde se guardara el resultado del factorial del primer numero.
*\param pResultadoFactorialSegundoOperador , es la variable donde se guardara el resultado del factorial del segundo numero.
*\return retorna 0 si esta todo bien, retorna -1 , si el primer numero no se pudo hacer el factorial, retona -2 , si el segundo numero y el primero no se
*pudieron hacer factorial,retorna -3 si el segundo numero no se pudo hacer el factorial.
*/
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
    }else{
        retorno=-1;
    }
    if(auxOperadorDos>0){
        for(int i=auxOperadorDos;i>=1;i--){
            auxParaResultadoFactorial=auxParaResultadoFactorial*i;
            if(i==1){
                *pResultadoFactorialSegundoOperador=auxParaResultadoFactorial;
            }
        }
    }else if(auxOperadorDos<0 && retorno==-1){
        retorno=-2;
    }else{
        retorno=-3;
    }
    return retorno;
}
/**
*\brief le paso por parametro los 2 numeros , le pasamos tambien el resultado de la Suma , Resta , Multiplicacion , Division y los factoriales.
*\param pOperadorUno, es el primer numero.
*\param pOperadorDos, es el segundo numero.
*\param pResultadoDeLaSuma, pasaremos el resultado de la Suma.
*\param pResultadoDeLaResta, pasaremos el resultado de la Resta.
*\param pResultadoDeLaDivision, pasaremos el resultado de la division si es que se realizo.
*\param pResultadoDeLaMultiplicacion, pasaremos el resultado de la multiplicacion.
*\param pResultadoDelFactorialPrimerOperador, pasaremos el resultado del factorial del primer numero.
*\param pResultadoDelFactorialSegundoOperador, pasaremos el resultado del factorial del segundo numero.
*\return retorna 0 si esta todo bien.
*/
int utn_listarResultados(int* pOperadorUno, int* pOperadorDos, int* pResultadoDeLaSuma  , int* pResultadoDeLaResta, float* pResultadoDeLaDivision,int* pResultadoDeLaMultiplicacion,
                     long* pResultadoDelFactorialPrimerOperador ,long* pResultadoDelFactorialSegundoOperador){

    int retorno=0;
    printf("el resultado de la suma entre %d y %d , es igual a %d .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaSuma);
    printf("el resultado de la resta entre %d y %d , es igual a %d .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaResta);
    if(*pOperadorDos!=0){
        printf("el resultado de la division entre %d y %d , es igual a %.2f .\n",*pOperadorUno,*pOperadorDos,*pResultadoDeLaDivision);
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
        printf("el resultado del factorial %d , es igual a %ld .\n\n",*pOperadorDos,*pResultadoDelFactorialSegundoOperador);
    }else{
        printf("no se pudo realizar el factorial de %d .\n \n",*pOperadorDos);
    }
    return retorno;
}
/**
*\brief lo que hace es mostrar  un menu , para las diferentes operaciones que querramos realizar,dentro de ella se encuentra la llamada a todas las demas funciones
*\ luego se la llama al main. en el caso que no pasara ningun operador , los 2 operadores se inicializan en 0 por defecto.
*\return retorna 0 si esta todo bien,
*/
void utn_showMenu(){
    int numeroDeOpcionIngresado;
    int operadorNumeroUno=0;
    int operadorNumeroDos=0;
    int resultadoDeLaSuma;
    int resultadoDeLaResta;
    float resultadoDeLaDivision;
    int resultadoDeLaMultiplicacion;
    long resultadoDelFactorialPrimerOperador;
    long resultadoDelFactorialSegundoOperador;
    int errorAlElegir=0;
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
