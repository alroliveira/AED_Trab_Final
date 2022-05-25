/*
 * Equipa.h
 */

#ifndef _H_EQUIPA
#define _H_EQUIPA

/* Tipo de dados: Equipa */
typedef struct _equipa * equipa;
typedef struct _equipa_emJogo * equipa_emJogo;

/* Prototipos das funcoes associadas a Equipa */

equipa criaEquipa();

int calculaClassificacao (equipa e);

void destroiEquipa(equipa e);

void destroiGenEquipa(void * e);

void destroiEquipaEArqueologo(equipa e);

equipa daArqueologoDaEquipa(equipa e, int pos);

void adicionarArqueologoAEquipa(equipa e, char *nome);

iterador iteradorEquipa(equipa e);

char *daNomeEquipa(equipa e);

int daEmJogoEquipa(equipa e);

void alteraEmJogoEquipa(equipa e, int emJogo);

int existPorNomeEquipa(equipa e, void *nome);

int daNEquipaPorNomeEquipa(equipa e, void *nome);

#endif /* EQUIPA_H_ */