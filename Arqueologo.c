/*
 * Arqueologo.c
 */

#include <stdlib.h>
#include <string.h>
#include "Iterador.h"
#include "Sequencia.h"
#include "Equipa.h"
#include "Arqueologo.h"

struct _arqueologo
{
    int emJogo;
    int tesouros;
    int penalizacao;
};


arqueologo criaArqueologo()

arqueologo daArqueologoEquipa()

int daMeritoArqueologo(arqueologo a)
{
    int merito = 0;

    merito = a->tesouros - a-> penalisacoes;
    return merito;
}

void destroiEquipaeArqueologo()