/*
 * Concurso.c
 */

#include <stdlib.h>
#include <string.h>
#include "Iterador.h"
#include "Sequencia.h"
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"
#include "Arqueologo.h"


struct _concurso
{
    terreno *campo_de_jogo;
    sequencia equipas;
};

concurso criaConcurso()
{
    int l=0, c=0;
    concurso o;
    o = (concurso) malloc(sizeof(concurso));
    if(c == NULL)
        return NULL;
    o->campo_de_jogo = criaTerreno(l,c);
    o->equipas =criaEquipa();
}

concurso daEquipaDoConcurso(concurso c, int pos)
{
    return elementoPosSequencia(c->equipas, pos);
}

void adicionarEquipaAoConcurso(concurso c, char *nome)
{
    equipa e;
    int pos;
    e = criarArqueolog(nome);
    pos = tamanhoSequencia(c->equipas) + 1;
    adicionaPosSequencia(c->equipas, (void*) e, pos);
}