#include "Gerenciador_Colisao.h"

#define COLLISION_DAMAGE 1lu

using namespace Gerenciador;

Gerenciador_Colisao::Gerenciador_Colisao()
{
    ptr1 = NULL;
    ptr2 = NULL;
    LObstaculo = NULL;
    VInimigo = NULL;
}

Gerenciador_Colisao::~Gerenciador_Colisao()
{

}

void Gerenciador_Colisao::setJogador(ent::per::jog::Jogador01* p1)
{
    ptr1 = p1;
}

void Gerenciador_Colisao::setJogador(ent::per::jog::Jogador02* p2)
{
    ptr2 = p2;
}

void Gerenciador_Colisao::setListas(Listas::ListaObstaculo* lo)
{
    this->LObstaculo = lo;
}

void Gerenciador_Colisao::setListas(Listas::VectorInimigo* vi)
{
    this->VInimigo = vi;
}

const bool Gerenciador_Colisao::ChecarColisaoJogadorObstaculo(ent::per::jog::Jogador* referencia, ent::obs::Obstaculo* colisor)
{
    Vector2D<unsigned long int> horizontal(0.0f, 0.0f);
    Vector2D<unsigned long int> vertical(0.0f, 0.0f);
    Vector2D<float> thisPosition = referencia->getPosition();
    Vector2D<float> thisHalfSize = referencia->getHalfSize();
    Vector2D<float> otherPosition = colisor->getPosition();
    Vector2D<float> otherHalfSize = colisor->getHalfSize();

    if(referencia->getFace())
    {
        thisPosition.x -= referencia->galho;
    }
    else
    {
        thisPosition.x += referencia->galho;
    }

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);

    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        colisor->Update();
        referencia->setColisao(true);
        colisor->setColisao(true);

        if(intersectX < intersectY)
        {
            //Colisão Vertical
            if(deltaY > 0.0f)
            {
                // colisao de BAIXO pra CIMA
                referencia->Move( 0.0f, +intersectY  * colisor->getPush());
                colisor->Move( 0.0f, -intersectY  * (1.0f - colisor->getPush()) );

                vertical.y = 1;
            }
            else
            {
                //colisao de CIMA pra BAIXO
                referencia->Move( 0.0f, -intersectY  * colisor->getPush() );
                colisor->Move( 0.0f, +intersectY  * (1.0f - colisor->getPush()));

                vertical.x = 1;
            }
            referencia->setVerticalCollision(vertical);
        }
        else
        {
            //Colisao Horizontal
            if(deltaX > 0.0f)
            {
                // colisao da ESQUERDA para DIREITA
                referencia->Move( +intersectY  * colisor->getPush() * 0.1, 0.0f );
                colisor->Move( -intersectY  * (1.0f - colisor->getPush()), 0.0f);

                horizontal.y = 1lu;
            }
            else
            {
                //colisao de DIREITA pra ESQUERDA
                referencia->Move( -intersectY * colisor->getPush() * 0.1, 0.0f);
                colisor->Move( intersectY * (1.0f - colisor->getPush()), 0.0f);

                horizontal.x = 1lu;
            }
            referencia->setHorizontalCollision(horizontal);
        }
        colisor->UpdatePosition();
        return(true);
    }
    return(false);
}

