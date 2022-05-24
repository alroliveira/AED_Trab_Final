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

void destroiTerreno(terreno t);

void destroiTerrenoTalhoes(terreno t);

int daValorTerreno(concurso c)

#endif