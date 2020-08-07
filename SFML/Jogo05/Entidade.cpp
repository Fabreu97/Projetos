#include "Entidade.h"

///IMPLEMENTACOES DA CLASS ENTIDADE

Gerenciador_Grafico* ent::Entidade::control = NULL;

ent::Entidade::Entidade(const string c)
{
    id = 0;
    caminho = c;
}

ent::Entidade::~Entidade()
{

}

void ent::Entidade::setID(const unsigned long int ID)
{
    id = ID;
}

const unsigned long int ent::Entidade::getID() const
{
    return(id);
}

const string ent::Entidade::getTexture() const
{
    return(caminho);
}

void ent::Entidade::setSizeTexture(const Vector2D<float> v)
{
    tam_tex = v;
}

void ent::Entidade::setSizeTexture(const float x, const float y)
{
    tam_tex.x = x;
    tam_tex.y = y;
}

const Vector2D<float> ent::Entidade::getSizeTexture() const
{
    return(tam_tex);
}

void ent::Entidade::setPosition(const Vector2D<float> v)
{
    pos = v;
}

void ent::Entidade::setPosition(const float x, const float y)
{
    pos.x = x;
    pos.y = y;
}

const Vector2D<float> ent::Entidade::getPosition() const
{
    return(pos);
}

void ent::Entidade::setGerenciadorGrafico(Gerenciador_Grafico* pg)
{
    control = pg;
}

Gerenciador_Grafico* ent::Entidade::getGerenciadorGrafico()
{
    return(control);
}

///IMPLEMENTAÇÕES DA CLASS ENTIDADE COLIDIVEL

ent::EntidadeColidivel::EntidadeColidivel(const string c):
    Entidade(c),
    colidiu(false),
    direcao(0.0f, 0.0f),
    tam(tam_tex)
{
}

ent::EntidadeColidivel::~EntidadeColidivel()
{

}

void ent::EntidadeColidivel::setColisao(const bool c)
{
    colidiu = c;
}

const bool ent::EntidadeColidivel::getColisao() const
{
    return(colidiu);
}

void ent::EntidadeColidivel::setDirecao(const Vector2D<float> v)
{
    if(direcao.x == 0.0f)
    {
        direcao.x = v.x;
    }
    if(direcao.y == 0.0f)
    {
        direcao.y = v.y;
    }
}

void ent::EntidadeColidivel::setDirecao(const float x, const float y)
{
    direcao.x = x;
    direcao.y = y;
}

const Vector2D<float> ent::EntidadeColidivel::getDirecao() const
{
    return(direcao);
}

void ent::EntidadeColidivel::IncrementarDirecao(Vector2D<float> v)
{
    if(direcao.x == 0.0f)
    {
        direcao.x = v.x;
    }
    if(direcao.y == 0.0f)
    {
        direcao.y = v.y;
    }
}

void ent::EntidadeColidivel::setSize(const Vector2D<float> v)
{
    tam = v;
}

void ent::EntidadeColidivel::setSize(const float x, const float y)
{
    tam.x = x;
    tam.y = y;
}

Vector2D<float> ent::EntidadeColidivel::getSize() const
{
    return(tam);
}

const Vector2D<float> ent::EntidadeColidivel::getHalfSize() const
{
    return(tam * 0.5f);
}

///IMPLEMENTACOES DA CLASS PERSONAGEM

ent::per::Personagem::Personagem(const bool pp, const float change_time, const string c):
    EntidadeColidivel(c),
    life(true),
    dano(false),
    change_animation(false),
    flag_change_face(false),
    velocidade(0.0f, 0.0f),
    cont_imagem(0,0),
    imagem_atual(0,0),
    face_certa(true),
    pode_pular(pp),
    lestatico(0),
    landando(0),
    lsalto(0),
    lataque(0),
    ldano(0),
    tempo_ciclo(change_time),
    galho(0.0f)
    {
        tempo_total = 0.0f;
    }

ent::per::Personagem::~Personagem()
{

}

void ent::per::Personagem::Dead(const bool l)
{
    life = l;
}

const bool ent::per::Personagem::getLife() const
{
    return(life);
}

void ent::per::Personagem::setDano(const bool d)
{
    dano = d;
}

const bool ent::per::Personagem::getDano() const
{
    return(dano);
}

const bool ent::per::Personagem::getFace() const
{
    return(face_certa);
}

void ent::per::Personagem::setVelocidade(const Vector2D<float> v)
{
    velocidade = v;
}

void ent::per::Personagem::setVelocidade(const float x, const float y)
{
    velocidade.x = x;
    velocidade.y = y;
}

const Vector2D<float> ent::per::Personagem::getVelocidade() const
{
    return(velocidade);
}

void ent::per::Personagem::incrementarVelocidade(const Vector2D<float>& vel)
{
    velocidade = velocidade + vel;
}

void ent::per::Personagem::incrementarVelocidade(const float& x, const float& y)
{
    velocidade.x += x;
    velocidade.y += y;
}

void ent::per::Personagem::setCurrentImage(const Vector2D<unsigned long int> v)
{
    imagem_atual = v;
}

void ent::per::Personagem::setCurrentImage(const unsigned long int x, const unsigned long int y)
{
    imagem_atual.x = x;
    imagem_atual.y = y;
}

