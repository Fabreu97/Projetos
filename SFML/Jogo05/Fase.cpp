#include "Fase.h"

ent::tela::fase::Fase::Fase(const string c):
    ent::Entidade(c)
{
    ptr1 = NULL;
    ptr2 = NULL;
    posicao_obst = Vector2D<float>(0.0f, 1000.0f);
    gc1.setListas(&LObstaculo);
    gc1.setListas(&VInimigo);

    this->criarRetaPlataforma(2lu);
    this->criarRetaPlataforma(3lu, 800.0f);
    this->criarRetaPlataforma(5lu, 1100.0f);
    this->criarRetaPlataforma(1lu, 800.0f);
    this->adicionarObstaculoBau(500.0f, 700.0f);
    this->adicionarObstaculoBau(1000.0f, 700.0f);
    this->adicionarObstaculoBau(8000.0f, 300.0f);
    this->adicionarInimigo01(800.0f, 750.0f);
    this->adicionarInimigo01(250.0f, 750.0f);
    this->adicionarInimigo01(1500.0f, 0.0f);
    this->adicionarInimigo01(2500.0f, 0.0f);
    this->adicionarInimigo01(3500.0f, 0.0f);
    this->adicionarInimigo01(6000.0f, 0.0f);
}

ent::tela::fase::Fase::~Fase()
{
    LEntidade.limpar();
    VInimigo.limpar();
    LObstaculo.limpar();
}

void ent::tela::fase::Fase::setJogador(ent::per::jog::Jogador01* p1)
{
    ptr1 = p1;
    LEntidade.incluirEntidade(ptr1);
    gc1.setJogador(p1);
}

void ent::tela::fase::Fase::setJogador(ent::per::jog::Jogador02* p2)
{
    ptr2 = p2;
    LEntidade.incluirEntidade(ptr2);
    gc1.setJogador(p2);
}

void ent::tela::fase::Fase::setTexture(const string t)
{
    caminho = t;
    control->setTextureFase(caminho);
}

void ent::tela::fase::Fase::InitialUpdate ()
{

}
void ent::tela::fase::Fase::UpdateGerenciador ()
{
    control->setSizeFase(tam);
    pos = control->getPositionFase();
}
void ent::tela::fase::Fase::Update ()
{

}
void ent::tela::fase::Fase::adicionarEntidade(ent::Entidade* e)
{
    LEntidade.incluirEntidade(e);
}

void ent::tela::fase::Fase::Draw()
{
    LEntidade.Draw();
}

void ent::tela::fase::Fase::Draw(const Vector2D<float> pos1)
{
    LEntidade.Draw(pos1);
}

void ent::tela::fase::Fase::Draw(const Vector2D<float> pos1, const Vector2D<float> pos2)
{
    LEntidade.Draw(pos1, pos2);
}

//VECTOR DE INIMIGO

void ent::tela::fase::Fase::adicionarInimigo01(const Vector2D<float> position)
{
    ent::per::ini::Inimigo01* inimigo = new ent::per::ini::Inimigo01 ();
    inimigo->setSize(TAM_N_LINUX, TAM_N_LINUY);
    inimigo->setPosition(position);
    inimigo->setContImage(1,1);
    inimigo->PreencherLinhas(0,0);
    inimigo->setTexture("Texture/n_linux.png");

    VInimigo.incluirInimigo(inimigo);
    LEntidade.incluirEntidade(inimigo);
}

void ent::tela::fase::Fase::adicionarInimigo01(const float x, const float y)
{
    ent::per::ini::Inimigo01* inimigo = new ent::per::ini::Inimigo01 ();
    inimigo->setSize(TAM_N_LINUX, TAM_N_LINUY);
    inimigo->setPosition(x, y);
    inimigo->setContImage(3,9);
    inimigo->PreencherLinhas(0,1);
    inimigo->setTempoCiclo(0.2);
    inimigo->setTexture("Texture/n_linux.png");
    inimigo->InitialUpdate();

    VInimigo.incluirInimigo(inimigo);
    LEntidade.incluirEntidade(inimigo);
}

void ent::tela::fase::Fase::ChecarColisoesEntreInimigosObstaculos()
{
    gc1.ChecarColisoesInimigosObstaculos();
}

void ent::tela::fase::Fase::ChecarColisoesEntreJogadoresInimigosProjeteis()
{
    gc1.ChecarColisoesJogadoresInimigosProjeteis();
}

void ent::tela::fase::Fase::adicionarObstaculoPlataforma()
{
    ent::obs::Obstaculo* o = new ent::obs::Obstaculo(posicao_obst);
    o->setTexture("Texture/MeioChaoGrande.png");
    posicao_obst.x += 2000.0f;
    LObstaculo.incluirObstaculo(o);
    adicionarEntidade(o);
}

void ent::tela::fase::Fase::adicionarObstaculoPlataforma(const Vector2D<float> position)
{
    ent::obs::Obstaculo* o = new ent::obs::Obstaculo(position);
    o->setTexture("Texture/MeioChaoGrande.png");
    o->InitialUpdate();
    LObstaculo.incluirObstaculo(o);
    adicionarEntidade(o);
}

void ent::tela::fase::Fase::adicionarObstaculoPlataforma(const float x, const float y)
{
    ent::obs::Obstaculo* o = new ent::obs::Obstaculo(Vector2D<float>(x,y));
    o->setTexture("Texture/MeioChaoGrande.png");
    LObstaculo.incluirObstaculo(o);
    o->InitialUpdate();
    adicionarEntidade(o);
}

void ent::tela::fase::Fase::adicionarObstaculoBau(const Vector2D<float> position)
{
    ent::obs::Obstaculo01* aux = new ent::obs::Obstaculo01();
    aux->setPosition(position);
    LObstaculo.incluirObstaculo(aux);
    adicionarEntidade(aux);
}

void ent::tela::fase::Fase::adicionarObstaculoBau(const float x, const float y)
{
    ent::obs::Obstaculo01* aux = new ent::obs::Obstaculo01();
    aux->setPosition(Vector2D<float>(x,y));
    aux->InitialUpdate();
    LObstaculo.incluirObstaculo(aux);
    adicionarEntidade(aux);
}

void ent::tela::fase::Fase::ChecarColisoesEntreJogadoresObstaculos()
{
    gc1.ChecarColisoesJogadoresObstaculos();
}

void ent::tela::fase::Fase::ChecarColisoesEntreObstaculos()
{
    LObstaculo.ChecarColisoesEntreObstaculo();
}

void ent::tela::fase::Fase::criarRetaPlataforma( const float distancia, const float y)
{
    unsigned long int t = static_cast<int>(distancia / 2000.0f);
    criarRetaPlataforma(y,t);
}

void ent::tela::fase::Fase::criarRetaPlataforma(const unsigned long int qtde_plataformas, const float y)
{
    unsigned long int i;
    posicao_obst.y = y;
    for(i = 0lu; i < qtde_plataformas; i++)
    {
        adicionarObstaculoPlataforma();
    }
}
