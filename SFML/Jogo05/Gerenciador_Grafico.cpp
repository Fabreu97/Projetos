#include "Gerenciador_Grafico.h"

using namespace Gerenciador;

///Funções Membros da classe Corpo

Gerenciador_Grafico::Corpo::Corpo(const Vector2D<float> tamanho, const string l)
{
    this->setSize(tamanho);
    caminho = l;
}

Gerenciador_Grafico::Corpo::~Corpo()
{

}

void Gerenciador_Grafico::Corpo::setPosition(const Vector2D<float> position)
{
    corpo.setPosition(sf::Vector2f(position.x, position.y));
}

void Gerenciador_Grafico::Corpo::setPosition(const float x, const float y)
{
    corpo.setPosition(sf::Vector2f(x, y));
}

const Vector2D<float> Gerenciador_Grafico::Corpo::getPosition() const
{
    return(Vector2D<float>(corpo.getPosition().x, corpo.getPosition().y));
}

void Gerenciador_Grafico::Corpo::setSize(const Vector2D<float> tamanho)
{
    corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));
    corpo.setOrigin(sf::Vector2f(tamanho.x/2, tamanho.y/2));
}

void Gerenciador_Grafico::Corpo::setSize(const float x, const float y)
{
    corpo.setSize(sf::Vector2f(x, y));
    corpo.setOrigin(sf::Vector2f(x/2.0, y/2.0));
}

const Vector2D<float> Gerenciador_Grafico::Corpo::getSize() const
{
    return(Vector2D<float>(corpo.getSize().x, corpo.getSize().y));
}

void Gerenciador_Grafico::Corpo::setTexture(const string t)
{
    caminho = t;
    if(textura.loadFromFile(caminho))
    {
        corpo.setTexture(&textura);
    }
    else
    {
        corpo.setTexture(nullptr);
    }
}

const string Gerenciador_Grafico::Corpo::getTexture() const
{
    return(caminho);
}

const Vector2D<float> Gerenciador_Grafico::Corpo::getTextureSize() const
{
    return(Vector2D<float>(textura.getSize().x, textura.getSize().y));
}

void Gerenciador_Grafico::Corpo::SemTextura()
{
    corpo.setTexture(nullptr);
}

void Gerenciador_Grafico::Corpo::setIntRect(const float width, const float height, const float left, const float top)
{
    uvRect.width = width;
    uvRect.height = height;
    uvRect.left = left;
    uvRect.top = top;
}

void Gerenciador_Grafico::Corpo::setTextureRect()
{
    corpo.setTextureRect(uvRect);
}

void Gerenciador_Grafico::Corpo::setColor(const float red, const float green, const float blue)
{
    corpo.setFillColor(sf::Color(red, green, blue));
}

void Gerenciador_Grafico::Corpo::move(const float x, const float y)
{
    corpo.move(sf::Vector2f(x,y));
}

void Gerenciador_Grafico::Corpo::move(const Vector2D<float> movimento)
{
    corpo.move(sf::Vector2f(movimento.x, movimento.y));
}

sf::RectangleShape* Gerenciador_Grafico::Corpo::getBody()
{
    return(&corpo);
}

const bool Gerenciador_Grafico::Corpo::operator == (const Corpo& c) const
{
    if(getPosition().x == c.getPosition().x)
    {
        if(getPosition().y == c.getPosition().y)
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }
    else
    {
        return(false);
    }
}

const bool Gerenciador_Grafico::Corpo::operator == (const Vector2D<float>& p) const
{
    if(this->getPosition().x == p.x)
    {
        if(this->getPosition().y == p.y)
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }
    else
    {
        return(false);
    }
}

const bool Gerenciador_Grafico::Corpo::operator != (const Corpo& c) const
{
    return( !(*this == c) );
}

const bool Gerenciador_Grafico::Corpo::operator != (const Vector2D<float>& p) const
{
    return( !(*this == p) );
}

///Funções Membros da classe Gerenciador Grafico

float Gerenciador_Grafico::delta_time = 0.0f;

Gerenciador_Grafico::Gerenciador_Grafico(const string nome_do_jogo, const Vector2D<unsigned int> tam_janela):
    window(sf::VideoMode(tam_janela.x, tam_janela.y), nome_do_jogo, sf::Style::Close | sf::Style::Resize),
    view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(static_cast<float>(tam_janela.x), static_cast<float>(tam_janela.y))),
    shape(100.0f)