void ent::per::Personagem::setContImage(const Vector2D<unsigned long int> v)
{
    cont_imagem = v;
}

void ent::per::Personagem::setContImage(const unsigned long int x, const unsigned long int y)
{
    cont_imagem.x = x;
    cont_imagem.y = y;
}

void ent::per::Personagem::PreencherLinhas(const unsigned long int estatico, const unsigned long int andando, const unsigned long int salto, const unsigned long int ataque, const unsigned long int dano)
{
    lestatico = estatico;
    landando = andando;
    lsalto = salto;
    lataque = ataque;
    ldano = dano;
}

void ent::per::Personagem::setTempoCiclo(const float t)
{
    tempo_ciclo = t;
}

const float ent::per::Personagem::getTempoCiclo() const
{
    return(tempo_ciclo);
}

void ent::per::Personagem::Update()
{
    InitialUpdate();
    UpdateAnimacao();
    UpdateGerenciador();
}


///IMPLEMENTACOES DA CLASSE BARRA_DE_VIDA

ent::per::Barra_de_Vida::Barra_de_Vida(const unsigned long int life):
    ent::per::Personagem(),
    vidas(life),
    invulnerabilidade(true),
    damage(0lu),
    time_in(0.0f),
    tempo_invulnerabilidade(TEMPO_INVUNERABILIDADE)
{
    imagem_atual = Vector2D<unsigned long int>(0,0);
    tam_tex = Vector2D<float>(64.0f, 64.0f);
    tam = Vector2D<float>(64.0f, 64.0f);
    caminho = "Texture/CCC.png";
}

ent::per::Barra_de_Vida::~Barra_de_Vida()
{

}

void ent::per::Barra_de_Vida::setTexture(const string t)
{
    caminho = t;
    control->setTextureLife01(t);
}

const long int ent::per::Barra_de_Vida::getVida() const
{
    return(vidas);
}

void ent::per::Barra_de_Vida::Damage(const unsigned long int attack_force)
{
    if(!invulnerabilidade)
    {
        damage = attack_force;
    }
}

void ent::per::Barra_de_Vida::InitialUpdate ()
{
    control->setSizeLife01(tam_tex);
    control->setPositionLife01();

    width_height.y = control->getTextureSizeLife01().y / cont_imagem.y;
    width_height.x = control->getTextureSizeLife01().x / cont_imagem.x;
    left_top.x = 0.0f;
    left_top.y = 0.0f;
}

void ent::per::Barra_de_Vida::UpdateAnimacao()
{
    time_in += control->get_Delta_Time();
    if(damage > 0)
    {
        if(!invulnerabilidade)
        {
            vidas--;
            damage--;
            imagem_atual.x++;

            time_in = 0.0f;
            invulnerabilidade = true;
        }
    }
    if(imagem_atual.x != 0)
    {
        if(tempo_total > tempo_ciclo)
        {
            tempo_total -= tempo_ciclo;
            imagem_atual.x++;
        }
        tempo_total += control->get_Delta_Time();
    }
    if(imagem_atual.x == cont_imagem.x)
    {
        imagem_atual.x = 0;
        imagem_atual.y++;
        if(imagem_atual.y == cont_imagem.y)
        {
            imagem_atual.y--;
            imagem_atual.x = 5;
        }
    }

    left_top.x = width_height.x * imagem_atual.x;
    left_top.y = width_height.y * imagem_atual.y;
}

void ent::per::Barra_de_Vida::UpdateGerenciador ()
{
    control->setIntRectLife01(width_height.x, width_height.y, left_top.x, left_top.y);
    control->setTextureRectLife01();
    control->setPositionLife01();
}
void ent::per::Barra_de_Vida::Update ()
{
    if(time_in > tempo_ciclo * cont_imagem.x)
    {
        invulnerabilidade = false;
    }

    UpdateAnimacao();
    UpdateGerenciador();

}
void ent::per::Barra_de_Vida::Draw ()
{
    control->DrawLife01();
}

void ent::per::Barra_de_Vida::Move(const Vector2D<float> v)
{
    control->moveLife01(v);
}

void ent::per::Barra_de_Vida::Move(const float x, const float y)
{
    control->moveLife01(x,y);
}

///IMPLEMENTACOES DA CLASSE PROJETIL

ent::per::Projetil::Projetil(const long int dano, const bool fc, const float lifetime, const float time_between_shots):
    Personagem(true, 0.01f, "Texture/fire.png"),
    damage(dano),
    tempo_vida(lifetime),
    tempo_entre_disparo(time_between_shots)
{
    face_certa = fc;
    timev = 0.0f;
}

ent::per::Projetil::~Projetil()
{

}

const long int ent::per::Projetil::attackForce() const
{
    return(damage);
}

void ent::per::Projetil::setTexture(const string t)
{
    caminho = t;
    control->setTextureProjetil(caminho);
}

void ent::per::Projetil::InitialUpdate ()
{
    control->setSizeProjetil(tam_tex);
    control->setPositionProjetil(pos);

    width_height.x = control->getTextureSizeProjetil().x / cont_imagem.x;
    width_height.y = control->getTextureSizeProjetil().y / cont_imagem.y;
    left_top.x = 0.0f;
    left_top.y = 0.0f;
}

void ent::per::Projetil::UpdatePosition()
{
    pos = control->getPositionProjetil();
}

