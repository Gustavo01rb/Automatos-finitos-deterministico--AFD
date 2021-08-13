#ifndef _MATRIZ_
#define _MATRIZ_

#include <stdio.h>
#include <stdlib.h>

/*Matrizes*/

int** IntMatrix(int colunas, int linhas){
	int **matriz = (int **)calloc(linhas , sizeof(int*));
	for(int i = 0; i < colunas; i++){
		matriz[i] = (int*)calloc(colunas , sizeof(int));
		for(int j = 0; j < colunas; j++)
			matriz[i][j] = 0;
	}
	
	return matriz;
}

char** CharMatrix(int colunas, int linhas){
	char **matriz = (char **)calloc(linhas , sizeof(char*));
	for(int i = 0; i < colunas; i++){
		matriz[i] = (char*)calloc(colunas , sizeof(char));
		for(int j = 0; j < colunas; j++)
			matriz[i][j] = '0';
	}
	
	return matriz;
}


void  ImprimeIntMatriz(int **matriz, int colunas, int linhas){
	for(int i = 0;  i < linhas; i++){
		for(int j = 0; j < colunas; j++)
			    printf("%d\t", matriz[i][j]);
		printf("\n");
	}
}

void  ImprimeCharMatriz(char **matriz, int colunas, int linhas){
	for(int i = 0;  i < linhas; i++){
		for(int j = 0; j < colunas; j++)
			    printf("%c\t", matriz[i][j]);
		printf("\n");
	}
}


/*Vetores*/

int* IntArray(int size){
    int* array = (int*)calloc(size, sizeof(int));
    for(int i = 0; i < size; i++)
        array[i] = 0;
    return array;
}

void PrintIntArray(int*array, int size){
    for(int i = 0; i < size; i++)
        printf("[%d]  ", array[i]);
}

char* CharArray(int size){
    char* array = (char*)calloc(size, sizeof(char));
    for(int i = 0; i < size; i++)
        array[i] = '0';
    return array;
}
void PrintCharArray(char*array, int size){
    for(int i = 0; i < size; i++)
        printf("[%c]  ", array[i]);
}


double* DoubleArray(int size){
    double* array = (double*)calloc(size, sizeof(double));
    for(int i = 0; i < size; i++)
        array[i] = 0;
    return array;
}
void PrintDoubleArray(double*array, int size){
    for(int i = 0; i < size; i++)
        printf("[%lf]  ", array[i]);
}


#endif