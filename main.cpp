#include <stdio.h>
#include <stdlib.h>

// #include "Estrutura.cpp"
#include "Grafo.cpp"

int main() {
    dataItem* InfosRN = RN();

    float **G = criarGrafo(InfosRN);
    
    float D[] = {0.05, 0.1, 0.15, 0.20, 0.25};

    // Questão I
    for (size_t i = 0; i < 5; i++) {
        printf("--- GRAFO MATRICIAL das cidades vizinhas do RN com base na distancia de %f. ---\n", D[i]);
        printGrafoMatricial(calculaDistancia(G, InfosRN, D[i]));
    }

    //Questão II
    for (size_t i = 0; i < 5; i++) {
        printf("\n--- A cidade do RN com mais vizinhas com base na distancia de %f é a seguinte. ---\n", D[i]);
        printCidadeComMaisVizinhos(calculaDistancia(G, InfosRN, D[i]), InfosRN, D[i]);
    }

    //Questão III
    for (size_t i = 0; i < 5; i++) {
        printf("\n--- A cidade do RN que não tem nenhuma vizinha com base na distancia de %f é a seguinte. ---\n", D[i]);
        printCidadeSemVizinhos(calculaDistancia(G, InfosRN, D[i]), InfosRN, D);
    }

    //Questão IV
    printDistTodasVizinhas(InfosRN);

}