void ent::per::Projetil::UpdateAnimacao()
{
    timev += control->get_Delta_Time();
    if(tempo_vida < timev)
    {
        colidiu = true;
    }
    if(colidiu)
    {
        tempo_total += control->get_Delta_Time();

        if(tempo_total > tempo_ciclo)
        {
            imagem_atual.x++;
            tempo_total -= tempo_ciclo;
        }

        if(imagem_atual.x == cont_imagem.x)
        {
            life = false;
        }
    }

    if(velocidade.x > 0.0f)
    {
        left_top.x = imagem_atual.x * abs(width_height.x);
    }
    else
    {
        left_top.x = (imagem_atual.x + 1) * abs(width_height.x);
        width_height.x = -abs(width_height.x);
    }

    control->setIntRectProjetil(width_height.x, width_height.y, left_top.x, left_top.y);
    control->setTextureRectProjetil();
}

void ent::per::Projetil::UpdateGerenciador ()
{
    control->setPositionProjetil(pos);
}

void ent::per::Projetil::Update ()
{
    UpdateAnimacao();
    UpdateGerenciador();
    if(!colidiu)
    {
        Move(velocidade * control->get_Delta_Time());
        pos = control->getPositionProjetil();
    }
}

void ent::per::Projetil::Draw ()
{
    if(life)
    {
        control->DrawProjetil();
    }
}

void ent::per::Projetil::Move(const Vector2D<float> v)
{
    control->moveProjetil(v);
}

void ent::per::Projetil::Move(const float x, const float y)
{
    control->moveProjetil(x,y);
}

inline bool ent::per::Projetil::operator ==(const ent::per::Projetil& p) const
{
    if(pos.x == p.getPosition().x)
    {
        if(pos.y == p.getPosition().y)
        {
            return(true);
        }
    }

    return (false);
}

inline void ent::per::Projetil::operator=(const ent::per::Projetil& p)
{
    this->pos = p.getPosition();
    this->tam_tex = p.getSizeTexture();
    this->caminho = p.getTexture();
}

///IMPLEMENTACOES DA CLASSE JOGADOR

ent::per::jog::Jogador::Jogador(const float height_jumper, const float aceleracao, const bool pp, const float change_time, const string c):
    Personagem(pp, change_time, c),
    speed(aceleracao),
    altura_salto(height_jumper)
{
    tempo_entre_disparo = 0.4f;
    time_projetil = 0.0f;
    cont_projetil = 5lu;
}

ent::per::jog::Jogador::~Jogador()
{

}

void ent::per::jog::Jogador::setTempoCicloLife(const float a)
{
    vida.setTempoCiclo(a);
}

void ent::per::jog::Jogador::setTextureLife(const string t)
{
    vida.setTexture(t);
}

void ent::per::jog::Jogador::setSizeLife(const Vector2D<float> s)
{
    vida.setSizeTexture(s);
    vida.setSize(s);
}

void ent::per::jog::Jogador::setSizeLife(const float x, const float y)
{
    vida.setSizeTexture(x,y);
}

void ent::per::jog::Jogador::setContImageLife(const Vector2D<unsigned long int> v)
{
    vida.setContImage(v);
}

void ent::per::jog::Jogador::setContImageLife(const unsigned long int x, const unsigned long int y)
{
    vida.setContImage(x,y);
}

void ent::per::jog::Jogador::setCurrentImageLife(const Vector2D<unsigned long int> v)
{
    vida.setCurrentImage(v);
}

void ent::per::jog::Jogador::setCurrentImageLife(const unsigned long int x, const unsigned long int y)
{
    vida.setCurrentImage(x,y);
}

void ent::per::jog::Jogador::Damage(const unsigned long int attack_force)
{
    vida.Damage(attack_force);
}

const unsigned long int ent::per::jog::Jogador::getVida() const
{
    return(vida.getVida());
}

void ent::per::jog::Jogador::setSpeed(const float aceleracao)
{
    speed = aceleracao;
}

const float ent::per::jog::Jogador::getSpeed() const
{
    return(speed);
}

void ent::per::jog::Jogador::setAlturaSalto(const float& a)
{
    altura_salto = a;
}

const float ent::per::jog::Jogador::getAlturaSalto() const
{
    return(altura_salto);
}

ent::per::Projetil* ent::per::jog::Jogador::getProjetil(const unsigned long int indice) const
{
    return(FilaProjetil.get_Info(indice));
}

const unsigned long int ent::per::jog::Jogador::getSizeListaProjetil() const
{
    return(FilaProjetil.get_Tamanho());
}

///IMPLEMENTACOES DA CLASSE JOGADOR01

