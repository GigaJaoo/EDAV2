/*****************************************************************//**
 * \file   Grafo.c
 * \brief  Implementação das Funções dos Grafos
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

//NÃO SEI O QUE FAZER NESTES
#pragma region CRIAR

 /**
  * Função que cria o Grafo.
  */
Vertice* CriaGrafo(int* resultado) {

}

/**
 * Função que cria um Vertice.
 */
Vertice* CriaVertice(int* resultado) {

}

/**
 * Função que cria um Adjacente.
 */
Adjacente* CriaAdjacente(int* resultado) {

}

#pragma endregion

//DONE (TESTAR)
/**
 * Função que insere um Vertice num Grafo.
 * 
 * Retorna o Grafo com o Vertice introduzido.
 * 
 * Resultado = -1 caso o Vertice já esteja presente no Grafo.
 * Resultado = 0 caso o Vertice seja inserido num Grafo vazio.
 * Resultado = 1 caso o Vertice seja inserido no inicio de um Grafo não vazio.
 * Resultado = 2 caso o Vertice seja inserido no meio de um Grafo não vazio.
 * Resultado = 3 caso o Vertice seja inserido no fim de um Grafo não da vazio.
 */
Vertice* InserirVertice(Vertice* grafo, Vertice* v, int* resultado) {
	if (ProcuraVertice(grafo, v) == 1) {
		*resultado = -1;
		return grafo;
	}

	Vertice* aux = grafo;
	Vertice* anterior = grafo;

	//Caso o Grafo esteja vazio
	if (grafo == NULL) {
		grafo = v;
		*resultado = 0;
		return grafo;
	}
	else {
		//Inserir por ordem crescente de Código
		//Inserir no Inicio
		if (grafo->codigo > v->codigo) {
			v->nextVertice = grafo;
			grafo = v;
			*resultado = 1;
			return grafo;
		}
		else {
			//Inserir no meio ou no fim
			aux = aux->nextVertice;
			while (aux != NULL) {
				if (aux->codigo > v->codigo) {
					v->nextVertice = aux;
					anterior->nextVertice = v;
					*resultado = 2;
					return grafo;
				}
				anterior = aux;
				aux = aux->nextVertice;
			}
			anterior->nextVertice = v;
		}
	}
	*resultado = 3;
	return grafo;
}

//DONE (TESTAR)
/**
 * Função que insere um Adjacente numa lista de Adjacentes.
 * 
 * Retorna a lista de Adjacentes com o novo Adjacente.
 * 
 * Resultado = -1 caso o Adjacente já esteja presente na lista.
 * Resultado = 0 caso o Adjacente seja inserido numa lista vazia.
 * Resultado = 1 caso o Adjacente seja inserido no inicio de uma lista vazia.
 * Resultado = 2 caso o Adjacente seja inserido no meio da lista.
 * Resultado = 3 caso o Adjacente seja inserido no fim da lista.
 */
Adjacente* InserirAdjacente(Adjacente* listaAdjs, Adjacente* novoAdj, int* resultado) {
	if (ProcuraAdjacente(listaAdjs, novoAdj) == 1) {
		*resultado = -1;
		return listaAdjs;
	}

	Adjacente* aux = listaAdjs;
	Adjacente* anterior = listaAdjs;

	//Caso a lista esteja vazia
	if (listaAdjs == NULL) {
		listaAdjs = novoAdj;
		*resultado = 0;
		return listaAdjs;
	}
	else {
		//Inserir por ordem crescente de Código
		//Inserir no Inicio
		if (listaAdjs->codigoAdj > novoAdj->codigoAdj) {
			novoAdj->nextAdj = listaAdjs;
			listaAdjs = novoAdj;
			*resultado = 1;
			return listaAdjs;
		}
		else {
			//Inserir no meio ou no fim
			aux = aux->nextAdj;
			while (aux != NULL) {
				if(aux->codigoAdj > novoAdj->codigoAdj) {
					novoAdj->nextAdj = aux;
					anterior->nextAdj = novoAdj;
					*resultado = 2;
					return listaAdjs;
				}
				anterior = aux;
				aux = aux->nextAdj;
			}
			anterior->nextAdj = novoAdj;
		}
	}
	*resultado = 3;
	return listaAdjs;
}

