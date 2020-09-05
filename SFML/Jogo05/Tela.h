#ifndef INCLUDED_TELA_H
#define INCLUDED_TELA_H

#include "Gerenciador_Colisao.h"

using namespace Listas;

namespace ent
{
    namespace tela
    {
        class Tela;

        class EstadoTela:
            public Entidade
        {
        public:

            EstadoTela(const string c = "");
            virtual ~EstadoTela();

            void ChangeState(ent::tela::Tela* t, ent::tela::EstadoTela* s);

            virtual void ChecarOperacoes(ent::tela::Tela* t) = 0;
            virtual void jogar(ent::tela::Tela* t) = 0;
            virtual void pause(ent::tela::Tela* t) = 0;
            virtual void opcao(ent::tela::Tela* t) = 0;
            virtual void sair(ent::tela::Tela* t) = 0;

        protected:

            ListaEntidade LEntidade;
        };

        namespace fase
        {
            class Fase:
                public ent::tela::EstadoTela
            {
            protected:

                ent::per::jog::Jogador01* ptr1;
                ent::per::jog::Jogador02* ptr2;

                Listas::ListaEntidade LEntidade;
                Listas::VectorInimigo VInimigo;
                Listas::ListaObstaculo LObstaculo;

                Gerenciador::Gerenciador_Colisao gc1;

                Vector2D<float> posicao_obst;

            public:

                Fase(const unsigned long int number_of_players = 1lu, const string c = "");
                ~Fase();

                void setJogador(ent::per::jog::Jogador01* p1);
                void setJogador(ent::per::jog::Jogador02* p2);

                void setTexture(const string t);


                //MÉTODOS GERAIS DO JOGO
                void VerificarInimigosMortos();

                void InitialUpdate ();
                void UpdateGerenciador ();
                void Update ();

                ///METODOS DE LISTA DE ENTIDADE
                void adicionarEntidade(ent::Entidade* e);
                void Draw();
                void Draw(const Vector2D<float> pos1);
                void Draw(const Vector2D<float> pos1, const Vector2D<float> pos2);

                ///METODOS DE VECTOR INIMIGO
                void adicionarInimigo01(const Vector2D<float> position);
                void adicionarInimigo01(const float x, const float y);
                void ChecarColisoesEntreInimigosObstaculos();
                void ChecarColisoesEntreJogadoresInimigosProjeteis();

                ///METODOS DE LISTA DE OBSTACULO
                void adicionarObstaculoPlataforma();
                void adicionarObstaculoPlataforma(const Vector2D<float> position);
                void adicionarObstaculoPlataforma(const float x, const float y);
                void adicionarObstaculoBau(const Vector2D<float> position);
                void adicionarObstaculoBau(const float x, const float y);
                void ChecarColisoesEntreJogadoresObstaculos();
                void ChecarColisoesEntreObstaculos();

                ///TENTATIVA DE PATRONIZAR A CRIACAO DE FASE
                void criarRetaPlataforma(const float distancia, const float y = 1000.0f);
                void criarRetaPlataforma(const unsigned long int qtde_plataformas = 1, const float y = 1000.0f);

                ///METODOS DE ESTADO DE TELA
                void ChecarOperacoes(ent::tela::Tela* t);//....................TO DO
                void jogar(ent::tela::Tela* t);//....................TO DO
                void pause(ent::tela::Tela* t);//....................TO DO
                void opcao(ent::tela::Tela* t);//....................TO DO
                void sair(ent::tela::Tela* t);//....................TO DO
            };

            class Fase01:
                public Fase
            {
            private:


            public:
                Fase01(const unsigned long int number_of_players = 1lu, const string c = "");
                ~Fase01();
            };

            class Fase02:
                public Fase
            {
            private:


            public:
                Fase02(const unsigned long int number_of_players = 1lu, const string c = "");
                ~Fase02();

            };