ent::per::jog::Jogador01::Jogador01(const float height_jumper, const float aceleracao, const bool pp, const float change_time, const string c):
    Jogador(height_jumper, aceleracao,pp,change_time,c),
    animacao_disparo(false),
    col_estatico(3lu),
    col_andando(9lu),
    col_ataque(5lu)
    {
        id = IDJOG01;
        this->setSize(TAMANHO_COLIDIVEL_JOGADOR01_X, TAMANHO_COLIDIVEL_JOGADOR01_Y);
        this->setSizeTexture(TAMANHO_DA_TEXTURA_JOGADOR01_X, TAMANHO_DA_TEXTURA_JOGADOR01_Y);
        this->setPosition(400.f, 800.0f);
        this->setContImage(9lu,3lu);
        this->PreencherLinhas(0lu,1lu, 0lu, 2lu);
        this->setSpeed(SPEED_JOGADOR01);
        this->setTempoCiclo(CHANGE_TIME_ANIMATION_PLAYER01);
        this->setTexture("Texture/Marco.png");

        this->setTextureLife("Texture/CCC.png");
        this->setSizeLife(96.0f, 32.0f);
        this->setContImageLife(6lu,6lu);
        this->setCurrentImageLife(0lu,0lu);
        this->setTempoCicloLife(0.15f);
        this->InitialUpdate();
        galho = (7.0f/51.0f) * tam_tex.x;
        tam.x = tam_tex.x * (29.0f/51.0f);
    }
ent::per::jog::Jogador01::~Jogador01()
{
    while(FilaProjetil.get_Tamanho() != 0lu)
    {
        ent::per::Projetil* aux = FilaProjetil.get_Info(0);
        delete(aux);
        aux = NULL;
        FilaProjetil.eliminar_Info(0lu);
    }
}


void ent::per::jog::Jogador01::setTexture(const string t)
{
    caminho = t;
    control->setTexturePlayer01(t);
}

void ent::per::jog::Jogador01::InitialUpdate()
{
    control->setSizePlayer01(tam_tex);
    control->setPositionPlayer01(pos);
    vida.InitialUpdate();
    control->setTextureProjetil("Texture/fire.png");
}

void ent::per::jog::Jogador01::Update()
{
    UpdateMovement();
    UpdateAnimacao();
    UpdateGerenciador();
    vida.Update();
    dano = false;
    DispararProjetil();
}

void ent::per::jog::Jogador01::UpdateMovement()
{
    velocidade.x = 0.0f;

    if(control->isP_Left() && !animacao_disparo)
    {
        velocidade.x -= speed;
    }
    if(control->isP_Right() && !animacao_disparo)
    {
        velocidade.x += speed;
    }
    if(control->isPEnter() && pode_pular)
    {
        pode_pular = false;
        velocidade.y = -sqrt(2 * 981.0f * altura_salto);
    }
}

void ent::per::jog::Jogador01::UpdateAnimacao()
{
    //=========ESPAÇO PARA O MÉTODO ONCOLLISION=========
    if(direcao.y > 0.0f && velocidade.y > 0.0f)
    {
        velocidade.y = 0.0f;
        pode_pular = true;
    }
    else
    {
        velocidade.y += 981.0f * control->get_Delta_Time();
    }

    //TESTES LÓGICOS PARA MUDANÇA DE ANIMAÇÃO DO JOAGDOR 01
    bool flag1 = face_certa;
    const unsigned long int flag_type_animation = imagem_atual.y;

    if(velocidade.x != 0.0f)
    {
        imagem_atual.y = landando;
        if(velocidade.x > 0.0f)
        {
            face_certa = true;
        }
        else
        {
            face_certa = false;
        }
    }
    else
    {
        imagem_atual.y = lestatico;
    }

    //TESTE PARA AJEITAR QUNADO TROCA A LINHA DE ANIMAÇÃO OU A FACE DO JOGADOR01

    if(face_certa != flag1)
    {
        flag_change_face = true;
    }

    tempo_total += control->get_Delta_Time();

    //ANIMAÇÃO QUANDO NÃO ESTA DISPARANDO O PROJETIL

    if(!animacao_disparo)
    {
        if(tempo_total > tempo_ciclo)
        {
            tempo_total -= tempo_ciclo;
            switch(imagem_atual.y)
            {
            case 1lu:
                {
                    imagem_atual.x = (imagem_atual.x + 1) % col_andando;
                    break;
                }
            case 0lu:
                {
                    imagem_atual.x = (imagem_atual.x + 1) % col_estatico;
                    break;
                }
            default:
                {
                    break;
                }
            }
        }
        if(flag_type_animation != imagem_atual.y)
        {
            imagem_atual.x = 0lu;
        }
    }

    //ANIMACAO DE DISPARO DE PROJETIL
    if(animacao_disparo)
    {
        imagem_atual.y = lataque;
        if(time_projetil == 0.0f)
        {
            imagem_atual.x = 0lu;
            change_animation = true;
        }
        float t = (tempo_entre_disparo / col_ataque) * (imagem_atual.x + 1);
        if(time_projetil > t)
        {
            imagem_atual.x = (imagem_atual.x + 1) % col_ataque;
            change_animation = false;
        }
        if(imagem_atual.x == 0lu && !change_animation)
        {
            animacao_disparo = false;
        }
    }

    time_projetil += control->get_Delta_Time();

    //AJEITANDO CONFIGURAÇÕES DA ANIMAÇÃO COMO ENTRADA PARA O GERENCIADOR GRÁFICO
    width_height.y = control->getTextureSizePlayer01().y / cont_imagem.y;
    width_height.x = control->getTextureSizePlayer01().x / cont_imagem.x;

    left_top.y = width_height.y * imagem_atual.y;

    if(face_certa)
    {
        left_top.x = width_height.x * imagem_atual.x;
    }
    else
    {
        width_height.x = -abs(width_height.x);
        left_top.x = (imagem_atual.x + 1) * abs(width_height.x);
    }

    Move(velocidade * control->get_Delta_Time());
}

