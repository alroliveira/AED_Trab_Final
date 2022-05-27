/*
 * Equipa.h
 */

#ifndef _H_EQUIPA
#define _H_EQUIPA

#include "Arqueologo.h"
#include "sequencia.h"

/* Tipo de dados: Equipa */
typedef struct _equipa * equipa; 

/* Prototipos das funcoes associadas a Equipa */

/***********************************************
criaEquipa - Criacao da instancia da estrutura associada a uma equipa.
Parametros:
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
equipa criaEquipa();

//int calculaClassificacao (equipa e);
//void destroiEquipa(equipa e);
//void destroiGenEquipa(void * e);
//void destroiEquipaEArqueologo(equipa e);
//equipa daArqueologoDaEquipa(equipa e, int pos);

/***********************************************
adicionarArqueologoAEquipa - Criacao da instancia da estrutura associada a um arqueologo pertencente a equipa.
Parametros:
    e - equipa
    nome - nome da equipa
Retorno:
Pre-condicoes: e != NULL
***********************************************/
void adicionarArqueologoAEquipa(equipa e, char *nome);

/***********************************************
iteradorEquipa - Cria e devolve um iterador para a equipa.
Parametros:
	e - equipa
Retorno: iterador da equipa
Pre-condicoes: e != NULL && vaziaSequencia(e)!=1
***********************************************/
iterador iteradorEquipa(equipa e);

/***********************************************
daNomeArqueologo - Consulta o nome da estrutura associada a equipa
Parametros: 
	e - equipa
Retorno: nome da equipa
Pre-condicoes: e != NULL
***********************************************/
char *daNomeEquipa(equipa e);

/***********************************************
daEmJogoEquipa - Consulta se a estrutura associada a equipa se encontra em jogo
Parametros: 
	e - equipa
Retorno: emJogo da equipa
Pre-condicoes: e != NULL
***********************************************/
int daEmJogoEquipa(equipa e);

/***********************************************
alteraEmJogoEquipa - Altera o estado de jogo da equipa.
Parametros:
	e - equipa
	merito - valor a incrementar
Retorno:
Pre-condicoes: e != NULL
***********************************************/
void alteraEmJogoEquipa(equipa e, int emJogo);

/***********************************************
atualizaNumEquipa - Atualiza o numero referente a equipa.
Parametros:
	e - equipa
Retorno:
Pre-condicoes: e != NULL
***********************************************/
void atualizaNumEquipa(equipa e);

//int existeEquipa(equipa e, void *nome);

/***********************************************
existPorNomeEquipa – Indica se existe uma equipa com a nome dado.
Parametros:
	e - equipa
	nome - nome da equipa
Retorno: retorna 1 se existir, e 0, caso contrario
Pre-condicoes: e != NULL && nome != NULL
***********************************************/
int existPorNomeEquipa(equipa e, void *nome);

/***********************************************
daNEquipaPorNomeEquipa – Consulta o numero da equipa com a nome dado.
Parametros:
	e - equipa
	nome - nome da equipa
Retorno: numero referente a equipa
Pre-condicoes: e != NULL && nome != NULL
***********************************************/
int daNEquipaPorNomeEquipa(equipa e, void *nome);

/***********************************************
arqueologoComMaiorMerito - Consulta o arqueologo pretencente a equipa com maior merito.
Parametros:
	e - equipa
Retorno: arqueologo com maior merito
Pre-condicoes: e != NULL && i>0 && vaziaSequencia(e)!=1
***********************************************/
arqueologo arqueologoComMaiorMerito(equipa e);

/***********************************************
alteraNumEquipa - Altera o numero referente a equipa.
Parametros:
	e - equipa
	num - numero desejado referente a equipa
Retorno:
Pre-condicoes: e != NULL
***********************************************/
void alteraNumEquipa (equipa e, int num);

/***********************************************
alteraNomeEquipa - Altera o nome referente a equipa.
Parametros:
	e - equipa
	nome - nome desejado referente a equipa
Retorno:
Pre-condicoes: e != NULL
***********************************************/
void alteraNomeEquipa (equipa e, char *nome);

/***********************************************
daEquipa - Consulta a instancia da estrutura associada a equipa com o referente nome.
Parametros:
	e - equipa
	nome - nome da equipa
Retorno: endereco da equipa
Pre-condicoes: e != NULL && tamanhoSequencia(e)
***********************************************/
equipa daEquipa(equipa e, char * nome);

sequencia daArqueologoDaEquipa(equipa e);
#endif /* EQUIPA_H_ */