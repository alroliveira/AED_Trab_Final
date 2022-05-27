/*
 * Terreno.c
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
#define MAXLINHA 10000
#define MAXCOLUNA 10000

struct _terreno
{
    int linhas;
    int colunas;
    sequencia talhoes;
};

terreno criaTerreno(int l,int c)
{
    terreno T;
    int n = l*c;
    T = (terreno) malloc(sizeof(terreno));
    if(T==NULL) return NULL;
    T->talhoes = (sequencia)criaTalhao(n);
    T->colunas = c;
    T->linhas = l;
    return T;
}


void destroiTerreno(terreno T)
{
    free(T);
}


void destroiTerrenoTalhoes(terreno T)
{
    destroiSeqElems(T->talhoes, destroiGenTalhoes);
    free(T);
}


int leValorTerreno(terreno T)
{
    int riqueza=0;
    talhao t;
    iterador it = iteradorSequencia(T->talhoes);

    while(temSeguinteIterador(it))
    {
        t = (talhao)seguinteIterador(it);
        riqueza += daValorTalhao(t);
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
    iterador it = iteradorSequencia(T->talhoes);
    int existe = 0;

    while(temSeguinteIterador(it) && existe == 0)
    {
        t = (talhao)seguinteIterador(it);
        if(daValorTalhao(t)==0)
            existe = 1;
    }
    destroiIterador(it);
    return existe;
}


void criaMatriz(terreno T,int l,int c,char m[MAXLINHA][MAXCOLUNA])
{
    iterador it = iteradorSequencia(T->talhoes);
    int existe = 0;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(daValorTalhao((talhao)T->talhoes)==0)
                m[i][j] = '-';
            else
                m[i][j] = '*';
            while(temSeguinteIterador(it) && existe == 0)
            {
                t = (talhao)seguinteIterador(it);
                if(daValorTalhao(t)==0)
                    existe = 1;
            }
        }
        
    }
    destroiIterador(it);
}


    //pos onde ta + o salto
int daLCSalto(arqueologo a, int lS, int cS, terreno T, int controlo) //se controlo==1 da as linhas, se controlo==0 da colunas   
{
    int lA, cA;
    int lFinal, cFinal;
    lA = daLCArqueologo(a, T, 1);
    cA = daLCArqueologo(a, T, 0);
    
    lFinal = lA + lS;
    cFinal = cA + cS;

    if (controlo)
        return lFinal;
    else
        return cFinal;
}


/*  precisamos de uma funcao assim (pelo menos para o main)
 * 
 *  void existemTesourosEnterrados()
 *  void destroiTerrenoECampoDeJogo()
 */