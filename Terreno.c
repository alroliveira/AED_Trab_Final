/*
 * Terreno.c
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
#include "Talhoes.h"


struct _terreno
{
    int linhas;
    int colunas;
    sequencia talhoes;
};


terreno criaTerreno(int l,int c)
{
    terreno T;
    T = (terreno) malloc(sizeof(terreno));
    if(t==NULL) return NULL;
    T->talhoes = criaTalhao(l,c)
    T->colunas = c;
    T->linhas = l;
    return T;
}


void destroiTerreno(terreno T)
{
    free(T);
}

/*
void destroiTerrenoTalhoes(terreno T)
{
    estroiSeqElems(e->arqueologos, destroiGenTalhoes);
    free(T);
}
*/

int leValorTerreno(terreno T)
{
    int riqueza=0;
    talhao t;
    iterador it = iteradorSequencia(T->talhoes);

    while(temSeguinteIterador(it))
    {
        t = (talhao)seguinteIterador(it);
        riqueza += daMeritoArqueologo(t);
    }
    destroiIterador(it);
    return riqueza;
}


int daLinhaTerreno(terreno T)
{
    return T->linhas;
}


int daColunaTerreno(terreno T)
{
    return T->colunas;
}


int existemTesourosEnterrados(terreno T)
{
    talhao t;
    iterador it = iteradorSequencia(T->talhao);

    while(temSeguinteIterador(it) && existe == 0)
    {
        t = (talhao)seguinteIterador(it);
        if(strcmp(mat, daEscavadoTalhao(t))==0)
            existe = 1;
    }
    destroiIterador(it);
    return existe;
}

char * criaMatriz(terreno T,int l,int c)
{
    char m[l][c]
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(daEscavadoTalhao(T->talhoes)==0)
                m[i][j] = '-';
            else
                m[i][j] = '*';
        }
        
    }
    return m;
}

/*  precisamos de uma funcao assim (pelo menos para o main)
 * 
 *  void existemTesourosEnterrados()
 *  void destroiTerrenoECampoDeJogo()
 */