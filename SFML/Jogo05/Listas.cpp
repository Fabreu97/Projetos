#include "Listas.h"

///MÉTODOS DA CLASSE LISTA DE ENTIDADES

Listas::ListaEntidade::ListaEntidade():
    lista()
    {

    }
Listas::ListaEntidade::~ListaEntidade()
{
    limpar();
}

const unsigned int Listas::ListaEntidade::getSize() const
{
    return(lista.size());
}

void Listas::ListaEntidade::incluirEntidade(ent::Entidade* e)
{
    lista.push_back(e);
}

void Listas::ListaEntidade::limpar()
{
    lista.clear();
}

void Listas::ListaEntidade::Draw()
{
    list<ent::Entidade*>::iterator it;

    for(it = lista.begin(); it != lista.end(); ++it)
    {
        (*it)->Update();
        (*it)->Draw();
    }
}

void Listas::ListaEntidade::Draw(const Vector2D<float>& p1)
{
    list<ent::Entidade*>::iterator it;
    float xe = p1.x - 2100.0f;
    float xd = p1.x + 2100.0f;
    for(it = lista.begin(); it != lista.end(); ++it)
    {

        if( (*it)->getPosition().x > xe && (*it)->getPosition().x < xd)
        {
            (*it)->Update();
            (*it)->Draw();
        }
    }
}

void Listas::ListaEntidade::Draw(const Vector2D<float>& p1, const Vector2D<float>& p2)
{
    list<ent::Entidade*>::iterator it;
    float xe, xd;
    xe = (p1.x + p2.x) / 2.0f;
    xd = xe;
    xe -= 2100.0f;
    xd += 2100.0f;
    for(it = lista.begin(); it != lista.end(); ++it)
    {
        if( (*it)->getPosition().x > xe &&  (*it)->getPosition().x < xd )
        {
            (*it)->Update();
            (*it)->Draw();
        }
    }
}

///IMPLEMENTACOES DA CLASSE VECTOR DE INIMIGO

Listas::VectorInimigo::VectorInimigo():
    vetor()
{

}

Listas::VectorInimigo::~VectorInimigo()
{
    limpar();
}

const unsigned long int Listas::VectorInimigo::getSize() const
{
    return(vetor.size());
}

const bool Listas::VectorInimigo::incluirInimigo(ent::per::ini::Inimigo* i)
{
    if(i != NULL)
    {
        vetor.push_back(i);
        return(true);
    }
    return(false);
}

ent::per::ini::Inimigo* Listas::VectorInimigo::getInimigo(const unsigned long int indice) const
{
    if(indice < getSize())
    {
        return(vetor[indice]);
    }
    return(NULL);
}

void Listas::VectorInimigo::eliminarInimigo(const unsigned long int indice)
{
    if(indice >= 0lu && indice < getSize())
    {
        delete(vetor[indice]);
        it = vetor.begin();
        unsigned long int i;
        for(i = 0lu; i < getSize(); i++)
        {
            if(i == indice)
            {
                vetor.erase(it);
                i = getSize();
            }
            it++;
        }
    }
}

void Listas::VectorInimigo::limpar()
{
    unsigned long int i;
    for(i = 0; i < vetor.size(); i++)
    {
        delete (vetor[i]);
    }
    vetor.clear();
}

///IMPLEMENTACOES DA CLASSE LISTA DE OBSTACULO

Listas::ListaObstaculo::ListaObstaculo():
    lista()
{

}

Listas::ListaObstaculo::~ListaObstaculo()
{
    limpar();
}

const unsigned long int Listas::ListaObstaculo::getSize() const
{
    return(lista.get_Tamanho());
}

const bool Listas::ListaObstaculo::incluirObstaculo(ent::obs::Obstaculo* o) //REVIEW
{
    return(lista.inserir(o));
}

