/*****************************************************************//**
 * \file   Meios.c
 * \brief  Implementação das Funções dos Meios
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

//DONE
 /**
  * Função para armazenar a lista de Meios em ficheiro de texto.
  * 
  * Retorna 0 caso a lista esteja vazia.
  * Retorna -1 caso não consiga ler o ficheiro.
  * Retorna 1 caso consiga guardar a lista no ficheiro com sucesso.
  */
int ArmazenarMeios(ListaMeios* head, char fileName[]) {
	if (head == NULL) {
		return 0;
	}
	ListaMeios* aux = head;
	FILE* fMeios;
	fMeios = fopen(fileName, "w");
	if (fMeios == NULL) {
		return (-1);
	}
	while (aux != NULL) {
		fprintf(fMeios, "%d;%d;%d\n", aux->meio->autonomia, aux->meio->geocodigo, (int)aux->meio->tipo);        //duvida de como ficará escrito o tipo de transporte
		aux = aux->nextMeio;
	}
	fclose(fMeios);
	return 1;
}

//DONE
/**
 * Função para armazenar a lista de Meios em ficherio binário.
 * 
 * Retorna 0 caso a lista esteja vazia.
 * Retorna -1 caso não consiga abrir o ficheiro.
 * Retorna 1 caso consiga guardar a lista no ficheiro com sucesso.
 */
int ArmazenarMeiosBin(ListaMeios* head, char fileName[]) {
	if (head == NULL) {
		return 0;
	}
	ListaMeios* aux = head;
	FILE* fMeiosBin;
	fMeiosBin = fopen(fileName, "wb");
	if (fMeiosBin == NULL) {
		return (-1);
	}
	while (aux != NULL) {
		fwrite(&aux->meio, 1, sizeof(Meio), fMeiosBin);
		aux = aux->nextMeio;
	}
	fclose(fMeiosBin);
	return 1;
}

//DONE
/**
 * Função para ler a lista de Meios de ficheiro de texto.
 * 
 * Retorna a lista lida a partir do ficheiro.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista a partir do ficheiro com sucesso.
 */
ListaMeios* LerMeios(char fileName[], int* resultado) {
	ListaMeios* head = NULL;
	FILE* fMeios;
	int i;
	fMeios = fopen(fileName, "r");
	if (fMeios == NULL) {
		resultado = 0;
		return 0;
	}

	Meio aux;      //Não é apontador aqui
	int transporte;
	while (!feof(fMeios)) {
		fscanf(fMeios, "%d;%d;%d\n", &aux.autonomia, &aux.geocodigo, &transporte);             //utilizar . em vez de -> no fscanf
		aux.tipo = (TipoTransporte)transporte;
		head = InserirMeios(head, &aux, &i);
	}
	fclose(fMeios);
	resultado = 1;
	return head;
}

//DONE
/**
 * Função para ler a lista de Meios de ficheiro binário.
 * 
 * Retorna a lista lida a partir do ficheiro.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista a partir do ficheiro com sucesso.
 */
ListaMeios* LerMeiosBin(char fileName[], int* resultado) {
	ListaMeios* head = NULL;
	FILE* fMeiosBin;
	int i;
	fMeiosBin = fopen(fileName, "rb");
	if (fMeiosBin == NULL) {
		resultado = 0;
		return 0;
	}

	Meio aux;          //Nao é apontador aqui
	while (fread(&aux, 1, sizeof(Meio), fMeiosBin)) {
		head = InserirMeios(head, &aux, &i);
	}
	fclose(fMeiosBin);
	resultado = 1;
	return head;
}

//DONE
/**
 * Função para inserir um novo Meios na lista de Meios por ordem crescente de ID.
 * 
 * Retorna a lista de Meios com o novo Meio.
 *
 * Resultado = 0 caso a lista esteja vazia e seja o unico elemento da lista.
 * Resultado = 1 caso insira no inicio de uma lista não vazia.
 * Resultado = 2 caso insira no meio de uma lista não vazia.
 * Resultado = 3 caso insira no fim de uma lista não vazia.
 */
