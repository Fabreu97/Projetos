#include "Principal.h"

Principal::Principal():
    Einstein(14, 3, 1879, "Einstein"),
    Newton(4, 1, 1643, "Newton"),
    LAluno(100),
    LProfessor(100),
    LDepartamento(100),
    LUniversidade(100)
{
    inicializar_Pessoas();
}
Principal::~Principal()
{

}

void Principal::inicializar_Pessoas()
{
    Fernando.inicializar(22, 1, 1997, "Fernando");

    Einstein.calculo_Idade(dia_atual,mes_atual, ano_atual);
    Newton.calculo_Idade(dia_atual,mes_atual, ano_atual);
    Fernando.calculo_Idade(dia_atual,mes_atual, ano_atual);
}

void Principal::Executar() const
{
    Einstein.print_Idade();
    Newton.print_Idade();
    Fernando.print_Idade();
}
