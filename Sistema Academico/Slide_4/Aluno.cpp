#include "Aluno.h"

Aluno::Aluno(int i)
{
    id = i;
}

Aluno::Aluno(int d, int m, int a, const char* nome):
    Pessoa(d,m,a,nome)
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
