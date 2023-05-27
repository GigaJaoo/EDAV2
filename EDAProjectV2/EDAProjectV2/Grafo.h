/*****************************************************************//**
 * \file   Grafo.h
 * \brief  Assinaturas das Fun��es e Structs para os Grafos
 * 
 * \author Jo�o Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#define N 50

#include <string.h>    // strings
#include <stdlib.h>    // malloc
#include <stdio.h>     // NULL
#include <stdbool.h>   // bools

/**
 * Estrutura de uma Adjacencia.
 */
typedef struct adjacente {
	int codigoVertice;
	int codigoAdj;
	int distancia;
	struct adjacente* nextAdj;
} Adjacente;

/**
 * Estrutura de uma Adjacencia para ser guardada em ficheiro.
 */
typedef struct adjFile {
	int codigoVertice;
	int codigoAdj;
	int distancia;
} AdjFile;

/**
 * Estrutura de um Vertice.
 */
typedef struct vertice {
	int codigo;
	char cidade[N];
	struct vertice* nextVertice;
	Adjacente* adjs;         //Lista das adjacencias
} Vertice;

/**
 * Estrutura de um Vertice para ser guardado em ficheiro.
 */
typedef struct verticeFile {
	int codigo;
	char cidade[N];
} VerticeFile;

/**
 * Fun��o que cria o Grafo.
 */
Vertice* CriaGrafo();

/**
 * Fun��o que cria um Vertice.
 */
Vertice* CriaVertice(int* codigo, char* cidade);

/**
 * Fun��o que cria um Adjacente.
 */
Adjacente* CriaAdjacente(int* codV, int* codA, int* peso);

/**
 * Fun��o que insere um Vertice num Grafo.
 */
Vertice* InserirVertice(Vertice* grafo, Vertice* v, int *resultado);

/**
 * Fun��o que insere um Adjacente numa lista de Adjacentes.
 */
Adjacente* InserirAdjacente(Adjacente* listaAdjs, Adjacente* novoAdj, int* resultado);

/**
 * Fun��o que insere um Adjacente num Grafo.
 */
Vertice* InserirAdjEmGrafo(Vertice* grafo, Adjacente* novoAdj, int* resultado);

/**
 * Fun��o que remove um Vertice de um Grafo, caso esteja presente no mesmo.
 */
Vertice* RemoverVertice(Vertice* grafo, Vertice* v, int* resultado);

/**
 * Fun��o que verifica se um Vertice est� presente num Grafo.
 */
int ProcuraVertice(Vertice* grafo, Vertice* v);

/**
 * Fun��o que verifica se dois Vertices s�o iguais.
 */
int ComparaVertices(Vertice* v1, Vertice* v2);

/**
 * Fun��o que remove um Adjacente da lista de Adjacentes recebida, se estiver presente na mesma.
 */
Adjacente* RemoverAdjacente(Adjacente* listaAdjs, Adjacente* adjRemovido, int* resultado);

/**
 * Fun��o que remove um Adjacente de um Grafo.
 */
Vertice* RemoverAdjGrafo(Vertice* grafo, Adjacente* adjRemovido, int* resultado);

/**
 * Fun��o que verifica se um Adjacente est� presente numa lista de Adjacentes.
 */
int ProcuraAdjacente(Adjacente* listaAdjs, Adjacente* adj);

/**
 * Fun��o que verifica se dois Adjacentes s�o iguais.
 */
int ComparaAdjacentes(Adjacente* a1, Adjacente* a2);

/**
 * Fun��o que destroi um Grafo.
 */
Vertice* DestroiGrafo(Vertice* grafo, int* resultado);

/**
 * Fun��o que destroi uma lista de Adjacencias.
 */
Adjacente* DestroiAdjacencias(Adjacente* adjs, int* resultado);

/**
 * Fun��o que guarda um Grafo em ficheiro de texto. (N�o � necess�rio)
 */
int SaveGrafo(Vertice* grafo, char* fileName);

/**
 * Fun��o que guarda um Grafo em ficheiro Bin�rio.
 */
int SaveGrafoBin(Vertice* grafo, char* fileName);

/**
 * Fun��o que guarda a lista de Vertices de um Grafo em ficheiro de texto.
 */
int SaveVertices(Vertice* grafo, char* fileName);

/**
 * Fun��o que guarda a lista de Vertices de um Grafo em ficheiro Bin�rio.
 */
int SaveVerticesBin(Vertice* grafo, char* fileName);

/**
 * Fun��o que guarda uma lista de Adjacencias em ficheiro de texto.
 */
int SaveAdjacencias(Adjacente* adjs, char* fileName);

/**
 * Fun��o que guarda uma lista de Adjacentes em ficheiro Bin�rio.
 */
int SaveAdjacenciasBin(Adjacente* adjs, char* fileName);

/**
 * Fun��o que l� um Grafo a partir de um ficheiro de texto.
 */
Vertice* LerGrafo(Vertice* grafo, char* fileName, int* resultado);

/**
 * Fun��o que l� um Grafo a partir de um ficheiro Bin�rio.
 */
Vertice* LerGrafoBin(Vertice* grafo, char* fileName, int* resultado);

/**
 * Fun��o que l� uma lista de Vertices a partir de um ficheiro de texto.
 */
Vertice* LerVertices(Vertice* head, char* fileName, int* resultado);

/**
 * Fun��o que l� uma lista de Vertices a partir de um ficheiro Bin�rio.
 */
Vertice* LerVerticesBin(Vertice* head, char* fileName, int* resultado);

/**
 * Fun��o que l� uma lista de Adjacencias a partir de um ficheiro de texto.
 */
Adjacente* LerAdjacencias(Adjacente* head, char* fileName, int* resultado);

/**
 * Fun��o que l� uma lista de Adjacencias a partir de um ficheiro Bin�rio.
 */
Adjacente* LerAdjacenciasBin(Adjacente* head, char* fileName, int* resultado);

/**
 * Fun��o que imprime todos os Vertices do Grafo e as suas Adjacencias.
 */
int MostraGrafo(Vertice* grafo);

/**
 * Fun��o que imprime as Adjacencias de um Vertice.
 */
int MostraAdjs(Adjacente* adjs);
