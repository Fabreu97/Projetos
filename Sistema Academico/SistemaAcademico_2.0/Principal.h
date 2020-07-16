#ifndef INCLUDED_PRINCIPAL_H
#define INCLUDED_PRINCIPAL_H

#include "ListaUniversidade.h" // ListaDepartamento, ListaDisciplina, ListaAluno
#include "ListaProfessor.h" // Professor, Pessoa

class Principal
{
private:

    int cont_ID_aluno;
    int cont_ID_prof;
    int cont_ID_disc;
    int cont_ID_depar;
    int cont_ID_univer;

    static const int dia_atual = 17;
    static const int mes_atual = 3;
    static const int ano_atual = 2020;

    //Alunos
    Aluno Fernando;
    Aluno AAA;
    Aluno BBB;
    Aluno CCC;
    Aluno DDD;
    Aluno EEE;
    Aluno Guilherme;

    //Professores
    Professor Einstein;
    Professor Newton;
    Professor Simao;
    Professor Barreto;

    //Discilpina
    Disciplina Computacao1_2006;
    Disciplina Introd_Alg_2007;
    Disciplina Computacao2_2007;
    Disciplina Metodos2_2007;
    Disciplina Calculo_III;
    Disciplina Fisica_III;

    //Departamentos
    Departamento DAELN;
    Departamento DAMAT;
    Departamento DAFIS;
    Departamento DAINF;
    Departamento Fisica_Princeton;
    Departamento Matematica_Cambridge;

    //Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;
    Universidade UNICAMP;

    //Listas
    ListaAluno LAluno;
    ListaProfessor LProfessor;
    ListaDisciplina LDisciplina;
    ListaDepartamento LDepartamento;
    ListaUniversidade LUniversidade;

public:

    Principal();
    ~Principal();

    //Inicializações Iniciais dos atributos
    void inicializar();
    void inicializar_Aluno();
    void inicializar_Professor();
    void inicializar_Disciplina();
    void inicializar_Departamento();
    void inicializar_Universidade();
    void inicializar_Listas();
    void calculo_Idade();

    //Menus
    void Menu();

    void menu_Cadastrar();
    void cadastrar_Aluno();
    void cadastrar_Professor();
    void cadastrar_Disciplina();
    void cadastrar_Departamento();
    void cadastrar_Universidade();

    void menu_Executar();
    void liste_Alunos_Disc();
    void lista_Disciplina_Depart();
    void liste_Departamento_Univer();

    void menu_Gravar();
    void menu_Gravar_Alunos();
    void menu_Gravar_Professor();
    void menu_Gravar_Disciplina();
    void menu_Gravar_Departamento();
    void menu_Gravar_Universidade();
    void menu_Gravar_Tudo();

    void menu_Recuperar();
    void menu_Recuperar_Tudo();
    void menu_Recuperar_Alunos();
    void menu_Recuperar_Professores();
    void menu_Recuperar_Disciplinas();
    void menu_Recuperar_Departamentos();
    void menu_Recuperar_Universidades();

    //Execução do Programa
    void Executar();
};

#endif // INCLUDED_PRINCIPAL_H


