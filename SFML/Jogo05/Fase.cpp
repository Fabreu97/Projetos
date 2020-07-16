#include "Fase.h"

ent::fase::Fase::Fase(const string c):
    ent::Entidade(c)
{
    ptr1 = NULL;
    ptr2 = NULL;
    posicao_obst = Vector2D<float>(0.0f, 1000.0f);
    gc1.setListas(&LObstaculo);
    gc1.setListas(&VInimigo);
}

ent::fase::Fase::~Fase()
{
    LEntidade.limpar();
    VInimigo.limpar();
    LObstaculo.limpar();
}

void ent::fase::Fase::setJogador(ent::per::jog::Jogador01* p1)
{
    ptr1 = p1;
    LEntidade.incluirEntidade(ptr1);
    gc1.setJogador(p1);
}

void ent::fase::Fase::setJogador(ent::per::jog::Jogador02* p2)
{
    ptr2 = p2;
    LEntidade.incluirEntidade(ptr2);
    gc1.setJogador(p2);
}

void ent::fase::Fase::setTexture(const string t)
{
    caminho = t;
    control->setTextureFase(caminho);
}

void ent::fase::Fase::InitialUpdate ()
{

}
void ent::fase::Fase::UpdateGerenciador ()
{
    control->setSizeFase(tam);
    pos = control->getPositionFase();
}
void ent::fase::Fase::Update ()
{

}
void ent::fase::Fase::adicionarEntidade(ent::Entidade* e)
{
    LEntidade.incluirEntidade(e);
}

void ent::fase::Fase::Draw()
{
    LEntidade.Draw();
}

void ent::fase::Fase::Draw(const Vector2D<float> pos1)
{
    LEntidade.Draw(pos1);
}

void ent::fase::Fase::Draw(const Vector2D<float> pos1, const Vector2D<float> pos2)
{
    LEntidade.Draw(pos1, pos2);
}

//VECTOR DE INIMIGO

void ent::fase::Fase::adicionarInimigo01(const Vector2D<float> position)
{
    ent::per::ini::Inimigo* inimigo = new ent::per::ini::Inimigo01 ();
    inimigo->setSize(TAM_N_LINUX, TAM_N_LINUY);
    inimigo->setPosition(position);
    inimigo->setContImage(1,1);
    inimigo->PreencherLinhas(0,0);
    inimigo->setTexture("imagem/n_linux.png");

    VInimigo.incluirInimigo(inimigo);
    LEntidade.incluirEntidade(inimigo);
}

void ent::fase::Fase::adicionarInimigo01(const float x, const float y)
{
    ent::per::ini::Inimigo01* inimigo = new ent::per::ini::Inimigo01 ();
    inimigo->setSize(TAM_N_LINUX, TAM_N_LINUY);
    inimigo->setPosition(x, y);
    inimigo->setContImage(3,9);
    inimigo->PreencherLinhas(0,1);
    inimigo->setTempoCiclo(0.2);
    inimigo->setTexture("imagem/n_linux.png");
    inimigo->InitialUpdate();

    VInimigo.incluirInimigo(inimigo);
    LEntidade.incluirEntidade(inimigo);
}

void ent::fase::Fase::ChecarColisoesEntreInimigosObstaculos()
{
    gc1.ChecarColisoesInimigosObstaculos();
}

void ent::fase::Fase::ChecarColisoesEntreJogadoresInimigosProjeteis()
{
    gc1.ChecarColisoesJogadoresInimigosProjeteis();
}

void ent::fase::Fase::adicionarObstaculoPlataforma()
{
    ent::obs::Obstaculo* o = new ent::obs::Obstaculo("imagem/MeioChaoGrande.png", posicao_obst);
    o->setTexture("imagem/MeioChaoGrande.png");
    posicao_obst.x += 2000.0f;
    LObstaculo.incluirObstaculo(o);
    adicionarEntidade(o);
}

void ent::fase::Fase::adicionarObstaculoPlataforma(const Vector2D<float> position)
{
    ent::obs::Obstaculo* o = new ent::obs::Obstaculo("imagem/MeioChaoGrande.png", position);
    o->setTexture("imagem/MeioChaoGrande.png");
    o->InitialUpdate();
    LObstaculo.incluirObstaculo(o);
    adicionarEntidade(o);
}

void ent::fase::Fase::adicionarObstaculoPlataforma(const float x, const float y)
{
    ent::obs::Obstaculo* o = new ent::obs::Obstaculo("imagem/MeioChaoGrande.png", Vector2D<float>(x,y));
    LObstaculo.incluirObstaculo(o);
    o->InitialUpdate();
    adicionarEntidade(o);
}

void ent::fase::Fase::adicionarObstaculoBau(const Vector2D<float> position)
{
    ent::obs::Obstaculo* aux = new ent::obs::Obstaculo01();
    aux->setPosition(position);
    LObstaculo.incluirObstaculo(aux);
    adicionarEntidade(aux);
}

void ent::fase::Fase::adicionarObstaculoBau(const float x, const float y)
{
    ent::obs::Obstaculo* aux = new ent::obs::Obstaculo01();
    aux->setPosition(Vector2D<float>(x,y));
    aux->InitialUpdate();
    LObstaculo.incluirObstaculo(aux);
    adicionarEntidade(aux);
}

void ent::fase::Fase::ChecarColisoesEntreJogadoresObstaculos()
{
    gc1.ChecarColisoesJogadoresObstaculos();
}

void ent::fase::Fase::ChecarColisoesEntreObstaculos()
{
    LObstaculo.ChecarColisoesEntreObstaculo();
}

void ent::fase::Fase::criarRetaPlataforma( const float distancia, const float y)
{
    unsigned long int t = static_cast<int>(distancia / 2000.0f);
    criarRetaPlataforma(y,t);
}

void ent::fase::Fase::criarRetaPlataforma(const unsigned long int qtde_plataformas, const float y)
{
    unsigned long int i;
    posicao_obst.y = y;
    for(i = 0lu; i < qtde_plataformas; i++)
    {
        adicionarObstaculoPlataforma();
    }
}
