#include "Aluno.h"
#include "Universidade.h"

Aluno::Aluno(int id, int ra, int d, int m, int a, const char* n):
    Pessoa(d,m,a,n),
    ID(id),
    RA(ra)
{
    ptr_univer = NULL;
}

Aluno::~Aluno()
{
    ptr_univer = NULL;
}

void Aluno::set_RA(const int r)
{
    RA = r;
}

const int Aluno::get_RA() const
{
    return(RA);
}

void Aluno::set_ID(const int id)
{
    this->ID = id;
}

const int Aluno::get_ID() const
{
    return(ID);
}

void Aluno::set_Universidade(Universidade* u)
{
    ptr_univer = u;
}

Universidade* Aluno::get_Universidade() const
{
    return(ptr_univer);
}

void Aluno::print_Info()
{
    cout << "\t\t" << get_Nome() << " - ("  << get_RA() << ") - ID: " << ID << endl;
    cout << "\t\t" << "Idade: " << get_Idade() << " anos" << endl;
}
