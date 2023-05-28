/*****************************************************************//**
 * \file   Paths.c
 * \brief  Implementação de Funções que utilizem Paths ou Alugueres
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

#pragma region ALUGUERES

 /**
  * Função que Cria e Retorna um Aluguer.
  * 
  * Resultado = -1 caso o Meio não esteja disponivel.
  * Resultado = 0 caso a data de fim seja anterior à data de inicio.
  * Resultado = 1 caso crie o Aluguer com sucesso.
  */
Aluguer* CriaAluguer(Cliente* c, Meio* m, Data* inicio, Data* fim, int* distancia, int *resultado) {
	if (m->disponivel == false) {
		*resultado = -1;
		return NULL;
	}
	int i = TempoTotal(*inicio, *fim);
	if (i < 0) {
		*resultado = 0;
		return NULL;
	}
	Aluguer* a;
	a->c = *c;
	a->m = *m;
	a->dataInicio = *inicio;
	a->dataFim = *fim;
	a->distPercorrida = *distancia;
	return a;
}

 /**
  * Fução que calcula e retorna o custo total de um aluguer.
  */
int CustoAluguer(Aluguer* a) {
	int i, custo = 0;
	custo += TempoTotal(a->dataInicio, a->dataFim, &i) + a->distPercorrida;
	return custo;
}

/**
 * Função que calcula e retorna o total de minutos entre duas Datas.
 */
int TempoTotal(Data inicio, Data fim) {
	int minutos = 0;
	minutos += (fim.ano - inicio.ano) * 525948 + (fim.mes - inicio.mes) * 43200 + (fim.dia - inicio.dia) * 1440
		+ (fim.h.hora - inicio.h.minuto) * 60 + (fim.h.minuto - inicio.h.minuto);
	return minutos;
}

/**
 * Função que insere um Aluguer numa Lista de Alugueres.
 * 
 * Retorna a lista com o Aluguer, inserindo por ordem crescente de codigo de Alugueres.
 * 
 * Resultado = 0 caso o Aluguer recebido já esteja na lista.
 * Resultado = 1 caso insira com sucesso.
 */
ListaAlugueres* InserirAluguer(ListaAlugueres* head, Aluguer* a, int* resultado) {
	if (ProcuraAluguer(head, a) == 1) {
		*resultado = 0;
		return head;
	}
	ListaAlugueres* novo = (ListaAlugueres*)malloc(sizeof(ListaAlugueres));
	novo->a = a;
	novo->nextAluguer = NULL;
	ListaAlugueres* aux = head;
	ListaAlugueres* anterior = head;
	if (head == NULL) {
		head = novo;
		*resultado = 1;
		return head;
	}
	else {
		//INICIO
		if (head->a->codigoAluguer > a->codigoAluguer) {
			novo->nextAluguer = head;
			head = novo;
			*resultado = 1;
			return head;
		}
		else {
			aux = aux->nextAluguer;
			while (aux != NULL) {
				if (aux->a->codigoAluguer > novo->a->codigoAluguer) {
					novo->nextAluguer = aux;
					anterior->nextAluguer = novo;
					*resultado = 1;
					return head;
				}
				anterior = aux;
				aux = aux->nextAluguer;
			}
			anterior->nextAluguer = novo;
		}
	}
	*resultado = 1;
	return head;
}

/**
 * Função que verifica se um Aluguer está presente numa Lista de Alugueres.
 * 
 * Retorna -1 caso a Lista esteja vazia.
 * Retorna 0 caso o Aluguer não esteja na Lista.
 * Retorna 1 caso o Aluger esteja na Lista.
 */
int ProcuraAluguer(ListaAlugueres* head, Aluguer* a) {
	if (head == NULL) {
		return -1;
	}
	ListaAlugueres* aux = head;
	int i;
	while (aux != NULL) {
		i = ComparaAlugueres(aux->a, a);
		if (i == 1) {
			return 1;
		}
		else {
			aux = aux->nextAluguer;
		}
	}
	return 0;
}

/**
 * Função que verifica se dois Alugueres são iguais.
 * 
 * Retorna 0 se os Alugueres forem diferentes.
 * Retorna 1 se os Alugueres forem iguais.
 */
int ComparaAlugueres(Aluguer* a1, Aluguer* a2) {
	if (a1->codigoAluguer == a2->codigoAluguer) {
		return 1;
	}
	else {
		return 0;
	}
}

#pragma endregion

#pragma region PATHS

/**
 * Função que retorna uma lista de Meios disponiveis num determinado raio, a partir de um Vertice recebido.
 * 
 * Resultado = -3 caso o Grafo esteja vazio.
 * Resultado = -2 caso a Lista de Meios esteja vazia.
 * Resultado = -1 caso o Vertice não pertença ao Grafo.
 * Resultado = 0 caso não existam Meios à distancia pretendida.
 * Resultado = 1 caso existam Meios à distancia pretendida.
 * 
 * Esta função poderia ser utilizada tanto no problema de um cliente pretender encontrar um meio a uma determinada distnacia, como tambem
 * no problema da recolha de meios por parte do camião.
 * 
 * Seria ainda necessário implementar corretamente o Algoritmo de Dijkstra na função BesthPath
 */
ListaMeios* MeiosDisponiveis(Vertice* grafo, Vertice* v, ListaMeios* meios, int distancia, int* resultado) {
	if (grafo == NULL) {
		*resultado = -3;
		return NULL;
	}
	if (meios == NULL) {
		*resultado = -2;
		return NULL;
	}
	int i = ProcuraVertice(grafo, v);
	if (i != 1) {
		*resultado = -1;
		return NULL;
	}
	ListaMeios* lista = NULL;
	ListaMeios* auxMeios = meios;
	Vertice* auxGrafo = grafo;
	Vertice* verticesProximos;
	Path* auxPath;
	int j, k;
	while (auxGrafo != NULL) {
		auxPath = BestPath(grafo, v, auxGrafo, &j);
		if (j == 1) {
			if (auxPath->distanciaPercorrida <= distancia) {
				while (auxMeios != NULL) {
					if (auxMeios->meio->geocodigo == auxGrafo->codigo) {
						lista = InserirMeios(lista, auxMeios->meio, &k);
					}
					else {
						auxMeios = auxMeios->nextMeio;
					}
				}
			}
		}
		else {
			auxGrafo = auxGrafo->nextVertice;
		}
	}
	if (lista == NULL) {
		*resultado = 0;
		return lista;
	}
	else {
		*resultado = 1;
		return lista;
	}
}

//Não consegui implementar o Algoritmo de Dijkstra
/**
 * Função que retorna o melhor caminho entre dois Vertices de um Grafo.
 * 
 * Resultado = -2 caso o Grafo esteja vazio.
 * Resultado = -1 caso pelo menos um dos Vertices não esteja presente no Grafo.
 * Resultado = 0 caso não exista um caminho válido entre os Vertices.
 * Resultado = 1 caso consiga retornar um caminho válido entre os Vertices.
 */
Path* BestPath(Vertice* grafo, Vertice* v1, Vertice* v2, int* resultado) {
	if (grafo == NULL) {
		*resultado = -2;
		return NULL;
	}
	int i = ProcuraVertice(grafo, v1);
	int j = ProcuraVertice(grafo, v2);
	if (i != 1 || j != 1) {
		*resultado = -1;
		return NULL;
	}
	Path* melhor = NULL;

	//Algoritmo de Dijkstra

	//Se não exister caminho
	//*resultado = 0;

	//Se existir caminho
	*resultado = 1;

	return melhor;
}

#pragma endregion
