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

/***********************************************
destroiGenTalhoes - Liberta a memoria ocupada pelas instancias da estrutura generica talhoes.
Parametros:
	t - endereco do talhao a destruir
Retorno:
Pre-condicoes: t != NULL
***********************************************/
void destroiGenTalhoes(void * t);

/***********************************************
daEscavadoTalhao - Consulta se o talhao associado, ja foi escavado.
Parametros: 
	t - talhao
Retorno: 1- caso tenha sido escavado; 0- caso contrario
Pre-condicoes: t != NULL
***********************************************/
int daEscavadoTalhao(talhao t);

/***********************************************
daValorTalhao - Consulta o valor da estrutura talhao associada.
Parametros: 
	t - talhao
Retorno: valor do talhao
Pre-condicoes: t != NULL
***********************************************/
int daValorTalhao(talhao t);

/***********************************************
alteraValorTalhao - Incrementa o valor do talhao.
Parametros:
	t - talhao
	valor - valor a incrementar
Retorno: valor do talhao
Pre-condicoes: t != NULL
***********************************************/
void alteraValorTalhao(talhao t, int valor);

/***********************************************
alteraEscavadoTalhao - Incrementa o numero de escavacoes do talhao.
Parametros:
	t - talhao
	escavado - valor a incrementar
Retorno: numero de escavacoes do talhao
Pre-condicoes: t != NULL
***********************************************/
void alteraEscavadoTalhao(talhao t, int Escavado);
#endif