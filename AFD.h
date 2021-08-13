#ifndef _AFD_
#define _AFD_

#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>



typedef struct AutomatoFinitoDeterministico AFD;
typedef struct Relatorio relatorio;

struct Relatorio{
    int size;
    char *palavra;
    int *sequencia;
};

struct AutomatoFinitoDeterministico{
    int numSimbolos;
    int numEstados;
    int numEstadosFinais;
    int estadoIncial;
    int* estadosFinais;
    char* simbolos;
    int** matriz;
    int estadoAtual;
    relatorio relatorio;
};


void NovoAutomato(AFD *afd);
void Informacoes(AFD *afd);
void SalvaDados(AFD *afd, char *Titulo);
int LeituraDeDados(AFD *afd, char* nomeArq);
int posicao(AFD *afd, char letra);
bool VerificaPalavra(AFD *afd, char*string, int size);
void GeraRelatorio(AFD *afd, char *palavra, int size);
void ImprimeRlatorio(relatorio *r);

void NovoAutomato(AFD *afd){
    int i;
    int aux;
    printf("\n\n\t\tAutomatos Finitos e Deterministicos");
    
    printf("\n\nInforme o numero de simbolos do automato: ");
    scanf("%d", &afd->numSimbolos);
    afd->simbolos = CharArray(afd->numSimbolos);
    for(i = 0; i < afd->numSimbolos; i++){
        printf("\tInforme o simbolo %c: ", i);
        scanf("%d", &aux);
        scanf("%c", &afd->simbolos[i]);
    }

    printf("\n\nInforme o numero de estados do automato: ");
    scanf("%d",&afd->numEstados);
    printf("Informe o estado inicial: ");
    scanf("%d",&afd->estadoIncial);
    afd->estadoAtual = afd->estadoIncial;
    printf("Informe o numero de estados finais: ");
    scanf("%d",&afd->numEstadosFinais);
    afd->estadosFinais = IntArray(afd->numEstadosFinais);
    printf("Informe os estados finais\n");
    for(i = 0; i < afd->numEstadosFinais; i++){
        printf("\tEstado final [%d]: ", i);
        scanf("%d", &afd->estadosFinais[i]);
    }

    afd->matriz = IntMatrix(afd->numEstados, afd->numSimbolos);

    printf("\n\nInforme as trasicoes automato\n");
    for(i = 0; i < afd->numEstados; i++){
        for(int j = 0; j < afd->numSimbolos; j++){
            printf("\tNo estado %d, ao ler o simbolo %c informe o proximo estado: ", i, afd->simbolos[j]);
            scanf("%d", &afd->matriz[j][i]);
        }
    }
    ImprimeIntMatriz(afd->matriz, afd->numEstados, afd->numSimbolos);
    system("clear");

}

void Informacoes(AFD *afd){
    char aux;
    int aux2;
    printf("\n\n\tInfomacoes do automato");
    printf("\n\nAlfabeto: ");
    for(int i = 0; i < afd->numSimbolos; i++) printf("[%c] ", afd->simbolos[i]);
    printf("\nEstados: ");
    for(int i = 0; i < afd->numEstados; i++) printf("[%d] ", i);
    printf("\nEstado inicial: [%d]", afd->estadoIncial);
    printf("\nEstados Finais: ");
    for(int i = 0; i < afd->numEstadosFinais; i++) printf("[%d] ", afd->estadosFinais[i]);

    printf("\n\nDeseja ver a lista de transicoes possiveis: [s/n]\n");
    scanf("%d", &aux2);
    scanf("%c", &aux);
    if(aux == 's' || aux == 'S'){
        for(int i = 0; i < afd->numEstados; i++){
            printf("\n\nEstado [%d]:", i);
            for(int j = 0; j < afd->numSimbolos; j++){
                printf("\n\t[%c] -> [%d]", afd->simbolos[j], afd->matriz[j][i]);
            }
        }
    }
    printf("\n\n");
}

