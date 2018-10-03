#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "UTN_ArrayEmployees.h"



int Func_ordenamientoPorInsercionParaInt(Employee arrayDeEmployee[], int limite ,int indice);
int Func_ordenamientoPorInsercionParaChar(Employee employee[], int limite , int indice);
int Func_ordenamientoPorInsercionPorDosCriterios(Employee arrayDeEmployee[], int limite , int indice);
int utn_getString(char* pBuffer, int limite);
int utn_getFloat(  float* pFloat,int tamano, char* msg,
                    char* msgErr, int reintentos);
int utn_getInt(  int* pEntero,int tamano, char* msg,
                    char* msgErr, int reintentos);
int utn_getNombre(  char* pNombre,int tamano, char* msg,
                    char* msgErr, int reintentos);


int utn_isValidFloat(char* pBuffer , int limite);
int utn_isValidInt(char* pBuffer , int limite);
int utn_isValidNombre(char* pBuffer , int limite);


#endif // FUNCIONES_H_INCLUDED
