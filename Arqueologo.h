/*
 * Arqueologo.c
 */
#ifndef _H_ARQUEOLOGO
#define _H_ARQUEOLOGO

/* Tipo de dados: Arqueologo */
typedef struct _arqueologo * arqueologo;
typedef struct _terreno * terreno;

/* Prototipos das funcoes associadas ao Arqueologo */

arqueologo criarArqueologo(char *nome); 

int calcularMeritoArqueologo(arqueologo a);

char *daNomeArqueologo(arqueologo a);

void destroiArqueologo(arqueologo a);

void destroiGenArqueologo(void * a);

int daPosArqueologo(arqueologo a);

int daLCArqueologo(arqueologo a, terreno T, int controlo);

int daPenalizacaoArqueologo(arqueologo a);

void incrementaTesouro(arqueologo a, int valor);

void alteraMeritoArqueologo(arqueologo a, int merito);

#endif /* ARQUEOLOGO_H_ */