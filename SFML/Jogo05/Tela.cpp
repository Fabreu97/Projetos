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
    caminho = t;
    control->setTextureFase(caminho);
}

void ent::tela::fase::Fase::VerificarInimigosMortos()
{
    unsigned long int i;
    for(i = 0; i < VInimigo.getSize(); i++)
    {
        ent::per::ini::Inimigo* enemy = VInimigo.getInimigo(i);
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

void ent::tela::fase::Fase::ChecarOperacoes(ent::tela::Tela* t)
{
    if(ptr2 != NULL)
    {
        control->Centralizar(ptr1->getPosition(), ptr2->getPosition());
    }
    else
    {
        control->Centralizar(ptr1->getPosition());
    }
    control->setView();
    cout << "Quantidade de Inimigos: " <<VInimigo.getSize() << endl;
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
void ent::tela::fase::Fase::jogar(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::pause(ent::tela::Tela* t)
{

}
void ent::tela::fase::Fase::opcao(ent::tela::Tela* t)
{
    //ChangeState(t, new ent::tela::menu::MenuPause(this));
}
void ent::tela::fase::Fase::sair(ent::tela::Tela* t)
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

ent::tela::menu::Botao::Botao(const string a):
    Entidade(a),
    click(false),
    ativo(false)
{
    tam_tex.x = 500.0f;
    tam_tex.y = 200.0f;
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

const bool ent::tela::menu::Botao::getClick() const
{
    return(click);
}

void ent::tela::menu::Botao::setTexture(const string t)
{
    caminho = t;
}

void ent::tela::menu::Botao::InitialUpdate()
{
    control->AdicionarBotaoNoMenu(chave, caminho, pos, tam_tex);
    click = false;
    ativo = false;
}

void ent::tela::menu::Botao::UpdateGerenciador()
{

}

void ent::tela::menu::Botao::Update()
{
    float xx = abs(control->getPositionMouse().x - (control->getPositionWindow().x + control->getSizeWindow().x/2.0 + (control->getPositionButton(chave).x * control->WindowRation()) ) );
    float yy = abs(control->getPositionMouse().y - ( (control->getPositionWindow().y + 25.0f) + (control->getSizeWindow().y)/2.0 + (control->getPositionButton(chave).y * control->WindowRation()) ) );
    ativo = false;
    if(xx <= (tam_tex.x * control->WindowRation() / 2.0f) )
    {
        if(yy <= (tam_tex.y * control->WindowRation()/ 2.0f))
        {
            ativo = true;
            if(control->isM_Left())
            {
                click = true;
            }
        }
    }
    cout << "Posicao do Botao "  << getID() << ": "<< pos.x << "," << pos.y << "  - " << id << endl;
    cout << "Posicao do Mouse: " << (control->getPositionMouse().x) << "," << (control->getPositionMouse().y) << endl;
    cout << "Posicao da Camera:" << control->getPositionView().x << " , " << control->getPositionView().y << endl;
    cout << "Posicao da Janela: " << control->getPositionWindow().x << " , " << control->getPositionWindow().y << endl;
    cout << "Posicao do Perto: (" << xx << " , " << yy << ")" << endl;
    cout << "Valor da Razao: " << control->WindowRation() << endl;


}

void ent::tela::menu::Botao::Draw()
{
    //control->DrawMap(chave);
    control->DrawMapBotao(chave, ativo);
}

///METODOS DO BOTAO Player01

ent::tela::menu::Game01::Game01(const string a):
    Botao(a)
{
    setKey("Player01");
}
ent::tela::menu::Game01::~Game01()
{

}

///METODOS DO BOTAO Player02

ent::tela::menu::Game02::Game02(const string a):
    Botao(a)
{
    setKey("Player02");
}
ent::tela::menu::Game02::~Game02()
{

}

///MÉTODOS DO BOTAO OPTION

ent::tela::menu::Option::Option(const string a):
    Botao(a)
{
    setKey("Option");
}
ent::tela::menu::Option::~Option()
{

}

///METODOS DO BOTAO Exit

ent::tela::menu::Exit::Exit(const string a):
    Botao(a)
{
    setKey("Exit");
}
ent::tela::menu::Exit::~Exit()
{

}

///MÉTODOS DE GERENCIADOR DE BOTOES

ent::tela::menu::GerenciadorBotao::GerenciadorBotao()
{

}

ent::tela::menu::GerenciadorBotao::~GerenciadorBotao()
{
    for(unsigned long int i = 0lu; i < Botoes.size(); i++)
    {
        delete(Botoes[i]);
    }
    Botoes.clear();
}

const long int ent::tela::menu::GerenciadorBotao::getIndiceBotao()
{
    for(it = Botoes.begin(); it != Botoes.end(); ++it)
    {
        if((*it)->getClick())
        {
            return((*it)->getID());
        }
    }
    return(-1l);
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
            (*it)->setSizeTexture(ent::Entidade::getGerenciadorGrafico()->getSizeButton((*it)->getKey()));
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
    Menu(c),
    number_of_players(0lu)
{
    play1 = new ent::tela::menu::Game01();
    play2 = new ent::tela::menu::Game02();
    option = new ent::tela::menu::Option();
    exit = new ent::tela::menu::Exit();

    menu.insertBotao(play1);
    menu.insertBotao(play2);
    menu.insertBotao(option);
    menu.insertBotao(exit);

    LEntidade.incluirEntidade(play1);
    LEntidade.incluirEntidade(play2);
    LEntidade.incluirEntidade(option);
    LEntidade.incluirEntidade(exit);

    InitialUpdate();
}

ent::tela::menu::MenuInicial::~MenuInicial()
{
    //delete(play);
}

void ent::tela::menu::MenuInicial::ChecarOperacoes(ent::tela::Tela* t)
{
    switch(menu.getIndiceBotao())
    {
    case 0:
        {
            number_of_players = 1lu;
            jogar(t);
            break;
        }
    case 1:
        {
            number_of_players = 2lu;
            jogar(t);
            break;
        }
    case 2:
        {
            opcao(t);
            break;
        }
    case 3:
        {
            sair(t);
            break;
        }
    default:
        {
            cout << menu.getIndiceBotao() << endl << endl;
            control->setView();
            control->limpar_Janela();
            Draw();
            control->Exibicao();
            break;
        }

    }
    /*control->setView();
    control->limpar_Janela();
    Draw();
    control->Exibicao();*/
}

void ent::tela::menu::MenuInicial::setTexture(const string t)
{
    caminho = t;
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


void ent::tela::menu::MenuInicial::jogar(ent::tela::Tela* t)
{
    t->deleteState();
    ChangeState(t, new ent::tela::fase::Fase01(number_of_players));
}

void ent::tela::menu::MenuInicial::pause(ent::tela::Tela* t)
{

}

void ent::tela::menu::MenuInicial::opcao(ent::tela::Tela* t)
{

}

void ent::tela::menu::MenuInicial::sair(ent::tela::Tela* t)
{
    control->close();
}

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
    delete(_state);
}

void ent::tela::Tela::jogar(Tela* t)
{
    _state->jogar(this);
}

void ent::tela::Tela::pause(Tela* t)
{
    _state->pause(this);
}

void ent::tela::Tela::opcao(Tela* t)
{
    _state->opcao(this);
}

void ent::tela::Tela::dificuldade(Tela* t)
{

}

void ent::tela::Tela::tirarTexture(Tela* t)
{
    tirarTexture(this);
}

void ent::tela::Tela::sair(Tela* t)
{
    _state->sair(this);
}

void ent::tela::Tela::Executar()
{
    _state->ChecarOperacoes(this);
}
