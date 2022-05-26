/*
 * Talhoes.h
 */

#ifndef talhoes_h
#define talhoes_h

//TAD
typedef struct _talhao * talhao; 

//funçoes

/***********************************************
criaTalão - Criacao da instancia da estrutura associada a um talhao.
Parametros:
	n - inteiro do numero de talhoes
Retorno: apontador para a  instancia criada
Pre-condicoes:  n < 0
***********************************************/
talhao criaTalhao(int n);

/***********************************************
criaIterador - Destroi a instancia da estrutura associada.
Parametros:
	t - Estrutura do tipo talhao
Retorno: 
Pre-condicoes:  t != NULL
***********************************************/
void destroiTalhao(talhao t);

void destroiGenTalhoes(void * t);

int valorTalhao(talhao t);

int daEscavadoTalhao(talhao t);

int daValorTalhao(talhao t);

void alteraValorTalhao(talhao t, int valor);

void alteraEscavadoTalhao(talhao t, int Escavado);
#endif