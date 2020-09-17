#ifndef INCLUDED_GERENCIADOR_COLISAO_H
#define INCLUDED_GERENCIADOR_COLISAO_H

#include "Listas.h"

namespace Gerenciador
{
    class Gerenciador_Colisao
    {
    private:

        ent::per::jog::Player01* ptr1;
        ent::per::jog::Player02* ptr2;

        Listas::ListaObstaculo* LObstaculo;
        Listas::VectorInimigo* VInimigo;

    public:

        Gerenciador_Colisao();
        ~Gerenciador_Colisao();

        void setJogador(ent::per::jog::Player01* p1);
        void setJogador(ent::per::jog::Player02* p2);

        void setListas(Listas::ListaObstaculo* lo);
        void setListas(Listas::VectorInimigo* vi);

        //COLISAO COM JOGADOR:
        const bool ChecarColisaoJogadorObstaculo(ent::per::jog::Player* referencia, ent::obs::Obstacle* colisor);
        const bool ChecarColisaoJogadorInimigo(ent::per::jog::Player* referencia, ent::per::ini::Enemy* colisor);//TO DO
        const bool ChecarColisaoProjetilInimigo(ent::per::Projectile* referencia, ent::per::ini::Enemy* colisor);
        const bool ChecarColisaoProjetilObstaculo(ent::per::Projectile* referencia, ent::obs::Obstacle* colisor);
        void ChecarColisoesJogadoresObstaculos();
        void ChecarColisoesInimigosObstaculos();
        void ChecarColisoesJogadoresInimigosProjeteis();

        //COLISAO COM INIMIGO:
        const bool ChecarColisaoInimigoObstaculo(ent::per::ini::Enemy* referencia, ent::obs::Obstacle* colisor);

        void ChecarCoisoesEntreObstaculos();
        void resetCollisions();
    };
}

#endif // INCLUDED_GERENCIADOR_COLISAO_H
