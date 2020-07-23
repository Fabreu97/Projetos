#include "Jogo.h"

Jogo::Jogo()
{
    g = new Gerenciador_Grafico();
    Entidade::setGerenciadorGrafico(g);

    t = new Tela();
}

Jogo::~Jogo()
{
    //delete p1;
    //p1 = NULL;
    //delete p2;
    //p2 = NULL;

    Entidade::setGerenciadorGrafico(NULL);
    delete g;
    g = NULL;
    delete(t);
}

void Jogo::Executar()
{
    while(g->isOpen())
    {
        g->set_Delta_Time();
        cout << "Delta Time: " << g->get_Delta_Time() << endl;
        while(g->captar_Evento())
        {
            if(g->fecho_Janela())
            {
                g->fecha_Janela();
            }
            if(g->Resized())
            {
                g->ResizeView();
            }
        }
        t->Executar();
    }
}
