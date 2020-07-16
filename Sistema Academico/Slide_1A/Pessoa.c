#include "Pessoa.h"

int calculo_Idade(struct Pessoa p,  int ano)
{
    p.idade = ano - p.ano;
    return(p.idade);
}
