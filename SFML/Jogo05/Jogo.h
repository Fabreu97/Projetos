#ifndef INCLUDED_JOGO_H
#define INCLUDED_JOGO_H

#define TAMANHO_DO_JOGADOR_X 84.0f
#define TAMANHO_DO_JOGADOR_Y 120.0f

#include "Fase.h"

using namespace ent;
using namespace per;
using namespace jog;
using namespace ini;
using namespace obs;
using namespace fase;
using namespace Listas;
using namespace Gerenciador;

class Jogo
{
private:

    Jogador01* p1;
    Jogador02* p2;

    Fase* f;
    Gerenciador_Grafico* g;

public:

    Jogo();  //....................................................TO REVIEW
    ~Jogo(); //....................................................TO REVIEW

    void criarFase(const unsigned long int i = 0lu); //............TO REVIEW

    void setJogadoresFase();//.....................................TO REVIEW

    void Executar ();//............................................TO REVIEW

};

#endif // INCLUDED_JOGO_H
