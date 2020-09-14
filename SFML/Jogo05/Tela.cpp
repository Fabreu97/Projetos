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

void ent::tela::EstadoTela::tirarTexture()
{
    if(ent::Entidade::getGerenciadorGrafico() != NULL)
    {
        ent::Entidade::getGerenciadorGrafico()->SemTextura();
    }
}

///METODOS DE FASE

ent::tela::fase::Fase::Fase(const unsigned long int number_of_players, const string c):
    ent::tela::EstadoTela(c)
{
    ptr1 = NULL;
    ptr2 = NULL;

    ptr1 = new ent::per::jog::Jogador01(HEIGHTJUMPER);
    ptr1->setTexture("Texture/Marco.png");
    LEntidade.incluirEntidade(ptr1);
    gc1.setJogador(ptr1);

    if(number_of_players == 2lu)
    {
        ptr2 = new ent::per::jog::Jogador02(HEIGHTJUMPER);
        ptr2->setSize(TAMANHO_COLIDIVEL_JOGADOR_X, TAMANHO_COLIDIVEL_JOGADOR_Y);
        ptr2->setSizeTexture(TAMANHO_DA_TEXTURA_JOGADOR_X, TAMANHO_DA_TEXTURA_JOGADOR_Y);
        ptr2->setPosition(700.f, 800.0f);
        ptr2->setContImage(3,9);
        ptr2->PreencherLinhas(0,1);
        ptr2->setSpeed(SPEED_JOGADOR);
        ptr2->setTempoCiclo(0.2);
        ptr2->setTexture("Texture/n_linux.png");
        ptr2->InitialUpdate();
        LEntidade.incluirEntidade(ptr2);
        gc1.setJogador(ptr2);
    }

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

    if(ptr1 != NULL)
    {
        delete(ptr1);
    }
    if(ptr2 != NULL)
    {
        delete(ptr2);
    }
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
    LEntidade.incluirEntidade(static_cast<Entidade*> (ptr2) );
    gc1.setJogador(p2);
}

void ent::tela::fase::Fase::setTexture(const string t)
{
    path = t;
    control->setTextureFase(path);
}

void ent::tela::fase::Fase::VerificarInimigosMortos()
{
    unsigned long int i;
    for(i = 0; i < VInimigo.getSize(); i++)
    {
        ent::per::ini::Inimigo* enemy = VInimigo[i];
        if(!enemy->getLife())
        {
            LEntidade.eliminarInimigo(enemy);
            VInimigo.eliminarInimigo(i);
        }
    }
}

void ent::tela::fase::Fase::InitialUpdate ()
{

}
void ent::tela::fase::Fase::UpdateGerenciador ()
{
    control->setSizeFase(tam_tex);
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
    inimigo->setSize(TAMANHO_COLIDIVEL_INIMIGO01_X, TAMANHO_COLIDIVEL_INIMIGO01_Y);
    inimigo->setSizeTexture(TAMANHO_DA_TEXTURA_INIMIGO01_X, TAMANHO_DA_TEXTURA_INIMIGO01_Y);
    inimigo->setPosition(position);
    inimigo->setContImage(1,1);
    inimigo->setTexture("Texture/n_linux.png");

    VInimigo.incluirInimigo(static_cast<ent::per::ini::Inimigo*> (inimigo));
    LEntidade.incluirEntidade(static_cast<ent::Entidade*> (inimigo));
}

void ent::tela::fase::Fase::adicionarInimigo01(const float x, const float y)
{
    ent::per::ini::Inimigo01* inimigo = new ent::per::ini::Inimigo01 ();
    inimigo->setSize(TAMANHO_COLIDIVEL_INIMIGO01_X, TAMANHO_COLIDIVEL_INIMIGO01_Y);
    inimigo->setSizeTexture(TAMANHO_DA_TEXTURA_INIMIGO01_X, TAMANHO_DA_TEXTURA_INIMIGO01_Y);
    inimigo->setPosition(x, y);
    inimigo->setContImage(3,9);
    inimigo->setTempoCiclo(0.2);
    inimigo->setTexture("Texture/n_linux.png");
    inimigo->InitialUpdate();

    VInimigo.incluirInimigo(static_cast<ent::per::ini::Inimigo*>(inimigo));
    LEntidade.incluirEntidade(static_cast<ent::Entidade*>(inimigo));
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
    ent::obs::Platform* p = new ent::obs::Platform(posicao_obst);
    p->setTexture("Texture/MeioChaoGrande.png");
    posicao_obst.x += 2000.0f;
    LObstaculo.incluirObstaculo(p);
    adicionarEntidade(p);
}

