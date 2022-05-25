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

#define MAX_E 2000

struct _concurso
{
    terreno campo_de_jogo;
    sequencia equipas;
    dicionario equipas_emJogo;
};


concurso criaConcurso(int l,int c)
{
    concurso o;
    o = (concurso) malloc(sizeof(concurso));
    if(o == NULL)
        return NULL;
    o->campo_de_jogo = criaTerreno(l,c);
    o->equipas =criaEquipa();
    o->equipas_emJogo =criaDicionario(MAX_E, 1);
}


void destroiConcursoTD(concurso c) //tem de ser editado n destroi terreno
 {
    destroiTerrenoTalhoes(c->terreno);                                   //.....................................
    destroiSeqElems(c->equipas, destroiGenArqueologo);
    free(c);
 }

/*
concurso daEquipaDoConcurso(concurso c, int pos) // ONDE ESTA O PROTOTIPO DISTO?? ONDE E QUE ISTO ESTA USADO???
{
    return elementoPosSequencia(c->equipas, pos);
}
*/

void adicionarEquipaAoConcurso(concurso c, char *nome)// ONDE ESTA O PROTOTIPO DISTO?? ONDE E QUE ISTO ESTA USADO??? no lerequipas()
{
    equipa e;
    int pos;
    e = criaArqueologo(nome);
    pos = tamanhoSequencia(c->equipas) + 1;
    adicionaPosSequencia(c->equipas, (void*) e, pos);
    void alteraNumEquipa (e, pos)
}

