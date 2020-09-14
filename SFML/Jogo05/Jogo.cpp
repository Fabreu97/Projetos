#include "Jogo.h"

Jogo::Jogo()
{
    g = new Gerenciador_Grafico();
    Entidade::setGerenciadorGrafico(g);

    t = new Tela();
}

Jogo::~Jogo()
{
    Entidade::setGerenciadorGrafico(NULL);
    delete g;
    g = NULL;
    delete(t);
}

void Jogo::Executar()
{
    //g->setFramerateLimit(120lu);
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
        t->run();
        if(g->isPR())
        {
            t->tirarTexture(t);
        }
    }
}
