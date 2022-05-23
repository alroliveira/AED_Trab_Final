/*
 * Concurso.c
 */

#include <stdlib.h>
#include <string.h>
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"


struct _concurso
{
    terreno *campo_de_jogo;
    equipa *equipas;
};


concurso criaConcurso()
{
    int l=0, c=0;
    concurso o;
    o = (concurso) malloc(sizeof(concurso));
    if(c == NULL)
        return NULL;
    o->campo_de_jogo = criaTerreno(l,c);
    o->equipas = criaEquipa();
}