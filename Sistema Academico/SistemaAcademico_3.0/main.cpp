#include "Principal.h"

int main()
{
    //Principal* objeto = new Principal();
    //objeto->Executar();
    char aux[8] = "possui ";
    MinhaString b1,b2("Minha casa ");
    MinhaString b3 = "carro rebaixado!";
    b1 = b2 + aux + b3;
    cout << b1;

    //delete(objeto);

    return 0;
}
