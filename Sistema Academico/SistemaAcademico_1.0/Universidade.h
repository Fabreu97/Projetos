#ifndef INCLUDED_UNIVERSIDADE_H
#define INCLUDED_UNIVERSIDADE_H

class Universidade
{
private:

    char* ptr_nome;
    int tamanho;

public:

    Universidade(const char* n = "");
    ~Universidade();

    void destroiNome();
    void setNome(char* n);
    const char* getNome() const;
    void printNome() const;

};
#endif // INCLUDED_UNIVERSIDADE_H