{
    swy = (float)tam_janela.y;
    Fase.setSize(static_cast<float>(tam_janela.x), static_cast<float>(tam_janela.y));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

}

void Gerenciador_Grafico::DrawTeste(sf::RectangleShape& t)
{
    window.draw(t);
}

bool Gerenciador_Grafico::isOpen()
{
    return(window.isOpen());
}

bool Gerenciador_Grafico::pollEvent()
{
    return(window.pollEvent(evento));
}

void Gerenciador_Grafico::clear()
{
    window.clear();
}

void Gerenciador_Grafico::display()
{
    window.display();
}

void Gerenciador_Grafico::close()
{
    window.close();
}

void Gerenciador_Grafico::ResizeView()
{
    float razao = (float)window.getSize().x / window.getSize().y;
    view.setSize(view.getSize().y * razao, view.getSize().y);
}

bool Gerenciador_Grafico::Resized()
{
    return(evento.type == sf::Event::Resized);
}

void Gerenciador_Grafico::setTitle(const string nome_da_janela)
{
    window.setTitle(nome_da_janela);
}

void Gerenciador_Grafico::setVerticalSyncEnabled(const bool chave)
{
    window.setVerticalSyncEnabled(chave);
}

void Gerenciador_Grafico::setFramerateLimit(const unsigned long int vel)
{
    window.setFramerateLimit(vel);
}

void Gerenciador_Grafico::setFramerateLimitTime(const float time)
{
    float t = 1 / time;
    window.setFramerateLimit(t);
}

const Vector2D<float> Gerenciador_Grafico::getPositionWindow() const
{
    return(Vector2D<float>(window.getPosition().x, window.getPosition().y));
}

float Gerenciador_Grafico::WindowRation()
{
    return(window.getSize().y / swy);
}

const Vector2D<float> Gerenciador_Grafico::getSizeWindow() const
{
    return( Vector2D<float>(window.getSize().x, window.getSize().y) );
}

bool Gerenciador_Grafico::janela_Aberta()
{
    return(window.isOpen());
}

bool Gerenciador_Grafico::captar_Evento()
{
    return(window.pollEvent(evento));
}

void Gerenciador_Grafico::setView()
{
    window.setView(view);
}

Vector2D<float> Gerenciador_Grafico::getPositionView() const
{
    return( Vector2D<float> ( view.getCenter().x, view.getCenter().y) );
}

void Gerenciador_Grafico::limpar_Janela()
{
    window.clear(sf::Color(20,150,220));
}

void Gerenciador_Grafico::Exibicao()
{
    window.display();
}

void Gerenciador_Grafico::fecha_Janela()
{
    window.close();
}

void Gerenciador_Grafico::Centralizar(const float x1, const float y1, const float x2, const float y2)
{
    view.setCenter( sf::Vector2f( (x2 + x2) / 2.0, (y1 + y2 - 200.0f) / 2.0) );
}

void Gerenciador_Grafico::Centralizar(const Vector2D<float> v1, const Vector2D<float> v2)
{
    view.setCenter(sf::Vector2f( (v1.x + v2.x)/ 2.0, (v1.y + v2.y - 200.0f) / 2.0 ) );
}

void Gerenciador_Grafico::Centralizar(const float x, const float y)
{
    view.setCenter(sf::Vector2f(x,y - 200.0f));
}

void Gerenciador_Grafico::Centralizar(Vector2D<float> v)
{
    view.setCenter(sf::Vector2f(v.x, v.y - 200.0f));
}

bool Gerenciador_Grafico::fecho_Janela()
{
    return(evento.type == sf::Event::Closed);
}

void Gerenciador_Grafico::Draw_Shape()
{
    window.draw(shape);
}

