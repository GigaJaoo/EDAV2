/*****************************************************************//**
 * \file   Clientes.c
 * \brief  Implementação das Funções dos Clientes
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

//DONE
 /**
  * Função para armazenar a lista de Clientes em ficheiro de texto.
  * 
  * Retorna 0 caso a lista esteja vazia.
  * Retorna -1 caso não consiga abrir o ficheiro.
  * Retorna 1 caso guarde a lista de Clientes no ficheiro com sucesso.
  */
int ArmazenarClientes(ListaClientes* head, char fileName[]) {
	if (head == NULL) {
		return 0;
	}
	ListaClientes* aux = head;
	FILE* fClientes;
	fClientes = fopen(fileName, "w");
	if (fClientes == NULL) {
		return (-1);
	}
	while (aux != NULL) {
		fprintf(fClientes, "%d;%d;%f;%s;%s\n", aux->cliente->nif, aux->cliente->idade, aux->cliente->saldo, aux->cliente->nome, aux->cliente->morada);
		aux = aux->nextCliente;
	}
	fclose(fClientes);
	return 1;
}

//DONE
/**
 * Função para armazenar a lista de Clientes em ficherio binário.
 */
int ArmazenarClientesBin(ListaClientes* head, char fileName[]) {
	if (head == NULL) {
		return 0;
	}
	ListaClientes* aux = head;
	FILE* fClientesBin;
	fClientesBin = fopen(fileName, "wb");
	if (fClientesBin == NULL) {
		return (-1);
	}
	while (aux != NULL) {
		fwrite(&aux->cliente, 1, sizeof(Cliente), fClientesBin);
		aux = aux->nextCliente;
	}
	fclose(fClientesBin);
	return 1;
}

//DONE
/**
 * Função para ler a lista de Clientes de ficheiro de texto.
 * 
 * Retorna a lista dos Clientes lida a partir do ficheiro de texto.
 * 
 * Resultado = 0 caso não consiga ler o ficheiro.
 * Resultado = 1 caso consiga ler a lista a partir do ficheiro.
 */
ListaClientes* LerClientes(char fileName[], int *resultado) {
	ListaClientes* head = NULL;
	FILE* fClientes;
	int i;
	fClientes = fopen(fileName, "r");
	if (fClientes == NULL) {
		resultado = 0;
		return 0;
	}
	Cliente aux;
	while (!feof(fClientes)) {
		fscanf(fClientes, "%d;%d;%f;[^;];%s\n", &aux.nif, &aux.idade, &aux.saldo, aux.nome, aux.morada);
		head = InserirClientes(head, &aux, &i);
	}
	fclose(fClientes);
	resultado = 1;
	return head;
}

//DONE
/**
 * Função para ler a lista de Clientes de ficheiro binário.
 * 
 * Retorna a lista de Clientes lida a partir do ficheiro de texto.
 * 
 * Resultado = 0 caso não consiga ler o ficheiro.
 * Resultado = 1 caso consiga ler a lista a partir do ficheiro.
 */
ListaClientes* LerClientesBin(char fileName[], int *resultado) {
	ListaClientes* head = NULL;
	FILE* fClientesBin;
	int i;
	fClientesBin = fopen(fileName, "rb");
	if (fClientesBin == NULL) {
		resultado = 1;
		return 0;
	}
	Cliente aux;
	while (fread(&aux, 1, sizeof(Cliente), fClientesBin)) {
		head = InserirClientes(head, &aux, &i);
	}
	fclose(fClientesBin);
	resultado = 1;
	return head;
}

//DONE
/**
 * Função para inserir um novo Cliente na lista de Clientes por ordem crescente de NIF.
 * 
 * Retorna a lista de Clientes com o novo cliente.
 * 
 * Resultado = 0 caso a lista esteja vazia e seja o unico elemento da lista.
 * Resultado = 1 caso insira no inicio de uma lista não vazia.
 * Resultado = 2 caso insira no meio de uma lista não vazia.
 * Resultado = 3 caso insira no fim de uma lista não vazia.
 */