//DONE (TESTAR)
/**
 * Função que remove um Vertice de um Grafo, caso esteja presente no mesmo.
 * 
 * Retorna o Grafo sem o Vertice caso o consiga remover.
 * 
 * Resultado = -1 caso o Grafo esteja vazio.
 * Resultado = 0 caso o Vertice não esteja no Grafo.
 * Resultado = 1 caso remova o Vertice com sucesso.
 */
Vertice* RemoverVertice(Vertice* grafo, Vertice* v, int* resultado) {
	if (grafo == NULL) {
		*resultado = -1;
		return grafo;
	}
	int i = ProcuraVertice(grafo, v);
	if (i == 0) {
		*resultado = 0;
		return grafo;
	}
	else if (i == 1) {
		Vertice* aux = grafo;
		Vertice* anterior = grafo;
		//Caso em que o Vértice removido é o primeiro elemento da lista de Vértices do Grafo
		if (ComparaVertices(aux, v) == 1) {
			grafo = aux->nextVertice;
			free(aux);
			*resultado = 1;
			return grafo;
		}

		//Caso em que o Vértice removido está no meio ou no fim
		aux = aux->nextVertice;
		while (aux != NULL) {
			if (ComparaVertices(aux, v) == 1) {
				anterior->nextVertice = aux->nextVertice;
				free(aux);
				*resultado = 1;
				return grafo;
			}
			else {
				anterior = anterior->nextVertice;
				aux = aux->nextVertice;
			}
		}
	}
}

//DONE (TESTAR)
/**
 * Função que verifica se um Vertice está presente num Grafo.
 * 
 * Retorna -1 caso o Grafo esteja vazio.
 * Retorna 0 caso o Vertice não esteja no Grafo.
 * Retorna 1 caso o Vertice esteja no Grafo.
 */
int ProcuraVertice(Vertice* grafo, Vertice* v) {
	if (grafo == NULL) {
		return -1;
	}
	Vertice* aux = grafo;
	while (aux != NULL) {
		if (ComparaVertices(aux, v) == 1) {
			return 1;
		}
		aux = aux->nextVertice;
	}
	return 0;
}

//DONE (TESTAR)
/**
 * Função que verifica se dois Vertices são iguais.
 * 
 * Retorna 0 caso os Vertices sejam Diferentes.
 * Retorna 1 caso os Vertices sejam Iguais.
 */
int ComparaVertices(Vertice* v1, Vertice* v2) {
	if ((strcmp(v1->cidade, v2->cidade) == 0) &&
		(v1->codigo == v2->codigo)
		) {
		return 1;
	}
	else {
		return 0;
	}
}

//DONE (TESTAR)
/**
 * Função que remove um Adjacente da lista de Adjacentes recebida, se estiver presente na mesma.
 * 
 * Retorna a lista de Adjacentes sem o Adjacente, caso o consiga remover.
 * 
 * Resultado = -1 caso a lista esteja vazia.
 * Resultado = 0 caso o Adjacente não esteja na lista.
 * Resultado = 1 caso remova o Adjacente com sucesso.
 */
Adjacente* RemoverAdjacente(Adjacente* listaAdjs, Adjacente* adjRemovido, int* resultado) {
	if (listaAdjs == NULL) {
		*resultado = -1;
		return listaAdjs;
	}
	int i = ProcuraAdjacente(listaAdjs, adjRemovido);
	if (i == 0) {
		*resultado = 0;
		return listaAdjs;
	}
	else if (i == 1) {
		Adjacente* aux = listaAdjs;
		Adjacente* anterior = listaAdjs;
		//Caso em que o Adjacente removido é o primeiro elemento da lista.
		if (ComparaAdjacentes(aux, adjRemovido) == 1) {
			listaAdjs = aux->nextAdj;
			free(aux);
			*resultado = 1;
			return listaAdjs;
		}

		//Caso em que o Adjacente removido está no meio ou no fim.
		aux = aux->nextAdj;
		while (aux != NULL) {
			if (ComparaAdjacentes(aux, adjRemovido) == 1) {
				anterior->nextAdj = aux->nextAdj;
				free(aux);
				*resultado = 1;
				return listaAdjs;
			}
			else {
				anterior = anterior->nextAdj;
				aux = aux->nextAdj;
			}
		}
	}
}

