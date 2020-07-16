#include "Professor.h"
#include <stdio.h>

Professor::Professor(int d, int m, int a, const char* n):
    Pessoa(d,m,a,n)
    {


    }
Professor::~Professor()
{

}

void Professor::print_Idade() const
{
    cout << "A idade do Professor " << nome << ": " << idade << " anos" << endl;
}
