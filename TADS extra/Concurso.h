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

concurso daEquipaDoConcurso(concurso c, int pos);

void adicionarEquipaAoConcurso(concurso c,char * nome);

#endif