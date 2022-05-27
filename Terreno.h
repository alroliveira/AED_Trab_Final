/*
 * Terreno.h
 */

#ifndef Terreno_h
#define Terreno_h

#include "Arqueologo.h"
#include "sequencia.h"

#define MAXLINHA 10000
#define MAXCOLUNA 10000

//TAD

typedef struct _terreno * terreno;

typedef struct _talhao * talhao;


//Prototipo das funções 

/***********************************************
criaTerreno - Criacao da instancia da estrutura terreno.
Parametros:
	l - numero de linhas do terreno
    c - numero de colunas do terreno
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
terreno criaTerreno();

/***********************************************
destroiTerreno - Liberta a memoria ocupada pela estrtura terreno.
Parametros:
	T - terreno a destruir
Retorno:
Pre-condicoes: T != NULL
***********************************************/
void destroiTerreno(terreno T);

/***********************************************
destroiTerrenoTalhoes - Liberta a memoria ocupada pela sequencia de talhoes e terreno.
Parametros:
	T - terreno a destruir
Retorno:
Pre-condicoes: T != NULL
***********************************************/
void destroiTerrenoTalhoes(terreno T);

/***********************************************
leValorTerreno - Consulta o valor da estrutura associada ao terreno.
Parametros: 
	T - terreno
Retorno: valor do terreno
Pre-condicoes: T != NULL
***********************************************/
int leValorTerreno(terreno T);

/***********************************************
daLinhaTerreno - Consulta o numero da linha da estrutura terreno.
Parametros: 
	T - terreno
Retorno: linha do terreno
Pre-condicoes: T != NULL
***********************************************/
int daLinhaTerreno(terreno T);

/***********************************************
daColunaTerreno - Consulta o numero da coluna da estrutura terreno.
Parametros: 
	T - terreno
Retorno: coluna do terreno
Pre-condicoes: T != NULL
***********************************************/
int daColunaTerreno(terreno T);

/***********************************************
daColunaTerreno - Consulta se ainda existem tesouros enterrados aa estrutura terreno.
Parametros: 
	T - terreno
Retorno: 1- caso existam; 0- caso contrario
Pre-condicoes: T != NULL
***********************************************/
int existemTesourosEnterrados(terreno T);

/***********************************************
criaMatriz - Cria uma matriz referente a estrutura terreno.
Parametros: 
	T - terreno
    l - numero de linhas que o terreno possui
    c - numero de colunas que o terreno possui
Retorno:
Pre-condicoes: T != NULL
***********************************************/
void criaMatriz(terreno T,int l,int c,char m[MAXLINHA][MAXCOLUNA]);

/***********************************************
daLCSalto - Consulta as linhas e colunas referentes a posicao final do Arqueologo, apos o salto.
Parametros: 
	a - arqueologo
    lS - numero de linhas a saltar
    cS - numero de colunas a saltar
	T - terreno
	controlo - variavel auxiliar para obter as linhas ou colunas
Retorno: para controlo==1 retorna linhas
		 para controlo==0 retorna colunas
Pre-condicoes: a != NULL && T!=NULL
***********************************************/
int daLCSalto(arqueologo a, int lS, int cS, terreno T, int controlo);

void atribuiLCTerreno(int linha, int coluna, terreno T);

sequencia daTalhaoDoTerreno( terreno T);
#endif