#include "Professor.h"
#include "Departamento.h"

Professor::Professor(int id, int d, int m, int a, const char* n):
    Pessoa(d,m,a,n),
    ID(id),
    salario(0.0),
    bolsa_projeto(0.0)
    {
        ptr_univer = NULL;
    }

Professor::~Professor()
{
    ptr_univer = NULL;
}

void Professor::set_ID(const int i)
{
    ID = i;
}

const int Professor::get_ID() const
{
    return(ID);
}

void Professor::set_Salario(const float s)
{
    salario = s;
}

const float Professor::get_Salario() const
{
    return(salario);
}

void Professor::set_Bolsa_Projeto(const float bp)
{
    bolsa_projeto = bp;
}

const float Professor::get_Bolsa_Projeto() const
{
    return(bolsa_projeto);
}

void Professor::set_Universidade(Universidade* u)
{
    ptr_univer = u;
}

Universidade* Professor::get_Universidade() const
{
    return(ptr_univer);
}

void Professor::set_Departamento(Departamento* d)
{
    ptr_depart = d;
}
Departamento* Professor::get_Departamento() const
{
    return(ptr_depart);
}

void Professor::print_Info()
{
    Onde_Trabalha();
}

void Professor::Onde_Trabalha() const
{
    cout << "O Professor " << get_Nome() << " trabalha para " << get_Universidade()->get_Nome() << endl;
}

void Professor::Qual_Departamento_Trabalha() const
{
    cout << "O Professor " << get_Nome() << " trabalha para " << get_Universidade()->get_Nome() << " no Departamento " << get_Departamento()->get_Nome() << endl;
}

void Professor::informa_Proventos() const
{
    cout << "O Professor " << this->get_Nome() << " ganha R$: " << get_Salario() << endl;
}
