#include "Disciplina.h"
#include "Departamento.h"

Disciplina::Disciplina(int id, const char* n):
    ID(id),
    nome(n),
    ptr_depar(NULL)
{

}

Disciplina::~Disciplina()
{
    ptr_depar = NULL;
    limpa();
}

void Disciplina::set_ID(const int id)
{
    ID = id;
}

const int Disciplina::get_ID() const
{
    return(ID);
}

void Disciplina::set_Nome(const char* n)
{
    nome.setString(n);
}

const char* Disciplina::get_Nome() const
{
    return(nome.getString());
}

void Disciplina::set_Departamento(Departamento* d)
{
    ptr_depar = d;
}

Departamento* Disciplina::get_Departamento() const
{
    return(ptr_depar);
}

bool Disciplina::incluir_Aluno(Aluno* a)
{
    return(LAluno.incluir_Aluno(a));
}

void Disciplina::limpa()
{
    LAluno.limpar();
}

void Disciplina::listar_Aluno()
{
    cout << endl << endl <<"A Disciplina " << this << " tem matriculado " << LAluno.get_Tamanho() << " Alunos que sao:" << endl << endl;
    LAluno.listar_Aluno();
}

ostream& operator<<(ostream& saida, Disciplina& d)
{
    saida << d.get_Nome();
    return(saida);
}