//DONE (TESTAR)
/**
 * Função que verifica se um Adjacente está presente numa lista de Adjacentes.
 * 
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso o Adjacente não esteja na lista.
 * Retorna 1 caso o Adjacente esteja na lista.
 */
int ProcuraAdjacente(Adjacente* listaAdjs, Adjacente* adj) {
	if (listaAdjs == NULL) {
		return -1;
	}
	Adjacente* aux = listaAdjs;
	while (aux != NULL) {
		if (ComparaAdjacentes(aux, adj) == 1) {
			return 1;
		}
		aux = aux->nextAdj;
	}
	return 0;
}

//DONE (TESTAR)
/**
 * Função que verifica se dois Adjacentes são iguais.
 * 
 * Retorna 0 caso os Adjacentes sejam Diferentes.
 * Retorna 1 caso os Adjacentes sejam Iguais.
 */
int ComparaAdjacentes(Adjacente* a1, Adjacente* a2) {
	if ((a1->codigoVertice == a2->codigoVertice) &&
		(a1->codigoAdj == a1->codigoAdj) &&
		(a1->distancia == a2->distancia)
		) {
		return 1;
	}
	else {
		return 0;
	}
}

//DONE (TESTAR)
/**
 * Função que destroi um Grafo.
 * 
 * Retorna 0 caso o Grafo esteja vazio.
 * Retorna 1 caso consiga destruir o Grafo.
 */
int DestroiGrafo(Vertice* grafo) {
	if (grafo == NULL) {
		return 0;
	}
	Vertice* aux = grafo;
	Vertice* anterior = grafo;
	int i;
	if (aux->nextVertice != NULL) {
		aux = aux->nextVertice;
		i = DestroiAdjacencias(anterior->adjs);
		grafo = RemoverVertice(grafo, anterior, &i);
		anterior = grafo;
	}
	else if (aux == NULL) {
		i = DestroiAdjacencias(aux->adjs);
		grafo = RemoverVertice(grafo, aux, &i);
	}
	return 1;
}

//DONE (TESTAR)
/**
 * Função que destroi uma lista de Adjacencias.
 * 
 * Retorna 0 caso a lista esteja vazia.
 * Retorna 1 caso consiga destruir a lista.
 */
int DestroiAdjacencias(Adjacente* adjs) {
	if (adjs == NULL) {
		return 0;
	}
	Adjacente* aux = adjs;
	Adjacente* anterior = adjs;
	int i;
	if (aux->nextAdj != NULL) {
		aux = aux->nextAdj;
		adjs = RemoverAdjacente(adjs, anterior, &i);
		anterior = adjs;
	}
	else if (aux->nextAdj == NULL) {
		adjs = RemoverAdjacente(adjs, aux, &i);
	}
	return 1;
}

#pragma region GUARDAR

//DONE (TESTAR)
/**
 * Função que guarda um Grafo em ficheiros de textos.
 * 
 * Retorna -1 caso o Grafo esteja vazio.
 * Retorna 0 caso não consiga abrir algum ficheiro.
 * Retorna 1 caso consiga gravar o Grafo com sucesso.
 */
int SaveGrafo(Vertice* grafo, char* fileName) {
	if (grafo == NULL) {
		return -1;
	}
	int i = SaveVertices(grafo, fileName);
	int j;
	char file[N]; 
	Vertice* aux = grafo;
	if (i == 0) {
		return 0;
	}
	else if (i == 1) {
		while (aux != NULL) {
			strcpy(file, aux->cidade);
			j = SaveAdjacencias(aux->adjs, file);
			if (j == 0) {
				return 0;
			}
			else if (j == 1) {
				aux = aux->nextVertice;
			}
		}
	}
	return 1;
}

