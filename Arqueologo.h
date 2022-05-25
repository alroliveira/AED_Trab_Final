/*
 * Arqueologo.c
 */

#ifndef _H_ARQUEOLOGO
#define _H_ARQUEOLOGO

/* Tipo de dados: Arqueologo */
typedef struct _arqueologo * arqueologo;

/* Prototipos das funcoes associadas ao Arqueologo */

arqueologo criaArqueologo(char *nome); 

int calcularMeritoArqueologo(arqueologo a);

char *daNomeArqueologo(arqueologo a);

void destroiArqueologo(arqueologo a);

void destroiGenArqueologo(void * a);

int daPosArqueologo(arqueologo a);
#endif /* ARQUEOLOGO_H_ */