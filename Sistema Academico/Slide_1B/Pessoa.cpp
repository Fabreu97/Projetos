#include "Pessoa.h"

Pessoa::Pessoa()
{
    diaP = 0;
    mesP = 0;
    anoP = 0;
    idadeP = 0;
}

Pessoa::Pessoa(int diaNa, int mesNa, int anoNa)
{
    diaP = diaNa;
    mesP = mesNa;
    anoP = anoNa;
    idadeP = 0;
}

void Pessoa::calculo_Idade(int diaAT, int mesAT, int anoAT)
{
    idadeP = anoAT - anoP;
    if(mesP < mesAT)
    {
        idadeP--;
    }
    else
    {
        if(mesAT == mesP)
        {
            if(diaAT > diaP)
            {
                idadeP--;
            }
        }
    }
}

int Pessoa::get_Idade()
{
    return(idadeP);
}