ent::obs::Obstaculo* Listas::ListaObstaculo::getObstaculo(const unsigned long int indice) const
{
    if(indice < getSize())
    {
        return(lista.get_Info(indice));
    }
    return(NULL);
}

void Listas::ListaObstaculo::eliminarObstaculo(const unsigned long int i)
{
    lista.eliminar_Info(i);
}

void Listas::ListaObstaculo::limpar()
{

    unsigned long int i;
    for(i = 0; i < lista.get_Tamanho(); i++)
    {
        ent::obs::Obstaculo* aux = lista.get_Info(i);
        delete aux;
    }
    lista.limpar();
}

const bool Listas::ListaObstaculo::ChecarColisoesEntreObstaculo(ent::obs::Obstaculo* a, ent::obs::Obstaculo* b)
{
    Vector2D<float> direcao;
    Vector2D<float> thisPosition = a->getPosition();
    Vector2D<float> thisHalfSize = a->getHalfSize();
    Vector2D<float> otherPosition = b->getPosition();
    Vector2D<float> otherHalfSize = b->getHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
    float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);

    if(intersectX < 0.0 && intersectY < 0.0)
    {
        a->setColisao(true);
        b->setColisao(true);

        if(intersectX > intersectY)
        {
            //COLISAO HORIZONTAL
            if(deltaX > 0.0f)
            {
                //COLISAO DA DIREITA DO REFERENCIAL

                if(a->getID() != 6)
                {
                    a->InitialUpdate();
                    a->Move(intersectX, 0.0f);
                    a->UpdatePosition();
                }

                if(b->getID() != 6)
                {
                    b->InitialUpdate();
                    b->Move(-intersectX, 0.0f);
                    b->UpdatePosition();
                }

                direcao.x = 1.0f;
                direcao.y = 0.0f;
            }
            else
            {

                if(a->getID() != 6lu)
                {
                    a->InitialUpdate();
                    a->Move(-intersectX, 0.0f);
                    a->UpdatePosition();
                }

                if(b->getID() != 6lu)
                {
                    b->InitialUpdate();
                    b->Move(intersectX, 0.0f);
                    b->UpdatePosition();
                }

                direcao.x = -1.0f;
                direcao.y = 0.0f;
            }
        }
        else
        {
            //COLISAO VERTICAL
            if(deltaY > 0.0f)
            {
                //COLISAOA BAIXO DO REFERENCIAL
                if(a->getID() != 6lu)
                {
                    a->InitialUpdate();
                    a->Move(0.0f, intersectY);
                    a->UpdatePosition();
                }

                if(b->getID() != 6lu)
                {
                    b->InitialUpdate();
                    b->Move(0.0f, -intersectY);
                    b->UpdatePosition();
                }

                direcao.x = 0.0f;
                direcao.y = 1.0f;
            }
            else
            {
                //COLISAOA CIMA DO REFERENCIAL

                if(a->getID() != 6lu)
                {
                    a->InitialUpdate();
                    a->Move(0.0f, -intersectY);
                    a->UpdatePosition();
                }

                if(b->getID() != 6lu)
                {
                    b->InitialUpdate();
                    b->Move(0.0f, intersectY);
                    b->UpdatePosition();
                }

                direcao.x = 0.0f;
                direcao.y = -1.0f;
            }
        }
        a->IncrementarDirecao(direcao);
        b->IncrementarDirecao(direcao * -1);

    }
    return(false);
}

void Listas::ListaObstaculo::ChecarColisoesEntreObstaculo()
{
    unsigned long int i;
    unsigned long int j;

    for(i = 0lu; i < lista.get_Tamanho(); i++)
    {
        lista.get_Info(i)->setDirecao(0.0f, 0.0f);
    }

    for(i = 0lu; i < (lista.get_Tamanho() - 1lu); i++)
    {
        for(j = i + 1lu; j < lista.get_Tamanho(); j++)
        {
            ChecarColisoesEntreObstaculo(lista.get_Info(i), lista.get_Info(j));
        }
    }
}
