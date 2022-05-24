/*
 * Terreno.h
 */

#ifndef Terreno_h
#define Terreno_h

//TAD
typedef struct _terreno * terreno;

typedef struct _talhao * talhao;


//Funções

terreno criaTerreno(int l,int c);

void preencheTerreno(int l, int c,terreno t);

#endif