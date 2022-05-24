/*
 * Terreno.c
 */

#include <stdlib.h>
#include <string.h>
#include "Concurso.h"
#include "Terreno.h"
#include "sequencia.h"


struct _terreno
{
    int linhas;
    int colunas;
    sequencia talhoes;
};


terreno criaTerreno(int l,int c)
{
    terreno T;
    T = (terreno) malloc(sizeof(terreno));
    if(t==NULL) return NULL;
    T->talhoes = criaTalhao(l,c)
    T->colunas = c;
    T->linhas = l;
    return T;
}

void destroiTerreno(terreno T)
{
    free(T);
}

void destroiTerrenoTalhoes(terreno T)
{
    estroiSeqElems(e->arqueologos, destroiGenTalhoes);
    free(T);
}


/*  precisamos de uma funcao assim (pelo menos para o main)
 *
 *  void existemTesourosEnterrados()
 *  void destroiTerrenoECampoDeJogo()
 */