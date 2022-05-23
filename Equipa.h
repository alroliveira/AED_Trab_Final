/*
 * Equipa.h
 */

#ifndef _H_EQUIPA
#define _H_EQUIPA

/* Tipo de dados: Equipa */
typedef struct _equipa * equipa;

/* Prototipos das funcoes associadas a Equipa */

equipa criaEquipa();
int calculaClassificacao (equipa e);
void destroiParque(equipa e);
void destroiEquipaEArqueologo(equipa e);
equipa daArqueologoDaEquipa(equipa e, int pos);
void adicionarArqueologoAEquipa(equipa e, char *nome);
iterador iteradorEquipa(equipa e);

#endif /* EQUIPA_H_ */