void ent::per::jog::Jogador01::UpdateGerenciador()
{
    control->setIntRectPlayer01(width_height.x, width_height.y, left_top.x, left_top.y);
    control->setTextureRectPlayer01();
    control->movePlayer01(velocidade * control->get_Delta_Time());
    pos = control->getPositionPlayer01();
    if(flag_change_face)
    {
        flag_change_face = false;
        if(face_certa)
        {
            pos.x += (2 * galho);
        }
        else
        {
            pos.x -= (2 * galho);
        }
        control->setPositionPlayer01(pos);
    }
}

void ent::per::jog::Jogador01::Draw()
{
    DrawProjetil();
    control->DrawPlayer01();
    vida.Draw();
}

void ent::per::jog::Jogador01::OnCollision()
{
    if(direcao.x < 0.0f)
    {
        pode_pular = true;
        velocidade.x = 0.0f;
    }
    else if(direcao.x > 0.0f)
    {
        pode_pular = true;
        velocidade.x = 0.0f;
    }
    if(direcao.y < 0.0f)
    {
        velocidade.y = 0.0f;
    }
    else if(direcao.y > 0.0f)
    {
        pode_pular = true;
        velocidade.y = 0.0f;
    }
}

void ent::per::jog::Jogador01::Move(const Vector2D<float> v)
{
    control->movePlayer01(v);
}

void ent::per::jog::Jogador01::Move(const float x, const float y)
{
    control->movePlayer01(x,y);
}

void ent::per::jog::Jogador01::DispararProjetil()
{
    if(control->isP_ALT())
    {
        if( (FilaProjetil.get_Tamanho() < cont_projetil) && (tempo_entre_disparo < time_projetil) && !animacao_disparo)
        {
            animacao_disparo = true;
            ent::per::Projetil* aux = new ent::per::Projetil();
            aux->setSizeTexture(20.0f, 20.0f);
            aux->setSize(20.0f, 20.0f);
            if(face_certa)
            {
                aux->setPosition(pos.x + ( tam_tex.x * (14.5f/51.0f) ), pos.y - ( tam_tex.y * (7.5f/ 51.0f) ) );
                aux->setVelocidade(VELOCIDADE_PROJETIL , 0.0f);
                //Move(-20.0f, 0.0f);
            }
            else
            {
                aux->setPosition(pos.x - ( tam_tex.x * (14.5f/51.0f) ), pos.y - ( tam_tex.y * (7.5f/ 51.0f) ) );
                aux->setVelocidade(-VELOCIDADE_PROJETIL , 0.0f);
                //Move(+20.0f, 0.0f);
            }
            aux->setContImage(7,1);
            aux->setTempoCiclo(TEMPO_CICLO_PROJETIL);
            aux->InitialUpdate();
            FilaProjetil.inserir(aux);
            time_projetil = 0.0f;
        }
    }
}

void ent::per::jog::Jogador01::DrawProjetil()
{
    unsigned long int i;

    for(i = 0lu; i < FilaProjetil.get_Tamanho(); i++)
    {
        ent::per::Projetil* aux = FilaProjetil.get_Info(i);

        if( aux->getLife() )
        {
            aux->Update();
            aux->Draw();
        }
        else
        {
            delete(aux);
            aux = NULL;
            FilaProjetil.eliminar_Info(i);
            i = 0;
        }
    }
}

///IMPLEMENTACOES DA CLASSE JOGADOR02

ent::per::jog::Jogador02::Jogador02(const float height_jumper, const float aceleracao, const bool pp, const float change_time, const string c):
    Jogador(height_jumper, aceleracao,pp,change_time,c)
    {
        id = IDJOG02;
        this->setSizeTexture(TAMANHO_DA_TEXTURA_JOGADOR_X, TAMANHO_DA_TEXTURA_JOGADOR_Y);
        this->setPosition(700.f, 800.0f);
        this->setContImage(3,9);
        this->PreencherLinhas(0,1);
        this->setSpeed(SPEED_JOGADOR);
        this->setTempoCiclo(0.2);
        this->setTexture("Texture/tux_from_linux.png");
        this->InitialUpdate();
    }
ent::per::jog::Jogador02::~Jogador02()
{

}


void ent::per::jog::Jogador02::setTexture(const string t)
{
    caminho = t;
    control->setTexturePlayer02(t);
}

void ent::per::jog::Jogador02::InitialUpdate()
{
    control->setSizePlayer02(tam_tex);
    control->setPositionPlayer02(pos);

}

void ent::per::jog::Jogador02::Update()
{
    this->UpdateMovement();
    this->UpdateAnimacao();
    this->UpdateGerenciador();
}

void ent::per::jog::Jogador02::UpdateMovement()
{
    velocidade.x *= 0.0f;

    if(control->isPA())
    {
        velocidade.x -= speed;
    }
    if(control->isPD())
    {
        velocidade.x += speed;
    }
    if(control->isP_Space() && pode_pular)
    {
        pode_pular = false;
        velocidade.y = -sqrt(2 * 981.0f * altura_salto);
    }
}

