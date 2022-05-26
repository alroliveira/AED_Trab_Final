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
criarArqueologo - Criacao da instancia da estrutura associada ao Arqueologo.
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
destroiArqueologo - Liberta a memoria ocupada pela instancia da estrutura associada ao arqueologo.
Parametros:
	a - arqueologo a destruir
Retorno:
Pre-condicoes: a != NULL
***********************************************/
void destroiArqueologo(arqueologo a);

void destroiGenArqueologo(void * a);

int daPosArqueologo(arqueologo a);

int daLCArqueologo(arqueologo a, terreno T, int controlo);

int daPenalizacaoArqueologo(arqueologo a);

void incrementaTesouro(arqueologo a, int valor);

void alteraMeritoArqueologo(arqueologo a, int merito);

#endif /* ARQUEOLOGO_H_ */