/*****************************************************************//**
 * \file   Gestores.c
 * \brief  Implementação das Funções dos Gestores
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

//DONE
 /**
  * Função para armazenar a lista de Gestores em ficheiro de texto.
  * 
  * Retorna 0 caso a lista esteja vazia.
  * Retorna -1 caso não consiga abrir o ficheiro.
  * Retorna 1 caso consiga guardar a lista no ficheiro com sucesso.
  */
int ArmazenarGestores(ListaGestores* head, char fileName[]) {
	if (head == NULL) {
		return 0;
	}
	ListaGestores* aux = head;
	FILE* fGestores;
	fGestores = fopen(fileName, "w");
	if (fGestores == NULL) {
		return (-1);
	}
	while (aux != NULL) {
		fprintf(fGestores, "%d;%d;%s\n", aux->gestor->nif, aux->gestor->idade, aux->gestor->nome);
		aux = aux->nextGestor;
	}
	fclose(fGestores);
	return 1;
}

//DONE
/**
 * Função para armazenar a lista de Gestores em ficherio binário.
 *
 * Caso consiga guardar a lista no ficheiro, retorna 1.
 * Caso a lista esteja vazia, retorna 0.
 * Caso não consiga guardar a lista no ficheiro, retorna -1.
 */
int ArmazenarGestoresBin(ListaGestores* head, char fileName[]) {
	if (head == NULL) {
		return 0;
	}
	ListaGestores* aux = head;
	FILE* fGestoresBin;
	fGestoresBin = fopen(fileName, "wb");
	if (fGestoresBin == NULL) {
		return (-1);
	}
	while (aux != NULL) {
		fwrite(&aux->gestor, 1, sizeof(Gestor), fGestoresBin);
		aux = aux->nextGestor;
	}
	fclose(fGestoresBin);
	return 1;
}

//DONE
/**
 * Função para ler a lista de Gestores de ficheiro de texto.
 * 
 * Retorna a lista lida a partir do ficheiro.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista a partir do ficheiro com sucesso.
 */
ListaGestores* LerGestores(char fileName[], int* resultado) {
	ListaGestores* head = NULL;
	FILE* fGestores;
	int i;
	fGestores = fopen(fileName, "r");
	if (fGestores == NULL) {
		resultado = 0;
		return 0;
	}

	Gestor aux;              //Não é apontador aqui
	while (!feof(fGestores)) {
		fscanf(fGestores, "%d;%d;%s\n", &aux.nif, &aux.idade, aux.nome);           //nas strings nao precisa do &
		head = InserirGestores(head, &aux, &i);                                           //mudar as -> para . n fscanf
	}
	fclose(fGestores);
	resultado = 1;
	return head;
}

//DONE
/**
 * Função para ler a lista de Gestores de ficheiro binário.
 * 
 * Retorna a lista de Gestores lida a partir do ficheiro.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista a partir do ficheiro.
 */
ListaGestores* LerGestoresBin(char fileName[], int* resultado) {
	ListaGestores* head = NULL;
	FILE* fGestoresBin;
	int i;
	fGestoresBin = fopen(fileName, "rb");
	if (fGestoresBin == NULL) {
		resultado = 0;
		return 0;
	}

	Gestor aux;           //Não é apontador
	while (fread(&aux, 1, sizeof(Gestor), fGestoresBin)) {
		head = InserirGestores(head, &aux, &i);
	}
	fclose(fGestoresBin);
	resultado = 1;
	return head;
}

//DONE
/**
 * Função para inserir um novo Gestor na lista de Gestores por ordem crescente de NIF.
 * 
 * Retorna a lista de Gestores com o novo Gestor
 * 
 * Resultado = 0 caso a lista esteja vazia e seja o unico elemento da lista.
 * Resultado = 1 caso insira no inicio de uma lista não vazia.
 * Resultado = 2 caso insira no meio de uma lista não vazia.
 * Resultado = 3 caso insira no fim de uma lista não vazia.
 */
