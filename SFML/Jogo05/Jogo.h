#ifndef INCLUDED_JOGO_H
#define INCLUDED_JOGO_H

#define TAMANHO_DO_JOGADOR_X 84.0f
#define TAMANHO_DO_JOGADOR_Y 120.0f

#include "Tela.h"

using namespace ent;
using namespace per;
using namespace jog;
using namespace ini;
using namespace obs;
using namespace tela;
using namespace fase;
using namespace Listas;
using namespace Gerenciador;

class Jogo
{
private:

    Gerenciador_Grafico* g;
    Tela* t;

public:

    Jogo();  //....................................................TO REVIEW
    ~Jogo(); //....................................................TO REVIEW

    void Executar ();//............................................TO REVIEW

};

#endif // INCLUDED_JOGO_H
