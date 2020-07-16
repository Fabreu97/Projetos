#ifndef INCLUDED_FASE_H
#define INCLUDED_FASE_H

#include "Gerenciador_Colisao.h"
namespace ent
{
    namespace fase
    {
        class Fase:
            public ent::Entidade
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

            Fase(const string c = "");
            ~Fase();

            void setJogador(ent::per::jog::Jogador01* p1);
            void setJogador(ent::per::jog::Jogador02* p2);

            void setTexture(const string t);

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
        };

        class Fase01:
            public Fase
        {
        private:


        public:
            Fase01();
            ~Fase01();

        };

        class Fase02:
            public Fase
        {
        private:


        public:
            Fase02();
            ~Fase02();

        };

        class Fase03:
            public Fase
        {
        private:


        public:
            Fase03();
            ~Fase03();

        };
    }
}

#endif // INCLUDED_FASE_H
