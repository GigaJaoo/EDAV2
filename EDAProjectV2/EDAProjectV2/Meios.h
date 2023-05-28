/*****************************************************************//**
 * \file   Meios.h
 * \brief  Assinaturas das Funções e Structs dos Meios
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
   * Tipos de transportes elétricos.
   */
typedef enum tipoTransporte {
	trotinete,
	bicicleta,
	motociclo,
	carro,
} TipoTransporte;

/**
 * Estrutura dos meios de mobilidade elétricos.
 */
typedef struct meiosMobilidadeEletricos {
	int id;
	int autonomia;
	TipoTransporte tipo;
	bool alugado;
} Meio;

/**
 * Estrutura para a criação da lista de meios de mobilidade elétricos.
 */
typedef struct listaMeios {
	Meio* meio;
	struct listaMeios* nextMeio;
} ListaMeios;

/**
 * Função para armazenar a lista de Meios em ficheiro de texto.
 */
int ArmazenarMeios(ListaMeios* head, char fileName[]);

/**
 * Função para armazenar a lista de Meios em ficherio binário.
 */
int ArmazenarMeiosBin(ListaMeios* head, char fileName[]);

/**
 * Função para ler a lista de Meios de ficheiro de texto.
 */
ListaMeios* LerMeios(char fileName[], int* resultado);

/**
 * Função para ler a lista de Meios de ficheiro binário.
 */
ListaMeios* LerMeiosBin(char fileName[], int* resultado);

/**
 * Função para inserir um novo Meios na lista de Meios por ordem crescente de ID.
 */
ListaMeios* InserirMeios(ListaMeios* head, Meio* novoMeio, int* resultado);

/**
 * Função para remover um determindado Meio de uma lista de Meios.
 */
ListaMeios* RemoverMeios(ListaMeios* head, Meio* meioRemovido, int* resultado);

/**
 * Imprime os dados dos Meios presentes numa determinada lista dos mesmos.
 */
int ImprimirMeios(ListaMeios* head);

/**
 * Verifica se o Meio recebido está presente na lista de Meios recebida.
 */
int PresenteListaMeios(ListaMeios* head, Meio* m);

/**
 * Verifica se dois Meios são iguais.
 */
int ComparaMeios(Meio* m1, Meio* m2);
