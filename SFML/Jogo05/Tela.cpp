#include "Tela.h"

///METODOS DE ESTADO DE TELA

ent::tela::EstadoTela::EstadoTela(const string c):
    Entidade(c)
    {

    }

ent::tela::EstadoTela::~EstadoTela()
{

}

void ent::tela::EstadoTela::ChangeState(ent::tela::Tela* t, ent::tela::EstadoTela* s)
{
    t->ChangeState(s);
}

///METODOS DE FASE

ent::tela::fase::Fase::Fase(const string c):
    ent::tela::EstadoTela(c)
{
    ptr1 = NULL;
    ptr2 = NULL;

    ptr1 = new ent::per::jog::Jogador01(HEIGHTJUMPER);
    ptr1->setTexture("Texture/n_linux.png");

    ptr2 = new ent::per::jog::Jogador02(HEIGHTJUMPER);
    ptr2->setSize(TAM_N_LINUX, TAM_N_LINUY);
    ptr2->setPosition(700.f, 800.0f);
    ptr2->setContImage(3,9);
    ptr2->PreencherLinhas(0,1);
    ptr2->setSpeed(SPEED_JOGADOR);
    ptr2->setTempoCiclo(0.2);
    ptr2->setTexture("Texture/n_linux.png");
    ptr2->InitialUpdate();

    LEntidade.incluirEntidade(ptr1);
    LEntidade.incluirEntidade(ptr2);

    gc1.setJogador(ptr1);
    gc1.setJogador(ptr2);


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

    delete(ptr1);
    delete(ptr2);
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

void ent::tela::fase::Fase::ChecarOperacoes()
{
    control->Centralizar(ptr1->getPosition(), ptr2->getPosition());
    control->setView();

    this->ChecarColisoesEntreJogadoresInimigosProjeteis();
    this->ChecarColisoesEntreJogadoresObstaculos();
    this->ChecarColisoesEntreObstaculos();
    this->ChecarColisoesEntreInimigosObstaculos();
    control->limpar_Janela();
    this->Draw(ptr1->getPosition(), ptr2->getPosition());
    control->Exibicao();
}
void ent::tela::fase::Fase::jogar(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::pause(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::opcao(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::sair(ent::tela::Tela* t)
{

}

///MÉTODOS DE FASE 01

ent::tela::fase::Fase01::Fase01(const string c):
    ent::tela::fase::Fase(c)
{

}

ent::tela::fase::Fase01::~Fase01()
{

}

///MÉTODOS DE FASE 02

ent::tela::fase::Fase02::Fase02(const string c):
    ent::tela::fase::Fase(c)
{

}

ent::tela::fase::Fase02::~Fase02()
{

}

///MÉTODOS DE FASE 03

ent::tela::fase::Fase03::Fase03(const string c):
    ent::tela::fase::Fase(c)
{

}

ent::tela::fase::Fase03::~Fase03()
{

}

///MÉTODOS DE BOTAO

ent::tela::menu::Botao::Botao(const string a):
    Entidade(a),
    click(false)
{

}

ent::tela::menu::Botao::~Botao()
{

}

void ent::tela::menu::Botao::setKey(const string key)
{
    chave = key;
}

const string ent::tela::menu::Botao::getKey() const
{
    return(chave);
}

void ent::tela::menu::Botao::setTexture(const string t)
{
    caminho = t;
}

void ent::tela::menu::Botao::InitialUpdate()
{
    control->AdicionarBotaoNoMenu(chave, caminho, pos, tam);
}

void ent::tela::menu::Botao::UpdateGerenciador()
{

}

void ent::tela::menu::Botao::Update()
{
    if(control->isM_Left())
    {
        float xx = abs(control->getPositionMouse().x - pos.x);
        float yy = abs(control->getPositionMouse().y - pos.y);
        if(xx < getHalfSize().x)
        {
            if(yy < getHalfSize().y)
            {
                click = true;
            }
        }
    }
}

void ent::tela::menu::Botao::Draw()
{
    control->DrawMap(chave);
}

///METODOS DO BOTAO JOGAR

ent::tela::menu::Jogar::Jogar(const string a):
    Botao(a)
{

}
ent::tela::menu::Jogar::~Jogar()
{

}

///MÉTODOS DE GERENCIADOR DE BOTOES

ent::tela::menu::GerenciadorBotao::GerenciadorBotao()
{

}

ent::tela::menu::GerenciadorBotao::~GerenciadorBotao()
{
    while(!Botoes.empty())
    {
        it = Botoes.begin();
        delete(*it);
    }
    Botoes.clear();
}

void ent::tela::menu::GerenciadorBotao::InitialUpdate()
{
    unsigned long int i = 0lu;
    if(!Botoes.empty())
    {
        for(it = Botoes.begin(); it != Botoes.end(); ++it)
        {
            (*it)->InitialUpdate();
            ent::Entidade::getGerenciadorGrafico()->ajustarBotoes((*it)->getKey(), Botoes.size(), i);
            (*it)->setSize(ent::Entidade::getGerenciadorGrafico()->getSizeButton((*it)->getKey()));
            (*it)->setPosition(ent::Entidade::getGerenciadorGrafico()->getPositionButton((*it)->getKey()));
            (*it)->setID(i);
            i++;
        }
    }
}

void ent::tela::menu::GerenciadorBotao::insertBotao(ent::tela::menu::Botao* b)
{
    Botoes.push_back(b);
}

///METODOS DE MENU

ent::tela::menu::Menu::Menu(const string c):
    EstadoTela(c)
{

}

ent::tela::menu::Menu::~Menu()
{

}

///METODOS DE MENU INICIAL

ent::tela::menu::MenuInicial::MenuInicial(const string c):
    Menu(c)
{
    Jogar* aux1 = new Jogar();
    Jogar* aux2 = new Jogar();
    Jogar* aux3 = new Jogar();

    menu.insertBotao(aux1);
    menu.insertBotao(aux2);
    menu.insertBotao(aux3);

    LEntidade.incluirEntidade(aux1);
    LEntidade.incluirEntidade(aux2);
    LEntidade.incluirEntidade(aux3);

    InitialUpdate();
}

ent::tela::menu::MenuInicial::~MenuInicial()
{

}

void ent::tela::menu::MenuInicial::ChecarOperacoes()
{

}

void ent::tela::menu::MenuInicial::setTexture(const string t)
{

}

void ent::tela::menu::MenuInicial::InitialUpdate ()
{
    menu.InitialUpdate();
}

void ent::tela::menu::MenuInicial::UpdateGerenciador ()
{

}

void ent::tela::menu::MenuInicial::Update ()
{
    Draw();
}

void ent::tela::menu::MenuInicial::Draw ()
{
    LEntidade.Draw(control->getPositionView());
}


void ent::tela::menu::MenuInicial::jogar(ent::tela::Tela* t)
{
    t->deleteState();
    ChangeState(t, new ent::tela::fase::Fase01());
}

void ent::tela::menu::MenuInicial::pause(ent::tela::Tela* t)
{

}

void ent::tela::menu::MenuInicial::opcao(ent::tela::Tela* t)
{

}

void ent::tela::menu::MenuInicial::sair(ent::tela::Tela* t)
{

}

///MÉTODOS DE TELA

ent::tela::Tela::Tela()
{
    _state = new ent::tela::fase::Fase();
}

ent::tela::Tela::~Tela()
{

}

void ent::tela::Tela::ChangeState(EstadoTela* s)
{
    _state = s;
}

void ent::tela::Tela::deleteState()
{
    delete(_state);
}

void ent::tela::Tela::jogar(Tela* t)
{

}

void ent::tela::Tela::pause(Tela* t)
{

}

void ent::tela::Tela::opcao(Tela* t)
{

}

void ent::tela::Tela::dificuldade(Tela* t)
{

}

void ent::tela::Tela::tirarTexture(Tela* t)
{

}

void ent::tela::Tela::sair(Tela* t)
{

}

void ent::tela::Tela::Executar()
{
    _state->ChecarOperacoes();
}
