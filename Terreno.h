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

void destroiTerrenoTalhao(terreno t);

int daValorTalhao(terreno t);

int daValorTerreno(concurso c)

int daEscavadoTalho(concurso c);


#endif