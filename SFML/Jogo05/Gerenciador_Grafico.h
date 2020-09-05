#ifndef INCLUDED_GERENCIADOR_GRAFICO
#define INCLUDED_GERENCIADOR_GRAFICO

#include "Vector2D.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace Vector;
using namespace std;

namespace Gerenciador
{
    class Gerenciador_Grafico
    {
    public:
        class Corpo
        {
        private:

            sf::RectangleShape corpo;
            sf::Texture textura;
            sf::IntRect uvRect;

            string caminho;

        public:

            Corpo(const Vector2D<float> tamanho = Vector2D<float>(100.0f, 200.0f), const string l = "imagem/tux_from_linux.png");
            ~Corpo();

            void setPosition(const Vector2D<float> position);
            void setPosition(const float x, const float y);
            const Vector2D<float> getPosition() const;

            void setSize(const Vector2D<float> tamanho);
            void setSize(const float x, const float y);
            const Vector2D<float> getSize() const;

            void setTexture(const string t);
            const string getTexture() const;
            const Vector2D<float> getTextureSize() const;
            void SemTextura();

            void setIntRect (const float width, const float height, const float left, const float top);
            void setTextureRect ();

            void setColor(const float red, const float green, const float blue);

            void move (const float x, const float y);
            void move (const Vector2D<float> movimento);
            sf::RectangleShape* getBody();

            //Sobrecarga de Operadores
            const bool operator == (const Corpo& c) const;
            const bool operator == (const Vector2D<float>& p) const;
            const bool operator != (const Corpo& c) const;
            const bool operator != (const Vector2D<float>& p) const;
        };

    private:

        sf::RenderWindow window; // Janela
        sf::View view; // Camera do Universo 2D da Tela
        sf::Event evento; //Evento da Janela
        sf::Clock clock; // Relógio

        int numero_de_jogadores;
        float swy;
        static float delta_time; //Tempo

        sf::RectangleShape* ptrR;

        //Corpos das Entidades
        Corpo Player01;
        Corpo Player02;
        Corpo Inimigo01;
        Corpo Inimigo02;
        Corpo Inimigo03;
        Corpo Plataforma;
        Corpo Obstaculo01;
        Corpo Obstaculo02;
        Corpo Obstaculo03;
        Corpo Projetil;
        Corpo Fase;

        Corpo Barra_de_Vida01;
        Corpo Barra_de_Vida02;

        map<string, Corpo*> menu;

        sf::CircleShape shape;

    public:

        Gerenciador_Grafico(const string nome_do_jogo = "The Game", const Vector2D<unsigned int> tam_janela = Vector2D<unsigned int>(1600u, 800u));
        ~Gerenciador_Grafico();

        void DrawTeste(sf::RectangleShape& t);

        //Ooerações com Janela
        bool isOpen();
        bool pollEvent();
        void setView(); //Colocar a Camera na Janela
        Vector2D<float> getPositionView() const;
        void clear();
        void display();
        void close();
        void ResizeView();
        bool Resized();
        void setTitle(const string nome_da_janela);
        void setVerticalSyncEnabled(const bool chave); //Deixa o loop com a mesma velocidade que seu monitor
        void setFramerateLimit(const unsigned long int vel); //colocar a velocidade por frame(1s / time = tempo do loop) RECOMENDAVEL POR VOLTA DE 100 A 60
        void setFramerateLimitTime(const float time);
        const Vector2D<float> getPositionWindow() const;
        float WindowRation();
        const Vector2D<float> getSizeWindow() const;

        //Ooerações com Janela BR
        bool janela_Aberta(); //Window.isOpen()
        bool captar_Evento(); //Window.isPoll()
        void limpar_Janela(); //clear
        void Exibicao(); // Display
        void fecha_Janela(); // evento.type == sf::Event::Close

        //Operações com a Camera(View) da Janela
        void Centralizar(const float x1, const float y1, const float x2, const float y2);
        void Centralizar(const Vector2D<float> v1, const Vector2D<float> v2);
        void Centralizar(const float x, const float y);
        void Centralizar(Vector2D<float> v);

        //Ooerações com Evento de Janela
        bool fecho_Janela();

        //Desenhar na Tela
        void Draw_Shape();
        void DrawPlayer01();
        void DrawPlayer02();
        void DrawInimigo01();
        void DrawInimigo02();
        void DrawInimigo03();
        void DrawPlataforma();
        void DrawObstaculo01();
        void DrawObstaculo02();
        void DrawObstaculo03();
        void DrawFase();
        void DrawProjetil();
        void DrawLife01();
        void DrawLife02();
        void SemTextura();

        //Detectar Teclas Preenchionadas
        const bool isPW() const;
        const bool isPS() const;
        const bool isPA() const;
        const bool isPD() const;
        const bool isPR() const;
        const bool isPEnter() const;
        const bool isP_UP() const;
        const bool isP_Down() const;
        const bool isP_Left() const;
        const bool isP_Right() const;
        const bool isP_ALT() const;
        const bool isP_Space() const;

