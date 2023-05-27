/*****************************************************************//**
 * \file   Programa.c
 * \brief  Programa Principal
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

int main() {
	/*
	//Inicialização da Lista de Clientes
	ListaClientes* inicioClientes = NULL;

	Cliente c1 = { 51, 19, 34.5f, "Joao", "Rua da Ambrosia" };
	Cliente c2 = { 28, 45, 0.4f, "Abel", "Avenida dos Astros" };
	Cliente c3 = { 180, 23, 473, "Vitor", "Riacho dos Caniscos" };
	Cliente c4 = { 11, 47, 126.7f, "Lima", "Casa de Esposende" };
	Cliente c5 = { 51, 19, 34.5f, "Joao", "Rua da Ambrosia" };
	Cliente c6 = { 34, 56, 32.7f, "Gaspar", "Anacleto Av" };

	int a = -3, b = -3, c = -3, d = -3;

	//Teste do InserirClientes
	printf("Teste do InserirClientes\n");
	inicioClientes = InserirClientes(inicioClientes, &c1, &a);
	inicioClientes = InserirClientes(inicioClientes, &c2, &b);
	inicioClientes = InserirClientes(inicioClientes, &c3, &c);
	inicioClientes = InserirClientes(inicioClientes, &c4, &d);
	
	printf("\nForam imprimidos %d clientes.\n", ImprimirClientes(inicioClientes));

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);

	//Teste do ComparaClientes
	printf("\n");
	printf("Teste do ComparaClientes\n");
	printf("%d\n", ComparaClientes(&c1, &c5));
	printf("%d\n", ComparaClientes(&c1, &c2));

	//Teste do PresenteListaClientes
	printf("\nTeste do PresenteListaClientes\n");
	printf("%d\n", PresenteListaClientes(inicioClientes, &c1));
	printf("%d\n", PresenteListaClientes(inicioClientes, &c6));

	//Teste do RemoverClientes
	printf("\nTeste do RemoverClientes\n");
	int r1, r2;
	inicioClientes = RemoverClientes(inicioClientes, &c6, &r1);
	inicioClientes = RemoverClientes(inicioClientes, &c2, &r2);
	printf("%d\n", r1);
	printf("%d\n", r2);

	printf("\nForam imprimidos %d clientes.\n", ImprimirClientes(inicioClientes));
	*/
	
	//Testes Funções Grafos
	printf("Testes das funcoes dos Grafos\n");
	Vertice* grafo1 = CriaGrafo();
	int res;

	//Testes Vertices
	int *cod1 = 13;
	char cidade1[N];
	strcpy(cidade1, "Barcelos");
	Vertice* v1 = CriaVertice(cod1, cidade1);

	int *cod2 = 27;
	char cidade2[N];
	strcpy(cidade2, "Porto");
	Vertice* v2 = CriaVertice(cod2, cidade2);

	int* cod3 = 5;
	char cidade3[N];
	strcpy(cidade3, "Lisboa");
	Vertice* v3 = CriaVertice(cod3, cidade3);

	int* cod4 = 49;
	char cidade4[N];
	strcpy(cidade4, "Algarve");
	Vertice* v4 = CriaVertice(cod4, cidade4);

	int* cod5 = 31;
	char cidade5[N];
	strcpy(cidade5, "Castelo Branco");
	Vertice* v5 = CriaVertice(cod5, cidade5);

	printf("\n");
	printf("Resultados da Insercao dos Vertices no Grafo:\n");

	grafo1 = InserirVertice(grafo1, v1, &res);
	printf("%d.\n", res);
	grafo1 = InserirVertice(grafo1, v2, &res);
	printf("%d.\n", res);
	grafo1 = InserirVertice(grafo1, v1, &res);
	printf("%d.\n", res);
	grafo1 = InserirVertice(grafo1, v3, &res);
	printf("%d.\n", res);
	grafo1 = InserirVertice(grafo1, v4, &res);
	printf("%d.\n", res);
	grafo1 = InserirVertice(grafo1, v5, &res);
	printf("%d.\n", res);
	printf("\n");

	//MostraGrafo(grafo1);
	//printf("\n");

	//Testes Adjacencias
	int* peso1 = 13;
	Adjacente* a1 = CriaAdjacente(cod1, cod4, peso1);
	int* peso2 = 47;
	Adjacente* a2 = CriaAdjacente(cod1, cod5, peso2);
	int* peso3 = 68;
	Adjacente* a3 = CriaAdjacente(cod4, cod3, peso3);
	int* peso4 = 50;
	Adjacente* a4 = CriaAdjacente(cod3, cod4, peso4);
	int* peso5 = 21;
	Adjacente* a5 = CriaAdjacente(cod2, cod1, peso5);
	int* peso6 = 12;
	Adjacente* a6 = CriaAdjacente(cod2, cod5, peso6);

	int* pesoErrado = 152;
	int* codErrado = 83;
	Adjacente* aErrado = CriaAdjacente(codErrado, cod1, pesoErrado);

	printf("Resultados da Insercao de Adjacentes no Grafo:\n");
	grafo1 = InserirAdjEmGrafo(grafo1, a1, &res);
	printf("%d.\n", res);
	grafo1 = InserirAdjEmGrafo(grafo1, a2, &res);
	printf("%d.\n", res);
	grafo1 = InserirAdjEmGrafo(grafo1, a3, &res);
	printf("%d.\n", res);
	grafo1 = InserirAdjEmGrafo(grafo1, a4, &res);
	printf("%d.\n", res);
	grafo1 = InserirAdjEmGrafo(grafo1, a5, &res);
	printf("%d.\n", res);
	grafo1 = InserirAdjEmGrafo(grafo1, a6, &res);
	printf("%d.\n", res);
	grafo1 = InserirAdjEmGrafo(grafo1, aErrado, &res);
	printf("%d.\n", res);
	printf("\n");

	MostraGrafo(grafo1);

	/*
	//Teste das funções de Remoção - WORKING
	printf("\n");
	printf("Teste das funcoes de destruicao.\n");
	grafo1 = RemoverVertice(grafo1, v1, &res);
	printf("%d.\n", res);
	grafo1 = RemoverAdjGrafo(grafo1, a6, &res);
	printf("%d.\n", res);
	printf("\n");

	MostraGrafo(grafo1);

	//Testes das funções de Guardar em ficheiros - ALL WORKING
	printf("\n");
	printf("Testes das Funcoes de Guardar em Ficheiros.\n");
	char fileName[20];
	strcpy(fileName, "Grafo1");
	res = SaveGrafo(grafo1, fileName);
	printf("%d.\n", res);
	char fileNameBin[20];
	strcpy(fileNameBin, "Grafo1Bin");
	res = SaveGrafoBin(grafo1, fileNameBin);
	printf("%d.\n", res);
	printf("\n");

	//Teste da Destruição do Grafo - WORKING
	printf("\n");
	grafo1 = DestroiGrafo(grafo1, &res);
	printf("Destruicao do Grafo - resultado = %d.\n", res);
	printf("\n");

	MostraGrafo(grafo1);

	//Teste das Funções de Leitura de ficheiros binários - WORKING
	printf("\n");
	printf("Teste das Funcoes de Leitura de Ficheiros Binarios.\n");
	grafo1 = LerGrafoBin(grafo1, fileNameBin, &res);
	printf("%d.\n", res);
	printf("\n");
	MostraGrafo(grafo1);

	//Volto a Destruir o Grafo
	printf("\n");
	grafo1 = DestroiGrafo(grafo1, &res);
	printf("Destruicao do Grafo - resultado = %d.\n", res);
	printf("\n");

	MostraGrafo(grafo1);

	//Teste das Funções de Leitura de ficheiros de texto - NOT WORKING
	
	printf("\n");
	printf("Teste das Funcoes de Leitura de Ficheiros de Texto.\n");
	grafo1 = LerGrafo(grafo1, fileName, &res);
	printf("%d.\n", res);
	printf("\n");
	MostraGrafo(grafo1);
	*/
}