void Gerenciador_Grafico::DrawPlayer01()
{
    ptrR = Player01.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawPlayer02()
{
    ptrR = Player02.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawInimigo01()
{
    ptrR = Inimigo01.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawInimigo02()
{
    ptrR = Inimigo02.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawInimigo03()
{
    ptrR = Inimigo03.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawPlataforma()
{
    ptrR = Plataforma.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawObstaculo01()
{
    ptrR = Obstaculo01.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawObstaculo02()
{
    ptrR = Obstaculo02.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawObstaculo03()
{
    ptrR = Obstaculo03.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawFase()
{
    ptrR = Fase.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawProjetil()
{
    ptrR = Projetil.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawLife01()
{
    ptrR = Barra_de_Vida01.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::DrawLife02()
{
    ptrR = Barra_de_Vida02.getBody();
    window.draw(*ptrR);
}

void Gerenciador_Grafico::SemTextura()
{
    Player01.SemTextura();
    Player02.SemTextura();
    Inimigo01.SemTextura();
    Inimigo02.SemTextura();
    Inimigo03.SemTextura();
    Plataforma.SemTextura();
    Obstaculo01.SemTextura();
    Obstaculo02.SemTextura();
    Obstaculo03.SemTextura();
}

const bool Gerenciador_Grafico::isPW() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::W));
}

const bool Gerenciador_Grafico::isPS() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::S));
}

const bool Gerenciador_Grafico::isPA() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::A));
}

const bool Gerenciador_Grafico::isPD() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}

const bool Gerenciador_Grafico::isPR() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::R));
}

const bool Gerenciador_Grafico::isPEnter() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
}

const bool Gerenciador_Grafico::isP_UP() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
}

const bool Gerenciador_Grafico::isP_Down() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
}

const bool Gerenciador_Grafico::isP_Left() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
}

const bool Gerenciador_Grafico::isP_Right() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
}

const bool Gerenciador_Grafico::isP_ALT() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt));
}

