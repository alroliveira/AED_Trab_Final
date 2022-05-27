/*
 * Arqueologo.c
 */
#ifndef _H_ARQUEOLOGO
#define _H_ARQUEOLOGO

/* Tipo de dados: Arqueologo */
typedef struct _arqueologo * arqueologo;
typedef struct _terreno * terreno;

/* Prototipos das funcoes associadas ao Arqueologo */

/***********************************************
criarArqueologo - Criacao da instancia da estrutura Arqueologo.
Parametros:
	nome - nome do arqueologo
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
arqueologo criarArqueologo(char *nome); 

/***********************************************
calcularMeritoArqueologo - Calcula o merito do arqueologo.
Parametros:
	a - arqueologo
Retorno: merito do arqueologo
Pre-condicoes: a != NULL
***********************************************/
int calcularMeritoArqueologo(arqueologo a);

/***********************************************
daNomeArqueologo - Consulta o nome da estrutura associada ao Arqueologo
Parametros: 
	a - arqueologo
Retorno: nome do arqueologo
Pre-condicoes: a != NULL
***********************************************/
char *daNomeArqueologo(arqueologo a);

/***********************************************
destroiArqueologo - Liberta a memoria ocupada pela instancia arqueologo.
Parametros:
	a - arqueologo a destruir
Retorno:
Pre-condicoes: a != NULL
***********************************************/
void destroiArqueologo(arqueologo a);

/***********************************************
destroiGenArqueologo - Liberta a memoria ocupada pelas instancias da estrutura generica arqueologos.
Parametros:
	a - endereco do arqueologo a destruir
Retorno:
Pre-condicoes: a != NULL
***********************************************/
void destroiGenArqueologo(void * a);

/***********************************************
daPosArqueologo - Consulta a posicao da estrutura associada ao Arqueologo
Parametros: 
	a - arqueologo
Retorno: posicao do arqueologo
Pre-condicoes: a != NULL
***********************************************/
int daPosArqueologo(arqueologo a);

/***********************************************
daLCArqueologo - Consulta as linhas e colunas referentes a posicao do Arqueologo
Parametros: 
	a - arqueologo
	T - terreno
	controlo - variavel auxiliar para obter as linhas ou colunas
Retorno: para controlo==1 retorna linhas
		 para controlo==0 retorna colunas
Pre-condicoes: a != NULL && T!=NULL
***********************************************/
int daLCArqueologo(arqueologo a, terreno T, int controlo);

/***********************************************
daPenalizacaoArqueologo - Consulta a penalizacao associada ao Arqueologo
Parametros: 
	a - arqueologo
Retorno: penalizacao do arqueologo
Pre-condicoes: a != NULL
***********************************************/
int daPenalizacaoArqueologo(arqueologo a);

/***********************************************
incrementaTesouro - Incrementa o tesouro do arqueologo.
Parametros:
	a - arqueologo
Retorno: merito do arqueologo
Pre-condicoes: a != NULL
***********************************************/
void incrementaTesouro(arqueologo a, int valor);

/***********************************************
incrementaTesouro - Incrementa o merito do arqueologo.
Parametros:
	a - arqueologo
	merito - valor a incrementar
Retorno: merito do arqueologo
Pre-condicoes: a != NULL
***********************************************/
void alteraMeritoArqueologo(arqueologo a, int merito);

#endif /* ARQUEOLOGO_H_ */