void ent::per::jog::Jogador02::UpdateAnimacao()
{
    if(direcao.y > 0.0f && velocidade.y > 0.0f)
    {
        velocidade.y = 0.0f;
        pode_pular = true;
    }
    else
    {
        velocidade.y += 981.0f * control->get_Delta_Time();
    }


    if(velocidade.x != 0.0f)
    {
        imagem_atual.y = landando;
        if(velocidade.x > 0.0f)
        {
            face_certa = true;
        }
        else
        {
            face_certa = false;
        }
    }
    else
    {
        imagem_atual.y = lestatico;
    }


    tempo_total += control->get_Delta_Time();

    if(tempo_total > tempo_ciclo)
    {
        tempo_total -= tempo_ciclo;
        imagem_atual.x = (imagem_atual.x + 1) % cont_imagem.x;
    }

    width_height.y = control->getTextureSizePlayer02().y / cont_imagem.y;
    width_height.x = control->getTextureSizePlayer02().x / cont_imagem.x;

    left_top.y = width_height.y * imagem_atual.y;

    if(face_certa)
    {
        left_top.x = width_height.x * imagem_atual.x;
    }
    else
    {
        width_height.x = -abs(width_height.x);
        left_top.x = (imagem_atual.x + 1) * abs(width_height.x);
    }

    Move(velocidade * control->get_Delta_Time());
}

void ent::per::jog::Jogador02::UpdateGerenciador()
{
    control->setIntRectPlayer02(width_height.x, width_height.y, left_top.x, left_top.y);
    control->setTextureRectPlayer02();
    control->movePlayer02(velocidade * control->get_Delta_Time());
    pos = control->getPositionPlayer02();
}

void ent::per::jog::Jogador02::Draw()
{
    control->DrawPlayer02();
}

void ent::per::jog::Jogador02::Move(const Vector2D<float> v)
{
    control->movePlayer02(v);
}

void ent::per::jog::Jogador02::Move(const float x, const float y)
{
    control->movePlayer02(x,y);
}

void ent::per::jog::Jogador02::OnCollision()
{
    if(direcao.x < 0.0f)
    {
        pode_pular = true;
        velocidade.x = 0.0f;
    }
    else if(direcao.x > 0.0f)
    {
        pode_pular = true;
        velocidade.x = 0.0f;
    }
    if(direcao.y < 0.0f)
    {
        velocidade.y = 0.0f;
    }
    else if(direcao.y > 0.0f)
    {
        pode_pular = true;
        velocidade.y = 0.0f;
    }
}

///IMPLEMENTACOES DA CLASSE INIMIGO

ent::per::ini::Inimigo::Inimigo(const bool pp, const float change_time, const string c):
    Personagem(pp,change_time,c),
    vidas(ENEMY_LIVES)
    {
        id = 0;
        acumulador_dist = 0.0f;
        dist_perc = 2.5f;
    }

ent::per::ini::Inimigo::~Inimigo()
{

}

void ent::per::ini::Inimigo::Damage(long int attack_force)
{
    vidas -= attack_force;
}

///IMPLEMENTACOES DA CLASSE INIMIGO01

ent::per::ini::Inimigo01::Inimigo01(const bool pp, const float change_time, const string c):
    Inimigo(pp,change_time,c)
    {
        id = IDINI01;
        velocidade.x = VELINI01;
    }

ent::per::ini::Inimigo01::~Inimigo01()
{

}

void ent::per::ini::Inimigo01::setTexture(const string t)
{
    caminho = t;
    control->setTextureInimigo01(t);
}

void ent::per::ini::Inimigo01::Update()
{
    if(vidas <= 0l)
    {
        life = false;
    }
    control->setPositionInimigo01(pos);
    UpdateMovement();
    UpdateAnimacao();
    UpdateGerenciador();
}

void ent::per::ini::Inimigo01::InitialUpdate()
{
    control->setSizeInimigo01(tam_tex);
    control->setPositionInimigo01(pos);
}

void ent::per::ini::Inimigo01::UpdateMovement()
{
    acumulador_dist += control->get_Delta_Time();
    if(acumulador_dist > dist_perc)
    {
        acumulador_dist -= dist_perc;
        velocidade.x = velocidade.x * (-1.0f);
    }

    if(direcao.x != 0.0f)
    {
        velocidade.x *= -1;
    }

    if(direcao.y > 0.0f)
    {
        velocidade.y = 0.0f;
    }
    else
    {
        velocidade.y += 981.0f * control->get_Delta_Time();
    }
}

void ent::per::ini::Inimigo01::UpdateAnimacao()
{
    if(velocidade.x != 0.0f)
    {
        imagem_atual.y = landando;
        if(velocidade.x > 0.0f)
        {
            face_certa = true;
        }
        else
        {
            face_certa = false;
        }
    }
    else
    {
        imagem_atual.y = lestatico;
    }

    tempo_total += control->get_Delta_Time();

    if(tempo_total > tempo_ciclo)
    {
        tempo_total -= tempo_ciclo;
        imagem_atual.x = (imagem_atual.x + 1) % cont_imagem.x;
    }

    width_height.y = control->getTextureSizeInimigo01().y / cont_imagem.y;
    width_height.x = control->getTextureSizeInimigo01().x / cont_imagem.x;

    left_top.y = width_height.y * imagem_atual.y;

    if(face_certa)
    {
        left_top.x = width_height.x * imagem_atual.x;
    }
    else
    {
        width_height.x = -abs(width_height.x);
        left_top.x = (imagem_atual.x + 1) * abs(width_height.x);
    }

    Move(velocidade * control->get_Delta_Time());
    control->setIntRectInimigo01(width_height.x, width_height.y, left_top.x, left_top.y);
    control->setTextureRectInimigo01();
}

