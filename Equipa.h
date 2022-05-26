/*
 * Equipa.h
 */

#ifndef _H_EQUIPA
#define _H_EQUIPA

#include "Arqueologo.h"

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
daNomeArqueologo - Consulta o nome da estrutura associada ao Arqueologo
Parametros: 
	a - arqueologo
Retorno: nome do arqueologo
Pre-condicoes: a != NULL
***********************************************/
char *daNomeEquipa(equipa e);

int daEmJogoEquipa(equipa e);

void alteraEmJogoEquipa(equipa e, int emJogo);

void atualizaNumEquipa(equipa e);

//int existeEquipa(equipa e, void *nome);

int existPorNomeEquipa(equipa e, void *nome);

int daNEquipaPorNomeEquipa(equipa e, void *nome);

arqueologo arqueologoComMaiorMerito(equipa e);

void alteraNumEquipa (equipa e, int num);

void alteraNomeEquipa (equipa e, char *nome);

equipa daEquipa(equipa e, char * nome);

#endif /* EQUIPA_H_ */