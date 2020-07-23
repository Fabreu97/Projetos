#include "Jogo.h"

Jogo::Jogo()
{
    g = new Gerenciador_Grafico();
    Entidade::setGerenciadorGrafico(g);

    p1 = new Jogador01(HEIGHTJUMPER);
    p1->setTexture("Texture/n_linux.png");

    p2 = new Jogador02(HEIGHTJUMPER);
    p2->setSize(TAM_N_LINUX, TAM_N_LINUY);
    p2->setPosition(700.f, 800.0f);
    p2->setContImage(3,9);
    p2->PreencherLinhas(0,1);
    p2->setSpeed(SPEED_JOGADOR);
    p2->setTempoCiclo(0.2);
    p2->setTexture("Texture/n_linux.png");
    p2->InitialUpdate();
}

Jogo::~Jogo()
{
    delete p1;
    p1 = NULL;
    delete p2;
    p2 = NULL;
    if(f != NULL)
    {
        delete f;
        f = NULL;
    }
    Entidade::setGerenciadorGrafico(NULL);
    delete g;
    g = NULL;
}

void Jogo::criarFase(const unsigned long int i)
{
    f = new ent::tela::fase::Fase();
}

void Jogo::setJogadoresFase()
{
    f->setJogador(p1);
    f->setJogador(p2);
}

void Jogo::Executar()
{
    criarFase();
    setJogadoresFase();

    //g->setFramerateLimit(120);

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
        /*g->Centralizar(p1->getPosition(), p2->getPosition());
        g->setView();

        f->ChecarColisoesEntreJogadoresInimigosProjeteis();
        f->ChecarColisoesEntreJogadoresObstaculos();
        f->ChecarColisoesEntreObstaculos();
        f->ChecarColisoesEntreInimigosObstaculos();

        g->limpar_Janela();

        f->Draw(p1->getPosition(), p2->getPosition());
        g->Exibicao();*/
        f->ChecarOperacoes();
    }
}
