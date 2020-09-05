#ifndef INCLUDED_UNIVERSIDADE_H
#define INCLUDED_UNIVERSIDADE_H

#include "ListaDepartamento.h"

class Universidade
{
private:
    int ID;
    MinhaString nome;

    ListaDepartamento LDepartamento;

public:

    Universidade(int id, const char* n = "");
    ~Universidade();

    void set_ID(const int id);
    const int get_ID() const;
    void set_Nome(const char* n);
    const char* get_Nome() const;

    bool incluir_Departamento(Departamento* d);
    void limpar();
    void listar_Departamentos() const;
};

ostream& operator<<(ostream& saida, Universidade& u);

#endif // INCLUDED_UNIVERSIDADE_H