ListaClientes* InserirClientes(ListaClientes* head, Cliente* novoCliente, int* resultado) {
	ListaClientes* novo = (ListaClientes*)malloc(sizeof(ListaClientes));
	novo->cliente = novoCliente;
	novo->nextCliente = NULL;

	ListaClientes* aux = head;
	ListaClientes* anterior = head;

	//Caso a lista seja vazia
	if (head == NULL) {
		head = novo;
		*resultado = 0;
		return head;
	}
	else {
		//Inserir por ordem crescente dos NIFs
		//Inserir no inicio
		if (head->cliente->nif > novoCliente->nif) {
			novo->nextCliente = head;
			head = novo;
			*resultado = 1;
			return head;
		}
		else {
			//Inserir no meio ou no fim
			aux = aux->nextCliente;
			while (aux != NULL) {
				if (aux->cliente->nif > novo->cliente->nif) {
					novo->nextCliente = aux;
					anterior->nextCliente = novo;
					*resultado = 2;
					return head;
				}
				anterior = aux;
				aux = aux->nextCliente;
			}
			anterior->nextCliente = novo;
		}
	}
	*resultado = 3;
	return head;
}

//DONE
/**
 * Função para remover um determindado Cliente de uma lista de Clientes.
 * 
 * Retorna a lista sem o Cliente caso o consiga remover.
 * 
 * Resultado = -1 caso a lista esteja vazia.
 * Resultado = 0 caso o cliente não esteja na lista
 * Resultado = 1 caso remova o cliente com sucesso
 */
ListaClientes* RemoverClientes(ListaClientes* head, Cliente* clienteRemovido, int* resultado) {
	if (head == NULL) {
		*resultado = -1;
		return head;
	}
	int i = PresenteListaClientes(head, clienteRemovido);
	if (i == 0) {
		*resultado = 0;
		return head;
	}
	else if (i == 1) {
		ListaClientes* aux = head;
		ListaClientes* anterior = head;
		//Caso em que o cliente removido é o primeiro elemento da lista
		if (ComparaClientes(aux->cliente, clienteRemovido) == 1) {
			head = aux->nextCliente;
			free(aux);
			*resultado = 1;
			return head;
		}
		//Caso em que o cliente removido está no meio ou no fim da lista.
		aux = aux->nextCliente;
		while (aux != NULL) {
			if (ComparaClientes(aux->cliente, clienteRemovido) == 1) {
				anterior->nextCliente = aux->nextCliente;
				free(aux);
				*resultado = 1;
				return head;
			}
			else {
				anterior = anterior->nextCliente;
				aux = aux->nextCliente;
			}
		}
	}
}

//DONE
/**
 * Imprime os dados dos Clientes presentes numa determinada lista dos mesmos.
 * 
 * Retorna 0 se a lista estiver vazia.
 * Retorna o número de clientes na lista caso não esteja vazia.
 */
int ImprimirClientes(ListaClientes* head) {
	int i;
	ListaClientes* aux = head;
	if (head == NULL) {
		return 0;
	}
	for (i = 0; aux != NULL; i++) {
		printf("\n");
		printf("Cliente %d:\n", i + 1);
		printf("NIF: %d\n", aux->cliente->nif);
		printf("Idade: %d\n", aux->cliente->idade);
		printf("Saldo: %f\n", aux->cliente->saldo);
		printf("Nome: %s\n", aux->cliente->nome);
		printf("Morada: %s\n", aux->cliente->morada);

		aux = aux->nextCliente;
	}
	return i;
}

//DONE
/**
 * Verifica se o Cliente recebido está presente na lista de Clientes recebida.
 * 
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso o Cliente não esteja na lista.
 * Retorna 1 caso o Cliente esteja presente na lista.
 */
int PresenteListaClientes(ListaClientes* head, Cliente* c){
	if (head == NULL) {
		return -1;
	}
	ListaClientes* aux = head;
	while (aux != NULL) {
		if (ComparaClientes(aux->cliente, c) == 1) {
			return 1;
		}
		aux = aux->nextCliente;
	}
	return 0;
}

//DONE
/**
 * Verifica se dois Clientes são iguais.
 * 
 * Retorna 1 caso os Clientes sejam iguais.
 * Retorna 0 caso os Clientes não sejam iguais.
 */
int ComparaClientes(Cliente* c1, Cliente* c2) {
	if ((c1->nif == c2->nif) &&
		(c1->idade == c2->idade) &&
		(c1->saldo == c2->saldo) &&
		(strcmp(c1->nome, c2->nome) == 0) &&
		(strcmp(c1->morada, c2->morada) == 0)
		) {
		return 1;
	}
	else {
		return 0;
	}
}