ListaGestores* InserirGestores(ListaGestores* head, Gestor* novoGestor, int* resultado) {
	ListaGestores* novo = (ListaGestores*)malloc(sizeof(ListaGestores));
	novo->gestor = novoGestor;
	novo->nextGestor = NULL;

	ListaGestores* aux = head;
	ListaGestores* anterior = head;

	//Caso a lista seja vazia
	if (head == NULL) {
		head = novo;
		*resultado = 0;
		return head;
	}
	else {
		//Inserir por ordem crescente dos NIFs
		//Inserir no inicio
		if (head->gestor->nif > novoGestor->nif) {
			novo->nextGestor = head;
			head = novo;
			*resultado = 1;
			return head;
		}
		else {
			//Inserir no meio ou no fim
			aux = aux->nextGestor;
			while (aux != NULL) {
				if (aux->gestor->nif > novo->gestor->nif) {
					novo->nextGestor = aux;
					anterior->nextGestor = novo;
					*resultado = 2;
					return head;
				}
				anterior = aux;
				aux = aux->nextGestor;
			}
			anterior->nextGestor = novo;
		}
	}
	*resultado = 3;
	return head;
}

//DONE
/**
 * Função para remover um determindado Gestor de uma lista de Gestores.
 *
 * Retorna a lista sem o Gestor caso o consiga remover.
 *
 * Resultado = -1 caso a lista esteja vazia.
 * Resultado = 0 caso o cliente não esteja na lista
 * Resultado = 1 caso remova o cliente com sucesso
 */
ListaGestores* RemoverGestores(ListaGestores* head, Gestor* gestorRemovido, int* resultado) {
	if (head == NULL) {
		*resultado = -1;
		return head;
	}
	int i = PresenteListaGestores(head, gestorRemovido);
	if (i == 0) {
		*resultado = 0;
		return head;
	}
	else if (i == 1) {
		ListaGestores* aux = head;
		ListaGestores* anterior = head;
		//Caso em que o Gestor removido é o primeiro elemento da lista
		if (ComparaGestores(aux->gestor, gestorRemovido) == 1) {
			head = aux->nextGestor;
			free(aux);
			*resultado = 1;
			return head;
		}

		//Caso em que o Gestor removido está no meio ou no fim da lista.
		aux = aux->nextGestor;
		while (aux != NULL) {
			if (ComparaGestores(aux->gestor, gestorRemovido) == 1) {
				anterior->nextGestor = aux->nextGestor;
				free(aux);
				*resultado = 1;
				return head;
			}
			else {
				anterior = anterior->nextGestor;
				aux = aux->nextGestor;
			}
		}
	}
}

//DONE
/**
 * Imprime os dados dos Gestores presentes numa determinada lista dos mesmos.
 * 
 * Retorna 0 se a lista estiver vazia.
 * Retorna o número de Gestores na lista caso não esteja vazia.
 */
int ImprimirGestores(ListaGestores* head) {
	int i;
	ListaGestores* aux = head;
	if (head == NULL) {
		return 0;
	}
	for (i = 0; aux != NULL; i++) {
		printf("\n");
		printf("Gestor %d:\n", i + 1);
		printf("NIF: %d\n", aux->gestor->nif);
		printf("Idade: %d\n", aux->gestor->idade);
		printf("Nome: %s\n", aux->gestor->nome);

		aux = aux->nextGestor;
	}
	return i;
}

//DONE
/**
 * Verifica se o Gestor recebido está presente na lista de Gestores recebida.
 *
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso o Gestor não esteja na lista.
 * Retorna 1 caso o Gestor esteja presente na lista.
 */
int PresenteListaGestores(ListaGestores* head, Gestor* g) {
	if (head == NULL) {
		return -1;
	}
	ListaGestores* aux = head;
	while (aux != NULL) {
		if (ComparaGestores(aux->gestor, g) == 1) {
			return 1;
		}
		aux = aux->nextGestor;
	}
	return 0;
}

//DONE
/**
 * Verifica se dois Gestores são iguais.
 *
 * Retorna 1 caso os Gestores sejam iguais.
 * Retorna 0 caso os Gestores não sejam iguais.
 */
int ComparaGestores(Gestor* g1, Gestor* g2) {
	if ((g1->nif == g2->nif) &&
		(g1->idade == g2->idade) &&
		(strcmp(g1->nome, g2->nome) == 0)
		) {
		return 1;
	}
	else {
		return 0;
	}
}
