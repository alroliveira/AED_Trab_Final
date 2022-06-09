/*
 * Equipa.c
 */

#include <stdlib.h>
#include <string.h>

// TADs
#include "iterador.h"
#include "sequencia.h"
#include "Concurso.h"
#include "Terreno.h"
#include "Equipa.h"
#include "Talhoes.h"
#include "Arqueologo.h"

#define MAX_E 2000
#define MAX_A_POR_E 500
#define NOME 50

struct _equipa
{
    sequencia arqueologos;
    char nome[NOME];
    int emJogo;                 //0 - se nunca teve em jogo     //1 - se ta em jogo ou ja teve e foi desqualificada
    int nEquipa;
};


equipa criaEquipa()
{
    equipa e;

    e = (equipa) malloc(sizeof(struct _equipa));

    if (e==NULL)
    {
        return NULL;
    }

    e->arqueologos = criaSequencia(MAX_A_POR_E);
    if (e->arqueologos==NULL)
    {
        free(e);
        return NULL;
    }
    e->nome[0]= '\0';
    //memset(e->nome, '\0', sizeof(e->nome)); //inicializar string nula
    e->emJogo = 0;
    e->nEquipa = 0;
    return e;
}

/*
int calculaClassificacao (equipa e)
{
    int merito=0;
    arqueologo a;
    iterador it = iteradorSequencia(e->arqueologos);

    while(temSeguinteIterador(it))
    {
        a = (arqueologo)seguinteIterador(it);
        merito += daMeritoArqueologo(a);
    }
    destroiIterador(it);
    return merito;
}
*/
/*
void destroiEquipa(equipa e)
{
    destroiSequencia(e->arqueologos);
    free(e);
}
*/
/*
void destroiGenEquipa(void * e)
{
    destroiEquipa((equipa)e);
}
*/
/*
void destroiEquipaEArqueologo(equipa e)
{
    destroiSeqElems(e->arqueologos, destroiGenArqueologo);
    free(e);
}
*/
/*
equipa daArqueologoDaEquipa(equipa e, int pos)
{
    return elementoPosSequencia(e->arqueologos, pos);
}
*/

void adicionarArqueologoAEquipa(equipa e, char *nome)
{
    arqueologo a;
    int pos;
    a = criarArqueologo(nome);
    pos = tamanhoSequencia(e->arqueologos) + 1;
    adicionaPosSequencia(e->arqueologos, (void*) a, pos);
}


iterador iteradorEquipa(equipa e)
{
    return iteradorSequencia(e->arqueologos);
}


char *daNomeEquipa(equipa e)
{
    return e->nome;
}


int daEmJogoEquipa(equipa e)
{
    return e->emJogo;
}


void alteraEmJogoEquipa(equipa e, int emJogo)
{
    e->emJogo = emJogo;
    if(emJogo==0)
    {
        removePosSequencia((sequencia)e, e->nEquipa);
        atualizaNumEquipa(e);
    }
}


void atualizaNumEquipa(equipa e)
{
    int i;
    for(i=1; i<=tamanhoSequencia((sequencia)e); i++)
        e->nEquipa=i;
}

/*
int existeEquipa(equipa e, void *nome){
	int i;
	for (i = 1; i<=tamanhoSequencia(e);i++)
		if (igualChaves(ch,priTuplo(d->elems[i]),d->tipoCh) == 1)
			return i;
	return -1;
    
    
    if (posElemDicionario(d,ch) != -1)
		return 1;
	return 0;
}
*/

int existPorNomeEquipa(equipa e, void *nome){
	
    if (daNEquipaPorNomeEquipa(e, nome) != -1)
		return 1;
	return 0;
}


int daNEquipaPorNomeEquipa(equipa e, void *nome){
	int i;
	for (i = 1; i<=tamanhoSequencia((sequencia)e);i++)
		if (strcmp(nome, e->nome))
			return i;
	return -1;
} 


arqueologo arqueologoComMaiorMerito(equipa e)
{
    arqueologo maxArq = elementoPosSequencia(e->arqueologos, 1) ;
    int num = tamanhoSequencia(e->arqueologos);

    for (int i=2; i<=num; i++)
    {
        arqueologo a = elementoPosSequencia(e->arqueologos, i);
        if (calcularMeritoArqueologo(maxArq) == calcularMeritoArqueologo(a)){
            if (daPenalizacaoArqueologo(maxArq) == daPenalizacaoArqueologo(a)){
                if (strcmp(daNomeArqueologo(maxArq), daNomeArqueologo(a)) < 0) {
                    maxArq = a;
                }
            }
            else if (daPenalizacaoArqueologo(maxArq) < daPenalizacaoArqueologo(a)){
                maxArq = a;
            }
        }
        else if (calcularMeritoArqueologo(maxArq) < calcularMeritoArqueologo(a)){
            maxArq = a;
        }
    }

    return maxArq;
}


void alteraNumEquipa (equipa e, int num){
    e->nEquipa=num;
}

void alteraNomeEquipa (equipa e, char *nome){
    strcpy(e->nome, nome);
}

equipa daEquipa(equipa e, char * nome){
    int i;
    for (i = 1; i<=tamanhoSequencia((sequencia)e);i++)
        if (strcmp(nome, e->nome))
            return e;
    return NULL;
}

sequencia daArqueologoDaEquipa(equipa e){
    return e->arqueologos;
}