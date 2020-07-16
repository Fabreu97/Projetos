#ifndef INCLUDED_ELEMENTO_DISICPLINA_H
#define INCLUDED_ELEMENTO_DISICPLINA_H

#include "Disciplina.h"

class ElDisciplina
{
private:

    Disciplina* ptr_info;

public:

    ElDisciplina();
    ~ElDisciplina();

    ElDisciplina* ptr_prox;
    ElDisciplina* ptr_anterior;

    void set_Disciplina(Disciplina* d);
    Disciplina* get_Disciplina();
    char* get_Nome();
};

#endif // INCLUDED_ELEMENTO_DISICPLINA_H
