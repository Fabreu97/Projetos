#ifndef INCLUDED_ENTIDADE_H
#define INCLUDED_ENTIDADE_H

//AJUDA
#define TAM_N_LINUX 70.3125f
#define TAM_N_LINUY 90.0f

//Identidade das Entidades
#define IDJOG01 1lu
#define IDJOG02 2lu
#define IDINI01 3lu
#define IDINI02 4lu
#define IDINI03 5lu
#define IDOBS00 6lu
#define IDOBS01 7lu
#define IDOBS02 8lu
#define IDOBS03 9lu

//Jogador
#define HEIGHTJUMPER 125.0f
#define QTD_VIDAS_JOG 6lu
#define TAMANHO_DO_JOGADOR_X 84.0f
#define TAMANHO_DO_JOGADOR_Y 120.0f
#define SPEED_JOGADOR 300.0f
#define TEMPO_CICLO_PROJETIL 0.03f


//INIMIGO01
#define VELINI01 300.0f;
#define CAMINI01 "imagem/tux_from_linux.png"

//PROJETIL
#define VELOCIDADE_PROJETIL 800.0f
#define TEMPO_VIDA_PROJETIL_JOGADOR 3.0f

//BARRA DE VIDA
#define TEMPO_INVUNERABILIDADE 2.5f

//Jogador
#define PUSH_BAU 0.75f
#define PUSH_CAIXOTE 0.75f
#define PUSH_PLATAFORMA 1.0f
#define PUSH_INIMIGO 1.0f

//Obstaculo e Inimigo
#define PUSH_INIMIGO_OBST 0.5f
#define PUSH_INIMIGO_PLATAFORMA 1.0f

//OBSTACULO 01 - BAU
#define BAU_SIZE_X 64.0f
#define BAU_SIZE_Y 64.0f

#include "Gerenciador_Grafico.h"
#include <list>
#include "Lista.h"
#include <vector>

//CAMINHOS
#define BARRA_DE_VIDA "imagem/CCC.png"

using namespace Gerenciador;

namespace ent
{
    class Entidade
    {
    protected:

        unsigned long int id;
        bool colidiu; //FLAG pra colisao
        Vector2D<float> direcao;
        string caminho;
        Vector2D<float> tam;
        Vector2D<float> pos;

        static Gerenciador_Grafico* control;

    public:

        Entidade(const string c = "");
        virtual ~Entidade();

        void setID(const unsigned long ID);
        const unsigned long int getID() const;

        void setColisao(const bool c);
        const bool getColisao() const;

        void setDirecao(const Vector2D<float> v);
        void setDirecao(const float x, const float y);
        const Vector2D<float> getDirecao() const;
        void IncrementarDirecao(Vector2D<float> v);

        virtual void setTexture(const string t) = 0;
        const string getTexture() const;

        void setSize(const Vector2D<float> v);
        void setSize(const float x, const float y);
        const Vector2D<float> getSize() const;
        const Vector2D<float> getHalfSize() const;

        void setPosition(const Vector2D<float> v);
        void setPosition(const float x, const float y);
        const Vector2D<float> getPosition() const;

        static void setGerenciadorGrafico(Gerenciador_Grafico* pg);
        static Gerenciador_Grafico* getGerenciadorGrafico();

        virtual void InitialUpdate () = 0;
        virtual void UpdateGerenciador () = 0;
        virtual void Update () = 0;
        virtual void Draw () = 0;
    };

    namespace per
    {
        class Personagem:
            public Entidade
        {
        protected:
            bool life;
            bool dano;

            Vector2D<float> velocidade;
            Vector2D<unsigned long int> cont_imagem;
            Vector2D<unsigned long int> imagem_atual;
            Vector2D<float> width_height;
            Vector2D<float> left_top;

            bool face_certa;
            bool pode_pular;

            //Atributos pra Animação
            unsigned long int lestatico;
            unsigned long int landando;
            unsigned long int lsalto;
            unsigned long int lataque;
            unsigned long int ldano;

            float tempo_ciclo;
            float tempo_total;

        public:
            Personagem(const bool pp = true, const float change_time = 0.3f, const string c = "");
            virtual ~Personagem();

            void setLife(const bool l);
            const bool getLife() const;

            void setDano(const bool d);
            const bool getDano() const;

            void setVelocidade(const Vector2D<float> v);
            void setVelocidade(const float x, const float y);
            const Vector2D<float> getVelocidade() const;
            void incrementarVelocidade(const Vector2D<float>& vel);
            void incrementarVelocidade(const float& x, const float& y);

            void setCurrentImage(const Vector2D<unsigned long int> v);
            void setCurrentImage(const unsigned long int x, const unsigned long int y);

            void setContImage(const Vector2D<unsigned long int> v);
            void setContImage(const unsigned long int x, const unsigned long int y);

            void PreencherLinhas(const unsigned long int estatico = 0lu, const unsigned long int andando = 0lu, const unsigned long int salto = 0lu, const unsigned long int ataque = 0lu, const unsigned long int dano = 0lu);

            void setTempoCiclo(const float t);
            const float getTempoCiclo() const;

            virtual void UpdateAnimacao() = 0;
            virtual void Update();
            virtual void Move(const Vector2D<float> v) = 0;
            virtual void Move(const float x, const float y) = 0;
        };

