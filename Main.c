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
void lerEquipas(concurso c);
void interpretedor(concurso c);
void iniciarConcurso(concurso c);
    //Funçoes comando
    void cmdRiqueza(concurso c);
    void cmdTerreno(concurso c, int linha, int coluna);
    void cmdEstrela(concurso c, char* nome_equipa);
    void cmdEqipa(concurso c, int i);
    void cmdEscavação();
    void cmdSair(concurso c);


//Funcoes
int main()
{
    concurso c;

    iniciarConcurso(c);
    interpretedor(c);
    destroiConcursoTD(c);
    return 0;
}

void iniciarConcurso(concurso c)
{
    int linha, coluna; 
    scanf("%d %d", linha, coluna);
    c = criaConcurso(linha, coluna);
    lerEquipas(c);
}


void interpretador(concurso c) //(comandos a executar)//
{
    while (1)
    {
        char linha[MAXCMD];
        fgets(linha, sizeof(linha), stdin);
        linha[strlen(linha) - 1] = '\0';
        char *comando = strtok(linha, " ");

        if (!strcmp(comando, "riqueza")) {                          //
            cmdRiqueza(c);
        }
        else if (!strcmp(comando, "terreno")) {                     //
            cmdTerreno(c);
        }
        else if (!strcmp(comando, "estrela")) {
            char *nome_equipa = strtok(NULL, " ");
            if (nome_equipa == NULL)
                continue;

            cmdEstrela(c, &nome_equipa);
        }
        else if (!strcmp(comando, "escavacao")) {                   //
            char *sLinha = strtok(NULL, " ");
            if (sLinha == NULL) continue;

            char *sColuna = strtok(NULL, " ");
            if (sColuna == NULL) continue;

            char *sNome = strtok(NULL, " ");
            if (sNome == NULL) continue;

            int iLinha = atoi(sLinha);
            int iColuna = atoi(sColuna);
            if (iLinha == 0 || iColuna == 0) continue;

            cmdEscavacao(c,iLinha,iColuna,sNome);
        }
        else if (!strcmp(comando, "reforco")) {
            cmdReforco(c);
        }
        else if (!strcmp(comando, "equipa")) {
            char *num_equipa = strtok(NULL, " ");
            if (num_equipa == NULL) continue;

            int i = atoi(num_equipa);
            if (i == 0)
            {
                printf("Equipa inexistente\n"); continue;
            }
            
            cmdEquipa(c, i);
        }
        else if (!strcmp(comando, "sair")) break;
        else printf("Comando invalido\n");
    }
    cmdSair(c);                    //   *sem a classificacao das equipas ao sair
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

    while (fgets(line, sizeof(line), file))
    {
        num = atoi(line);
        fgets(line, sizeof(line), file);
        adicionarEquipaAoConcurso(c, line);

        for (i = 1; i <= num; i++)
        {
            fgets(line, sizeof(line), file);
            adicionarArqueologoAEquipa(e, line);
        }
        nEquipa++;
    }
} 


void cmdRiqueza(concurso c)
{
    int riqueza = 0;
    terreno T;
    riqueza = leValorTerreno(T);
    printf("Riqueza enterrada: %d\n",riqueza);
}


void cmdTerreno(concurso c)
{
    terreno T;
    int linha=daLinhaTerreno(T),coluna=daColunaTerreno(T);
    char matriz[linha][coluna];
    
    matriz = char * criaMatriz(T,linha,coluna);
    for(int i=0;i<linha;i++)
    {
        for(int j=0;j<coluna;j++)
        {
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
}


void cmdEstrela(concurso c, char* nome_equipa)
{
    int i;
    equipa e, eq;
    arqueologo a;

    if (!existPorNomeEquipa(e, nome_equipa))
    {
        printf("Equipa invalida\n");
        return;
    }
    eq = elementoPosSequencia(e, daNEquipaPorNomeEquipa(e, nome_equipa));
    a = arqueologoComMaiorMerito(eq);
    printf("Estrela de %s: %s\n", eq->nome, a->nome);
}


void cmdEquipa(concurso c, int i)
{
    equipa e;
    equipa_emJogo e_emJogo;
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
        alteraEmJogoEquipa(e, 1);
    }
}


void cmdEscavacao(concurso c, int iLinha, int iColuna, char sNome)
{
    equipa e;
    Terreno T;

    if (iLinha==0 || iColuna==0){
        printf("Salto invalido\n");
    }
    else if (daNEquipaPorNomeEquipa(e, nome)==-1){
        printf("Equipa invalida\n");
    }
    else{
        daLFinal(e, iLinha, T);
        daCFinal(e, iColuna, T);
    }
}


void cmdSair (concurso c)       //.......(existemTesourosEnterrados()).......
{
    //equipa_emJogo e_emJogo;
    equipa e;
    terreno T;
    
    if(tamanhoSequencia(e)==0){
        printf("Todas as equipas foram expulsas.\n");
    }
    else{
        if(existemTesourosEnterrados(T)){                            //.........................................
            printf("Ainda havia tesouros por descobrir...\n");
        }
        else{
            printf("Todos os tesouros foram descobertos!\n");
        }
    }
}


/*                  Projeto Final AED 2022                          *\
        Nome: Rodrigo Fonseca    nº 63272 LEEC Turno: P1
        Nome: Alexandra Oliveira nº 62263 LEEC Turno: P1
\*                                                                  */