#include "Pessoa.h"
#include <stdio.h>
/*
Slide 1A - Apresenta
Slide 1B - Fala a diferencia TAD usado em C por meio de struct com a TAD
           usada na linguagem C++(OO) por class.
           Sendo esses slide utilizado pra fazer esse projeto
Slide 1C - Conteudo desses slides são o estudo de passagem de parametros pra funções
           através por referência, referência escondida ou passagem por valor.
*/
int main()
{
    Pessoa Einstein(14, 3, 1879);
    Pessoa Newton(4, 1, 1643);

    Einstein.calculo_Idade(19, 3, 2020);
    Newton.calculo_Idade(19, 3, 2020);

    printf("Einstein teria de idade %d anos\n", Einstein.informa_Idade());
    printf("Newton teria de idade %d anos\n", Newton.informa_Idade());

    return 0;
}