        class Barra_de_Vida:
            public Personagem
        {
        private:

            unsigned long int vidas;
            float time_in;
            float tempo_invulnerabilidade;

        public:

            Barra_de_Vida (unsigned long int life = QTD_VIDAS_JOG);
            ~Barra_de_Vida ();

            void setTexture(const string t = "imagem/CCC.png");
            unsigned long int getVida() const;

            void InitialUpdate ();
            void UpdateAnimacao(const bool dano);
            void UpdateAnimacao();
            void UpdateGerenciador ();
            void Update (const bool dano);
            void Draw ();

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Projetil:
            public Personagem
        {
        private:

            float tempo_vida;
            float tempo_entre_disparo;
            float timev;
            float speed;

        public:

            Projetil(const bool fc = true, const float lifetime = TEMPO_VIDA_PROJETIL_JOGADOR, const float time_between_shots = 0.2f);
            ~Projetil();

            void setTexture(const string t);

            void InitialUpdate ();
            void UpdatePosition();
            void UpdateAnimacao();
            void UpdateGerenciador ();
            void Update ();
            void Draw ();

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);

            inline bool operator == (const ent::per::Projetil& p) const;
            inline void operator=(const ent::per::Projetil& p);
        };

        namespace jog
        {

            class Jogador:
                public Personagem
            {
            protected:

                Barra_de_Vida vida;
                Lista<Projetil> FilaProjetil;
                float tempo_entre_disparo;
                float time_projetil;
                unsigned long int cont_projetil;

                float speed; // aceleracao
                float altura_salto;

            public:

                Jogador(const float height_jumper = 1000.0f, const float aceleracao = 200.0f, const bool pp = false, const float change_time = 0.15f, const string c = "imagem/tux_from_linux.png");
                ~Jogador();

                void setTempoCicloLife(const float a);
                void setTextureLife(const string t = "imagem/CCC.png");
                void setSizeLife(Vector2D<float> s);
                void setSizeLife(const float x, const float y);
                void setContImageLife(const Vector2D<unsigned long int> v);
                void setContImageLife(const unsigned long int x, const unsigned long int y);
                void setCurrentImageLife(const Vector2D<unsigned long int> v);
                void setCurrentImageLife(const unsigned long int x, const unsigned long int y);

                void DecrementarVida(const bool dano);
                const unsigned long int getVida() const;

                void setSpeed(const float aceleracao);
                const float getSpeed() const;

                void setAlturaSalto(const float& a);
                const float getAlturaSalto() const;

                //MÉTODOS DA LISTA PROJETIL
                ent::per::Projetil* getProjetil(const unsigned long int indice) const;
                const unsigned long int getSizeListaProjetil() const;

            };

            class Jogador01:
                public Jogador
            {
            private:

            public:

                Jogador01(const float height_jumper = 500.0f, const float aceleracao = 200.0f, const bool pp = true, const float change_time = 0.15f, const string c = "imagem/tux_from_linux.png");
                ~Jogador01();

                void setTexture(const string t);

                //Update
                void Update(); //Posso Ocultar
                void InitialUpdate();
                void UpdateMovement();
                void UpdateAnimacao();
                void UpdateGerenciador();


                void Draw();
                void OnCollision(); //..............REVIEW

                void Move(const Vector2D<float> v);
                void Move(const float x, const float y);


                void DispararProjetil();
                void DrawProjetil();
            };

            class Jogador02:
                public Jogador
            {
            public:

                Jogador02(const float height_jumper = 500.0f, const float aceleracao = 200.0f, const bool pp = true, const float change_time = 0.15f, const string c = "imagem/tux_from_linux.png");
                ~Jogador02();

                void setTexture(const string t);

                //Update
                void Update(); //Posso Ocultar
                void InitialUpdate();
                void UpdateMovement();
                void UpdateAnimacao();
                void UpdateGerenciador();
                void Draw();
                void OnCollision();

                void Move(const Vector2D<float> v);
                void Move(const float x, const float y);
            };

        }

