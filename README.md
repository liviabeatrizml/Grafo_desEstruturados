## :family_man_woman_girl_boy: Equipe
:man_teacher: Professor: [Kennedy Reurison Lopes](https://github.com/kennedyufersa).<br />
:man_student: Integrante: [Arthur Kellyson Pinheiro de Negreiros](https://github.com/Arthurkellysonp). <br />
:woman_student: Integrante: [Geísa Morais Gabriel](https://github.com/Geisa-mg).<br />
:man_student: Integrante: [Leonardo Inácio Guilherme Dantas](https://github.com/LeonardoIGD).<br />
:woman_student: Integrante: [Lívia Beatriz Maia de Lima](https://github.com/liviabeatrizml).<br />
:man_student: Integrante: [Pedro Makson Fontes da Costa](https://github.com/PedroMakson).


## Grafos
> O conceito de grafos refere-se às relações entre os objetos de um conjunto, isto é, um conjunto de vértices interconectados dois a dois por arestas. Assim sendo, essas estruturas podem ser representadas por G(V, E), em que V são os vértices e E as arestas do grafo. Nesse sentido, podemos exemplificar um grafo qualquer como G(6, 7), onde 6 é o número de vértices e 7 o número de arestas.

![Grafo](components/Grafo.png)


Baseado no estudo dos Grafos, diante das aulas teóricas em sala de aula, foi possível desenvolver o código em questão com a linguagem C++. No conteúdo de Grafos para resolver essa questão iremos utilizar a matriz adjacência, matriz essa que irá dispor das cidades do RN com suas respectivas coordenadas.

 -  Alteração no código pré-determinado pelo professor
	-   Arquivos não alterados
	    -   cidade.cpp - Não alteramos nada nesse arquivo para mantermos a mesma estrutura utilizada no projeto [Hash](https://github.com/liviabeatrizml/hashTable_desEstruturados);
	    - lerArquivos.cpp - Não alteramos nada nesse arquivo para mantermos a mesma estrutura utilizada no projeto [Hash](https://github.com/liviabeatrizml/hashTable_desEstruturados).
	-   Arquivos alterados
		-   bancoDeDados - Organizamos um banco de dados contendo as informações das cidades;
		-   Grafo.cpp - Criamos funções para a aplicação do método de grafo, diante da matriz adjacência;
		-   main.cpp - Modificamos o arquivo para apresentar e organizar corretamente as ideias.


## Grafo.cpp
> No arquivo Grafo.cpp foi desenvolvido as funções desde a alocação na matriz quanto a comparação da distância entre as cidades do RN.

De início foi colocado as bibliotecas que iremos utilizar no decorrer do código, após isso é conectado o arquivo lerArquivos que tem como função as buscas e capturas de dados no banco de dados. Seguindo, temos a definição do tamanho e início do desenvolvimento das funções.

### float  **alocaMatriz()
A função do tipo float alocaMatriz, irá alocar memória dinamicamente na matriz com o "FOR" apresentado no código e por fim irá retornar a matriz por completo.

### dataItem*  RN()
Como o professor pediu para que seja pego as cidades do RN, é nessa estrutura que isso ocorre. Explicando um pouco o código, de início iremos pegar as cidades do RN e suas informações que estão no bancoDeDados.

### float  **criarGrafo()
Na função float criarGrafo, iremos criar o  grafo com a matriz estaticamente, no código é possível notar dois "for" e eles tem função de colocar um zero em toda a matriz.