---
title: "IMPORTANTE: Instruções extras para 3a Unidade"
output: 
  beamer_presentation:
    theme: "CambridgeUS"
    keep_tex: true
---

## Sobre a questão única
A atividade deve ser respondida de acordo com o que descreve o roteiro, ou seja, a **QUESTÃO ÚNICA** deve ser minimamente respondida!

Para isto, as instruções na sala de aula sobre grafos serão de extrema importância para o desenvolvimento do trabalho. Mas para iluminar o entendimento de como começar a construção do grafo, vou apresentar a construção de um grafo simples.

## Estruturas já criadas:

As estruturas iniciais podem ser as próprias definidas no trabalho de Hash

```cpp
struct cidade {
    unsigned int id;
    char *estado;
    char *cidade;
};
struct gps {
    unsigned int id;
    latitude la;
    longitude lo;
};
struct dataItem {
    int key;
    cidade city;
    gps GPS;
};
```
## Captura de dados
Observe que para a *Hash*, os valores poderiam ser estruturados simplesmente pelos *dataItem's*. O próprio arquivo **lerArquivos.cpp** *ensina* como podemos extrair os valores das cidades presentes nos arquivos <u>coordenacao.csv</u> e <u>cidades.csv</u>, que estão presentes no perfil do github do professor.

Atenção: Verificar se o código está funcionando adequadamente para as necessidades suas, talvez os nomes dos arquivos estejam diferentes nos projetos: [Projeto HashTable](https://github.com/kennedyufersa/hashTable) e [Projeto Grafo](https://github.com/kennedyufersa/scriptLab).

## Captura de dados
Mais precisamente, as funções abaixo conseguem capturar os dados das cidades nestes arquivos. 

```cpp
dataItem *getItens(cidade *, gps *);
cidade *getCidades(char *arquivo);
gps *getGps(char *);
```
Utilizando a função dataItem, por exemplo, vocês tem acesso a todas as cidades que estão no arquivo. Já que dataItem é formado por uma chave, a estrutura da cidade e localização da cidade.


## Captura de dados
Vou aqui agora apresentar como construir um grafo a partir das cidades dos arquivos.

```cpp
//...
    cidade *todasCidades = getCidades((char*)"bancoDeDados/cidades.csv");
    gps *todoLocal = getGps((char*)"bancoDeDados/coordenadas.csv");
    dataItem* d = getItens(todasCidades, todoLocal);

//Selecionando as cidades do RN:
int k=0;
dataItem* cidadesDoRN = (dataItem*)malloc(167*sizeof(dataItem*));
gps * localRN = (gps*)malloc(167*sizeof(gps*));
for(int i = 0; i<5570; i++){
    if( comparar (todasCidades[i].cidade.estado, "RN" ) == 0){
        cidadesDoRN[k] = todasCidades[i];
        localRN[k] = todoLocal[i];
        k++;
    }
}
//...
```
## Captura de dados
Depois desse passo, teremos no vetor *cidadesDoRN* os valores de todas as cidades do estado do RN. Feito isso, podemos calcular a distância entre **cada par de cidades** da seguinte maneira. Um exemplo abaixo, comparo a distância entre a cidade 5 e a cidade 10 com a distância de $0.05$.

```cpp
    //...
    float d = distancia(localRN[5], localRN[10]);
    if(d < 0.05){
        //São vizinhas
        G[5][10] = d;
        G[10][5] = d;
    }
    //...
```

## Construção do Grafo
Veja que o grafo, simplesmente é a matriz G. Que pode ser definida da seguinte maneira:

```cpp
float G[167][167];
```

## Construção do Grafo
A representação do grafo, que considero mais simples, avalia simplesmente os valores de G. Neste caso, estaremos construindo um Grafo com $n=167$ vértices e no máximo $\frac{n(n-1)}{2} = 13.861$ arestas. Este grafo é não orientado, simétrico e ponderado. Os pesos representam simplesmente a distância entre os centros das cidades (informações no arquivo coordenada.csv).

## Entrega dos resultados

Para concluir e facilitar a entrega da atividade, solicito que preencham as tabelas abaixo abaixo e coloquem esses resultados em um arquivo dos seus repositorios com o nome resultados.md.

Tabela 1


| Dist | **Cid. mais viz** | Qnt | **Cid. menos viz** | Qnt |
| ---- | ----------------- | --- | ------------------ | --- |
| 0.05 |                   |     |                    |     |
| 0.10 |                   |     |                    |     |
| 0.20 |                   |     |                    |     |
| 0.25 |                   |     |                    |     |

Ou seja, indiquem qual a cidade com mais e menos vizinhos e a quantidade de vizinhos.

## Entrega dos resultados

Tabela 2

|     | Distancia |
| --- | --------- |
| Máx |           |
| Min |           |

Sendo:

+ Máx: A menor distância possível para que **todas** as cidades do RN seja consideradas vizinhas.
+ Min: A maior distância possível para que **nenhuma** cidade seja considerada vizinha.


## Entrega:

A entrega dos resultados será por grupo na quinta-feira (24/11)! Na oportunidade, **algum integrante** do grupo deverá aparecer para **representar o grupo por completo** e mostrar as execuções dos códigos e as conclusões apresentadas (informações das tabelas preenchidas).
