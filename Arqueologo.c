/*
 * Arqueologo.c
 */

#include <stdlib.h>
#include <string.h>
#include "Iterador.h"
#include "Sequencia.h"
#include "Equipa.h"
#include "Arqueologo.h"
#include "Terreno.h"

#define NOME 50

struct _arqueologo
{
    int emJogo;
    int tesouros;
    int penalizacao;
    char nome[NOME];
    int posicao; // guarda a ultima posição do arqueologo
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

/*
int calcularMeritoArqueologo(arqueologo a)
{
    int merito = 0;

    merito = a->tesouros - a->penalizacao;
    return merito;
}
*/
/*
char *daNomeArqueologo(arqueologo a)
{
    return a->nome;
}
*/

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