/**
 * Função que guarda um Grafo em ficheiro Binário.
 * 
 * Retorna -1 caso o Grafo esteja vazio.
 * Retorna 0 caso não consiga abrir algum ficheiro.
 * Retorna 1 caso consiga gravar o Grafo com sucesso.
 */
int SaveGrafoBin(Vertice* grafo, char* fileName) {
	if (grafo == NULL) {
		return -1;
	}
	int i = SaveVerticesBin(grafo, fileName);
	int j;
	char fileBin[N];
	Vertice* aux = grafo;
	if (i == 0) {
		return 0;
	}
	else if (i == 1) {
		while (aux != NULL) {
			strcpy(fileBin, aux->cidade);
			strcat(fileBin, "Bin");
			j = SaveAdjacenciasBin(aux->adjs, fileBin);
			if (j == 0) {
				return 0;
			}
			else if (j == 1) {
				aux = aux->nextVertice;
			}
		}
	}
	return 1;
}

//DONE (TESTAR)
/**
 * Função que guarda os Vertices de um Grafo em ficheiro de texto. (Não é necessário)
 * 
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso não consiga abrir o ficheiro.
 * Retorna 1 caso consiga guardar o grafo com sucesso.
 */
int SaveVertices(Vertice* grafo, char* fileName) {
	if (grafo == NULL) {
		return -1;
	}
	Vertice* aux = grafo;
	FILE *fVertices;
	fVertices = fopen(fileName, "w");
	if (fVertices == NULL) {
		return 0;
	}
	while (aux != NULL) {
		fprintf(fVertices, "%d;%s\n", aux->codigo, aux->cidade);
		aux = aux->nextVertice;
	}
	fclose(fVertices);
	return 1;
}

//DONE (TESTAR)
/**
 * Função que guarda os Vertices de um Grafo em ficheiro Binário.
 * 
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso não consiga abrir o ficheiro.
 * Retorna 1 caso consiga guardar a lista com sucesso.
 */
int SaveVerticesBin(Vertice* grafo, char* fileName) {
	if (grafo == NULL) {
		return -1;
	}
	Vertice* aux = grafo;
	VerticeFile* v = NULL;
	FILE* fVerticesBin;
	fVerticesBin = fopen(fileName, "wb");
	if (fVerticesBin == NULL) {
		return 0;
	}
	while (aux != NULL) {
		v->codigo = aux->codigo;
		strcpy(v->cidade, aux->cidade);
		fwrite(v, 1, sizeof(VerticeFile), fVerticesBin);
		aux = aux->nextVertice;
	}
	fclose(fVerticesBin);
	return 1;
}

//DONE (TESTAR)
/**
 * Função que guarda uma lista de Adjacencias em ficheiro de texto.
 * 
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso não consiga abrir o ficheiro.
 * Retorna 1 caso consiga guardar a lista com sucesso.
 */
int SaveAdjacencias(Adjacente* adjs, char* fileName) {
	if (adjs == NULL) {
		return -1;
	}
	Adjacente* aux = adjs;
	FILE* fAjds;
	fAjds = fopen(fileName, "w");
	if (fAjds == NULL) {
		return 0;
	}
	while (aux != NULL) {
		fprintf(fAjds, "%d;%d;%d\n", aux->codigoVertice, aux->codigoAdj, aux->distancia);
		aux = aux->nextAdj;
	}
	fclose(fAjds);
	return 1;
}

//DONE (TESTAR)
/**
 * Função que guarda uma lista de Adjacentes em ficheiro Binário.
 * 
 * Retorna -1 caso a lista esteja vazia.
 * Retorna 0 caso não consiga abrir o ficheiro.
 * Retorna 1 caso consiga guardar a lista com sucesso.
 */
