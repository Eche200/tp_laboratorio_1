void utn_showMenu();
int utn_validarInt(int auxNumero,int min , int max);
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_calcularSuma(int* pOperadorUno, int* pOperadorDos, int* pResultadoSuma );
int utn_calcularResta(int* pOperadorUno, int* pOperadorDos, int* pResultadoResta );
int utn_calcularDivision(int* pOperadorUno, int* pOperadorDos, float* pResultadoDivision );
int utn_calcularMultiplicacion(int* pOperadorUno, int* pOperadorDos, int* pResultadoMultiplicacion );
int utn_calcularFactorial(int* pOperadorUno,int* pOperadorDos,long* pResultadoFactorialPrimerOperador, long* pResultadoFactorialSegundoOperador );
int listarResultados(int* pOperadorUno, int* pOperadorDos, int* pResultadoDeLaSuma  , int* pResultadoDeLaResta, float* pResultadoDeLaDivision,int* pResultadoDeLaMultiplicacion,
                     long* pResultadoDelFactorialPrimerOperador ,long* pResultadoDelFactorialSegundoOperador);

