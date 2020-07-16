#include "Pessoa.h"

Pessoa::Pessoa()
{
    //valores pra default
    dia = 0;
    mes = 0;
    ano = 0;
    idade = 0;
}

Pessoa::Pessoa(int d, int m, int a)
{
    dia = d;
    mes = m;
    ano = a;
    idade = 0;
}

Pessoa::~Pessoa()
{

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
