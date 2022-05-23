/********************************************************************\
----------------------Concurso de Arqueologia-------------------------
\********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//TADs
#include "Concurso.h"
#include "Terreno.h"

//constants
#define MAXCMD 50
 
//Prototypes
void lerTerreno();
void lerEquipas();
void interpretedor(concurso c);


int main()
{
    concurso c;
    //FILE *file = NULL;


    c = criarConcurso();
    lerTerreno();
    lerEquipas();
    interpretedor(c);
    destroiConcursoTD(c);
    
}

void lerTerreno()
{
    int l, c;
    scanf("%d %d", l, c);
}

void lerEquipas()
{
    
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
    cmdSair(c);    /* !!! QUE MERDA É ESTA ALEXA?*/ //   *sem a classificacao das equipas ao sair
}




/*                  Projeto Final AED 2022                          *\
        Nome: Rodrigo Fonseca    nº 63272 LEEC Turno: P1
        Nome: Alexandra Oliveira nº 62263 LEEC Turno: P1
\*                                                                  */