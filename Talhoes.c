/*
 * Concurso.c
 */
#include <stdlib.h>
#include <string.h>

// TADs
#include "iterador.h"
#include "sequencia.h"
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"
#include "Talhoes.h"
#include "Arqueologo.h"

struct _talhao
{
    int valor;
    int escavado;
};

talhao criaTalhao(int nt)
{
    talhao t = (talhao) malloc(sizeof(talhao));
    if(t == NULL) return NULL;
    t->valor = 0;
    t->escavado = 0;
    return t;
}


void destroiTalhao(talhao t)
{
    free(t);
}


void destroiGenTalhoes(void * t)
{
    destroiTalhao((talhao)t);
}


int daEscavadoTalhao(talhao t)
{
    return t->escavado;
}

int daValorTalhao(talhao t)
{
    return t->valor;
}

void alteraValorTalhao(talhao t, int valor){
    t->valor += valor;
}

void alteraEscavadoTalhao(talhao t, int escavado){
    t->escavado += escavado;
}
