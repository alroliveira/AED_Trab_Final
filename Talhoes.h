/*
 * Talhoes.h
 */

#ifndef talhoes_h
#define talhoes_h


//TAD
typedef struct _talhao * talhao;

//funçoes

talhao criaTalhao(int l,int c);

void destroiTalhao(talhao t);

void destroiGenTalhoes(void * t);

int daValorTalhao(terreno T);

int daEscavadoTalho(concurso c);

#endif