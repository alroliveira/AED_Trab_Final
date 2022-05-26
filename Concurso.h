/*
 * Concurso.h
 */

#ifndef concurso_h
#define concurso_h

// TAD
typedef struct _concurso * concurso;
 
//Funções

/***********************************************
criaConcurso - Criacao da instancia da estrutura concurso.
Parametros:
	l - numero de linhas do terreno
    c - numero de colunas do terreno
Retorno: apontador para a  instancia criada
Pre-condicoes:
***********************************************/
concurso criaConcurso(int l, int c);

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

#endif