ListaMeios* InserirMeios(ListaMeios* head, Meio* novoMeio, int* resultado) {
	ListaMeios* novo = (ListaMeios*)malloc(sizeof(ListaMeios));
	novo->meio = novoMeio;
	novo->nextMeio = NULL;

	ListaMeios* aux = head;
	ListaMeios* anterior = head;

	//Caso a lista seja vazia
	if (head == NULL) {
		head = novo;
		*resultado = 0;
		return head;
	}
	else {
		//Inserir por ordem crescente dos IDs
		//Inserir no inicio
		if (head->meio->id > novoMeio->id) {
			novo->nextMeio = head;
			head = novo;
			*resultado = 1;
			return head;
		}
		else {
			//Inserir no meio ou no fim
			aux = aux->nextMeio;
			while (aux != NULL) {
				if (aux->meio->id > novo->meio->id) {
					novo->nextMeio = aux;
					anterior->nextMeio = novo;
					*resultado = 2;
					return head;
				}
				anterior = aux;
				aux = aux->nextMeio;
			}
			anterior->nextMeio = novo;
		}
	}
	*resultado = 3;
	return head;
}

//DONE
/**
 * Função para remover um determindado Meio de uma lista de Meios.
 *
 * Retorna a lista sem o Meio caso o consiga remover.
 *
 * Resultado = -1 caso a lista esteja vazia.
 * Resultado = 0 caso o cliente não esteja na lista
 * Resultado = 1 caso remova o cliente com sucesso
 */
ListaMeios* RemoverMeios(ListaMeios* head, Meio* meioRemovido, int* resultado) {
	if (head == NULL) {
		*resultado = -1;
		return head;
	}
	int i = PresenteListaMeios(head, meioRemovido);
	if (i == 0) {
		*resultado = 0;
		return head;
	}
	else if (i == 1) {
		ListaMeios* aux = head;
		ListaMeios* anterior = head;
		//Caso em que o Meio removido é o primeiro elemento da lista
		if (ComparaMeios(aux->meio, meioRemovido) == 1) {
			head = aux->nextMeio;
			free(aux);
			*resultado = 1;
			return head;
		}

		//Caso em que o Meio removido está no meio ou no fim da lista.
		aux = aux->nextMeio;
		while (aux != NULL) {
			if (ComparaMeios(aux->meio, meioRemovido) == 1) {
				anterior->nextMeio = aux->nextMeio;
				free(aux);
				*resultado = 1;
				return head;
			}
			else {
				anterior = anterior->nextMeio;
				aux = aux->nextMeio;
			}
		}
	}
}

//DONE
/**
 * Imprime os dados dos Meios presentes numa determinada lista dos mesmos.
 * 
 * Retorna 0 se a lista estiver vazia.
 * Retorna o número de Meios na lista caso não esteja vazia.
 */
int ImprimirMeios(ListaMeios* head) {
	int i;
	ListaMeios* aux = head;
	if (head == NULL) {
		return 0;
	}
	for (i = 0; aux != NULL; i++) {
		printf("\n");
		printf("Meio %d:\n", i + 1);
		printf("ID: %d\n", aux->meio->id);
		printf("Autonomia: %d\n", aux->meio->autonomia);
		printf("Geocodigo: %d\n", aux->meio->geocodigo);

		if (aux->meio->tipo == trotinete) {
			printf("Tipo de transporte: Trotinete\n");
		}
		else if (aux->meio->tipo == bicicleta) {
			printf("Tipo de transporte: Bicicleta\n");
		}
		else if (aux->meio->tipo == motociclo) {
			printf("Tipo de transporte: Motociclo\n");
		}
		else if (aux->meio->tipo == carro) {
			printf("Tipo de transporte: Carro\n");
		}
		else {
			printf("Tipo de transporte: Indefinido\n");
		}

		aux = aux->nextMeio;
	}
	return i;
}

//DONE
/**
 * Verifica se o Meio recebido está presente na lista de Meios recebida.
 *
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso o Meio não esteja na lista.
 * Retorna 1 caso o Meio esteja presente na lista.
 */
int PresenteListaMeios(ListaMeios* head, Meio* m) {
	if (head == NULL) {
		return -1;
	}
	ListaMeios* aux = head;
	while (aux != NULL) {
		if (ComparaMeios(aux->meio, m) == 1) {
			return 1;
		}
		aux = aux->nextMeio;
	}
	return 0;
}

//DONE
/**
 * Verifica se dois Meios são iguais.
 *
 * Retorna 1 caso os Meios sejam iguais.
 * Retorna 0 caso os Meios não sejam iguais.
 */
int ComparaMeios(Meio* m1, Meio* m2) {
	if ((m1->id == m2->id) &&
		(m1->autonomia == m2->autonomia) &&
		(m1->geocodigo == m2->geocodigo) &&
		(m1->tipo == m2->tipo)
		) {
		return 1;
	}
	else {
		return 0;
	}
}
