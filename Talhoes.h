/*
 * Talhoes.h
 */

#ifndef talhoes_h
#define talhoes_h

//TAD
typedef struct _talhao
{
    int valor;
    int escavado;
} *talhao;

typedef struct _talhao * talhao; 

//funçoes

talhao criaTalhao(int l,int c);

void destroiTalhao(talhao t);

void destroiGenTalhoes(void * t);

int valorTalhao(talhao t);

int daEscavadoTalhao(talhao t);

int daValorTalhao(talhao t);

void alteraValorTalhao(talhao t, int valor);

void alteraEscavadoTalhao(talhao t, int Escavado);
#endif