#include "Aluno.h"
#include <stdio.h>

Aluno::Aluno(const long int r, int d, int m, int a, const char* n):
    Pessoa(d,m,a,n),
    RA(r)
    {

    }

Aluno::~Aluno()
{

}

void Aluno::setRA(const long int r)
{
    RA = r;
}

const long int Aluno::getRA() const
{
    return(RA);
}

void Aluno::print_Idade() const
{
    cout << "A idade do Aluno " << nome << ": " << idade << " anos" << endl;
}
