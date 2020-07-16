#include "ListaDisciplina.h"
#include <stdio.h>

ListaDisciplina::ListaDisciplina(int nd):
    max_disc(nd),
    cont_disc(0)
    {
        ptr_atual = NULL;
        ptr_primeiro = NULL;
    }

ListaDisciplina::~ListaDisciplina()
{
    ElDisciplina* aux = ptr_primeiro;

    while(aux != NULL)
    {
        ptr_primeiro = aux->ptr_prox;
        delete(aux);
        aux = ptr_primeiro;
    }
    ptr_atual = NULL;
    ptr_primeiro = NULL;
}

void ListaDisciplina::inclua_Disciplina(Disciplina* d)
{
    ElDisciplina* aux = new ElDisciplina();
    aux->set_Disciplina(d);

    if(cont_disc < max_disc && d != NULL)
    {
        if(ptr_primeiro == NULL)
        {
            ptr_atual = aux;
            ptr_primeiro = aux;
        }
        else
        {
            ptr_atual->ptr_prox = aux;
            aux->ptr_anterior = ptr_atual;
            ptr_atual = aux;
        }
        cont_disc++;
    }
    else
    {
        printf("Disciplina nao incluida!\n");
    }
}

void ListaDisciplina::liste_Disciplina()
{
    ElDisciplina* aux = ptr_primeiro;

    while(aux != NULL)
    {
        printf("\t%s\n", aux->get_Nome());
        aux = aux->ptr_prox;
    }
}

void ListaDisciplina::liste_Disciplina2()
{
    ElDisciplina* aux = ptr_atual;

    while(aux != NULL)
    {
        printf("\t%s\n", aux->get_Nome());
        aux = aux->ptr_anterior;
    }
}
