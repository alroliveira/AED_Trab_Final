/*
 * Terreno.h
 */

#ifndef Terreno_h
#define Terreno_h

#include "Arqueologo.h"

//TAD
typedef struct _terreno * terreno;

typedef struct _talhao * talhao;


//Funções 

terreno criaTerreno(int l,int c);

void destroiTerreno(terreno T);

void destroiTerrenoTalhoes(terreno T);

int leValorTerreno(terreno T);

int daLinhaTerreno(terreno T);

int daColunaTerreno(terreno T);

int existemTesourosEnterrados(terreno T);

char * criaMatriz(terreno T,int l, int c);

int daLCSalto(arqueologo a, int lS, int cS, terreno T, int controlo);


#endif