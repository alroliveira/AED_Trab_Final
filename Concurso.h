/*
 * Concurso.h
 */

#ifndef concurso_h
#define concurso_h

// TAD
typedef struct _concurso * concurso;

//Funções

concurso criaConcurso();

void destroiConcursoTD(concurso c);

concurso daEquipaDoConcurso(concursoc, int pos);

void adicionarEquipaAoConcurso(concurso c,char * nome);

#endif