const bool Gerenciador_Grafico::isP_Space() const
{
    return(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
}

const bool Gerenciador_Grafico::isM_Left() const
{
    return(sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

const bool Gerenciador_Grafico::isM_Right() const
{
    return(sf::Mouse::isButtonPressed(sf::Mouse::Right));
}



const Vector2D<float> Gerenciador_Grafico::getPositionMouse() const
{
    return(Vector2D<float>(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
}

void Gerenciador_Grafico::set_Delta_Time()
{
    delta_time = clock.restart().asSeconds();
    if(delta_time >= 0.05f)
    {
        delta_time = 0.05f;
    }
}

float Gerenciador_Grafico::get_Delta_Time()
{
    return(delta_time);
}


///Metodos Dedicado ao Corpo do Player01
void Gerenciador_Grafico::setPositionPlayer01(const Vector2D<float> position)
{
    Player01.setPosition(position);
}
void Gerenciador_Grafico::setPositionPlayer01(const float x, const float y)
{
    Player01.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionPlayer01() const
{
    return(Player01.getPosition());
}

void Gerenciador_Grafico::setSizePlayer01(const Vector2D<float> tamanho)
{
    Player01.setSize(tamanho);
}

void Gerenciador_Grafico::setSizePlayer01(const float x, const float y)
{
    Player01.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizePlayer01() const
{
    return(Player01.getSize());
}

void Gerenciador_Grafico::setTexturePlayer01(const string t)
{
    Player01.setTexture(t);
}

const string Gerenciador_Grafico::getTexturePlayer01() const
{
    return(Player01.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizePlayer01() const
{
    return(Player01.getTextureSize());
}

void Gerenciador_Grafico::setIntRectPlayer01(const float width, const float height, const float left, const float top)
{
    Player01.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectPlayer01()
{
    Player01.setTextureRect();
}

void Gerenciador_Grafico::movePlayer01 (const float x, const float y)
{
    Player01.move(x,y);
}

void Gerenciador_Grafico::movePlayer01 (const Vector2D<float> movimento)
{
    Player01.move(movimento);
}

///Métodos Dedicados ao Corpo do Player02

void Gerenciador_Grafico::setPositionPlayer02(const Vector2D<float> position)
{
    Player02.setPosition(position);
}
void Gerenciador_Grafico::setPositionPlayer02(const float x, const float y)
{
    Player02.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionPlayer02() const
{
    return(Player02.getPosition());
}

void Gerenciador_Grafico::setSizePlayer02(const Vector2D<float> tamanho)
{
    Player02.setSize(tamanho);
}

void Gerenciador_Grafico::setSizePlayer02(const float x, const float y)
{
    Player02.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizePlayer02() const
{
    return(Player02.getSize());
}

void Gerenciador_Grafico::setTexturePlayer02(const string t)
{
    Player02.setTexture(t);
}

const string Gerenciador_Grafico::getTexturePlayer02() const
{
    return(Player02.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizePlayer02() const
{
    return(Player02.getTextureSize());
}

void Gerenciador_Grafico::setIntRectPlayer02(const float width, const float height, const float left, const float top)
{
    Player02.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectPlayer02()
{
    Player02.setTextureRect();
}

void Gerenciador_Grafico::movePlayer02 (const float x, const float y)
{
    Player02.move(x,y);
}

void Gerenciador_Grafico::movePlayer02 (const Vector2D<float> movimento)
{
    Player02.move(movimento);
}

///Métodos Dedicados ao Corpo do Inimigo01

void Gerenciador_Grafico::setPositionInimigo01(const Vector2D<float> position)
{
    Inimigo01.setPosition(position);
}
void Gerenciador_Grafico::setPositionInimigo01(const float x, const float y)
{
    Inimigo01.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionInimigo01() const
{
    return(Inimigo01.getPosition());
}

void Gerenciador_Grafico::setSizeInimigo01(const Vector2D<float> tamanho)
{
    Inimigo01.setSize(tamanho);
    Inimigo01.setColor(255.0f, 100.0f, 100.0f);
}

void Gerenciador_Grafico::setSizeInimigo01(const float x, const float y)
{
    Inimigo01.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeInimigo01() const
{
    return(Inimigo01.getSize());
}

void Gerenciador_Grafico::setTextureInimigo01(const string t)
{
    Inimigo01.setTexture(t);
}

const string Gerenciador_Grafico::getTextureInimigo01() const
{
    return(Inimigo01.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeInimigo01() const
{
    return(Inimigo01.getTextureSize());
}

void Gerenciador_Grafico::setIntRectInimigo01(const float width, const float height, const float left, const float top)
{
    Inimigo01.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectInimigo01()
{
    Inimigo01.setTextureRect();
}

void Gerenciador_Grafico::moveInimigo01 (const float x, const float y)
{
    Inimigo01.move(x,y);
}

void Gerenciador_Grafico::moveInimigo01 (const Vector2D<float> movimento)
{
    Inimigo01.move(movimento);
}

///Métodos Dedicados ao Corpo do Inimigo02

void Gerenciador_Grafico::setPositionInimigo02(const Vector2D<float> position)
{
    Inimigo02.setPosition(position);
}
void Gerenciador_Grafico::setPositionInimigo02(const float x, const float y)
{
    Inimigo02.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionInimigo02() const
{
    return(Inimigo02.getPosition());
}

void Gerenciador_Grafico::setSizeInimigo02(const Vector2D<float> tamanho)
{
    Inimigo02.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeInimigo02(const float x, const float y)
{
    Inimigo02.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeInimigo02() const
{
    return(Inimigo02.getSize());
}

void Gerenciador_Grafico::setTextureInimigo02(const string t)
{
    Inimigo02.setTexture(t);
}

const string Gerenciador_Grafico::getTextureInimigo02() const
{
    return(Inimigo02.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeInimigo02() const
{
    return(Inimigo02.getTextureSize());
}

void Gerenciador_Grafico::setIntRectInimigo02(const float width, const float height, const float left, const float top)
{
    Inimigo02.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectInimigo02()
{
    Inimigo02.setTextureRect();
}

void Gerenciador_Grafico::moveInimigo02 (const float x, const float y)
{
    Inimigo02.move(x,y);
}

void Gerenciador_Grafico::moveInimigo02 (const Vector2D<float> movimento)
{
    Inimigo02.move(movimento);
}

///Métodos Dedicados ao Corpo do Inimigo03

void Gerenciador_Grafico::setPositionInimigo03(const Vector2D<float> position)
{
    Inimigo03.setPosition(position);
}
void Gerenciador_Grafico::setPositionInimigo03(const float x, const float y)
{
    Inimigo03.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionInimigo03() const
{
    return(Inimigo03.getPosition());
}

void Gerenciador_Grafico::setSizeInimigo03(const Vector2D<float> tamanho)
{
    Inimigo03.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeInimigo03(const float x, const float y)
{
    Inimigo03.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeInimigo03() const
{
    return(Inimigo03.getSize());
}

void Gerenciador_Grafico::setTextureInimigo03(const string t)
{
    Inimigo03.setTexture(t);
}

const string Gerenciador_Grafico::getTextureInimigo03() const
{
    return(Inimigo03.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeInimigo03() const
{
    return(Inimigo03.getTextureSize());
}

void Gerenciador_Grafico::setIntRectInimigo03(const float width, const float height, const float left, const float top)
{
    Inimigo03.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectInimigo03()
{
    Inimigo03.setTextureRect();
}

void Gerenciador_Grafico::moveInimigo03 (const float x, const float y)
{
    Inimigo03.move(x,y);
}

void Gerenciador_Grafico::moveInimigo03 (const Vector2D<float> movimento)
{
    Inimigo03.move(movimento);
}

///Métodos Dedicados ao Corpo do Plataforma

void Gerenciador_Grafico::setPositionPlataforma(const Vector2D<float> position)
{
    Plataforma.setPosition(position);
}
void Gerenciador_Grafico::setPositionPlataforma(const float x, const float y)
{
    Plataforma.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionPlataforma() const
{
    return(Plataforma.getPosition());
}

void Gerenciador_Grafico::setSizePlataforma(const Vector2D<float> tamanho)
{
    Plataforma.setSize(tamanho);
}

void Gerenciador_Grafico::setSizePlataforma(const float x, const float y)
{
    Plataforma.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizePlataforma() const
{
    return(Plataforma.getSize());
}

void Gerenciador_Grafico::setTexturePlataforma(const string t)
{
    Plataforma.setTexture(t);
}

const string Gerenciador_Grafico::getTexturePlataforma() const
{
    return(Plataforma.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizePlataforma() const
{
    return(Plataforma.getTextureSize());
}

void Gerenciador_Grafico::setIntRectPlataforma(const float width, const float height, const float left, const float top)
{
    Plataforma.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectPlataforma()
{
    Plataforma.setTextureRect();
}

void Gerenciador_Grafico::movePlataforma (const float x, const float y)
{
    Plataforma.move(x,y);
}

void Gerenciador_Grafico::movePlataforma (const Vector2D<float> movimento)
{
    Plataforma.move(movimento);
}

///Métodos Dedicados ao Corpo do Obstaculo01

void Gerenciador_Grafico::setPositionObstaculo01(const Vector2D<float> position)
{
    Obstaculo01.setPosition(position);
}
void Gerenciador_Grafico::setPositionObstaculo01(const float x, const float y)
{
    Obstaculo01.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionObstaculo01() const
{
    return(Obstaculo01.getPosition());
}

void Gerenciador_Grafico::setSizeObstaculo01(const Vector2D<float> tamanho)
{
    Obstaculo01.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeObstaculo01(const float x, const float y)
{
    Obstaculo01.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeObstaculo01() const
{
    return(Obstaculo01.getSize());
}

void Gerenciador_Grafico::setTextureObstaculo01(const string t)
{
    Obstaculo01.setTexture(t);
}

const string Gerenciador_Grafico::getTextureObstaculo01() const
{
    return(Obstaculo01.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeObstaculo01() const
{
    return(Obstaculo01.getTextureSize());
}

void Gerenciador_Grafico::setIntRectObstaculo01(const float width, const float height, const float left, const float top)
{
    Obstaculo01.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectObstaculo01()
{
    Obstaculo01.setTextureRect();
}

void Gerenciador_Grafico::moveObstaculo01 (const float x, const float y)
{
    Obstaculo01.move(x,y);
}

void Gerenciador_Grafico::moveObstaculo01 (const Vector2D<float> movimento)
{
    Obstaculo01.move(movimento);
}

///Métodos Dedicados ao Corpo do Obstaculo02

void Gerenciador_Grafico::setPositionObstaculo02(const Vector2D<float> position)
{
    Obstaculo02.setPosition(position);
}
void Gerenciador_Grafico::setPositionObstaculo02(const float x, const float y)
{
    Obstaculo02.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionObstaculo02() const
{
    return(Obstaculo02.getPosition());
}

void Gerenciador_Grafico::setSizeObstaculo02(const Vector2D<float> tamanho)
{
    Obstaculo02.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeObstaculo02(const float x, const float y)
{
    Obstaculo02.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeObstaculo02() const
{
    return(Obstaculo02.getSize());
}

void Gerenciador_Grafico::setTextureObstaculo02(const string t)
{
    Obstaculo02.setTexture(t);
}

const string Gerenciador_Grafico::getTextureObstaculo02() const
{
    return(Obstaculo02.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeObstaculo02() const
{
    return(Obstaculo02.getTextureSize());
}

void Gerenciador_Grafico::setIntRectObstaculo02(const float width, const float height, const float left, const float top)
{
    Obstaculo02.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectObstaculo02()
{
    Obstaculo02.setTextureRect();
}

void Gerenciador_Grafico::moveObstaculo02 (const float x, const float y)
{
    Obstaculo02.move(x,y);
}

void Gerenciador_Grafico::moveObstaculo02 (const Vector2D<float> movimento)
{
    Obstaculo02.move(movimento);
}

///Métodos Dedicados ao Corpo do Obstaculo03

void Gerenciador_Grafico::setPositionObstaculo03 (const Vector2D<float> position)
{
    Obstaculo03.setPosition(position);
}
void Gerenciador_Grafico::setPositionObstaculo03 (const float x, const float y)
{
    Obstaculo03.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionObstaculo03 () const
{
    return(Obstaculo03.getPosition());
}

void Gerenciador_Grafico::setSizeObstaculo03 (const Vector2D<float> tamanho)
{
    Obstaculo03.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeObstaculo03 (const float x, const float y)
{
    Obstaculo03.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeObstaculo03 () const
{
    return(Obstaculo03.getSize());
}

void Gerenciador_Grafico::setTextureObstaculo03 (const string t)
{
    Obstaculo03.setTexture(t);
}

const string Gerenciador_Grafico::getTextureObstaculo03 () const
{
    return(Obstaculo03.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeObstaculo03 () const
{
    return(Obstaculo03.getTextureSize());
}

void Gerenciador_Grafico::setIntRectObstaculo03 (const float width, const float height, const float left, const float top)
{
    Obstaculo03.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectObstaculo03 ()
{
    Obstaculo03.setTextureRect();
}

void Gerenciador_Grafico::moveObstaculo03 (const float x, const float y)
{
    Obstaculo03.move(x,y);
}

void Gerenciador_Grafico::moveObstaculo03 (const Vector2D<float> movimento)
{
    Obstaculo03.move(movimento);
}

///Métodos Dedicados ao Corpo da Fase

void Gerenciador_Grafico::setPositionFase (const Vector2D<float> position)
{
    Fase.setPosition(position);
}
void Gerenciador_Grafico::setPositionFase (const float x, const float y)
{
    Fase.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionFase () const
{
    return(Fase.getPosition());
}

void Gerenciador_Grafico::setSizeFase (const Vector2D<float> tamanho)
{
    Fase.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeFase (const float x, const float y)
{
    Fase.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeFase () const
{
    return(Fase.getSize());
}

void Gerenciador_Grafico::setTextureFase (const string t)
{
    Fase.setTexture(t);
}

const string Gerenciador_Grafico::getTextureFase () const
{
    return(Fase.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeFase () const
{
    return(Fase.getTextureSize());
}

void Gerenciador_Grafico::setIntRectFase (const float width, const float height, const float left, const float top)
{
    Fase.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectFase ()
{
    Fase.setTextureRect();
}

void Gerenciador_Grafico::moveFase (const float x, const float y)
{
    Fase.move(x,y);
}

void Gerenciador_Grafico::moveFase (const Vector2D<float> movimento)
{
    Fase.move(movimento);
}

///METODOS DEDICADOS PARA BARRA DE VIDA 01

void Gerenciador_Grafico::setPositionLife01()
{
    sf::Vector2f centro = view.getCenter();
    sf::Vector2i tamanho;
    tamanho.x = view.getSize().x / 2;
    tamanho.y = view.getSize().y / 2;
    centro.x -= tamanho.x;
    centro.y -= tamanho.y;
    centro.x = centro.x + (Barra_de_Vida01.getSize().x / 2);
    centro.y = centro.y + (Barra_de_Vida01.getSize().y / 2);

    Barra_de_Vida01.setPosition(centro.x, centro.y);
}

void Gerenciador_Grafico::setSizeLife01(const Vector2D<float> v)
{
    Barra_de_Vida01.setSize(v);
}

void Gerenciador_Grafico::setSizeLife01(const float x, const float y)
{
    Barra_de_Vida01.setSize(x,y);
}

void Gerenciador_Grafico::setTextureLife01(const string t)
{
    Barra_de_Vida01.setTexture(t);
}

Vector2D<float> Gerenciador_Grafico::getTextureSizeLife01() const
{
    return( Barra_de_Vida01.getTextureSize() );
}

void Gerenciador_Grafico::setIntRectLife01(const float width, const float height, const float left, const float top)
{
    Barra_de_Vida01.setIntRect(width, height, left, top);
}

void Gerenciador_Grafico::setTextureRectLife01()
{
    Barra_de_Vida01.setTextureRect();
}

void Gerenciador_Grafico::moveLife01(const Vector2D<float> v)
{
    Barra_de_Vida01.move(v);
}

void Gerenciador_Grafico::moveLife01(const float x, const float y)
{
    Barra_de_Vida01.move(x,y);
}

///METODOS DEDICADOS PARA BARRA DE VIDA 02

void Gerenciador_Grafico::setPositionLife02()
{
    sf::Vector2f centro = view.getCenter();
    sf::Vector2i tamanho;
    tamanho.x = view.getSize().x / 2;
    tamanho.y = view.getSize().y / 2;
    centro.x -= tamanho.x;
    centro.y -= tamanho.y;
    centro.x = centro.x + (Barra_de_Vida02.getSize().x / 2);
    centro.y = centro.y + Barra_de_Vida02.getSize().y;

    Barra_de_Vida02.setPosition(centro.x, centro.y);
}

void Gerenciador_Grafico::setSizeLife02(const Vector2D<float> v)
{
    Barra_de_Vida02.setSize(v);
}

void Gerenciador_Grafico::setSizeLife02(const float x, const float y)
{
    Barra_de_Vida02.setSize(x,y);
}

void Gerenciador_Grafico::setTextureLife02(const string t)
{
    Barra_de_Vida02.setTexture(t);
}

Vector2D<float> Gerenciador_Grafico::getTextureSizeLife02() const
{
    return( Barra_de_Vida02.getTextureSize() );
}

void Gerenciador_Grafico::setIntRectLife02(const float width, const float height, const float left, const float top)
{
    Barra_de_Vida02.setIntRect(width, height, left, top);
}

void Gerenciador_Grafico::setTextureRectLife02()
{
    Barra_de_Vida02.setTextureRect();
}

void Gerenciador_Grafico::moveLife02(const Vector2D<float> v)
{
    Barra_de_Vida02.move(v);
}

void Gerenciador_Grafico::moveLife02(const float x, const float y)
{
    Barra_de_Vida02.move(x,y);
}

///Métodos Dedicados ao Corpo da Projetil

void Gerenciador_Grafico::setPositionProjetil (const Vector2D<float> position)
{
    Projetil.setPosition(position);
}
void Gerenciador_Grafico::setPositionProjetil (const float x, const float y)
{
    Projetil.setPosition(x,y);
}
const Vector2D<float> Gerenciador_Grafico::getPositionProjetil () const
{
    return(Projetil.getPosition());
}

void Gerenciador_Grafico::setSizeProjetil (const Vector2D<float> tamanho)
{
    Projetil.setSize(tamanho);
}

void Gerenciador_Grafico::setSizeProjetil (const float x, const float y)
{
    Projetil.setSize(x,y);
}

const Vector2D<float> Gerenciador_Grafico::getSizeProjetil () const
{
    return(Projetil.getSize());
}

void Gerenciador_Grafico::setTextureProjetil (const string t)
{
    Projetil.setTexture(t);
}

const string Gerenciador_Grafico::getTextureProjetil () const
{
    return(Projetil.getTexture());
}

const Vector2D<float> Gerenciador_Grafico::getTextureSizeProjetil () const
{
    return(Projetil.getTextureSize());
}

void Gerenciador_Grafico::setIntRectProjetil (const float width, const float height, const float left, const float top)
{
    Projetil.setIntRect(width,height,left,top);
}

void Gerenciador_Grafico::setTextureRectProjetil ()
{
    Projetil.setTextureRect();
}

void Gerenciador_Grafico::moveProjetil (const float x, const float y)
{
    Projetil.move(x,y);
}

void Gerenciador_Grafico::moveProjetil (const Vector2D<float> movimento)
{
    Projetil.move(movimento);
}

///MÉTODOS RELARIONADOS AO MAPA DE CORPOS

Gerenciador_Grafico::Corpo* Gerenciador_Grafico::getMap(const string key)
{
    map<string, Corpo*>::iterator it;
    it = menu.find(key);
    if(it == menu.end())
    {
        return(NULL);
    }

    return(it->second);
}

const bool Gerenciador_Grafico::ExisteChave(const string key)
{
    map<string, Corpo*>::iterator it;
    it = menu.find(key);

    if(it == menu.end())
    {
        //Não encontro a chave
        return(false);
    }

    return(true);
}

void Gerenciador_Grafico::AdicionarBotaoNoMenu(const string key, const string texture, const Vector2D<float> position, const Vector2D<float> sizeB)
{
    if(!ExisteChave(key))
    {
        Corpo* aux = new Corpo();
        aux->setSize(sizeB);
        aux->setPosition(position);
        aux->setTexture(texture);
        menu.insert(pair<string, Corpo*>(key, aux));
    }
    else
    {
        cout << "Error: Chave não Valida, portanto não criado o Botão" << endl;
    }
}

void Gerenciador_Grafico::ajustarBotoes(const string key, const unsigned long int qtd_botoes, const unsigned long int indice)
{
    if(ExisteChave(key))
    {
        Corpo* aux = getMap(key);
        Vector2D<float> tamanho_da_janela;
        Vector2D<float> posicao_da_janela;

        tamanho_da_janela.x = view.getSize().x / qtd_botoes;
        tamanho_da_janela.y = view.getSize().y / qtd_botoes;
        posicao_da_janela.x = view.getCenter().x;
        posicao_da_janela.y = view.getCenter().y - (view.getSize().y/2) + aux->getSize().y/2;
        posicao_da_janela.y += indice * aux->getSize().y;

        aux->setPosition(posicao_da_janela);
    }
}

Vector2D<float> Gerenciador_Grafico::getPositionButton(const string key)
{
    if(ExisteChave(key))
    {
        Corpo* aux = getMap(key);
        return(aux->getPosition());
    }

    cout << "Botao " << key << "Não Existe - retorno na Posicao Padrao" << endl;
    return(Vector2D<float>(-1000.0f, -1000.0f));

}

Vector2D<float> Gerenciador_Grafico::getSizeButton(const string key)
{
    if(ExisteChave(key))
    {
        Corpo* aux = getMap(key);
        return(aux->getSize());
    }

    cout << "Botao " << key << "Não Existe - retorno na Tamanho Padrao" << endl;
    return(Vector2D<float>(100.0f, 100.0f));
}

void Gerenciador_Grafico::DrawMap(const string key)
{
    if(ExisteChave(key))
    {
        ptrR = getMap(key)->getBody();
        window.draw(*ptrR);
    }
    else
    {
        cout << "Error Gerenciador: Comando DrawMap - Chave: " << key << endl;
    }
}

void Gerenciador_Grafico::DrawMapBotao(const string key, const bool active)
{
    if(ExisteChave(key))
    {
        Corpo* aux = getMap(key);
        //ptrR = aux->getBody();
        Vector2D<float> left_top;
        Vector2D<float> width_height;
        width_height = aux->getTextureSize();
        width_height.x /= 2.0;
        left_top.y = 0.0f;
        if(active)
        {
            left_top.x = width_height.x;
            //left_top.x = 0.0f;
        }
        else
        {
            left_top.x = 0.0f;
            //left_top.x = width_height.x;
        }

        aux->setIntRect( width_height.x, width_height.y, left_top.x, left_top.y);
        aux->setTextureRect();
        window.draw(*(aux->getBody()));
    }
    else
    {
        cout << "Error Gerenciador: Comando DrawMap - Chave: " << key << endl;
    }
}
