#include "Aluno.h"

Aluno::Aluno(int id, int d, int m, int a, const char* nome):
    Pessoa(d,m,a,nome)
{
    this->ID = id;
}

Aluno::~Aluno()
{

}

void Aluno::set_RA(int ra)
{
    RA = ra;
}

int Aluno::get_RA()
{
    return(RA);
}