const bool Gerenciador_Colisao::ChecarColisaoJogadorInimigo(ent::per::jog::Jogador* referencia, ent::per::ini::Inimigo* colisor)
{
    Vector2D<unsigned long int> horizontal(0.0f, 0.0f);
    Vector2D<unsigned long int> vertical(0.0f, 0.0f);
    Vector2D<float> thisPosition = referencia->getPosition();
    Vector2D<float> thisHalfSize = referencia->getHalfSize();
    Vector2D<float> otherPosition = colisor->getPosition();
    Vector2D<float> otherHalfSize = colisor->getHalfSize();

    if(referencia->getFace())
    {
        thisPosition.x -= referencia->galho;
    }
    else
    {
        thisPosition.x += referencia->galho;
    }

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);

    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        colisor->Update();
        if(intersectX > intersectY)
        {
            //COLISAO HORIZONTAL
            if(deltaX > 0.0f)
            {
                //colisao da esquerda para direita
                referencia->Move(intersectX);
                colisor->Move(-intersectX * 0.1f);
                horizontal.y = 1lu;
            }
            else
            {
                //colisao da direita para esquerda
                referencia->Move(-intersectX * 1.0f);
                colisor->Move(intersectX * 0.1f);
                horizontal.x = 1lu;
            }
            referencia->setDano(true);
            referencia->setHorizontalCollision(horizontal);
        }
        else
        {
            //COLISAO VERTICAL
            if(deltaY > 0.0f)
            {
                //colisão a baixo da referencia
                referencia->Move(0.0f, intersectY);

                vertical.y = 1lu;
                colisor->setDano(true);
            }
            else
            {
                referencia->Move(0.0f, -intersectY);

                vertical.x = 1lu;
            }
            referencia->setVerticalCollision(vertical);
        }
        colisor->UpdatePosition();

        return(true);
    }
    return(false);
}
void Gerenciador_Colisao::ChecarColisoesJogadoresObstaculos()
{
    if(LObstaculo != NULL)
    {
        if(ptr1 != NULL)
        {
            unsigned long int i;
            unsigned long int j;
            for(i = 0lu; i < LObstaculo->getSize(); i++)
            {
                ent::obs::Obstaculo* aux1 = LObstaculo->getObstaculo(i);
                for(j = 0lu; j < ptr1->getSizeListaProjetil(); j++)
                {
                    ent::per::Projetil* pro1 = ptr1->getProjetil(j);
                    if(ChecarColisaoProjetilObstaculo(pro1, aux1))
                    {
                        pro1->setColisao(true);
                    }
                    //pro1->setColisao(ChecarColisaoProjetilObstaculo(pro1, aux1));
                }
                ChecarColisaoJogadorObstaculo(ptr1, aux1);
            }
        }

        if(ptr2 != NULL)
        {
            unsigned long int i;
            unsigned long int j;
            for(i = 0lu; i < LObstaculo->getSize(); i++)
            {
                ent::obs::Obstaculo* aux2 = LObstaculo->getObstaculo(i);
                for(j = 0lu; j < ptr2->getSizeListaProjetil(); j++)
                {
                    ent::per::Projetil* pro2 = ptr2->getProjetil(j);
                    if(ChecarColisaoProjetilObstaculo(pro2, aux2))
                    {
                        pro2->setColisao(true);
                    }
                }
                ChecarColisaoJogadorObstaculo(ptr2, aux2);
            }
        }
    }
}

const bool Gerenciador_Colisao::ChecarColisaoInimigoObstaculo(ent::per::ini::Inimigo* referencia, ent::obs::Obstaculo* colisor)
{
    Vector2D<unsigned long int> horizontal(0.0f, 0.0f);
    Vector2D<unsigned long int> vertical(0.0f, 0.0f);
    Vector2D<float> thisPosition = referencia->getPosition();
    Vector2D<float> thisHalfSize = referencia->getHalfSize();
    Vector2D<float> otherPosition = colisor->getPosition();
    Vector2D<float> otherHalfSize = colisor->getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);


    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        referencia->InitialUpdate();
        colisor->Update(); //atualiza o tamanho e a posição

        referencia->setColisao(true);
        colisor->setColisao(true);

        if(intersectX < intersectY)
        {
            //Colisão Vertical
            if(deltaY > 0.0f)
            {
                // colisao de BAIXO pra CIMA
                referencia->Move( 0.0f, +intersectY  * 1.0f);

                vertical.y = 1lu;
            }
            else
            {
                //colisao de CIMA pra BAIXO
                referencia->Move( 0.0f, -intersectY  * colisor->getPush() );

                vertical.x = 1lu;
            }
            referencia->setVerticalCollision(vertical);
        }
        else
        {
            //Colisao Horizontal
            if(deltaX > 0.0f)
            {
                // colisao da ESQUERDA para DIREITA
                referencia->Move( +intersectY  * colisor->getPush() * 0.1, 0.0f );
                //ent::Entidade::getGerenciadorGrafico()->get_Delta_Time()

                horizontal.y = 1lu;

            }
            else
            {
                //colisao de DIREITA pra ESQUERDA
                referencia->Move( -intersectY * colisor->getPush() * 0.1, 0.0f);

                horizontal.x = 1lu;
            }
            referencia->setHorizontalCollision(horizontal);
        }
        referencia->UpdatePosition();
        //colisor->UpdatePosition();
        return(true);
    }
    return(false);
}

void Gerenciador_Colisao::ChecarColisoesInimigosObstaculos()
{
    if(VInimigo != NULL)
    {
        if(LObstaculo != NULL)
        {
            unsigned long int i;
            unsigned long int j;
            for(i = 0lu; i < VInimigo->getSize(); i++)
            {
                ent::per::ini::Inimigo* aux = (*VInimigo)[i];
                for(j = 0lu; j < LObstaculo->getSize(); j++)
                {
                    ChecarColisaoInimigoObstaculo(aux, LObstaculo->getObstaculo(j));
                }
            }
        }
    }
}

