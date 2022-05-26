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

talhao criaTalhao(int l,int c)
{
    talhao t = (talhao) malloc(sizeof(talhao)* (l*c));
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