void ent::tela::fase::Fase::adicionarObstaculoPlataforma(const Vector2D<float> position)
{
    ent::obs::Platform* p = new ent::obs::Platform(position);
    p->setTexture("Texture/MeioChaoGrande.png");
    p->InitialUpdate();
    LObstaculo.incluirObstaculo(p);
    adicionarEntidade(p);
}

void ent::tela::fase::Fase::adicionarObstaculoPlataforma(const float x, const float y)
{
    ent::obs::Platform* p = new ent::obs::Platform(Vector2D<float>(x,y));
    p->setTexture("Texture/MeioChaoGrande.png");
    LObstaculo.incluirObstaculo(p);
    p->InitialUpdate();
    adicionarEntidade(p);
}

void ent::tela::fase::Fase::adicionarObstaculoBau(const Vector2D<float> position)
{
    ent::obs::Obstaculo01* aux = new ent::obs::Obstaculo01();
    aux->setPosition(position);
    LObstaculo.incluirObstaculo(static_cast<ent::obs::Obstaculo*> (aux) );
    adicionarEntidade(aux);
}

void ent::tela::fase::Fase::adicionarObstaculoBau(const float x, const float y)
{
    ent::obs::Obstaculo01* aux = new ent::obs::Obstaculo01();
    aux->setPosition(Vector2D<float>(x,y));
    aux->InitialUpdate();
    LObstaculo.incluirObstaculo(static_cast<ent::obs::Obstaculo*> (aux) );
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

void ent::tela::fase::Fase::run(ent::tela::Tela* t)
{
    if(ptr1 != NULL)
    {
        if(ptr2 != NULL)
        {
            control->Centralizar(ptr1->getPosition(), ptr2->getPosition());
            ptr1->restartCollisions();
            ptr2->restartCollisions();
        }
        else
        {
            control->Centralizar(ptr1->getPosition());
            ptr1->restartCollisions();
        }
    }
    else
    {
        if(ptr2 != NULL)
        {
            control->Centralizar(ptr2->getPosition());
            ptr2->restartCollisions();
        }
        else
        {
            //CHAMA O MENU DE MORTE
        }
    }
    control->setView();
    gc1.resetCollisions();
    this->ChecarColisoesEntreJogadoresInimigosProjeteis();
    this->ChecarColisoesEntreJogadoresObstaculos();
    this->ChecarColisoesEntreObstaculos();
    this->ChecarColisoesEntreInimigosObstaculos();
    VerificarInimigosMortos();
    control->limpar_Janela();
    if(ptr2 != NULL)
    {
        this->Draw(ptr1->getPosition(), ptr2->getPosition());
    }
    else
    {
        this->Draw(ptr1->getPosition());
    }

    control->Exibicao();
}
void ent::tela::fase::Fase::play(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::pause(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::option(ent::tela::Tela* t)
{
    //ChangeState(t, new ent::tela::menu::MenuPause(this));
}
void ent::tela::fase::Fase::exit(ent::tela::Tela* t)
{

}

///MÉTODOS DE FASE 01

ent::tela::fase::Fase01::Fase01(const unsigned long int number_of_players, const string c):
    ent::tela::fase::Fase(number_of_players, c)
{

}

ent::tela::fase::Fase01::~Fase01()
{

}

///MÉTODOS DE FASE 02

ent::tela::fase::Fase02::Fase02(const unsigned long int number_of_players, const string c):
    ent::tela::fase::Fase(number_of_players, c)
{

}

ent::tela::fase::Fase02::~Fase02()
{

}

///MÉTODOS DE FASE 03

ent::tela::fase::Fase03::Fase03(const unsigned long int number_of_players, const string c):
    ent::tela::fase::Fase(number_of_players, c)
{

}

ent::tela::fase::Fase03::~Fase03()
{

}

///MÉTODOS DE BOTAO

ent::tela::menu::Button::Button(const string a):
    Entidade(a),
    click(false),
    active(false)
{
    tam_tex.x = 375.0f;
    tam_tex.y = 150.0f;
}

ent::tela::menu::Button::~Button()
{

}

void ent::tela::menu::Button::setKey(const string k)
{
    key = k;
}

const string ent::tela::menu::Button::getKey() const
{
    return(key);

}

const bool ent::tela::menu::Button::getClick() const
{
    return(click);
}

void ent::tela::menu::Button::setTexture(const string t)
{
    path = t;
}

void ent::tela::menu::Button::InitialUpdate()
{
    control->AdicionarBotaoNoMenu(key, path, pos, tam_tex);
    click = false;
    active = false;
}

void ent::tela::menu::Button::UpdateGerenciador()
{

}

void ent::tela::menu::Button::Update()
{
    float xx = abs(control->getPositionMouse().x - (control->getPositionWindow().x + control->getSizeWindow().x/2.0 + (control->getPositionButton(key).x * control->WindowRation()) ) );
    float yy = abs(control->getPositionMouse().y - ( (control->getPositionWindow().y + 27.5f) + (control->getSizeWindow().y)/2.0 + (control->getPositionButton(key).y * control->WindowRation()) ) );
    active = false;
    if(xx <= (tam_tex.x * control->WindowRation() / 2.0f) )
    {
        if(yy <= (tam_tex.y * control->WindowRation()/ 2.0f))
        {
            active = true;
            if(control->isM_Left() || control->isPEnter())
            {
                click = true;
            }
        }
    }
}

void ent::tela::menu::Button::Draw()
{
    //control->DrawMap(key);
    control->DrawMapBotao(key, active);
}

///METODOS DO BOTAO Player01

ent::tela::menu::Game01::Game01(const string a):
    Button(a)
{
    setKey("Player01");
}
ent::tela::menu::Game01::~Game01()
{

}

///METODOS DO BOTAO Player02

ent::tela::menu::Game02::Game02(const string a):
    Button(a)
{
    setKey("Player02");
}
ent::tela::menu::Game02::~Game02()
{

}

///MÉTODOS DE BOTAO LOAD GAME

ent::tela::menu::LoadGame::LoadGame(const string a):
    Button(a)
{
    setKey("LoadGame");
}
ent::tela::menu::LoadGame::~LoadGame()
{

}
///MÉTODOS DO BOTAO OPTION

ent::tela::menu::Option::Option(const string a):
    Button(a)
{
    setKey("Option");
}
ent::tela::menu::Option::~Option()
{

}

///METODOS DO Button BOTAO Exit

ent::tela::menu::Exit::Exit(const string a):
    Button(a)
{
    setKey("Exit");
}
ent::tela::menu::Exit::~Exit()
{

}

///MÉTODOS DE GERENCIADOR DE BOTOES

ent::tela::menu::ButtonManager::ButtonManager()
{

}

ent::tela::menu::ButtonManager::~ButtonManager()
{
    for(unsigned long int i = 0lu; i < buttons.size(); i++)
    {
        delete(buttons[i]);
    }
    buttons.clear();
}

const long int ent::tela::menu::ButtonManager::getIndiceBotao()
{
    deque<Button*>::iterator it;
    for(it = buttons.begin(); it != buttons.end(); ++it)
    {
        if((*it)->getClick())
        {
            return((*it)->getID());
        }
    }
    return(-1l);
}

void ent::tela::menu::ButtonManager::InitialUpdate()
{
    unsigned long int i = 0lu;
    deque<Button*>::iterator it;
    for(it = buttons.begin(); it != buttons.end(); ++it)
    {
        (*it)->InitialUpdate();
        ent::Entidade::getGerenciadorGrafico()->ajustarBotoes((*it)->getKey(), buttons.size(), i);
        (*it)->setSizeTexture(ent::Entidade::getGerenciadorGrafico()->getSizeButton((*it)->getKey()));
        (*it)->setPosition(ent::Entidade::getGerenciadorGrafico()->getPositionButton((*it)->getKey()));
        (*it)->setID(i);
        i++;
    }

}

void ent::tela::menu::ButtonManager::insertButton(ent::tela::menu::Button* b)
{
    buttons.push_back(b);
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
    Menu(c),
    number_of_players(0lu)
{
    ent::tela::menu::Button* aux = new ent::tela::menu::Game01();
    menu.insertButton(aux);
    LEntidade.incluirEntidade(aux);

    aux = new ent::tela::menu::Game02();
    menu.insertButton(aux);
    LEntidade.incluirEntidade(aux);

    aux = new ent::tela::menu::LoadGame();
    menu.insertButton(aux);
    LEntidade.incluirEntidade(aux);

    aux = new ent::tela::menu::Option();
    menu.insertButton(aux);
    LEntidade.incluirEntidade(aux);

    aux = new ent::tela::menu::Exit();
    menu.insertButton(aux);
    LEntidade.incluirEntidade(aux);

    InitialUpdate();
}

ent::tela::menu::MenuInicial::~MenuInicial(){}

void ent::tela::menu::MenuInicial::run(ent::tela::Tela* t)
{
    switch(menu.getIndiceBotao())
    {
    case 0lu:
        {
            number_of_players = 1lu;
            play(t);
            break;
        }
    case 1lu:
        {
            number_of_players = 2lu;
            play(t);
            break;
        }
    case 2lu:
        {
            //loadGame(t);
            break;
        }
    case 3lu:
        {
            option(t);
            break;
        }
    case 4lu:
        {
            exit(t);
            break;
        }
    default: // -1(long int)
        {
            control->setView();
            control->limpar_Janela();
            Draw();
            control->Exibicao();
            break;
        }
    }
}

void ent::tela::menu::MenuInicial::setTexture(const string t)
{
    path = t;
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

}

void ent::tela::menu::MenuInicial::Draw ()
{
    LEntidade.Draw(control->getPositionView());
}


void ent::tela::menu::MenuInicial::play(ent::tela::Tela* t)
{
    t->deleteState();
    ChangeState(t, new ent::tela::fase::Fase01(number_of_players));
}

void ent::tela::menu::MenuInicial::pause(ent::tela::Tela* t)
{

}

void ent::tela::menu::MenuInicial::option(ent::tela::Tela* t)
{

}

void ent::tela::menu::MenuInicial::exit(ent::tela::Tela* t)
{
    //t->deleteState();
    control->close();
}

///MÉTODOS DE MENU DE PAUSE

ent::tela::menu::MenuPause::MenuPause(ent::tela::fase::Fase* f):
    ent::tela::menu::Menu("Texture/menuPause.png"),
    game(f)
{
}

ent::tela::menu::MenuPause::~MenuPause(){}

void ent::tela::menu::MenuPause::run(ent::tela::Tela* t){}

void ent::tela::menu::MenuPause::setTexture(const string t){path = t;}
void ent::tela::menu::MenuPause::InitialUpdate (){}
void ent::tela::menu::MenuPause::UpdateGerenciador (){}
void ent::tela::menu::MenuPause::Update (){}
void ent::tela::menu::MenuPause::Draw (){}

void ent::tela::menu::MenuPause::play(ent::tela::Tela* t){}
void ent::tela::menu::MenuPause::pause(ent::tela::Tela* t){}
void ent::tela::menu::MenuPause::option(ent::tela::Tela* t){}
void ent::tela::menu::MenuPause::exit(ent::tela::Tela* t){}

///MÉTODOS DE TELA

ent::tela::Tela::Tela():
    //_state(new ent::tela::fase::Fase01())
    _state(new ent::tela::menu::MenuInicial())
{

}

ent::tela::Tela::~Tela()
{
    deleteState();
}

void ent::tela::Tela::ChangeState(EstadoTela* s)
{
    _state = s;
}

void ent::tela::Tela::deleteState()
{
    if(_state != NULL)
    {
        delete(_state);
        _state = NULL;
    }
}

void ent::tela::Tela::play(Tela* t)
{
    _state->play(this);
}

void ent::tela::Tela::pause(Tela* t)
{
    _state->pause(this);
}

void ent::tela::Tela::option(Tela* t)
{
    _state->option(this);
}

void ent::tela::Tela::dificuldade(Tela* t)
{

}

void ent::tela::Tela::tirarTexture(Tela* t)
{
    _state->tirarTexture();
}

void ent::tela::Tela::exit(Tela* t)
{
    _state->exit(this);
}

void ent::tela::Tela::run()
{
    _state->run(this);
}