        //Mouse Preenchionado
        const bool isM_Left() const;
        const bool isM_Right() const;

        const Vector2D<float> getPositionMouse() const;

        void set_Delta_Time();
        static float get_Delta_Time();

        //Metodos Dedicados ao Corpo do Player 01
        void setPositionPlayer01(const Vector2D<float> position);
        void setPositionPlayer01(const float x, const float y);
        const Vector2D<float> getPositionPlayer01() const;
        void setSizePlayer01(const Vector2D<float> tamanho);
        void setSizePlayer01(const float x, const float y);
        const Vector2D<float> getSizePlayer01() const;
        void setTexturePlayer01(const string t);
        const string getTexturePlayer01() const;
        const Vector2D<float> getTextureSizePlayer01() const;
        void setIntRectPlayer01(const float width, const float height, const float left, const float top);
        void setTextureRectPlayer01();
        void movePlayer01 (const float x, const float y);
        void movePlayer01 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Player02
        void setPositionPlayer02(const Vector2D<float> position);
        void setPositionPlayer02(const float x, const float y);
        const Vector2D<float> getPositionPlayer02() const;
        void setSizePlayer02(const Vector2D<float> tamanho);
        void setSizePlayer02(const float x, const float y);
        const Vector2D<float> getSizePlayer02() const;
        void setTexturePlayer02(const string t);
        const string getTexturePlayer02() const;
        const Vector2D<float> getTextureSizePlayer02() const;
        void setIntRectPlayer02(const float width, const float height, const float left, const float top);
        void setTextureRectPlayer02();
        void movePlayer02 (const float x, const float y);
        void movePlayer02 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Inimigo01
        void setPositionInimigo01(const Vector2D<float> position);
        void setPositionInimigo01(const float x, const float y);
        const Vector2D<float> getPositionInimigo01() const;
        void setSizeInimigo01(const Vector2D<float> tamanho);
        void setSizeInimigo01(const float x, const float y);
        const Vector2D<float> getSizeInimigo01() const;
        void setTextureInimigo01(const string t);
        const string getTextureInimigo01() const;
        const Vector2D<float> getTextureSizeInimigo01() const;
        void setIntRectInimigo01(const float width, const float height, const float left, const float top);
        void setTextureRectInimigo01();
        void moveInimigo01 (const float x, const float y);
        void moveInimigo01 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Inimigo02
        void setPositionInimigo02(const Vector2D<float> position);
        void setPositionInimigo02(const float x, const float y);
        const Vector2D<float> getPositionInimigo02() const;
        void setSizeInimigo02(const Vector2D<float> tamanho);
        void setSizeInimigo02(const float x, const float y);
        const Vector2D<float> getSizeInimigo02() const;
        void setTextureInimigo02(const string t);
        const string getTextureInimigo02() const;
        const Vector2D<float> getTextureSizeInimigo02() const;
        void setIntRectInimigo02(const float width, const float height, const float left, const float top);
        void setTextureRectInimigo02();
        void moveInimigo02 (const float x, const float y);
        void moveInimigo02 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Inimigo03
        void setPositionInimigo03(const Vector2D<float> position);
        void setPositionInimigo03(const float x, const float y);
        const Vector2D<float> getPositionInimigo03() const;
        void setSizeInimigo03(const Vector2D<float> tamanho);
        void setSizeInimigo03(const float x, const float y);
        const Vector2D<float> getSizeInimigo03() const;
        void setTextureInimigo03(const string t);
        const string getTextureInimigo03() const;
        const Vector2D<float> getTextureSizeInimigo03() const;
        void setIntRectInimigo03(const float width, const float height, const float left, const float top);
        void setTextureRectInimigo03();
        void moveInimigo03 (const float x, const float y);
        void moveInimigo03 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Plataforma
        void setPositionPlataforma(const Vector2D<float> position);
        void setPositionPlataforma(const float x, const float y);
        const Vector2D<float> getPositionPlataforma() const;
        void setSizePlataforma(const Vector2D<float> tamanho);
        void setSizePlataforma(const float x, const float y);
        const Vector2D<float> getSizePlataforma() const;
        void setTexturePlataforma(const string t);
        const string getTexturePlataforma() const;
        const Vector2D<float> getTextureSizePlataforma() const;
        void setIntRectPlataforma(const float width, const float height, const float left, const float top);
        void setTextureRectPlataforma();
        void movePlataforma (const float x, const float y);
        void movePlataforma (const Vector2D<float> movimento);


