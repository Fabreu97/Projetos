#ifndef INCLUDED_LISTAS_H
#define INCLUDED_LISTAS_H

#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#include "Entidade.h" // contem Entidade

namespace Listas
{
    class ListaEntidade
    {
    private:

        //LISTA DE ENDEREÇOS DE ENTIDADE ALOCADAS DINAMICAMENTE
        list<ent::Entidade*> lista;

    public:

        ListaEntidade();
        ~ListaEntidade();

        const unsigned int getSize() const;

        void incluirEntidade(ent::Entidade* e);
        void limpar();
        void Draw();
        void Draw(const Vector2D<float>& p1);
        void Draw(const Vector2D<float>& p1, const Vector2D<float>& p2);
        void DrawPause(const Vector2D<float>& v);
        const bool eliminarInimigo(ent::per::ini::Enemy* i);
    };

    class VectorInimigo
    {
    private:

        vector<ent::per::ini::Enemy*> vetor;
        vector<ent::per::ini::Enemy*>::iterator it;

    public:

        VectorInimigo();
        ~VectorInimigo();

        const unsigned long int getSize() const;
        const bool incluirInimigo(ent::per::ini::Enemy* i);
        void eliminarInimigo(const unsigned long int indice);
        void limpar();
        ent::per::ini::Enemy* operator[](const unsigned long int i) const;
        void resetCollisions();
    };

    class ListaObstaculo
    {
    private:

        List<ent::obs::Obstacle> lista;

    public:

        ListaObstaculo();
        ~ListaObstaculo();

        const unsigned long int getSize() const;
        const bool incluirObstaculo(ent::obs::Obstacle* o); //..........REVIEW
        ent::obs::Obstacle* getObstaculo(const unsigned long int indice) const;
        void eliminarObstaculo(const unsigned long int i);//..............;;;;REVIEW E NÃO USAR
        void limpar();
        const bool ChecarColisoesEntreObstaculo(ent::obs::Obstacle* a, ent::obs::Obstacle* b);
        void ChecarColisoesEntreObstaculo();
        void resetCollisions();
    };
}

#endif // INCLUDED_LISTAS_H
