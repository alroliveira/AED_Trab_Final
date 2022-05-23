/*
 * Arqueologo.c
 */

#include <stdlib.h>
#include <string.h>
#include "Iterador.h"
#include "Sequencia.h"
#include "Equipa.h"
#include "Arqueologo.h"

#define NOME 50

struct _arqueologo
{
    int emJogo;
    int tesouros;
    int penalizacao;
    char nome[NOME];
};


arqueologo criaArqueologo(char *nome)
{
    arqueologo a;
    a = (arqueologo) malloc(sizeof(struct _arqueologo));

    if (a==NULL)
        return NULL;
    a->emJogo = 1;
    a->tesouros = 0;
    a->penalizacao = 0;
    strcpy(a->nome, nome);
    return a;
}

int calcularMeritoArqueologo(arqueologo a)
{
    int merito = 0;

    merito = a->tesouros - a->penalizacao;
    return merito;
}

char *daNomeArqueologo(arqueologo a)
{
    return a->nome;
}

void destroiArqueologo(arqueologo a)
{
    free(a);
}

void destroiGenArqueologo(void * a)
{
    destroiArqueologo((arqueologo)a);
}