/**
 * ATENÇÃO: Este arquivo é apenas um modelo de como pretendo que as respostas finais sejam apresentadas por vocês.
*/
#include <stdio.h>
/**
 * O Arquivo estrutura.cpp inclui todas as funções que definem o Grafo e serão utilizadas neste arquivo main.cpp.
 */
#include "estruturas.cpp"

int main() {
    Grafo G = criarGrafo("cidades.csv", "coordenada.csv");
    float *D = {0.05, 0.1, 0.15, 0.20, 0.25};
    // Questão I
    for (size_t i = 0; i < 5; i++) {
        printTodasDistancias(G, D);
    }

    //Questão II
    for (size_t i = 0; i < 5; i++) {
        printCidadeComMaisVizinhos(G, D);
    }

    //Questão III
    for (size_t i = 0; i < 5; i++) {
        printCidadeSemVizinhos(G, D);
    }

}