        //Métodos Dedicados ao Corpo do Obstaculo01
        void setPositionObstaculo01(const Vector2D<float> position);
        void setPositionObstaculo01(const float x, const float y);
        const Vector2D<float> getPositionObstaculo01() const;
        void setSizeObstaculo01(const Vector2D<float> tamanho);
        void setSizeObstaculo01(const float x, const float y);
        const Vector2D<float> getSizeObstaculo01() const;
        void setTextureObstaculo01(const string t);
        const string getTextureObstaculo01() const;
        const Vector2D<float> getTextureSizeObstaculo01() const;
        void setIntRectObstaculo01(const float width, const float height, const float left, const float top);
        void setTextureRectObstaculo01();
        void moveObstaculo01 (const float x, const float y);
        void moveObstaculo01 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Obstaculo02
        void setPositionObstaculo02(const Vector2D<float> position);
        void setPositionObstaculo02(const float x, const float y);
        const Vector2D<float> getPositionObstaculo02() const;
        void setSizeObstaculo02(const Vector2D<float> tamanho);
        void setSizeObstaculo02(const float x, const float y);
        const Vector2D<float> getSizeObstaculo02() const;
        void setTextureObstaculo02(const string t);
        const string getTextureObstaculo02() const;
        const Vector2D<float> getTextureSizeObstaculo02() const;
        void setIntRectObstaculo02(const float width, const float height, const float left, const float top);
        void setTextureRectObstaculo02();
        void moveObstaculo02 (const float x, const float y);
        void moveObstaculo02 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Obstaculo03
        void setPositionObstaculo03(const Vector2D<float> position);
        void setPositionObstaculo03(const float x, const float y);
        const Vector2D<float> getPositionObstaculo03() const;
        void setSizeObstaculo03(const Vector2D<float> tamanho);
        void setSizeObstaculo03(const float x, const float y);
        const Vector2D<float> getSizeObstaculo03() const;
        void setTextureObstaculo03(const string t);
        const string getTextureObstaculo03() const;
        const Vector2D<float> getTextureSizeObstaculo03() const;
        void setIntRectObstaculo03(const float width, const float height, const float left, const float top);
        void setTextureRectObstaculo03();
        void moveObstaculo03 (const float x, const float y);
        void moveObstaculo03 (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo do Fase
        void setPositionFase(const Vector2D<float> position);
        void setPositionFase(const float x, const float y);
        const Vector2D<float> getPositionFase() const;
        void setSizeFase(const Vector2D<float> tamanho);
        void setSizeFase(const float x, const float y);
        const Vector2D<float> getSizeFase() const;
        void setTextureFase(const string t);
        const string getTextureFase() const;
        const Vector2D<float> getTextureSizeFase() const;
        void setIntRectFase(const float width, const float height, const float left, const float top);
        void setTextureRectFase();
        void moveFase (const float x, const float y);
        void moveFase (const Vector2D<float> movimento);

        //Métodos Dedicados ao Corpo de Corações
        void setPositionLife01();
        void setSizeLife01(const Vector2D< float> v);
        void setSizeLife01(const  float x, const  float y);
        void setTextureLife01(const string t);
        Vector2D<float> getTextureSizeLife01() const;
        void setIntRectLife01(const float width, const float height, const float left, const float top);
        void setTextureRectLife01();
        void moveLife01(const Vector2D<float> v);
        void moveLife01(const float x, const float y);

        //METODOS DEDICADOS AO CORPO DA BARRA DE VIDA DO PLAYER 02
        void setPositionLife02();
        void setSizeLife02(const Vector2D< float> v);
        void setSizeLife02(const  float x, const  float y);
        void setTextureLife02(const string t);
        Vector2D<float> getTextureSizeLife02() const;
        void setIntRectLife02(const float width, const float height, const float left, const float top);
        void setTextureRectLife02();
        void moveLife02(const Vector2D<float> v);
        void moveLife02(const float x, const float y);

        //MÉTODOS DO CORPO PROJETIL
        void setPositionProjetil(const Vector2D<float> position);
        void setPositionProjetil(const float x, const float y);
        const Vector2D<float> getPositionProjetil() const;
        void setSizeProjetil(const Vector2D<float> tamanho);
        void setSizeProjetil(const float x, const float y);
        const Vector2D<float> getSizeProjetil() const;
        void setTextureProjetil(const string t);
        const string getTextureProjetil() const;
        const Vector2D<float> getTextureSizeProjetil() const;
        void setIntRectProjetil(const float width, const float height, const float left, const float top);
        void setTextureRectProjetil();
        void moveProjetil (const float x, const float y);
        void moveProjetil (const Vector2D<float> movimento);

        //MÉTODOS DO CORPO SERA DICIOANDO NO MAP MENU
        Corpo* getMap(const string key);
        const bool ExisteChave(const string key);
        void AdicionarBotaoNoMenu(const string key, const string texture, const Vector2D<float> position, const Vector2D<float> sizeB);
        void ajustarBotoes(const string key, const unsigned long int qtd_botoes, const unsigned long int indice);
        Vector2D<float> getPositionButton(const string key);
        Vector2D<float> getSizeButton(const string key);
        void DrawMap(const string key);
        void DrawMapBotao(const string key, const bool active);
    };
}

#endif // INCLUDED_GERENCIADOR_GRAFICO
