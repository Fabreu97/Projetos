#include "Pessoa.h"
#include "Universidade.h"

using namespace std;

int Pessoa::cont = 0;

Pessoa::Pessoa(int d, int m, int a, const char* n):
    nome(n)
{
    dia = d;
    mes = m;
    ano = a;
    idade = 0;
    cont++;
}

Pessoa::~Pessoa()
{
    dia = 0;
    mes = 0;
    ano = 0;
    cont--;
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

void Pessoa::set_Idade(const int i)
{
    idade = i;
}

const int Pessoa::get_Idade() const
{
    return(idade);
}

void Pessoa::set_Nome(const char* n)
{
    nome.setString(n);
}

const char* Pessoa::get_Nome() const
{
    return(nome.getString());
}

int Pessoa::get_Cont()
{
    return(cont);
}

void Pessoa::print_Info()
{
    if(nome.getString() != NULL)
    {
        cout << "A pessoa " << get_Nome() <<  " teria " << get_Idade() << " anos" << endl;
    }
    else
    {
        cout << "Pessoa sem informacao" << endl;
    }
}

void Pessoa::informa_Proventos() const
{
    cout << "Nenhuma informacao sobre proventos de " << nome.getString() << "." <<endl;
}


ostream& operator<<(ostream& saida, Pessoa& a)
{
    saida << a.get_Nome();
    return(saida);
}
