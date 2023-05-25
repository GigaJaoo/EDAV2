/*****************************************************************//**
 * \file   Gestores.h
 * \brief  Assinaturas das Fun��es e Structs dos Gestores
 * 
 * \author Jo�o Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#define NOME 50
#define MORADA 100

#include <string.h>    // strings
#include <stdlib.h>    // malloc
#include <stdio.h>     // NULL
#include <stdbool.h>   // bools

 /**
  * Estrutura dos Gestores.
  */
typedef struct gestor {
	int nif;
	int idade;
	char nome[NOME];
} Gestor;

/**
 * Estrutura para a cria��o da lista de Gestores.
 */
typedef struct listaGestores {
	Gestor* gestor;
	struct listaGestores* nextGestor;
} ListaGestores;

/**
 * Fun��o para armazenar a lista de Gestores em ficheiro de texto.
 */
int ArmazenarGestores(ListaGestores* head, char fileName[]);

/**
 * Fun��o para armazenar a lista de Gestores em ficherio bin�rio.
 */
int ArmazenarGestoresBin(ListaGestores* head, char fileName[]);

/**
 * Fun��o para ler a lista de Gestores de ficheiro de texto.
 */
ListaGestores* LerGestores(char fileName[], int *resultado);

/**
 * Fun��o para ler a lista de Gestores de ficheiro bin�rio.
 */
ListaGestores* LerGestoresBin(char fileName[], int *resultado);

/**
 * Fun��o para inserir um novo Gestor na lista de Gestores por ordem crescente de NIF.
 */
ListaGestores* InserirGestores(ListaGestores* head, Gestor* novoGestor, int* resultado);

/**
 * Fun��o para remover um determindado Gestor de uma lista de Gestores.
 */
ListaGestores* RemoverGestores(ListaGestores* head, Gestor* gestorRemovido, int* resultado);

/**
 * Imprime os dados dos Gestores presentes numa determinada lista dos mesmos.
 */
int ImprimirGestores(ListaGestores* head);

/**
 * Verifica se o Gestor recebido est� presente na lista de Gestores recebida.
 */
int PresenteListaGestores(ListaGestores* head, Gestor* g);

/**
 * Verifica se dois Gestores s�o iguais.
 */
int ComparaGestores(Gestor* g1, Gestor* g2);
