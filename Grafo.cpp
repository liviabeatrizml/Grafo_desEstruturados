#ifndef GRAFO_CPP
#define GRAFO_CPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lerAquivos.cpp"
#define SIZE 167

// typedef float** Grafo;

float **alocaMatriz(){
    size_t i, j;

    float **matriz = (float**) malloc(SIZE * sizeof(float*));
    for(i = 0; i < SIZE; i++)
        matriz[i] = (float*) malloc(SIZE * sizeof(float));

    return matriz;
}

dataItem* RN(){
    cidade *todasCidades = getCidades((char*)"bancoDeDados/cidades.csv");
    gps *todosLocais = getGps((char*)"bancoDeDados/coordenada.csv");

    dataItem* d = getItens(todasCidades, todosLocais);

    dataItem* cidadesDoRN = (dataItem*) malloc(167 * sizeof(cidade*));

    int i, k = 0;

    for(i = 0; i < 5570; i++){
        if(strcmp(d[i].city.estado, "RN") == 0){
            cidadesDoRN[k] = d[i];
            k++;
        }
    }

    return cidadesDoRN;
}

float **criarGrafo(){
    int i, j;

    float** matriz = alocaMatriz();

    for (i = 0; i < 167; i++) {
        for (j = 0; j < 167; j++) 
            matriz[i][j] = 0;
    }

    return matriz;
}

float** calculaDistancia(float **Grafo, dataItem* informacoesRN, float Distancia){
    int i, j;

    for (i = 0; i < SIZE; i++){
        // int cont = i+1;

        for (j = 0; j < i+1; j++){
            if (i == j) {
                Grafo[i][j] = -1;
            } else {
                float dist = sqrt(pow((informacoesRN[i].GPS.la - informacoesRN[j].GPS.la), 2) + pow((informacoesRN[i].GPS.lo - informacoesRN[j].GPS.lo), 2));

                if(dist < Distancia){
                    Grafo[i][j] = dist;
                    Grafo[j][i] = dist;
                } else {
                    Grafo[i][j] = -1;
                    Grafo[j][i] = -1;
                }
            }
        } 
    }

    return Grafo;
}

void printCidadeComMaisVizinhos(float **Grafo, dataItem* informacoesRN, float Distancia){
    int results[2] = {0, 0};
    size_t cont = 0;

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++){
            cont = (Grafo[i][j] > 0) ? cont + 1 : cont;
        }

        if(cont > results[1]){
            results[0] = i;
            results[1] = cont;
        }

        cont *= 0;
    }

    printf("\n\t\t %s\t tem %d vizinhas!!!\n\n", informacoesRN[results[0]].city.cidade, results[1]);
}

void printCidadeSemVizinhos(float **Grafo, dataItem* informacoesRN, float* Distancias){
    int j = 0, quantVizinha = 0;

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++){
            if (Grafo[i][j] < 0){
                quantVizinha == 0;
            } else {
                quantVizinha == 1;
                break;
            }
        }

        if (quantVizinha == 0){
            printf("\n\t %s e tem 0 vizinhas!!!\n\n", informacoesRN[i].city.cidade);
            break;
        } else {
            printf("\n\t Nao ha cidades sem vizinha!!!\n\n");
            break;
        }
    }
}

void printDistTodasVizinhas(dataItem* informacoesRN){
    float dist, maior = 0;
    
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            if (i != j){
                dist = sqrt(pow(informacoesRN[i].GPS.la - informacoesRN[j].GPS.la, 2) + pow(informacoesRN[i].GPS.lo - informacoesRN[j].GPS.lo, 2));
            
                if (dist > maior){
                    maior = dist;
                }
            }
        }
    }

    printf("\nEh necessario que a distancia seja de %.5f para que todas sejam vizinhas!!!\n", maior);
}

void printDistMinTodasVizinhas(dataItem* informacoesRN){
    float dist, maior = 0;
    
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            if (i != j){
                dist = sqrt(pow(informacoesRN[i].GPS.la - informacoesRN[j].GPS.la, 2) + pow(informacoesRN[i].GPS.lo - informacoesRN[j].GPS.lo, 2));
            
                if (dist > maior){
                    maior = dist;
                }
            }
        }
    }

    printf("\nEh necessario que a distancia seja de %.5f para que nenhuma seja vizinhas!!!\n", maior);
}

void printDistMaxNenhumVizinhas(dataItem* informacoesRN){
    float dist, menor = 100;
    
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            if (i != j){
                dist = sqrt(pow(informacoesRN[i].GPS.la - informacoesRN[j].GPS.la, 2) + pow(informacoesRN[i].GPS.lo - informacoesRN[j].GPS.lo, 2));
            
                if (dist < menor){
                    menor = dist;
                }
            }
        }
    }

    printf("\nEh necessaria que a distancia seja de %.5f para que todas sejam vizinhas!!!\n\n", menor);
}

void printGrafoMatricial(float **matriz){
    for (int i = 0; i < SIZE; i++) {
        printf("\n");
        for (int j = 0; j < SIZE; j++) {
            if(matriz[i][j] == 0){
                printf("%.1f\t", matriz[i][j]);
            } else {
                printf("%.3f\t", matriz[i][j]);
            }
        }

        printf("\n\n");
    }
}

#endif