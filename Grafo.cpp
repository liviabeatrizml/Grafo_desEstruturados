#ifndef GRAFO_CPP
#define GRAFO_CPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lerAquivos.cpp"
#define SIZE 167

typedef float** Grafo;

float **alocaMatriz(){
    size_t i, j;

    float **matriz = (float** ) malloc(16 * sizeof(float*));

    for(i = 0; i < 16; i++)
        matriz[i] = (float* ) malloc(16 * sizeof(float));



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

Grafo criarGrafo(){
    int i, j;
    
    float **matriz = (float **) malloc(SIZE * sizeof(float*));

    for (size_t i = 0; i < SIZE; i++){
        matriz[i] = (float *) malloc(SIZE * sizeof(float));
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) 
            matriz[i][j] = 0;
    }

    return matriz;
}

Grafo calculaDistancia(float **Grafo, dataItem* informacoesRN, float Distancia){
    int i, j;

    for (i = 0; i < SIZE; i++){
        int cont = i+1;

        for (j = 0; i < cont; i++){
            if (i == j) {
                Grafo[i][j] = 0;
            } else {
                float dist = sqrt(pow(informacoesRN[i].GPS.la - informacoesRN[j].GPS.la, 2) + pow(informacoesRN[i].GPS.lo - informacoesRN[j].GPS.lo, 2));

                if(dist <= Distancia){
                    Grafo[i][j] = dist;
                    Grafo[j][i] = dist;
                } else {
                    Grafo[i][j] = 0;
                    Grafo[j][i] = 0;
                }
            }
        } 
    }

    return Grafo;
}

void printCidadeComMaisVizinhos(float **Grafo, dataItem* informacoesRN, float Distancia){
    int j = 0, cont = 0, quantVizinha = 0, idCidade;

    for (size_t i = 0; i < SIZE; i++) {
        cont = (Grafo[i][j] > 0) ? cont++ : cont;  

        if(cont > quantVizinha){
            idCidade = i;
            quantVizinha = cont;
        }

        cont = 0;
        j++;
    }

    printf("\n\t %s e tem %d vizinhas!!!\n\n", informacoesRN[idCidade].city.cidade, quantVizinha);
}

void printCidadeSemVizinhos(float **Grafo, dataItem* informacoesRN, float* Distancias){
    int j = 0, quantVizinha = 0;

    for (size_t i = 0; i < SIZE; i++) {
        if (Grafo[i][j] == 0){
            quantVizinha == 0;
            j++;
        } else {
            quantVizinha == 1;
            i++;
            j = 0; 
        }

        if (quantVizinha == 0 && j == SIZE - 1){
            printf("\n\t %s e tem 0 vizinhas!!!\n\n", informacoesRN[i].city.cidade);
            break;
        } else {
            printf("\n\t Não há cidades sem vizinha!!!\n\n");
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
            }

            if (dist > maior){
                maior = dist;
            }
        }
    }

    printf("\nÉ necessario que a distancia seja de %.2f para que todas sejam vizinhas!!!\n", maior);
}

void printGrafoMatricial(float **matriz){
    for (int i = 0; i < SIZE; i++) {
        printf("\n");
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] == 0 ? printf("%.1f\t", matriz[i][j]): printf("%.3f\t", matriz[i][j]);
        }
    }

    printf("\n\n");
}

#endif