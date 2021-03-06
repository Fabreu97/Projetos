#include "Principal.h"

Principal::Principal():
    cont_id_aluno(0),
    Fernando(cont_id_aluno++),
    AAA(cont_id_aluno++),
    BBB(cont_id_aluno++),
    CCC(cont_id_aluno++),
    DDD(cont_id_aluno++),
    EEE(cont_id_aluno++)
{
     inicializar();
}
Principal::~Principal()
{

}

void Principal::inicializar()
{
    inicializar_Aluno();
    inicializar_Professor();
    inicializar_Disciplina();
    inicializar_Departamento();
    inicializar_Universidade();
}

void Principal::inicializar_Aluno()
{
    Fernando.set_Nome("Fernando");
    AAA.set_Nome("AAA");
    BBB.set_Nome("BBB");
    CCC.set_Nome("CCC");
    DDD.set_Nome("DDD");
    EEE.set_Nome("EEE");
}

void Principal::inicializar_Professor()
{
    Einstein.inicializar(14, 3 , 1879, "Einstein");
    Newton.inicializar(14, 3, 1643, "Newton");
    Simao.inicializar(3, 10, 1976, "Simao");

    Einstein.set_Departamento(&Fisica_Cambridge);
    Newton.set_Departamento(&Matematica_Princeton);
    Simao.set_Departamento(&DAINF);

    Simao.set_Universidade(&UTFPR);
    Einstein.set_Universidade(&Princeton);
    Newton.set_Universidade(&Cambridge);

}

void Principal::inicializar_Disciplina()
{
    Computacao1_2006.set_Nome("Computacao I - 2006");
    Introd_Alg_2007.set_Nome("introducao a Algoritmo - 2007");
    Computacao2_2007.set_Nome("Computacao II - 2007");
    Metodos2_2007.set_Nome("Metodos II - 2007");

    Computacao1_2006.set_Departamento(&DAINF);
    Computacao2_2007.set_Departamento(&DAINF);
    Introd_Alg_2007.set_Departamento(&DAINF);
    Metodos2_2007.set_Departamento(&DAINF);

    Metodos2_2007.inclua_Aluno(&Fernando);
    Metodos2_2007.inclua_Aluno(&AAA);
    Metodos2_2007.inclua_Aluno(&BBB);
    Metodos2_2007.inclua_Aluno(&DDD);
    Metodos2_2007.inclua_Aluno(&CCC);

    Computacao2_2007.inclua_Aluno(&AAA);
    Computacao2_2007.inclua_Aluno(&CCC);
    Computacao2_2007.inclua_Aluno(&EEE);
}

void Principal::inicializar_Departamento()
{
    MODA.set_Nome("MODA");
    DAINF.set_Nome("DAINF");
    DAFIS.set_Nome("DAFIS");
    Matematica_Princeton.set_Nome("Matematica");
    Fisica_Cambridge.set_Nome("Fisica");
}

void Principal::inicializar_Universidade()
{
    UTFPR.set_Nome("UTFPR");
    Princeton.set_Nome("Universidade de Princeton");
    Cambridge.set_Nome("Universidade de Cambridge");

    UTFPR.set_Departamento(&MODA);
    UTFPR.set_Departamento(&DAINF);
    UTFPR.set_Departamento(&DAFIS);
    Princeton.set_Departamento(&Matematica_Princeton);
    Cambridge.set_Departamento(&Fisica_Cambridge);
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

    DAINF.liste_Disciplina();

    Metodos2_2007.liste_Aluno();
    Computacao2_2007.liste_Aluno2();

}
