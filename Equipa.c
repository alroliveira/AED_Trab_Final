/*
 * Equipa.c
 */

#include <stdlib.h>
#include <string.h>
#include "Iterador.h"
#include "Sequencia.h"
#include "Equipa.h"
#include "Arqueologo.h"

#define MAX_E 2000
#define MAX_A_POR_E 500
#define NOME 50

struct _equipa
{
    sequencia arqueologos;
    char nome[NOME];
    int emJogo;                 //0 - se nunca teve em jogo     //1 - se ta em jogo ou ja teve e foi desqualificada
};

struct _equipa_emJogo
{
    sequencia arqueologos;
    char nome[NOME];
};

equipa criaEquipa(char *nome)
{
    equipa e;

    e = criaSequencia(MAX_E); 
    if (e==NULL)
    {
        return NULL;
    }

    e->arqueologos = criaSequencia(MAX_A_POR_E);
    if (e->arqueologos==NULL)
    {
        free(e);
        return NULL;
    }
    strcpy(e->nome, nome);
    e->emJogo = 0;
    return e;
}

int calculaClassificacao (equipa e)
{
    int existe=0;
    int merito=0;
    arqueologo a;
    iterador it = iteradorSequencia(e->arqueologos);

    while(temSeguinteIterador(it) && existe == 0)
    {
        a = (arqueologo)seguinteIterador(it);
        merito = merito + daMeritoArqueologo(a);
    }
    destroiIterador(it);
    return merito;
}

void destroiEquipa(equipa e)
{
    destroiSequencia(e->arqueologos);
    free(e);
}

void destroiGenEquipa(void * e)
{
    destroiEquipa((equipa)e);
}

void destroiEquipaEArqueologo(equipa e)
{
    destroiSeqElems(e->arqueologos, destroiGenArqueologo);
    free(e);
}

equipa daArqueologoDaEquipa(equipa e, int pos)
{
    return elementoPosSequencia(e->arqueologos, pos);
}

void adicionarArqueologoAEquipa(equipa e, char *nome)
{
    arqueologo a;
    int pos;
    a = criarArqueolog(nome);
    pos = tamanhoSequencia(e->arqueologos) + 1;
    adicionaPosSequencia(e->arqueologos, (void*) a, pos);
}

iterador iteradorEquipa(equipa e)
{
    return iteradorSequencia(e->arqueologos);
}

char *daNomeEquipa(equipa e)
{
    return e->nome;
}

int daEmJogoEquipa(equipa e)
{
    return e->emJogo;
}

void alteraEmJogoEquipa(equipa e, int emJogo)
{
    e->emJogo = emJogo;
}