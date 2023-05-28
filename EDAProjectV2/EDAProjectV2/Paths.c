/*****************************************************************//**
 * \file   Paths.c
 * \brief  Implementação de Funções que utilizem Paths
 * 
 * \author João Pereira - a24254
 * \date   May 2023
 *********************************************************************/

#include "Assinaturas.h"

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
