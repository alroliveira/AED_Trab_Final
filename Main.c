/********************************************************************\
----------------------Concurso de Arqueologia-------------------------
\********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// TADs
#include "sequencia.h"
#include "dicionario.c"
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"
#include "Arqueologo.h"

// constants
#define MAXCMD 50
#define MAXNOME 50

// Prototypes
void lerTerreno(concurso con);
void lerEquipas();
void interpretedor(concurso c);

int main()
{
    concurso c;
    // FILE *file = NULL;

    iniciarConcurso(c);
    interpretedor(c);
    destroiConcursoTD(c);
}

void iniciarConcurso(concurso c)
{
    int l, c;
    scanf("%d %d", l, c);
    c = criarConcurso(l, c);
    lerEquipas();
}

void lerEquipas() // ||
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

    while (fgets(line, sizeof(line) - 1, file))
    {
        num = atoi(line);
        fgets(line, sizeof(line) - 1, file);
        adicionarEquipaAoConcurso(c, line);

        for (i = 1; i <= num; i++)
        {
            fgets(line, sizeof(line) - 1, file);
            adicionarArqueologoAEquipa(e, line);
        }
    }
}

void interpretador(concurso c) //(comandos a executar)//
{
    while (1)
    {
        char linha[MAXCMD];
        fgets(linha, sizeof(linha), stdin);
        linha[strlen(linha) - 1] = '\0'; // remover \n
        char *comando = strtok(linha, " ");

        if (!strcmp(comando, "riqueza")) {
            cmdRiqueza(c);
        }
        else if (!strcmp(comando, "terreno")) {
            cmdTerreno();
        }
        else if (!strcmp(comando, "estrela"))
        {
            char *nome_equipa = strtok(NULL, " ");
            if (nome_equipa == NULL)
                continue;

            cmdEstrela(c, &nome_equipa);
        } //
        else if (!strcmp(comando, "escavacao"))
        {
            char *sLinha = strtok(NULL, " ");
            if (sLinha == NULL) continue;

            char *sColuna = strtok(NULL, " ");
            if (sColuna == NULL) continue;

            char *sNome = strtok(NULL, " ");
            if (sNome == NULL) continue;

            int iLinha = atoi(sLinha);
            int iColuna = atoi(sColuna);
            if (iLinha == 0 || iColuna == 0) continue;

            cmdEscavacao();
        }
        else if (!strcmp(comando, "reforco")) {
            cmdReforco();
        }
        else if (!strcmp(comando, "equipa"))
        {
            char *num_equipa = strtok(NULL, " ");
            if (num_equipa == NULL) continue;

            int i = atoi(num_equipa);
            if (i == 0)
            {
                printf("Equipa inexistente\n"); continue;
            }
            
            cmdEquipa(c, i);                                        //
        }
        else if (!strcmp(comando, "sair")) break;
        else printf("Comando invalido\n");
    }
    cmdSair(c);                                                     //   *sem a classificacao das equipas ao sair
}

void cmdEquipa(concurso c, int i)
{
    equipa e;
    equipa_emJogo j;
    char *nome;
   
    if (tamanhoSequencia(e) < i)
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

void cmdEstrela(concurso c, char* nome_equipa)
{
    char nome[MAXNOME];

    scanf(" %s", nome);
}

/*                  Projeto Final AED 2022                          *\
        Nome: Rodrigo Fonseca    nº 63272 LEEC Turno: P1
        Nome: Alexandra Oliveira nº 62263 LEEC Turno: P1
\*                                                                  */