int SaveAdjacenciasBin(Adjacente* adjs, char* fileName) {
	if (adjs == NULL) {
		return -1;
	}
	Adjacente* aux = adjs;
	AdjFile* a = NULL;
	FILE* fAdjBin;
	fAdjBin = fopen(fileName, "wb");
	if (fAdjBin == NULL) {
		return 0;
	}
	while (aux != NULL) {
		a->codigoVertice = aux->codigoVertice;
		a->codigoAdj = aux->codigoAdj;
		a->distancia = aux->distancia;
		fwrite(a, 1, sizeof(AdjFile), fAdjBin);
		aux = aux->nextAdj;
	}
	fclose(fAdjBin);
	return 1;
}

#pragma endregion

#pragma region LER

//DONE (TESTAR)
/**
 * Função que lê um Grafo a partir de ficheiros de textos.
 * 
 * Retorna o Grafo, caso o consiga ler.
 * 
 * Resultado = 0 caso não consiga abrir algum ficheiro.
 * Resultado = 1 caso consiga ler o Grafo com sucesso.
 */
Vertice* LerGrafo(char* fileName, int* resultado) {
	Vertice* grafo = NULL;
	Vertice* aux;
	int i, j;
	grafo = LerVertices(fileName, &i);
	if (i == 0) {
		*resultado = 0;
		return NULL;
	}
	else if (i == 1) {
		aux = grafo;
		while (aux != NULL) {
			aux->adjs = LerAdjacencias(aux->cidade, &j);
			if (j == 0) {
				*resultado = 0;
				return NULL;
			}
			else if (j == 1) {
				aux = aux->nextVertice;
			}
		}
	}
	*resultado = 1;
	return grafo;
}

//DONE (TESTAR)
/**
 * Função que lê um Grafo a partir de ficheiros Binários.
 * 
 * Retorna o Grafo, caso o consiga ler
 */
Vertice* LerGrafoBin(char* fileName, int* resultado) {
	Vertice* grafo = NULL;
	Vertice* aux;
	int i, j;
	char fileBin[N];
	grafo = LerVerticesBin(fileName, &i);
	if (i == 0) {
		*resultado = 0;
		return NULL;
	}
	else if (i == 1) {
		aux = grafo;
		while (aux != NULL) {
			strcpy(fileBin, aux->cidade);
			strcat(fileBin, "Bin");
			aux->adjs = LerAdjacenciasBin(fileBin, &j);
			if (j == 0) {
				*resultado = 0;
				return NULL;
			}
			else if (j == 1) {
				aux = aux->nextVertice;
			}
		}
	}
	*resultado = 1;
	return grafo;
}

//DONE (TESTAR)
/**
 * Função que lê uma lista de Vertices a partir de um ficheiro de texto.
 * 
 * Retorna a lista de Vertices, caso a consiga ler.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista com sucesso.
 */
Vertice* LerVertices(char* fileName, int* resultado) {
	Vertice* head = NULL;
	FILE* fVertices;
	int i;
	fVertices = fopen(fileName, "r");
	if (fVertices == NULL) {
		*resultado = 0;
		return 0;
	}
	Vertice aux;
	while (!feof(fVertices)) {
		fscanf(fVertices, "%d;%s\n", &aux.codigo, aux.cidade);
		head = InserirVertice(head, &aux, &i);
	}
	fclose(fVertices);
	*resultado = 1;
	return head;
}

//DONE (TESTAR)
/**
 * Função que lê uma lista de Vertices a partir de um ficheiro Binário.
 * 
 * Retorna a lista de Vertices, caso a consiga ler.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista com sucesso.
 */
Vertice* LerVerticesBin(char* fileName, int* resultado) {
	Vertice* head = NULL;
	FILE* fVerticesBin;
	int i;
	fVerticesBin = fopen(fileName, "rb");
	if (fVerticesBin == NULL) {
		*resultado = 0;
		return 0;
	}
	VerticeFile aux1;
	Vertice* aux2 = NULL;
	while (fread(&aux1, 1, sizeof(VerticeFile), fVerticesBin)) {
		strcpy(aux2->cidade, aux1.cidade);
		aux2->codigo = aux1.codigo;
		head = InserirVertice(head, aux2, &i);
	}
	fclose(fVerticesBin);
	*resultado = 1;
	return head;

}

