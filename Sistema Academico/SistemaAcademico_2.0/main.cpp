#include "Principal.h"
//#include "Lista.h"
#include "Lista2.h"
int main()
{
    Principal* objeto = new Principal();
    objeto->Executar();

    delete(objeto);

    return 0;
}
