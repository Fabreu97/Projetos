#ifndef INCLUDED_ALUNO_H
#define INCLUDED_ALUNO_H

#include "Pessoa.h"

class Aluno: public Pessoa
{
private:

    int RA;

public:

    Aluno(int id, int d = 0, int m = 0, int a = 0, const char* nome = "Default");
    ~Aluno();

    void set_RA(int ra);
    int get_RA();
};

#endif // INCLUDED_ALUNO_H
