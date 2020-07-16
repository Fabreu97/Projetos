#include "MinhaString.h"

#define TAM 20

using namespace ms;

int main()
{
    MinhaString S1 ( "Minha primeira string soh minha." );
    MinhaString S2A, S2B, S2C;

    S2A = "Operador de atribuicao sobrecarregado eh muito util.";
    S2B = "Eu aprendi a sobrecarregar operador!!!";

    cout << "S1 = " << S1 << endl;
    cout << "S2A = " << S2A << endl;
    cout << "S2B = " << S2B << endl;
    cout << endl;

    S1 = S2B + S2A + S1;

    cout << "S1 = " << S1 << endl;

    cout << "Digite algo para ser inserido em S1: ";
    cin >> S1;

    cout << endl << endl << S1 << endl << endl;

    cout << S1.get_Nome_Classe() << " " << S1.get_Numero_Objetos() << endl;
    cout << S2A.get_Nome_Classe() << " " << S2A.get_Numero_Objetos() << endl;
    cout << S2B.get_Nome_Classe() << " " << S2B.get_Numero_Objetos() << endl;

    return 0;
}
