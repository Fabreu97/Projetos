#ifndef INCLUDED_GERENCIADOR_COLISAO_H
#define INCLUDED_GERENCIADOR_COLISAO_H

#include "Listas.h"

namespace Gerenciador
{
    class Gerenciador_Colisao
    {
    private:

        ent::per::jog::Jogador01* ptr1;
        ent::per::jog::Jogador02* ptr2;

        Listas::ListaObstaculo* LObstaculo;
        Listas::VectorInimigo* VInimigo;

    public:

        Gerenciador_Colisao();
        ~Gerenciador_Colisao();

        void setJogador(ent::per::jog::Jogador01* p1);
        void setJogador(ent::per::jog::Jogador02* p2);

        void setListas(Listas::ListaObstaculo* lo);
        void setListas(Listas::VectorInimigo* vi);

        //COLISAO COM JOGADOR:
        const bool ChecarColisaoJogadorObstaculo(ent::per::jog::Jogador* referencia, ent::obs::Obstaculo* colisor);
        const bool ChecarColisaoJogadorInimigo(ent::per::jog::Jogador* referencia, ent::per::ini::Inimigo* colisor);//TO DO
        const bool ChecarColisaoProjetilInimigo(ent::per::Projetil* referencia, ent::per::ini::Inimigo* colisor);
        const bool ChecarColisaoProjetilObstaculo(ent::per::Projetil* referencia, ent::obs::Obstaculo* colisor);
        void ChecarColisoesJogadoresObstaculos();
        void ChecarColisoesInimigosObstaculos();
        void ChecarColisoesJogadoresInimigosProjeteis();

        //COLISAO COM INIMIGO:
        const bool ChecarColisaoInimigoObstaculo(ent::per::ini::Inimigo* referencia, ent::obs::Obstaculo* colisor);

        void ChecarCoisoesEntreObstaculos();
        void resetCollisions();
    };
}

#endif // INCLUDED_GERENCIADOR_COLISAO_H
