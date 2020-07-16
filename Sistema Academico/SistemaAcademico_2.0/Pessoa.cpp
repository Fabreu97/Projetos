#include "Pessoa.h"
#include "Universidade.h"

using namespace std;

Pessoa::Pessoa(int d, int m, int a, const char* n)
{
    dia = d;
    mes = m;
    ano = a;
    idade = 0;

    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(nome, n);
}

Pessoa::~Pessoa()
{
    this->destroiNome();
    dia = 0;
    mes = 0;
    ano = 0;
}

void Pessoa::inicializar(int d, int m, int a, const char* n)
{
    dia = d;
    mes = m;
    ano = a;
    if(n != NULL)
    {
        set_Nome(n);
    }
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
            if(da < dia)
            {
                idade--;
            }
        }
    }
}

void Pessoa::destroiNome()
{
    free(nome);
    nome = NULL;
    tam = 0;
}

const int Pessoa::get_Idade() const
{
    return(idade);
}

void Pessoa::set_Nome(const char* n)
{
    destroiNome();

    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) + (tam + 1) );
    strcpy(nome, n);
}

const char* Pessoa::get_Nome() const
{
    return(nome);
}

void Pessoa::print_Info()
{
    if(nome != NULL)
    {
        cout << "A pessoa " << get_Nome() <<  " teria " << get_Idade() << " anos" << endl;
    }
    else
    {
        cout << "Pessoa sem informacao" << endl;
    }
}
