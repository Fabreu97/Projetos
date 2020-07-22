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

}

void ent::tela::menu::MenuInicial::Draw ()
{
    LEntidade.Draw();
}


void ent::tela::menu::MenuInicial::jogar(ent::tela::Tela* t)
{
    delete(t->getState());
    //ChangeState(t, );
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

