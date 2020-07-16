#include "Principal.h"

Principal::Principal():
    Einstein(14, 3 , 1879, "Einstein"), // chamando o contrutor do objeto de Pessoa, Einstein, com parametro
    Newton(14, 3, 1643, "Newton"), // Quando for dentro do escobo do metodo é chamado a construção sem parametro
    Simao(3, 10, 1976, "Simao")
    {
        UTFPR.set_Nome("UTFPR");
        Princeton.set_Nome("Universidade de Princeton");
        Cambridge.set_Nome("Universidade de Cambridge");

        Simao.set_Universidade(&UTFPR);
        Einstein.set_Universidade(&Princeton);
        Newton.set_Universidade(&Cambridge);

        MODA.set_Nome("MODA");
        DAINF.set_Nome("DAINF");
        DAFIS.set_Nome("DAFIS");
        Fisica_Princeton.set_Nome("Fisica");
        Matematica_Cambridge.set_Nome("Matematica");

        UTFPR.set_Departamento(&MODA);
        UTFPR.set_Departamento(&DAINF);
        UTFPR.set_Departamento(&DAFIS);
        Princeton.set_Departamento(&Fisica_Princeton);
        Cambridge.set_Departamento(&Matematica_Cambridge);
    }
Principal::~Principal()
{

}

void Principal::Executar()
{
    Einstein.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Newton.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Simao.calculo_Idade(dia_atual, mes_atual, ano_atual);

    Einstein.print_Idade();
    Newton.print_Idade();
    Simao.print_Idade();

    Simao.Onde_Trabalha();
    Einstein.Onde_Trabalha();
    Newton.Onde_Trabalha();

    UTFPR.imprimir_Departamentos();
    Princeton.imprimir_Departamentos();
    Cambridge.imprimir_Departamentos();

}
