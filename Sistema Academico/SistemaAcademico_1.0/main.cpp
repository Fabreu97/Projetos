#include "Principal.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//#include "Lista.h"
int main()
{
    Principal p;
    p.Executar();

    Lista2<int> lista;
    int a,b,c,d;
    a = 2;
    b = 5;
    c = 8;
    d = 1;

    lista.incluirInformacao(&a);
    lista.incluirInformacao(&b);
    lista.incluirInformacao(&c);
    lista.incluirInformacao(&d);

    int i;
    for(i = 0; i < (lista.getTamanho()); i++)
    {
        int* aux;
        aux = lista.getInformacao(i);
        if(aux != NULL)
        {
            printf("\t%d",*aux);
        }
    }

    return 0;
}