void SalvaDados(AFD *afd, char *Titulo){
    FILE *arq;
    arq = fopen(Titulo, "w");
    if(arq == NULL){
        printf("Erro na abertura do arquivo!");
        return;
    }
    fprintf(arq, "%d\n", afd->numSimbolos);
    fprintf(arq, "%d\n", afd->numEstados);
    fprintf(arq, "%d\n", afd->numEstadosFinais);
    fprintf(arq, "%d\n", afd->estadoIncial);
    for(int i = 0; i < afd->numEstadosFinais; i++)
        fprintf(arq, "%d\n", afd->estadosFinais[i]);
    for(int i = 0; i < afd->numSimbolos; i++)
        fprintf(arq, "%c\n", afd->simbolos[i]);
    for(int i = 0; i < afd->numSimbolos; i++)
        for(int j = 0; j < afd->numEstados; j++)
            fprintf(arq, "%d\n", afd->matriz[i][j]);
    
              
    fclose(arq);
}

int LeituraDeDados(AFD *afd, char* nomeArq){
    FILE *arq;
    int teste;
    arq = fopen(nomeArq, "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo!");
        return -1;
    }
    fscanf(arq, "%d", &afd->numSimbolos);
    fscanf(arq, "%d", &afd->numEstados);
    fscanf(arq, "%d", &afd->numEstadosFinais);
    fscanf(arq, "%d", &afd->estadoIncial);

    afd->simbolos = CharArray(afd->numSimbolos);
    afd->estadosFinais = IntArray(afd->numEstadosFinais);
    afd->matriz = IntMatrix(afd->numEstados, afd->numSimbolos);

    for(int i = 0; i < afd->numEstadosFinais; i++)
        fscanf(arq, "%d", &afd->estadosFinais[i]);
    for(int i = 0; i < afd->numSimbolos; i++){
        fscanf(arq, "%c", &afd->simbolos[i]);
        fscanf(arq, "%c", &afd->simbolos[i]);
    }
    for(int i = 0; i < afd->numSimbolos; i++)
        for(int j = 0; j < afd->numEstados; j++)
            fscanf(arq, "%d", &afd->matriz[i][j]);

    fclose(arq);
    return 0;
}

bool VerificaPalavra(AFD *afd, char*string, int size){
    int cont = 0;
    bool resposta = false;
    afd->estadoAtual = afd->estadoIncial;


    while(string[cont] != '\0' ){
        afd->estadoAtual = afd->matriz[posicao(afd, string[cont])][afd->estadoAtual];
        cont++;
    }

    GeraRelatorio(afd, string, cont);
    
    for(int i = 0; i < afd->numEstadosFinais; i++){
        if(afd->estadoAtual == afd->estadosFinais[i])
            resposta = true;
    }

    return resposta;

}

int posicao(AFD *afd, char letra){
    int resposta = -1;
    for(int i = 0; i < afd->numSimbolos; i++){
        if(afd->simbolos[i] == letra)
            resposta = i;
    }
    return resposta;
}

void GeraRelatorio(AFD *afd, char *palavra, int size){
    afd->relatorio.size = size;
    afd->relatorio.palavra = CharArray(size);
    afd->relatorio.sequencia = IntArray(size + 1);
    afd->relatorio.sequencia[0] = afd->estadoIncial;

    afd->relatorio.palavra = palavra;
    for(int i = 1; i <= size; i++)
        afd->relatorio.sequencia[i] = afd->matriz[posicao(afd, palavra[i-1])][afd->relatorio.sequencia[i-1]];

}

void ImprimeRlatorio(relatorio *r){
    printf("\n\n-----------------------------------------------------------------------");
    printf("\n\n\tRelatorio\n");
    printf("\nPalavra Informada: %s\n\nTrasicoes: \n", r->palavra);
    for(int i = 0; i < r->size; i++)
        printf("[%d]-----'%c'----->",r->sequencia[i], r->palavra[i]);
    printf("[%d]", r->sequencia[r->size]);
    printf("\n\n-----------------------------------------------------------------------\n\n");
}

#endif