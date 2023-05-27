/*****************************************************************//**
 * \file   Grafo.h
 * \brief  Assinaturas das Funções e Structs para os Grafos
 * 
 * \author João Pereira - a24254
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
 * Função que cria o Grafo.
 */
Vertice* CriaGrafo();

/**
 * Função que cria um Vertice.
 */
Vertice* CriaVertice(int* codigo, char* cidade);

/**
 * Função que cria um Adjacente.
 */
Adjacente* CriaAdjacente(int* codV, int* codA, int* peso);

/**
 * Função que insere um Vertice num Grafo.
 */
Vertice* InserirVertice(Vertice* grafo, Vertice* v, int *resultado);

/**
 * Função que insere um Adjacente numa lista de Adjacentes.
 */
Adjacente* InserirAdjacente(Adjacente* listaAdjs, Adjacente* novoAdj, int* resultado);

/**
 * Função que insere um Adjacente num Grafo.
 */
Vertice* InserirAdjEmGrafo(Vertice* grafo, Adjacente* novoAdj, int* resultado);

/**
 * Função que remove um Vertice de um Grafo, caso esteja presente no mesmo.
 */
Vertice* RemoverVertice(Vertice* grafo, Vertice* v, int* resultado);

/**
 * Função que verifica se um Vertice está presente num Grafo.
 */
int ProcuraVertice(Vertice* grafo, Vertice* v);

/**
 * Função que verifica se dois Vertices são iguais.
 */
int ComparaVertices(Vertice* v1, Vertice* v2);

/**
 * Função que remove um Adjacente da lista de Adjacentes recebida, se estiver presente na mesma.
 */
Adjacente* RemoverAdjacente(Adjacente* listaAdjs, Adjacente* adjRemovido, int* resultado);

/**
 * Função que remove um Adjacente de um Grafo.
 */
Vertice* RemoverAdjGrafo(Vertice* grafo, Adjacente* adjRemovido, int* resultado);

/**
 * Função que verifica se um Adjacente está presente numa lista de Adjacentes.
 */
int ProcuraAdjacente(Adjacente* listaAdjs, Adjacente* adj);

/**
 * Função que verifica se dois Adjacentes são iguais.
 */
int ComparaAdjacentes(Adjacente* a1, Adjacente* a2);

/**
 * Função que destroi um Grafo.
 */
Vertice* DestroiGrafo(Vertice* grafo, int* resultado);

/**
 * Função que destroi uma lista de Adjacencias.
 */
Adjacente* DestroiAdjacencias(Adjacente* adjs, int* resultado);

/**
 * Função que guarda um Grafo em ficheiro de texto. (Não é necessário)
 */
int SaveGrafo(Vertice* grafo, char* fileName);

/**
 * Função que guarda um Grafo em ficheiro Binário.
 */
int SaveGrafoBin(Vertice* grafo, char* fileName);

/**
 * Função que guarda a lista de Vertices de um Grafo em ficheiro de texto.
 */
int SaveVertices(Vertice* grafo, char* fileName);

/**
 * Função que guarda a lista de Vertices de um Grafo em ficheiro Binário.
 */
int SaveVerticesBin(Vertice* grafo, char* fileName);

/**
 * Função que guarda uma lista de Adjacencias em ficheiro de texto.
 */
int SaveAdjacencias(Adjacente* adjs, char* fileName);

/**
 * Função que guarda uma lista de Adjacentes em ficheiro Binário.
 */
int SaveAdjacenciasBin(Adjacente* adjs, char* fileName);

/**
 * Função que lê um Grafo a partir de um ficheiro de texto.
 */
Vertice* LerGrafo(Vertice* grafo, char* fileName, int* resultado);

/**
 * Função que lê um Grafo a partir de um ficheiro Binário.
 */
Vertice* LerGrafoBin(Vertice* grafo, char* fileName, int* resultado);

/**
 * Função que lê uma lista de Vertices a partir de um ficheiro de texto.
 */
Vertice* LerVertices(Vertice* head, char* fileName, int* resultado);

/**
 * Função que lê uma lista de Vertices a partir de um ficheiro Binário.
 */
Vertice* LerVerticesBin(Vertice* head, char* fileName, int* resultado);

/**
 * Função que lê uma lista de Adjacencias a partir de um ficheiro de texto.
 */
Adjacente* LerAdjacencias(Adjacente* head, char* fileName, int* resultado);

/**
 * Função que lê uma lista de Adjacencias a partir de um ficheiro Binário.
 */
Adjacente* LerAdjacenciasBin(Adjacente* head, char* fileName, int* resultado);

/**
 * Função que imprime todos os Vertices do Grafo e as suas Adjacencias.
 */
int MostraGrafo(Vertice* grafo);

/**
 * Função que imprime as Adjacencias de um Vertice.
 */
int MostraAdjs(Adjacente* adjs);
