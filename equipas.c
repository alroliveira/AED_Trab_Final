/*
 * equipas.c
 */

#include <stdlib.h>
#include <string.h>
#include "Concurso.h"
#include "Terreno.h"
#include "equipas.h"
//#include "arqueologo.h"

#define MAXCHAR 100


struct _Equipa
{
    int n_membros;
    char nome_equipa [MAXCHAR];
    //arqueologo arqueologo_x;
}


equipa criaEquipa()
{
    equipa e;
    e= (equipa) malloc(sizeof(equipa));
}