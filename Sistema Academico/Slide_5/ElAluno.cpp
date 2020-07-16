#include "ElAluno.h"

ElAluno::ElAluno()
{
    ptr_anterior = NULL;
    ptr_prox = NULL;
    ptr_info = NULL;
}

ElAluno::~ElAluno()
{
    ptr_anterior = NULL;
    ptr_prox = NULL;
    ptr_info = NULL;
}

void ElAluno::set_Aluno(Aluno* a)
{
    ptr_info = a;
}

Aluno* ElAluno::get_Aluno()
{
    return(ptr_info);
}

char* ElAluno::get_Nome()
{
    return(ptr_info->get_Nome());
}
