#include "Universidade.h"
#include <string.h>

Universidade::Universidade(const char* n)
{
    if(n != NULL)
    {
        strcpy(nome, n);
    }
}

Universidade::~Universidade()
{

}

void Universidade::set_Nome(const char* n)
{
    if(n != NULL)
    {
        strcpy(nome, n);
    }
}

const char* Universidade::get_Nome() const
{
    return(nome);
}
