/********************************************************************\
----------------------Concurso de Arqueologia-------------------------
\********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// TADs
#include "iterador.h"
#include "sequencia.h"
#include "Concurso.h"
#include "Equipa.h"
#include "Terreno.h"
#include "Talhoes.h"
#include "Arqueologo.h"

// constants
#define MAXCMD 50
#define MAXNOME 50


// Prototypes
void lerTerreno(concurso con);
void lerEquipas(concurso c);
void interpretador(concurso c);
void iniciarConcurso(concurso c);
    //Funçoes comando
    void cmdRiqueza(concurso c);
    void cmdTerreno(concurso c);
    void cmdEstrela(concurso c, char* nome_equipa);
    void cmdEquipa(concurso c, int i);
    void cmdEscavacao(concurso c, int lSalto, int cSalto, char *nome);
    void cmdSair(concurso c);


//Funcoes
int main()
{
    concurso c;

    iniciarConcurso(c);
    interpretador(c);
    destroiConcursoTD(c);
    getchar();
    return 0;
}


void iniciarConcurso(concurso c)
{
    int linha, coluna; 
    scanf("%d %d", &linha, &coluna);
    c = criaConcurso(linha, coluna);
    lerEquipas(c);
}


void interpretador(concurso c) //(comandos a executar)//
{
    while (1)
    {
        char linha[MAXCMD];
        fgets(linha, sizeof(linha), stdin);
        //printf("c------------");
        getc(stdin);
        //linha[strlen(linha) - 1] = '\0';
        char *comando = strtok(linha, " ");
        if (!strcmp(comando, "riqueza")) {                          //
            cmdRiqueza(c);
        }
        else if (!strcmp(comando, "terreno")) {                     //
            cmdTerreno(c);
        }
        else if (!strcmp(comando, "estrela")) {
            printf("a");
            char *nome_equipa = strtok(NULL, " ");
            if (nome_equipa == NULL)
                //printf("c");
                continue;
            //printf("b");
            cmdEstrela(c, nome_equipa);
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
            //cmdReforco(c);
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
    char line[50];
    int num;
    int i;
    e = daEquipa(e, line)
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
            adicionarArqueologoAEquipa(, line);
        }
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
    criaMatriz(T,linha,coluna,matriz);
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
    equipa e, eq;
    arqueologo a;

    if (!existPorNomeEquipa(e, nome_equipa))
    {
        printf("Equipa invalida\n");
        return;
    }
    eq = (equipa)elementoPosSequencia((sequencia)e, daNEquipaPorNomeEquipa(e, nome_equipa));
    a = arqueologoComMaiorMerito(eq);
    printf("Estrela de %s: %s\n", daNomeEquipa(eq), daNomeArqueologo(a));
}


void cmdEquipa(concurso c, int i)
{
    equipa e;
   
    if (tamanhoSequencia((sequencia)e) < i)
    {
        printf("Equipa inexistente\n");
    }
    else if (daEmJogoEquipa(e))
    {
        printf("Equipa invalida\n");
    }
    else
    {
        alteraEmJogoEquipa(e, 1);
    }
}


void cmdEscavacao(concurso c, int lSalto, int cSalto, char *nome)
{
    equipa e = daEquipa(e, nome);
    terreno T;
    talhao t;
    int lFinal, cFinal;
    arqueologo a; 
    iterador it;
    
    if (lSalto==0 || cSalto==0){
        printf("Salto invalido\n");
    }
    else if (daNEquipaPorNomeEquipa(e, nome)==-1){
        printf("Equipa invalida\n");
    }
    else{
        if(temSeguinteIterador(it))
        {
            a = (arqueologo)seguinteIterador(it);
            lFinal = daLCSalto(a, lSalto, cSalto, T, 1);
            cFinal = daLCSalto(a, lSalto, cSalto, T, 0);
            t = elementoPosSequencia((sequencia)t, lFinal+cFinal);

            if(lFinal>daLinhaTerreno(T) || cFinal>daColunaTerreno(T)){
                destroiArqueologo(a);
                if(vaziaSequencia((sequencia)e)){
                    printf("%s foi expulsa\n", nome);
                    return;
                }
                return;
            }
            
            if (!daEscavadoTalhao(t) && daValorTalhao(t)){
                t->escavado = t->escavado + 1;
                incrementaTesouro(a, daEscavadoTalhao(t));
                t->valor = 0;
            }
            else if (!daEscavadoTalhao(t)){
                t->escavado += 1;
            }
            else{
                t->escavado += 1;
                
            }
        }
        
        t = elementoPosSequencia((sequencia)t,lFinal * cFinal); 
        
        it = iteradorEquipa(e);
        
        destroiIterador(it);
    }
}


void cmdSair (concurso c)      //tem um problema do comando sair
{
    equipa e;
    terreno T;
    
    if(tamanhoSequencia((sequencia)e)==0){
        printf("Todas as equipas foram expulsas.\n");
    }
    else{
        if(existemTesourosEnterrados(T)){                          
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