void ent::per::ini::Inimigo01::UpdateGerenciador() //TO DO
{
    control->setIntRectInimigo01(width_height.x, width_height.y, left_top.x, left_top.y);
    control->setTextureRectInimigo01();
    pos = control->getPositionInimigo01();
}

void ent::per::ini::Inimigo01::UpdatePosition()
{
    pos = control->getPositionInimigo01();
}

void ent::per::ini::Inimigo01::Draw()
{
    control->DrawInimigo01();
}

void ent::per::ini::Inimigo01::Move(const Vector2D<float> v)
{
    control->moveInimigo01(v);
}

void ent::per::ini::Inimigo01::Move(const float x, const float y)
{
    control->moveInimigo01(x,y);
}

///IMPLEMENTACOES DA CLASSE INIMIGO02

ent::per::ini::Inimigo02::Inimigo02(const bool pp, const float change_time, const string c):
    Inimigo(pp,change_time,c)
    {
        id = IDINI02;
    }

ent::per::ini::Inimigo02::~Inimigo02()
{

}

void ent::per::ini::Inimigo02::setTexture(const string t)
{
    caminho = t;
    control->setTextureInimigo02(t);
}

void ent::per::ini::Inimigo02::Update()
{

}

void ent::per::ini::Inimigo02::InitialUpdate()
{

}

void ent::per::ini::Inimigo02::UpdateAnimacao()
{

}

void ent::per::ini::Inimigo02::UpdateGerenciador()
{

}

void ent::per::ini::Inimigo02::UpdatePosition()
{
    pos = control->getPositionInimigo02();
}

void ent::per::ini::Inimigo02::Draw()
{
    control->DrawInimigo02();
}

void ent::per::ini::Inimigo02::Move(const Vector2D<float> v)
{
    control->moveInimigo02(v);
}

void ent::per::ini::Inimigo02::Move(const float x, const float y)
{
    control->moveInimigo02(x,y);
}


///IMPLEMENTACOES DA CLASSE INIMIGO03

ent::per::ini::Inimigo03::Inimigo03(const bool pp, const float change_time, const string c):
    Inimigo(pp,change_time,c)
    {
        id = IDINI03;
    }

ent::per::ini::Inimigo03::~Inimigo03()
{

}

void ent::per::ini::Inimigo03::setTexture(const string t)
{
    caminho = t;
    control->setTextureInimigo03(t);
}

void ent::per::ini::Inimigo03::Update()
{

}

void ent::per::ini::Inimigo03::InitialUpdate()
{
    control->setSizeInimigo03(tam_tex);
    control->setPositionInimigo03(pos);
}

void ent::per::ini::Inimigo03::UpdateAnimacao()
{

}

void ent::per::ini::Inimigo03::UpdateGerenciador()
{

}

void ent::per::ini::Inimigo03::UpdatePosition()
{
    pos = control->getPositionInimigo03();
}

void ent::per::ini::Inimigo03::Draw()
{
    control->DrawInimigo03();
}

void ent::per::ini::Inimigo03::Move(const Vector2D<float> v)
{
    control->moveInimigo03(v);
}

void ent::per::ini::Inimigo03::Move(const float x, const float y)
{
    control->moveInimigo03(x,y);
}

///IMPLEMENTACOES DA CLASSE OBSTACULO

ent::obs::Obstaculo::Obstaculo( const Vector2D<float> position, const Vector2D<float> tamanho, const string c):
    EntidadeColidivel(c),
    push_jogador(PUSH_PLATAFORMA)
    {
        id = IDOBS00;
        tam_tex = tamanho;
        tam = tamanho;
        pos = position;
    }
ent::obs::Obstaculo::~Obstaculo()
{

}

void ent::obs::Obstaculo::setVelocidade(const Vector2D<float> v)
{
    velocidade = v;
}

void ent::obs::Obstaculo::setVelocidade(const float x, const float y)
{
    velocidade.x = x;
    velocidade.y = y;
}

const Vector2D<float> ent::obs::Obstaculo::getVelocidade() const
{
    return(velocidade);
}

void ent::obs::Obstaculo::setPush(const float p)
{
    push_jogador = p;
}

const float ent::obs::Obstaculo::getPush() const
{
    return(push_jogador);
}

void ent::obs::Obstaculo::setTempoCiclo(const float t)
{

}
const float ent::obs::Obstaculo::getTempoCiclo() const
{
    return(0.0);
}

void ent::obs::Obstaculo::setCurrentImage(const Vector2D<unsigned long int> v)
{

}
void ent::obs::Obstaculo::setCurrentImage(const unsigned long int x, const unsigned long int y)
{

}
const Vector2D<unsigned long int> ent::obs::Obstaculo::getCurrentImage() const
{
    return(Vector2D<unsigned long int>(0lu,0lu));
}

void ent::obs::Obstaculo::setContImage(const Vector2D<unsigned long int> v)
{

}
void ent::obs::Obstaculo::setContImage(const unsigned long int x, const unsigned long int y)
{

}
const Vector2D<unsigned long int> ent::obs::Obstaculo::getContImage() const
{
    return(Vector2D<unsigned long int>(0lu,0lu));
}

