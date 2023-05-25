/*****************************************************************//**
 * \file   Clientes.h
 * \brief  Assinaturas das Fun��es e Structs dos Clientes
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
   * Estrutura dos Clientes.
   */
typedef struct cliente {
	int nif;
	int idade;
	float saldo;
	char nome[NOME];
	char morada[MORADA];
} Cliente;

/**
 * Estrutura para a cria��o da lista de Clientes.
 */
typedef struct listaClientes {
	Cliente* cliente;
	struct listaClientes* nextCliente;
} ListaClientes;

/**
 * Fun��o para armazenar a lista de Clientes em ficheiro de texto.
 */
int ArmazenarClientes(ListaClientes* head, char fileName[]);

/**
 * Fun��o para armazenar a lista de Clientes em ficherio bin�rio.
 */
int ArmazenarClientesBin(ListaClientes* head, char fileName[]);

/**
 * Fun��o para ler a lista de Clientes de ficheiro de texto.
 */
ListaClientes* LerClientes(char fileName[], int resultado);

/**
 * Fun��o para ler a lista de Clientes de ficheiro bin�rio.
 */
ListaClientes* LerClientesBin(char fileName[], int resultado);

/**
 * Fun��o para inserir um novo Cliente na lista de Clientes por ordem crescente de NIF.
 */
ListaClientes* InserirClientes(ListaClientes* head, Cliente* novoCliente, int *resultado);

/**
 * Fun��o para remover um determindado Cliente de uma lista de Clientes.
 */
ListaClientes* RemoverClientes(ListaClientes* head, Cliente* clienteRemovido, int* resultado);

/**
 * Imprime os dados dos Clientes presentes numa determinada lista dos mesmos.
 */
int ImprimirClientes(ListaClientes* head);

/**
 * Verifica se o Cliente recebido est� presente na lista de Clientes recebida.
 */
int PresenteListaClientes(ListaClientes* head, Cliente* c);

/**
 * Verifica se dois Clientes s�o iguais.
 */
int ComparaClientes(Cliente* c1, Cliente* c2);
