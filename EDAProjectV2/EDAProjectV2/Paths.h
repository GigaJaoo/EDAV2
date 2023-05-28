/*****************************************************************//**
 * \file   Paths.h
 * \brief  Assinaturas de Structs e Fun��es que utilizem Paths ou Alugueres
 * 
 * \author Jo�o Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include <string.h>    // strings
#include <stdlib.h>    // malloc
#include <stdio.h>     // NULL
#include <stdbool.h>   // bools
#include "Clientes.h"  // Clientes
#include "Meios.h"     // Meios

#define MAX 10

/**
 * Estrutura de uma Hora.
 */
typedef struct hora {
	int hora;
	int minuto;
} Hora;

/**
 * Estrutura de uma Data.
 */
typedef struct data {
	int dia;
	int mes;
	int ano;
	Hora h;
} Data;

/**
 * Estrutura de um Aluguer.
 */
typedef struct aluguer {
	int codigoAluguer;
	Cliente c;
	Meio m;
	Data dataInicio;
	Data dataFim;
	int distPercorrida;
} Aluguer;

/**
 * Estrutura de um Nodo para uma Lista de Alugueres.
 */
typedef struct listaAlugueres {
	Aluguer* a;
	struct listaAlugueres* nextAluguer;
} ListaAlugueres;

/**
 * Estrutura de um Path.
 */
typedef struct path {
	int distanciaPercorrida;  //Soma dos pesos dos vertices percorridos
	int verticesPercorridos[MAX];   //Array com os codigos dos vertices percorridos
} Path;

#pragma region ALUGUERES

/**
 * Fun��o que Cria e Retorna um Aluguer.
 */
Aluguer* CriaAluguer(Cliente* c, Meio* m, Data* inicio, Data* fim, int* distancia, int* resultado);

/**
 * Fu��o que calcula o custo total de um aluguer.
 */
int CustoAluguer(Aluguer* a);

/**
 * Fun��o que calcula o n�mero de minutos entre duas Datas.
 */
int TempoTotal(Data inicio, Data fim);

/**
 * Fun��o que insere um Aluguer numa Lista de Alugueres.
 */
ListaAlugueres* InserirAluguer(ListaAlugueres* head, Aluguer* a, int* resultado);

/**
 * Fun��o que verifica se um Aluguer est� presente numa Lista de Alugueres.
 */
int ProcuraAluguer(ListaAlugueres* head, Aluguer* a);

/**
 * Fun��o que verifica se dois Alugueres s�o iguais.
 */
int ComparaAlugueres(Aluguer* a1, Aluguer* a2);

#pragma endregion

#pragma region PATHS

/**
 * Fun��o que retorna uma lista de Meios disponiveis num determinado raio.
 */
ListaMeios* MeiosDisponiveis(Vertice* grafo, Vertice* v, ListaMeios* meios);

/**
 * Fun��o que retorna o melhor caminho entre dois Vertices de um Grafo.
 */
Path* BestPath(Vertice* grafo, Vertice* v1, Vertice* v2, int* resultado);

#pragma endregion
