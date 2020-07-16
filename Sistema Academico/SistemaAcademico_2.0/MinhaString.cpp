#include "MinhaString.h"

MinhaString::MinhaString(const char* n)
{
    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(nome, n);
}

MinhaString::~MinhaString()
{
    free(nome);
}

void MinhaString::set_Nome(const char* n)
{
    free(nome);
    tam = strlen(n);
    nome = (char*)malloc( sizeof(char) * (tam + 1) );
    strcpy(nome, n);
}

const char* MinhaString::get_Nome() const
{
    return(nome);
}
