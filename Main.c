/********************************************************************\
----------------------Concurso de Arqueologia-------------------------
\********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//TADs
#include "sequencia.h"
#include "dicionario.c"
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"
#include "Arqueologo.h"

//constants
#define MAXCMD 50
#define MAXNOME 50
 
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
    lerEquipas(c);
    interpretedor(c);
    destroiConcursoTD(c);
    
}

void lerTerreno()
{
    int l, c;
    scanf("%d %d", l, c);
}

void lerEquipas(concurso c)
{
    FILE *file = NULL;
    equipa e;
    arqueologo a;
    char line[50];
    int num;
    int i;

    file = fopen("teams", "r");
    if (file == NULL)
		return;

    while (fgets(line, sizeof(line)-1, file))
	{
        num = atoi(line);
        fgets(line, sizeof(line)-1, file);
        adicionarEquipaAoConcurso(c, line);

        for (i=1; i<=num; i++)
        {
            fgets(line, sizeof(line)-1, file);
            adicionarArqueologoAEquipa(e, line);
        }
	}
}



void interpretador(concurso c)       //(comandos a executar)//
{
    char linha [MAXCMD];
    int i;

    strtok(linha, " ");
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
            cmdEquipa(c);                            //
        else
            printf("Comando invalido\n");
    }
    cmdSair(c);                                         //   *sem a classificacao das equipas ao sair
}

void cmdEquipa(concurso c)
{
    equipa e;
    equipa_emJogo j;
    char *nome;
    int i;

    scanf(" %d", &i);
    if (tamanhoSequencia(e)<i)
    {
        printf("Equipa inexistente\n");
    }
    else if (daEmJogoEquipa(e))
    {
        printf("Equipa invalida\n");
    }
    else
    {
        nome = daNomeEquipa(e);
        adicionaElemDicionario(j, nome, elementoPosSequencia(e, i));
        alteraEmJogoEquipa(e, 1);
    }
}

void cmdEstrela(concurso c)
{
    char nome[MAXNOME];

    scanf(" %s", nome);
    
}

/*                  Projeto Final AED 2022                          *\
        Nome: Rodrigo Fonseca    nº 63272 LEEC Turno: P1
        Nome: Alexandra Oliveira nº 62263 LEEC Turno: P1
\*                                                                  */