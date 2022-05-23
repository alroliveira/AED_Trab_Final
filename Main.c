/********************************************************************\
----------------------Concurso de Arqueologia-------------------------
\********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//TADs
#include "Concurso.h"

//constants
#define MAXCMD 50
 
//Prototypes
int lerTerreno();
int lerEquipas();
void lerFicheiroEquipas();
void interpretedor(concurso c);


int main()
{
    concurso c;
    FILE *file = NULL;

    c = criarConcurso();~
    lerTerreno();
    lerFicheiroEquipas();
    interpretedor(c);
    destroiConcursoTD(c);
    
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



void interpretador(concurso c)       //(comandos a executar)//
{
    char linha [MAXCMD];

    fgets(linha, MAXCMD, stdin);
    while (strcmp(linha, "sair"))
    {
        if (!strcmp(linha, "riqueza"))
            cmdRiqueza(c);                              //
        else if (!strcmp(linha, "terreno"))
            cmdTerreno(c);                              //
        else if (!strcmp(linha, "estrela"))
            cmdEstrela(c);                              //
        else if (!strcmp(linha, "escavacao"))
            cmdEscavacao(c);                            //
        else if (!strcmp(linha, "reforco"))
            cmdReforco(c);
        else if (!strcmp(linha, "equipa"))
            cmdEquipa(c);                               //
        else
            printf("Comando invalido\n");
    }
    cmdSair(c);                                         //   *sem a classificacao das equipas ao sair
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