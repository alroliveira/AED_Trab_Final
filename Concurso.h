/*
 * Concurso.h
 */

#ifndef concurso_h
#define concurso_h

#include "Terreno.h"
#include "sequencia.h"

// TAD
typedef struct _concurso * concurso;
 
//Funções

/***********************************************
criaConcurso - Criacao da instancia da estrutura concurso.
Parametros:
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
concurso criaConcurso();

/***********************************************
destroiConcursoTD - Liberta a memoria ocupada pela estrutura concurso.
Parametros:
	c - concurso a destruir
Retorno:
Pre-condicoes: c != NULL
***********************************************/
void destroiConcursoTD(concurso c);

//concurso daEquipaDoConcurso(concurso c, int pos);

/***********************************************
adicionarEquipaAoConcurso - Criacao da instancia da estrutura equipa pertencente ao concurso.
Parametros:
    c - concurso
    nome - nome da equipa
Retorno:
Pre-condicoes: c != NULL
***********************************************/
void adicionarEquipaAoConcurso(concurso c,char * nome);

terreno daTerrenoDoConcurso(concurso c);

sequencia daEquipaDoConcurso(concurso c);

#endif