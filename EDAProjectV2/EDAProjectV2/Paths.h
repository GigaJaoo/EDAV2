/*****************************************************************//**
 * \file   Paths.h
 * \brief  Assinaturas de Fun��es que utilizem Paths
 * 
 * \author Jo�o Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include <string.h>    // strings
#include <stdlib.h>    // malloc
#include <stdio.h>     // NULL
#include <stdbool.h>   // bools
#include "Clientes.h"  // Clientes
#include "Meios.h"     // Meios

/**
 * Estrutura de uma Hora.
 */
typedef struct hora {
	int hora;
	int minuto;
} Hora;

/**
 * Estrutura de uma Data.
 */
typedef struct data {
	int dia;
	int mes;
	int ano;
	Hora h;
} Data;

/**
 * Estrutura de um Aluguer.
 */
typedef struct aluguer {
	int codigoAluguer;
	Cliente c;
	Meio m;
	Data dataInicio;
	Data dataFim;
	int distPercorrida;
} Aluguer;

/**
 * Estrutura de um Nodo para uma Lista de Alugueres.
 */
typedef struct listaAlugueres {
	Aluguer a;
	struct listaAlugueres* nextAluguer;
} ListaAlugueres;

/**
 * Fu��o que calcula o custo total de um aluguer.
 */
int CustoAluguer(Aluguer* a);

/**
 * Fun��o que calcula o n�mero de minutos entre duas Datas.
 */
int TempoTotal(Data inicio, Data fim);




