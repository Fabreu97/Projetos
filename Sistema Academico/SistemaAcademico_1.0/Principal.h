#ifndef INCLUDED_PRINCIPAL_H
#define INCLUDED_PRINCIPAL_H

#include "Universidade.h"
#include "Departamento.h"

#define DIA 5
#define MES 3
#define ANO 2020

class Principal
{
private:
    static const int dia_atual = 8;
    static const int mes_atual = 3;
    static const int ano_atual = 2020;

    // Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    // Departamentos
    Departamento EletronicaUTFPR;
    Departamento MatematicaUTFPR;
    Departamento FisicaUTFPR;
    Departamento MatematicaPrinceton;
    Departamento FisicaPrinceton;
    Departamento MatematicaCambridge;
    Departamento FisicaCambridge;

    // Professores
    Professor Simao;
    Professor Einstein;
    Professor Newton;

    // Disciplinas
    Disciplina	Computacao1_2006;
    Disciplina	Introd_Alg_2007;
    Disciplina	Computacao2_2007;
    Disciplina	Metodos2_2007;
    Disciplina TecProg;
    Disciplina Fisica_2;
    Disciplina Oficina_1;

	// Alunos
    Aluno AAA;
    Aluno BBB;
    Aluno CCC;
    Aluno DDD;
    Aluno EEE;
    Aluno Fernando;

    //Listas
    Lista2<Aluno> LAluno;
    Lista2<Professor> LProfessor;
    Lista2<Departamento> LDepartamento;
    Lista2<Universidade> LUniversidade;

public:
    Principal();
    ~Principal();

    void inicializar_Pessoas();
    void inicializar_Alunos();
    void inicializar_Professor();
    void inicializar_Disciplina();
    void inicializar_Departamento();
    void inicializar_Universidade();


    void Executar() const;
};

#endif // INCLUDED_PRINCIPAL_H
