/********************************************************************\
----------------------Concurso de Arqueologia-------------------------
\********************************************************************/
#include <stdio.h>
#include <ctype.h>     

//TADs
#include "Concurso.h"


//Prototypes
int lerTerreno(int l, int c);
int lerEquipas()


int main(){

    lerTerreno();
    
}


int lerTerreno()
{ 
    int l, c;
    scanf("%d %d", l, c);
    campo_de_jogo = criaTerreno(l,c);
    if (campo_de_jogo == NULL) 
    {
        return 1;
    }
    return 0;
}

/*
lerEquipas()
{
    char numeros[];
    scanf("%s", numeros);
    for(int i=0; i>stringlen(numeros);i++)
        strint(numeros[i]);
}
*/


/*                  Projeto Final AED 2022                          *\
        Nome: Rodrigo Fonseca    nº 63272 LEEC Turno: P1
        Nome: Alexandra Oliveira nº 62263 LEEC Turno: P1
\*                                                                  */