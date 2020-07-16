#include "Estagiario.h"

Estagiario::Estagiario(float be, int id, int ra, int d, int m, int a, const char* n):
    Aluno(id,ra,d,m,a,n),
    bolsa_estudo(be)
    {

    }

Estagiario::~Estagiario()
{

}

void Estagiario::set_Bolsa(const float be)
{
    bolsa_estudo = be;
}

const float Estagiario::get_Bolsa() const
{
    return(bolsa_estudo);
}

void Estagiario::informa_Proventos() const
{
    cout << "O valor da Bolsa de " << get_Nome() << " eh " << bolsa_estudo << "." << endl;
}
