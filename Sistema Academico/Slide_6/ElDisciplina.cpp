#include "ElDisciplina.h"

ElDisciplina::ElDisciplina()
{
    ptr_info = NULL;
    ptr_anterior = NULL;
    ptr_prox = NULL;
}

ElDisciplina::~ElDisciplina()
{
    ptr_info = NULL;
    ptr_anterior = NULL;
    ptr_prox = NULL;
}

void ElDisciplina::set_Disciplina(Disciplina* d)
{
    ptr_info = d;
}

Disciplina* ElDisciplina::get_Disciplina()
{
    return(ptr_info);
}

char* ElDisciplina::get_Nome()
{
    return(ptr_info->get_Nome());
}