            class Fase03:
                public Fase
            {
            private:


            public:
                Fase03(const unsigned long int number_of_players = 1lu, const string c = "");
                ~Fase03();

            };
        }

        namespace menu
        {
            class Botao:
                public Entidade
            {
            protected:

                string chave;
                bool click;
                bool ativo;

            public:

                Botao(const string a = "Texture/Botoes/Play.png");
                ~Botao();

                void setKey(const string key);
                const string getKey() const;

                const bool getClick() const;

                void setTexture(const string t);

                void InitialUpdate();
                void UpdateGerenciador();//............TO DO
                void Update();//.......................TO DO
                void Draw();
            };

            class Game01:
                public Botao
            {
            public:
                Game01(const string a = "Texture/Botoes/Player012.png");
                ~Game01();
            };

            class Game02:
                public Botao
            {
            public:
                Game02(const string a = "Texture/Botoes/Player022.png");
                ~Game02();
            };

            class Option:
                public Botao
            {
            public:
                Option(const string a = "Texture/Botoes/Option2.png");
                ~Option();
            };

            class Exit:
                public Botao
            {
            public:
                Exit(const string a = "Texture/Botoes/Exit2.png");
                ~Exit();
            };

            class GerenciadorBotao
            {
            private:

            long int indice_do_botao;

                deque<Botao*> Botoes;
                deque<Botao*>::iterator it;

            public:

                GerenciadorBotao();
                ~GerenciadorBotao();

                const long int getIndiceBotao();

                void InitialUpdate();
                void insertBotao(ent::tela::menu::Botao* b);
            };

            class Menu:
                public EstadoTela
            {
            protected:

                GerenciadorBotao menu;

            public:

                Menu(const string c);
                virtual ~Menu();

            };

            class MenuInicial:
                public Menu
            {
            private:

                unsigned long int number_of_players;
                ent::tela::menu::Game01* play1;
                ent::tela::menu::Game02* play2;
                ent::tela::menu::Option* option;
                ent::tela::menu::Exit* exit;


            public:

                MenuInicial(const string c = "");
                ~MenuInicial();

                void ChecarOperacoes(ent::tela::Tela* t);

                void setTexture(const string t);
                void InitialUpdate ();
                void UpdateGerenciador ();
                void Update ();
                void Draw ();

                void jogar(ent::tela::Tela* t);
                void pause(ent::tela::Tela* t);
                void opcao(ent::tela::Tela* t);
                void sair(ent::tela::Tela* t);

            };

            class MenuPause:
                public Menu
            {
            public:

                MenuPause();
                ~MenuPause();

                void ChecarOperacoes(ent::tela::Tela* t);

                void setTexture(const string t);
                void InitialUpdate ();
                void UpdateGerenciador ();
                void Update ();
                void Draw ();

                void jogar(ent::tela::Tela* t);
                void pause(ent::tela::Tela* t);
                void opcao(ent::tela::Tela* t);
                void sair(ent::tela::Tela* t);

            };

            class MenuOpcao:
                public Menu
            {
            public:

                MenuOpcao();
                ~MenuOpcao();

                void ChecarOperacoes(ent::tela::Tela* t);

                void setTexture(const string t);
                void InitialUpdate ();
                void UpdateGerenciador ();
                void Update ();
                void Draw ();

                void jogar(Tela* t);
                void pause(Tela* t);
                void opcao(Tela* t);
                void sair(Tela* t);

            };
        }

        class Tela
        {
        private:

            friend class EstadoTela;
            void ChangeState(EstadoTela* s);

        private:

            ent::tela::EstadoTela* _state;
            unsigned long int dif;

        public:

            Tela();
            ~Tela();

            void deleteState();

            void jogar(Tela* t);
            void pause(Tela* t);
            void opcao(Tela* t);
            void dificuldade(Tela* t);
            void tirarTexture(Tela* t);
            void sair(Tela* t);

            void Executar();
        };
    }
}

#endif // INCLUDED_TELA_H
