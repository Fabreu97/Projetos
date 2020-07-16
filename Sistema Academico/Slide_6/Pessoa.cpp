#include "Pessoa.h"
#include "Universidade.h"
#include <string.h>

Pessoa::Pessoa(int d, int m, int a, const char* nome)
{
    dia = d;
    mes = m;
    ano = a;
    idade = 0;
    strcpy(nomep, nome);
    ptr_univer = NULL;
}

Pessoa::~Pessoa()
{
    ptr_univer = NULL;
}

void Pessoa::calculo_Idade(int da, int ma, int aa)
{
    idade = aa - ano;

    if(ma > mes)
    {
        idade--;
    }
    else
    {
        if(mes == ma)
        {
            if(da > dia)
            {
                idade--;
            }
        }
    }
}

int Pessoa::informa_Idade()
{
    return(idade);
}

void Pessoa::print_Idade()
{
    cout << "A idade da Pessoa " << nomep << " teria " << informa_Idade() << " anos" << endl;
}

void Pessoa::inicializar(int d, int m, int a, const char* n)
{
    dia = d;
    mes = m;
    ano = a;

    set_Nome(n);
}

void Pessoa::set_Nome(const char* n)
{
    strcpy(nomep, n);
}

char* Pessoa::get_Nome()
{
    return(nomep);
}

void Pessoa::set_ID(int i)
{
    this->ID = i;
}

int Pessoa::get_ID()
{
    return(ID);
}

void Pessoa::set_Universidade(Universidade* u)
{
    ptr_univer = u;
}

Universidade* Pessoa::get_Universidade() const
{
    return(ptr_univer);
}

void Pessoa::Onde_Trabalha() const
{
    if(ptr_univer != NULL)
    {
        cout << "A Pessoa " << nomep << " trabalha na " << ptr_univer->get_Nome() << endl;
    }
}
