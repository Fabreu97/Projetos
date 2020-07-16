#include "Pessoa.h"
#include <string.h>

Pessoa::Pessoa(int d, int m, int a,const char* n):
    idade(0)
{
    inicializar(d,m,a,n);
}

Pessoa::~Pessoa()
{
    destroiNome();
}

void Pessoa::destroiNome()
{
    delete(nome);
    tam = 0;
}

void Pessoa::setNome(const char* n)
{
    destroiNome();
    tam = strlen(n);
    nome = new char(tam + 1);
    strcpy(nome, n);
}

const char* Pessoa::getNome() const
{
    return(nome);
}

void Pessoa::inicializar(int d, int m, int a,const char* n)
{
    dia = d;
    mes = m;
    ano = a;
    tam = strlen(n);
    nome = new char(tam + 1);
    strcpy(nome, n);
}

void Pessoa::calculo_Idade(int da, int ma, int aa)
{
    idade = aa - ano;
    if(mes > ma)
    {
        idade--;
    }
    else
    {
        if(mes == ma)
        {
            if(dia > da)
            {
                idade--;
            }
        }
    }
}

const int Pessoa::get_Idade() const
{
    return(idade);
}

void Pessoa::print_Idade() const
{
    cout << "A idade de " << nome << ": " << this->get_Idade() << " anos"<< endl;
}
