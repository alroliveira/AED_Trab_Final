/*
 * Equipa.h
 */

#ifndef _H_EQUIPA
#define _H_EQUIPA

#include "Arqueologo.h"

/* Tipo de dados: Equipa */
typedef struct _equipa * equipa; 

/* Prototipos das funcoes associadas a Equipa */

equipa criaEquipa();

//int calculaClassificacao (equipa e);

//void destroiEquipa(equipa e);

//void destroiGenEquipa(void * e);

//void destroiEquipaEArqueologo(equipa e);

//equipa daArqueologoDaEquipa(equipa e, int pos);

void adicionarArqueologoAEquipa(equipa e, char *nome);

iterador iteradorEquipa(equipa e);

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