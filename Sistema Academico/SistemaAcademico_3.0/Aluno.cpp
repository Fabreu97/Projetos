#include "Aluno.h"
#include "Universidade.h"

Aluno::Aluno(int id, int ra, int d, int m, int a, const char* n):
    Pessoa(d,m,a,n),
    ID(id),
    RA(ra)
{
    set_ID(id);
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
    cout << "\t\t" << *this << " - ("  << get_RA() << ") - ID: " << get_ID() << endl;
    cout << "\t\t" << "Idade: " << get_Idade() << " anos" << endl;
}

void Aluno::informa_Proventos() const
{
    cout << "Nenhum provento a ser informado do Aluno " << nome.getString() << endl;
}

ostream& operator<<(ostream& saida, Aluno& a)
{
    saida << a.get_Nome();
    return(saida);
}