//DONE (TESTAR)
/**
 * Função que lê uma lista de Adjacencias a partir de um ficheiro de texto.
 * 
 * Retorna a lista de Adjacencias, caso a consiga ler.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso consiga ler a lista com sucesso.
 */
Adjacente* LerAdjacencias(char* fileName, int* resultado) {
	Adjacente* head = NULL;
	FILE* fAdjs;
	int i;
	fAdjs = fopen(fileName, "r");
	if (fAdjs == NULL) {
		*resultado = 0;
		return 0;
	}
	Adjacente aux;
	while (!feof(fAdjs)) {
		fscanf(fAdjs, "%d;%d;%d\n", &aux.codigoVertice, &aux.codigoAdj, &aux.distancia);
		head = InserirAdjacente(head, &aux, &i);
	}
	fclose(fAdjs);
	*resultado = 1;
	return head;
}

//DONE (TESTAR)
/**
 * Função que lê uma lista de Adjacencias a partir de um ficheiro Binário.
 * 
 * Retorna a lista de Adjacencias, caso a consiga ler.
 * 
 * Resultado = 0 caso não consiga abrir o ficheiro.
 * Resultado = 1 caso leia a lista com sucesso.
 */
Adjacente* LerAdjacenciasBin(char* fileName, int* resultado) {
	Adjacente* head = NULL;
	FILE* fAdjsBin;
	int i;
	fAdjsBin = fopen(fileName, "rb");
	if (fAdjsBin == NULL) {
		*resultado = 0;
		return 0;
	}
	AdjFile aux1;
	Adjacente* aux2 = NULL;
	while (fread(&aux1, 1, sizeof(AdjFile), fAdjsBin)) {
		aux2->codigoVertice = aux1.codigoVertice;
		aux2->codigoAdj = aux1.codigoAdj;
		aux2->distancia = aux1.distancia;
		head = InserirAdjacente(head, aux2, &i);
	}
	fclose(fAdjsBin);
	*resultado = 1;
	return head;
}

#pragma endregion

//DONE (TESTAR)
/**
 * Função que imprime todos os Vertices do Grafo e as suas Adjacencias.
 * 
 * Retorna 0 caso o Grafo esteja vazio.
 * Retorna 1 caso imprima o Grafo com sucesso.
 */
int MostraGrafo(Vertice* grafo) {
	if (grafo == NULL) {
		return 0;
	}
	Vertice* aux = grafo;
	int i = 1;
	int j;
	printf("Grafo:\n");
	printf("\n");
	while (aux != NULL) {
		printf("----------------------------\n");
		printf("Vertice %d:\n", i);
		printf("   Codigo: %d.\n", aux->codigo);
		printf("   Cidade: %s.\n", aux->cidade);
		printf("\n");
		printf("Adjacencias:\n");
		j = MostraAdjs(aux->adjs);
		if (j == 0) {
			printf("Sem Adjacencias registadas.\n");
		}
		printf("\n");
		printf("----------------------------\n");
		i++;
		aux = aux->nextVertice;
	}
	return 1;
}

//DONE (TESTAR)
/**
 * Função que imprime as Adjacencias de um Vertice.
 * 
 * Retorna 0 caso a lista de Adjacencias esteja vazia.
 * Retorna 1 caso imprima a lista de Adjacencias com sucesso.
 */
int MostraAdjs(Adjacente* adjs){
	if (adjs == NULL) {
		return 0;
	}
	Adjacente* aux = adjs;
	int i = 1;
	while (aux != NULL) {
		printf("\n");
		printf("Adjacente %d:\n", i);
		printf("   Codigo: %d.\n", aux->codigoAdj);
		printf("   Distancia: %d.\n", aux->distancia);
		i++;
		aux = aux->nextAdj;
	}
	return 1;
}
