/*
 * Concurso.h
 */

#ifndef concurso_h
#define concurso_h

// TAD
typedef struct _concurso * concurso;
 
//Funções

concurso criaConcurso(int l, int c);

void destroiConcursoTD(concurso c);

concurso daEquipaDoConcurso(concursoc, int pos);

void adicionarEquipaAoConcurso(concurso c,char * nome);

int daLFinal(equipa e, int iLinha, terreno T);

int daCFinal(equipa e, iColuna, terreno T);

#endif