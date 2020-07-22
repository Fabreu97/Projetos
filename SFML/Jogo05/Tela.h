#ifndef INCLUDED_TELA_H
#define INCLUDED_TELA_H

#include "Fase.h"

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

            virtual void ChecarOperacoes() = 0;
            virtual void jogar(ent::tela::Tela* t) = 0;
            virtual void pause(ent::tela::Tela* t) = 0;
            virtual void opcao(ent::tela::Tela* t) = 0;
            virtual void sair(ent::tela::Tela* t) = 0;

        protected:

            ListaEntidade LEntidade;
        };

        namespace menu
        {
            class Botao:
                public Entidade
            {
            protected:

                string chave;
                bool click;

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

            class Jogar:
                public Botao
            {
            public:
                Jogar(const string a = "Texture/Botoes/Play.png");
                ~Jogar();

            };

            class GerenciadorBotao
            {
            private:

                deque<Botao*> Botoes;
                deque<Botao*>::iterator it;

            public:

                GerenciadorBotao();
                ~GerenciadorBotao();

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
            public:

                MenuInicial(const string c = "");
                ~MenuInicial();

                void ChecarOperacoes();

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

                void ChecarOperacoes();

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

                void ChecarOperacoes();

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

            ent::tela::EstadoTela* state;
            unsigned long int dif;

        public:

            Tela();
            ~Tela();

            ent::tela::EstadoTela* getState() const;

            void jogar(Tela* t);
            void pause(Tela* t);
            void opcao(Tela* t);
            void dificuldade(Tela* t);
            void tirarTexture(Tela* t);
            void sair(Tela* t);
        };
    }
}

#endif // INCLUDED_TELA_H
