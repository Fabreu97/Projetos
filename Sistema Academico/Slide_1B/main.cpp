#include "Pessoa.h"
using namespace std;

int main()
{
    Pessoa Einstein(14, 3, 1879);
    Pessoa Newton(4, 1, 1643);

    Einstein.calculo_Idade(27, 3, 2020);
    Newton.calculo_Idade(27, 3, 2020);

    printf("Einstein teria %d anos\n", Einstein.get_Idade());
    printf("Newton teria %d anos\n", Newton.get_Idade());

    getchar();

    return(0);
}
