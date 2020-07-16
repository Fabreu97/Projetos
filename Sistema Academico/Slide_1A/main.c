#include "Pessoa.h"

int main()
{
    struct Pessoa Einstein, Newton;

    Einstein.dia = 14;
    Einstein.mes = 3;
    Einstein.ano = 1879;

    Newton.dia = 4;
    Newton.mes = 1;
    Newton.ano = 1643;

    printf("A idade de Eisntein seria %d anos\n", calculo_Idade(Einstein, 2007));
    printf("A idade de Newton seria %d anos\n", calculo_Idade(Newton, 2007));

    getchar();

}
