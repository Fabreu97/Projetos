#ifndef INCLUDED_DEPARTAMENTO_H
#define INCLUDED_DEPARTAMENTO_H

class Universidade;
class Disciplina;

class Departamento
{
private:

    char nome[50];
    Universidade* ptr_univer;

    Disciplina* ptr_primeiro;
    Disciplina* ptr_atual;

public:
    Departamento(const char* n = "");
    ~Departamento();

    void set_Nome(char* n);
    char* get_Nome();

    void set_Universidade(Universidade* u);
    Universidade* get_Universidade();

    void incluir_Disciplina(Disciplina* d);
    void liste_Disciplina();
};

#endif // INCLUDED_DEPARTAMENTO_H