void ent::obs::Obstaculo::setTexture(const string t)
{
    caminho = t;
    control->setTexturePlataforma(caminho);
}

void ent::obs::Obstaculo::UpdatePosition()
{
    pos = control->getPositionPlataforma();
}

void ent::obs::Obstaculo::InitialUpdate()
{
    control->setSizePlataforma(tam_tex);
    control->setPositionPlataforma(pos);
    control->setTexturePlataforma(caminho);
}

void ent::obs::Obstaculo::UpdateGerenciador()
{

}

void ent::obs::Obstaculo::Update()
{
    control->setSizePlataforma(tam_tex);
    control->setPositionPlataforma(pos);
}

void ent::obs::Obstaculo::Draw()
{
    control->DrawPlataforma();
}

void ent::obs::Obstaculo::Move(const Vector2D<float> v)
{
    control->movePlataforma(v);
}

void ent::obs::Obstaculo::Move(const float x, const float y)
{
    control->movePlataforma(x,y);
}


///IMPLEMENTACOES DA CLASSE OBSTACULO01

ent::obs::Obstaculo01::Obstaculo01(const Vector2D<float> position, const Vector2D<float> tamanho, const string c):
    Obstaculo(position, tamanho, c)
{
    id = IDOBS01;
    push_jogador = PUSH_BAU;
    this->setSizeTexture(BAU_SIZE_X,BAU_SIZE_Y);
    this->setSize(BAU_SIZE_X,BAU_SIZE_Y);
    setTexture(c);
}

ent::obs::Obstaculo01::~Obstaculo01()
{

}

void ent::obs::Obstaculo01::setTexture(const string t)
{
    caminho = t;
    control->setTextureObstaculo01(caminho);
}

void ent::obs::Obstaculo01::UpdatePosition()
{
    pos = control->getPositionObstaculo01();
}

void ent::obs::Obstaculo01::InitialUpdate()
{
    control->setSizeObstaculo01(tam_tex);
    control->setPositionObstaculo01(pos);
}

void ent::obs::Obstaculo01::UpdateGerenciador()
{
    InitialUpdate();
    //control->setTextureObstaculo01(caminho);
}

void ent::obs::Obstaculo01::Update()
{
    velocidade.y += 981.0f * control->get_Delta_Time();
    UpdateGerenciador();
    if(direcao.y > 0.0f)
    {
        velocidade.y = 0.0f;
    }
    Move(velocidade * control->get_Delta_Time());
    UpdatePosition();

}

void ent::obs::Obstaculo01::Draw()
{
    control->DrawObstaculo01();
}

void ent::obs::Obstaculo01::Move(const Vector2D<float> v)
{
    control->moveObstaculo01(v);
}

void ent::obs::Obstaculo01::Move(const float x, const float y)
{
    control->moveObstaculo01(x,y);
}

///IMPLEMENTACOES DA CLASSE OBSTACULO02

ent::obs::Obstaculo02::Obstaculo02(const Vector2D<float> position, const Vector2D<float> tamanho, const string c):
    Obstaculo(position, tamanho, c)
{
    id = IDOBS02;
}

ent::obs::Obstaculo02::~Obstaculo02()
{

}

void ent::obs::Obstaculo02::setTexture(const string t)
{
    caminho = t;
    control->setTextureObstaculo02(t);
}

void ent::obs::Obstaculo02::UpdatePosition()
{
    pos = control->getPositionObstaculo02();
}

void ent::obs::Obstaculo02::InitialUpdate()
{

}

void ent::obs::Obstaculo02::UpdateGerenciador()
{

}

void ent::obs::Obstaculo02::Update()
{

}

void ent::obs::Obstaculo02::Draw()
{
    control->DrawObstaculo02();
}

void ent::obs::Obstaculo02::Move(const Vector2D<float> v)
{
    control->moveObstaculo02(v);
}

void ent::obs::Obstaculo02::Move(const float x, const float y)
{
    control->moveObstaculo02(x,y);
}

///IMPLEMENTACOES DA CLASSE OBSTACULO03

ent::obs::Obstaculo03::Obstaculo03(const Vector2D<float> position, const Vector2D<float> tamanho, const string c):
    Obstaculo(position, tamanho, c)
{
    id = IDOBS03;
}

ent::obs::Obstaculo03::~Obstaculo03()
{

}

void ent::obs::Obstaculo03::setTexture(const string t)
{
    caminho = t;
    control->setTextureObstaculo03(t);
}

void ent::obs::Obstaculo03::UpdatePosition()
{
    pos = control->getPositionObstaculo03();
}

void ent::obs::Obstaculo03::InitialUpdate()
{

}

void ent::obs::Obstaculo03::UpdateGerenciador()
{

}

void ent::obs::Obstaculo03::Update()
{

}

void ent::obs::Obstaculo03::Draw()
{
    control->DrawObstaculo03();
}

void ent::obs::Obstaculo03::Move(const Vector2D<float> v)
{
    control->moveObstaculo03(v);
}

void ent::obs::Obstaculo03::Move(const float x, const float y)
{
    control->moveObstaculo03(x,y);
}

///IMPLEMENTACOES DA CLASSE PLATAFORMA
