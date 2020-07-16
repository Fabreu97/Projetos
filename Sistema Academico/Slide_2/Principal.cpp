#include "Principal.h"

Principal::Principal():
    Einstein(14, 3 , 1879, "Einstein"), // chamando o contrutor do objeto de Pessoa, Einstein, com parametro
    Newton(14, 3, 1643, "Newton"), // Quando for dentro do escobo do metodo é chamado a construção sem parametro
    Simao(3, 10, 1976, "Simao")
    {
        UTFPR.set_Nome("UTFPR");
        Princeton.set_Nome("Universidade de Princeton");
        Cambridge.set_Nome("Universidade de Cambridge");
    }
Principal::~Principal()
{

}

void Principal::Executar()
{
    Einstein.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Newton.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Simao.calculo_Idade(dia_atual, mes_atual, ano_atual);

    Simao.set_Universidade(&UTFPR);
    Einstein.set_Universidade(&Princeton);
    Newton.set_Universidade(&Cambridge);

    Einstein.print_Idade();
    Newton.print_Idade();
    Simao.print_Idade();

    Simao.Onde_Trabalha();
    Einstein.Onde_Trabalha();
    Newton.Onde_Trabalha();

}
