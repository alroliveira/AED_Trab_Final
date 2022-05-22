#include <stdlib.h>
#include <string.h>
#include "Concurso.h"
#include "Terreno.h"


struct _terreno
{
    int linhas;
    int colunas;
    talhão * talhões;
};

struct _talhão
{
    int valor;
    int escavado;
}
//
terreno criaTerreno(int l,int c)
{
    terreno t;
    t = (terreno) malloc(sizeof(terreno));
    if(t==NULL) return NULL;
    t->talhões = (talhão *) malloc(sizeof(talhão)* (l*c));
    if(t->talhões == NULL){
        free(t);
        return NULL;
    }
    t->colunas = c;
    t->linhas = l;
    return t;
}


int preencheTerreno()
{
    int x;
}