/*
 * Terreno.c
 */

#include <stdlib.h>
#include <string.h>
#include "Concurso.h"
#include "Terreno.h"


struct _terreno
{
    int linhas;
    int colunas;
    talhao * talhoes;
};

struct _talhao
{
    int valor;
    int escavado;
};


terreno criaTerreno(int l,int c)
{
    terreno t;
    t = (terreno) malloc(sizeof(terreno));
    if(t==NULL) return NULL;
    t->talhoes = (talhao *) malloc(sizeof(talhao)* (l*c));
    if(t->talhoes == NULL){
        free(t);
        return NULL;
    }
    t->colunas = c;
    t->linhas = l;
    return t;
}
