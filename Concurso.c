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

#define MAX_E 2000

struct _concurso
{
    terreno campo_de_jogo;
    sequencia equipas;
};


concurso criaConcurso()
{
    concurso o;
    o = (concurso) malloc(sizeof(struct _concurso));
    if(o == NULL)
        return NULL;
    o->campo_de_jogo = criaTerreno(); 
    o->equipas = (sequencia)criaSequencia(MAX_E);
    return o;
}


void destroiConcursoTD(concurso c) //tem de ser editado n destroi terreno
 {
    destroiTerrenoTalhoes(c->campo_de_jogo);                                   //.....................................
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
    e = criaEquipa();
    alteraNomeEquipa (e, nome);
    pos = tamanhoSequencia(c->equipas) + 1;
    adicionaPosSequencia(c->equipas, (void*) e, pos);
    alteraNumEquipa(e, pos);
}

terreno daTerrenoDoConcurso(concurso c){
    return c->campo_de_jogo;
}

sequencia daEquipaDoConcurso(concurso c){
    return c->equipas;
}
