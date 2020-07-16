#ifndef INCLUDED_ELEMENTO_ALUNO_H
#define INCLUDED_ELEMENTO_ALUNO_H

#include "Aluno.h"

class ElAluno
{
private:

    Aluno* ptr_info;

public:

    ElAluno();
    ~ElAluno();

    ElAluno* ptr_prox;
    ElAluno* ptr_anterior;

    void set_Aluno(Aluno* a);
    Aluno* get_Aluno();
    char* get_Nome();
};

#endif // INCLUDED_ELEMENTO_ALUNO_H
