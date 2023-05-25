/*****************************************************************//**
 * \file   Gestores.h
 * \brief  Assinaturas das Funções e Structs dos Gestores
 * 
 * \author João Pereira - a24254
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
 * Estrutura para a criação da lista de Gestores.
 */
typedef struct listaGestores {
	Gestor* gestor;
	struct listaGestores* nextGestor;
} ListaGestores;

/**
 * Função para armazenar a lista de Gestores em ficheiro de texto.
 */
int ArmazenarGestores(ListaGestores* head, char fileName[]);

/**
 * Função para armazenar a lista de Gestores em ficherio binário.
 */
int ArmazenarGestoresBin(ListaGestores* head, char fileName[]);

/**
 * Função para ler a lista de Gestores de ficheiro de texto.
 */
ListaGestores* LerGestores(char fileName[], int *resultado);

/**
 * Função para ler a lista de Gestores de ficheiro binário.
 */
ListaGestores* LerGestoresBin(char fileName[], int *resultado);

/**
 * Função para inserir um novo Gestor na lista de Gestores por ordem crescente de NIF.
 */
ListaGestores* InserirGestores(ListaGestores* head, Gestor* novoGestor, int* resultado);

/**
 * Função para remover um determindado Gestor de uma lista de Gestores.
 */
ListaGestores* RemoverGestores(ListaGestores* head, Gestor* gestorRemovido, int* resultado);

/**
 * Imprime os dados dos Gestores presentes numa determinada lista dos mesmos.
 */
int ImprimirGestores(ListaGestores* head);

/**
 * Verifica se o Gestor recebido está presente na lista de Gestores recebida.
 */
int PresenteListaGestores(ListaGestores* head, Gestor* g);

/**
 * Verifica se dois Gestores são iguais.
 */
int ComparaGestores(Gestor* g1, Gestor* g2);
