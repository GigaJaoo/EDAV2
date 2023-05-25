/*****************************************************************//**
 * \file   Clientes.h
 * \brief  Assinaturas das Funções e Structs dos Clientes
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
 * Estrutura para a criação da lista de Clientes.
 */
typedef struct listaClientes {
	Cliente* cliente;
	struct listaClientes* nextCliente;
} ListaClientes;

/**
 * Função para armazenar a lista de Clientes em ficheiro de texto.
 */
int ArmazenarClientes(ListaClientes* head, char fileName[]);

/**
 * Função para armazenar a lista de Clientes em ficherio binário.
 */
int ArmazenarClientesBin(ListaClientes* head, char fileName[]);

/**
 * Função para ler a lista de Clientes de ficheiro de texto.
 */
ListaClientes* LerClientes(char fileName[], int resultado);

/**
 * Função para ler a lista de Clientes de ficheiro binário.
 */
ListaClientes* LerClientesBin(char fileName[], int resultado);

/**
 * Função para inserir um novo Cliente na lista de Clientes por ordem crescente de NIF.
 */
ListaClientes* InserirClientes(ListaClientes* head, Cliente* novoCliente, int *resultado);

/**
 * Função para remover um determindado Cliente de uma lista de Clientes.
 */
ListaClientes* RemoverClientes(ListaClientes* head, Cliente* clienteRemovido, int* resultado);

/**
 * Imprime os dados dos Clientes presentes numa determinada lista dos mesmos.
 */
int ImprimirClientes(ListaClientes* head);

/**
 * Verifica se o Cliente recebido está presente na lista de Clientes recebida.
 */
int PresenteListaClientes(ListaClientes* head, Cliente* c);

/**
 * Verifica se dois Clientes são iguais.
 */
int ComparaClientes(Cliente* c1, Cliente* c2);
