/*
 * Concurso.c
 */

#include <stdlib.h>
#include <string.h>
#include "iterador.h"
#include "sequencia.h"
#include "dicionario.h"
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"
#include "Arqueologo.h"
#include "Talhoes.h"

struct _talhao
{
    int valor;
    int escavado;
};


talhao criaTalhao(int l,int c)
{
    talhao t;
    t = (talhao *) malloc(sizeof(talhao)* (l*c));
    if(t == NULL) return NULL;
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


int valorTalhao(talhao t)
{
    return t->valor;
}