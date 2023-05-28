/*****************************************************************//**
 * \file   Meios.h
 * \brief  Assinaturas das Fun��es e Structs dos Meios
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
   * Tipos de transportes el�tricos.
   */
typedef enum tipoTransporte {
	trotinete,
	bicicleta,
	motociclo,
	carro,
} TipoTransporte;

/**
 * Estrutura dos meios de mobilidade el�tricos.
 */
typedef struct meiosMobilidadeEletricos {
	int id;
	int autonomia;
	TipoTransporte tipo;
	bool alugado;
} Meio;

/**
 * Estrutura para a cria��o da lista de meios de mobilidade el�tricos.
 */
typedef struct listaMeios {
	Meio* meio;
	struct listaMeios* nextMeio;
} ListaMeios;

/**
 * Fun��o para armazenar a lista de Meios em ficheiro de texto.
 */
int ArmazenarMeios(ListaMeios* head, char fileName[]);

/**
 * Fun��o para armazenar a lista de Meios em ficherio bin�rio.
 */
int ArmazenarMeiosBin(ListaMeios* head, char fileName[]);

/**
 * Fun��o para ler a lista de Meios de ficheiro de texto.
 */
ListaMeios* LerMeios(char fileName[], int* resultado);

/**
 * Fun��o para ler a lista de Meios de ficheiro bin�rio.
 */
ListaMeios* LerMeiosBin(char fileName[], int* resultado);

/**
 * Fun��o para inserir um novo Meios na lista de Meios por ordem crescente de ID.
 */
ListaMeios* InserirMeios(ListaMeios* head, Meio* novoMeio, int* resultado);

/**
 * Fun��o para remover um determindado Meio de uma lista de Meios.
 */
ListaMeios* RemoverMeios(ListaMeios* head, Meio* meioRemovido, int* resultado);

/**
 * Imprime os dados dos Meios presentes numa determinada lista dos mesmos.
 */
int ImprimirMeios(ListaMeios* head);

/**
 * Verifica se o Meio recebido est� presente na lista de Meios recebida.
 */
int PresenteListaMeios(ListaMeios* head, Meio* m);

/**
 * Verifica se dois Meios s�o iguais.
 */
int ComparaMeios(Meio* m1, Meio* m2);
