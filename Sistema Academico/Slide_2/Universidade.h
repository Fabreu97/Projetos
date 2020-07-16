#ifndef INCLUDED_UNIVERSIDADE_H
#define INCLUDED_UNIVERSIDADE_H

class Universidade
{
private:
    char nome[50];

public:
    Universidade(const char* n = "Default"); //Construtor
    ~Universidade();                         //Destrutor

    void set_Nome(const char* n);
    const char* get_Nome() const;
};

#endif // INCLUDED_UNIVERSIDADE_H
