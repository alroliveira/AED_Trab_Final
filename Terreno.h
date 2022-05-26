/*
 * Terreno.h
 */

#ifndef Terreno_h
#define Terreno_h

#include "Arqueologo.h"

#define MAXLINHA 10000
#define MAXCOLUNA 10000

//TAD
struct _terreno
{
    int linhas;
    int colunas;
    sequencia talhoes;
};

typedef struct _terreno * terreno;

typedef struct _talhao * talhao;


//Prototipo das funções 

terreno criaTerreno(int l,int c);

void destroiTerreno(terreno T);

void destroiTerrenoTalhoes(terreno T);

int leValorTerreno(terreno T);

int daLinhaTerreno(terreno T);

int daColunaTerreno(terreno T);

int existemTesourosEnterrados(terreno T);

void criaMatriz(terreno T,int l,int c,char m[MAXLINHA][MAXCOLUNA]);

int daLCSalto(arqueologo a, int lS, int cS, terreno T, int controlo);


#endif