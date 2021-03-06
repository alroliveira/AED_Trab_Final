/*
 * Arqueologo.c
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

#define NOME 50

struct _arqueologo
{
    int emJogo;
    int merito;
    int penalizacao;
    char nome[NOME];
    int posicao; // guarda a ultima posição do arqueologo
};
 

arqueologo criarArqueologo(char *nome)
{
    arqueologo a;
    a = (arqueologo) malloc(sizeof(struct _arqueologo));

    if (a==NULL)
        return NULL;
    a->emJogo = 1;
    a->merito = 0;
    a->penalizacao = 0;
    strcpy(a->nome, nome);
    a->posicao = 0;
    return a;
}


int calcularMeritoArqueologo(arqueologo a)
{
    int merito = 0;

    merito = a->merito - a->penalizacao;
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


int daPosArqueologo(arqueologo a)
{
    return a->posicao;
}

int daLCArqueologo(arqueologo a, terreno T, int controlo) //se controlo==1 da as linhas, se controlo==0 da colunas   
{
    int pos, l, c, cT;
    cT=daColunaTerreno(T);
    pos = daPosArqueologo(a);
    int k;

    for (k=cT-1; k>=0;k--){
        if((pos+k)%cT==0){
            c=cT-k;
            l=(pos+k)/cT;
        }
    }
    if (controlo)
        return l;
    else
        return c;
}


int daPenalizacaoArqueologo(arqueologo a){
    return a->penalizacao;
}

void incrementaTesouro(arqueologo a, int valor) {
    a->merito += valor;
}

void alteraMeritoArqueologo(arqueologo a, int merito){
    a->merito += merito;
}