const bool Gerenciador_Colisao::ChecarColisaoProjetilInimigo(ent::per::Projetil* referencia, ent::per::ini::Inimigo* colisor)
{
    Vector2D<unsigned long int> horizontal(0.0f, 0.0f);
    Vector2D<unsigned long int> vertical(0.0f, 0.0f);
    Vector2D<float> thisPosition = referencia->getPosition();
    Vector2D<float> thisHalfSize = referencia->getHalfSize();
    Vector2D<float> otherPosition = colisor->getPosition();
    Vector2D<float> otherHalfSize = colisor->getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);


    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        referencia->InitialUpdate();
        if(intersectY < intersectX)
        {
            //COLISAO HORIZONTAL
            if(deltaX > 0.0f)
            {
                referencia->Move(intersectX, 0.0f);
                //colisor->setDirecao(-1.0f, 0.0f);
                colisor->setHorizontalCollision(1lu, 0lu);
            }
            else
            {
                referencia->Move(-intersectX, 0.0f);
                //colisor->setDirecao(1.0f, 0.0f);
                colisor->setHorizontalCollision(0lu, 1lu);
            }
        }
        else
        {
            //COLISÃO VERTICAL
            if(deltaY > 0.0f)
            {
                referencia->Move(0.0f, intersectY);
            }
            else
            {
                referencia->Move(0.0f, -intersectY);
            }
        }
        referencia->UpdatePosition();
        return(true);
    }
    return(false);
}

const bool Gerenciador_Colisao::ChecarColisaoProjetilObstaculo(ent::per::Projetil* referencia, ent::obs::Obstaculo* colisor)
{
    Vector2D<float> thisPosition = referencia->getPosition();
    Vector2D<float> thisHalfSize = referencia->getHalfSize();
    Vector2D<float> otherPosition = colisor->getPosition();
    Vector2D<float> otherHalfSize = colisor->getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);

    if(intersectX < 0.0f && intersectY < 0.0f)
    {
        referencia->InitialUpdate();
        if(deltaX > 0.0f)
        {
            referencia->Move(intersectX);
        }
        else
        {
            referencia->Move(-intersectX);
        }
        referencia->UpdatePosition();
        return(true);
    }
    return(false);
}

void Gerenciador_Colisao::ChecarColisoesJogadoresInimigosProjeteis()
{
    if(VInimigo != NULL)
    {
        if(ptr1 != NULL)
        {
            unsigned long int i;
            unsigned long int j;
            for(i = 0lu; i < VInimigo->getSize(); i++)
            {
                ent::per::ini::Inimigo* ini01 = (*VInimigo)[i];
                for(j = 0lu; j < ptr1->getSizeListaProjetil(); j++)
                {
                    ent::per::Projetil* pro1 = ptr1->getProjetil(j);
                    if(ChecarColisaoProjetilInimigo(pro1, ini01))
                    {
                        pro1->setColisao(true);
                        ini01->setDano(true);
                        ini01->Damage(pro1->attackForce());
                    }
                }
                ptr1->setDano(false);
                if(ChecarColisaoJogadorInimigo(ptr1, ini01))
                {
                    if(ptr1->getDano())
                    {
                        ptr1->Damage(COLLISION_DAMAGE);
                    }
                }
            }
        }
        if(ptr2 != NULL)
        {
            unsigned long int i;
            unsigned long int j;
            for(i = 0lu; i < VInimigo->getSize(); i++)
            {
                ent::per::ini::Inimigo* ini02 = (*VInimigo)[i];
                for(j = 0lu; j < ptr2->getSizeListaProjetil(); j++)
                {
                    ent::per::Projetil* pro2 = ptr2->getProjetil(j);
                    if(ChecarColisaoProjetilInimigo(pro2, ini02))
                    {
                        pro2->setColisao(true);
                        ini02->setDano(true);
                    }
                }
                if(ChecarColisaoJogadorInimigo(ptr2, ini02))
                {

                }
            }
        }
    }
}

void Gerenciador_Colisao::ChecarCoisoesEntreObstaculos()
{
    LObstaculo->ChecarColisoesEntreObstaculo();
}

void Gerenciador_Colisao::resetCollisions()
{
    LObstaculo->resetCollisions();
    VInimigo->resetCollisions();
}
