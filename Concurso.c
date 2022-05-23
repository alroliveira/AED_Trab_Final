/*
 * Concurso.c
 */

#include <stdlib.h>
#include <string.h>
#include "Concurso.h"
#include "Terreno.h"


struct _concurso
{
    terreno campo_de_jogo;
    int n_equipas;
    char arqueologo;
};


concurso criaConcurso()
{
    int l=0, c=0;
    concurso c;
    c = (concurso) malloc(sizeof(concurso));
    if(c == NULL)
        return NULL;
    c->campo_de_jogo = criaTerreno(l,c);

}