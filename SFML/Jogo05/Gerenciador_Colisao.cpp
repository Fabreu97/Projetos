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
    Vector2D<float> direcao;
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

                direcao.x = 0.0f;
                direcao.y = 1.0f;
            }
            else
            {
                //colisao de CIMA pra BAIXO
                referencia->Move( 0.0f, -intersectY  * colisor->getPush() );
                colisor->Move( 0.0f, +intersectY  * (1.0f - colisor->getPush()));

                direcao.x = 0.0f;
                direcao.y = -1.0f;
            }
        }
        else
        {
            //Colisao Horizontal
            if(deltaX > 0.0f)
            {
                // colisao da ESQUERDA para DIREITA
                referencia->Move( +intersectY  * colisor->getPush() * 0.1, 0.0f );
                colisor->Move( -intersectY  * (1.0f - colisor->getPush()), 0.0f);
                //ent::Entidade::getGerenciadorGrafico()->get_Delta_Time()

                direcao.x = 1.0f;
                direcao.y = 0.0f;

            }
            else
            {
                //colisao de DIREITA pra ESQUERDA
                referencia->Move( -intersectY * colisor->getPush() * 0.1, 0.0f);
                colisor->Move( intersectY * (1.0f - colisor->getPush()), 0.0f);

                direcao.x = -1.0f;
                direcao.y = 0.0f;
            }
        }
        referencia->IncrementarDirecao(direcao);
        colisor->UpdatePosition();
        return(true);
    }
    return(false);
}

const bool Gerenciador_Colisao::ChecarColisaoJogadorInimigo(ent::per::jog::Jogador* referencia, ent::per::ini::Inimigo* colisor)
{
    Vector2D<float> direcao;
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
        colisor->InitialUpdate();
        if(intersectX > intersectY)
        {
            //COLISAO HORIZONTAL
            if(deltaX > 0.0f)
            {
                //colisao da esquerda para direita
                referencia->Move(intersectX);
                colisor->Move(-intersectX * 0.1f);
                direcao.x = 1.0f;
                direcao.y = 0.0f;
            }
            else
            {
                //colisao da direita para esquerda
                referencia->Move(-intersectX * 1.0f);
                colisor->Move(intersectX * 0.1f);
                direcao.x = -1.0f;
                direcao.y = 0.0f;
            }
            referencia->setDano(true);
        }
        else
        {
            //COLISAO VERTICAL
            if(deltaY > 0.0f)
            {
                referencia->Move(0.0f, intersectY);

                //direcao.y = 1.0f;
                direcao.x = 0.0f;
                referencia->setDirecao(0.0f, 0.0f);
                colisor->setDano(true);
                if(referencia->getVelocidade().y >= 0.0f)
                {
                    referencia->incrementarVelocidade(0.0f, -sqrtf(5 * referencia->getAlturaSalto() * 981.0f));
                }
            }
            else
            {
                referencia->Move(0.0f, -intersectY);

                direcao.y = -1.0f;
                direcao.x = 0.0f;
            }
        }
        referencia->IncrementarDirecao(direcao);
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
    Vector2D<float> direcao;
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
        colisor->Update();

        referencia->setColisao(true);
        colisor->setColisao(true);

        if(intersectX < intersectY)
        {
            //Colisão Vertical
            if(deltaY > 0.0f)
            {
                // colisao de BAIXO pra CIMA
                referencia->Move( 0.0f, +intersectY  * 1.0f);

                direcao.x = 0.0f;
                direcao.y = 1.0f;
            }
            else
            {
                //colisao de CIMA pra BAIXO
                referencia->Move( 0.0f, -intersectY  * colisor->getPush() );

                direcao.x = 0.0f;
                direcao.y = -1.0f;
            }
        }
        else
        {
            //Colisao Horizontal
            if(deltaX > 0.0f)
            {
                // colisao da ESQUERDA para DIREITA
                referencia->Move( +intersectY  * colisor->getPush() * 0.1, 0.0f );
                //ent::Entidade::getGerenciadorGrafico()->get_Delta_Time()

                direcao.x = 1.0f;
                direcao.y = 0.0f;

            }
            else
            {
                //colisao de DIREITA pra ESQUERDA
                referencia->Move( -intersectY * colisor->getPush() * 0.1, 0.0f);

                direcao.x = -1.0f;
                direcao.y = 0.0f;
            }
        }
        referencia->IncrementarDirecao(direcao);
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
                ent::per::ini::Inimigo* aux = VInimigo->getInimigo(i);
                aux->setDirecao(0.0f, 0.0f);
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
            }
            else
            {
                referencia->Move(-intersectX, 0.0f);
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
            ptr1->setDirecao(0.0f, 0.0f);
            for(i = 0lu; i < VInimigo->getSize(); i++)
            {
                ent::per::ini::Inimigo* ini01 = VInimigo->getInimigo(i);
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
            ptr2->setDirecao(0.0f, 0.0f);
            for(i = 0lu; i < VInimigo->getSize(); i++)
            {
                ent::per::ini::Inimigo* ini02 = VInimigo->getInimigo(i);
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
