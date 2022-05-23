/*
 * Equipa.c
 */

#include <stdlib.h>
#include <string.h>
#include "Iterador.h"
#include "Sequencia.h"
#include "Equipa.h"
#include "Arqueologo.h"

#define MAX_A_POR_E 500

struct _equipa
{
    sequencia arqueologos;
    int emJogo;
};

equipa criaEquipa()
{
    equipa e;

    e = (equipa) malloc(sizeof(struct _equipa));
    if (e==NULL)
        return NULL;

    e->arqueologos = criaSequencia(MAX_A_POR_E);
    if (e->arqueologos==NULL)
    {
        free(e);
        return NULL;
    }
    e->emJogo = 0;
    return e;
}

arqueologo daArqueologoEquipa()

int daClassificacao (equipa e)
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

void destroiArqueologo()