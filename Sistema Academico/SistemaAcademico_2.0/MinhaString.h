#ifndef INCLUDED_MINHA_STRING_H
#define INCLUDED_MINHA_STRING_H

#include <string.h>
#include <stdlib.h>

class MinhaString
{
private:

    char* nome;
    int tam;

public:
    MinhaString(const char* n = "");
    ~MinhaString();

    void set_Nome(const char* n);
    const char* get_Nome() const;
};


#endif // INCLUDED_MINHA_STRING_H
