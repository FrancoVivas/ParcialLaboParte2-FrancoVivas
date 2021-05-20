/*
 * biblioteca.h
 *
 *  Created on: 13 may. 2021
 *      Author: Franco Vivas
 */

#ifndef UTN_H_
#define UTN_H_

int SizeString(char string[]);
int isChar(char string[]);
int getString(char string[], int tam);
int utn_getString(char mensaje[], char mensajeError[], int tam, int reintentos,char input[]);
int isInt(char resultado[]);
int getInt(int* input);
int utn_getInt(char mensaje[],char mensajeError[],int min,int max,int reintentos,int* input);
int isFloat(char resultado[]);
int getFloat(float* input);
int utn_getFloat(char mensaje[], char mensajeError[], float min, float max, int reintentos, float* input);




#endif /* UTN_H_ */