        namespace ini
        {
            class Inimigo:
                public Personagem
            {

            protected:

                float dist_perc;
                float acumulador_dist;

            public:

                Inimigo(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Inimigo();

                virtual void UpdatePosition() = 0;
            };

            class Inimigo01:
                public Inimigo
            {
            public:

                Inimigo01(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Inimigo01();

                void setTexture(const string t);

                //Update
                void Update();//.................. TO DO
                void InitialUpdate();//............TO DO
                void UpdateMovement();//...........TO DO
                void UpdateAnimacao();//...........TO DO
                void UpdateGerenciador();//........TO DO
                void UpdatePosition();

                void Draw();

                void Move(const Vector2D<float> v);
                void Move(const float x, const float y);
            };

            class Inimigo02:
                public Inimigo
            {

            public:

                Inimigo02(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Inimigo02();

                void setTexture(const string t);

                //Update
                void Update(); //Posso Ocultar // TO DO
                void InitialUpdate();          // TO DO
                void UpdateAnimacao();         // TO DO
                void UpdateGerenciador();      // TO DO
                void UpdatePosition();

                void Draw();
                void Move(const Vector2D<float> v);
                void Move(const float x, const float y);
            };

            class Inimigo03:
                public Inimigo
            {
            public:

                Inimigo03(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Inimigo03();

                void setTexture(const string t);

                //Update
                void Update(); //.................TO DO
                void InitialUpdate();//...........TO DO
                void UpdateAnimacao();//..........TO DO
                void UpdateGerenciador();//.......TO DO
                void UpdatePosition();

                void Draw();

                void Move(const Vector2D<float> v);
                void Move(const float x, const float y);
            };
        }
    }

    namespace obs
    {
        class Obstaculo:
            public Entidade
        {
        protected:

            Vector2D<float> velocidade;
            float push_jogador;

        public:
            Obstaculo(const string c = "imagem/MeioChaoGrande.png", const Vector2D<float> position = Vector2D<float>(700.0f, 772.0f), const Vector2D<float> tamanho = Vector2D<float>(2000.0, 400.0f));
            virtual ~Obstaculo();

            void setVelocidade(const Vector2D<float> v);
            void setVelocidade(const float x, const float y);
            const Vector2D<float> getVelocidade() const;

            void setPush(const float p);
            const float getPush() const;

            virtual void setMudaImagem(const bool b);
            virtual const bool getMudaImagem() const;

            virtual void setTempoCiclo(const float t);
            virtual const float getTempoCiclo() const;

            virtual void setCurrentImage(const Vector2D<unsigned long int> v);
            virtual void setCurrentImage(const unsigned long int x, const unsigned long int y);
            virtual const Vector2D<unsigned long int> getCurrentImage() const;

            virtual void setContImage(const Vector2D<unsigned long int> v);
            virtual void setContImage(const unsigned long int x, const unsigned long int y);
            virtual const Vector2D<unsigned long int> getContImage() const;

            virtual void setEspelho(const bool e);
            virtual const bool getEspelho() const;

            virtual void setTexture(const string t);
            virtual void UpdatePosition();
            virtual void InitialUpdate ();      // TO DO
            virtual void UpdateGerenciador();   // TO DO
            virtual void Update();              // TO DO
            virtual void Draw();

            virtual void Move(const Vector2D<float> v);
            virtual void Move(const float x, const float y);
        };

        class Obstaculo01:
            public Obstaculo
        {
        private:


        public:

            Obstaculo01(const string c = "imagem/bau.png");
            ~Obstaculo01();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//...........TO DO
            void UpdateGerenciador();//........TO DO
            void Update();//...................TO DO
            void Draw();//.....................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Obstaculo02:
            public Obstaculo
        {
        private:

        public:

            Obstaculo02(const string c = "imagem/Plataforma_03.png");
            ~Obstaculo02();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//............TO DO
            void UpdateGerenciador();//.........TO DO
            void Update();//....................TO DO
            void Draw();//......................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Obstaculo03:
            public Obstaculo
        {
        private:

        public:

            Obstaculo03(const string c = "imagem/Plataforma_03.png");
            ~Obstaculo03();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//............TO DO
            void UpdateGerenciador();//.........TO DO
            void Update();//....................TO DO
            void Draw();//......................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };
    }
}

#endif // INCLUDED_ENTIDADE_H
