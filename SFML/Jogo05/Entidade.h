#ifndef INCLUDED_ENTIDADE_H
#define INCLUDED_ENTIDADE_H

//AJUDA

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

//JOGADOR
#define HEIGHTJUMPER 100.0f
#define QTD_VIDAS_JOG 6lu
#define TAMANHO_DA_TEXTURA_JOGADOR_X 70.3125f
#define TAMANHO_DA_TEXTURA_JOGADOR_Y 90.0f
#define TAMANHO_COLIDIVEL_JOGADOR_X 70.3125f
#define TAMANHO_COLIDIVEL_JOGADOR_Y 90.0f
#define SPEED_JOGADOR 300.0f
#define TEMPO_CICLO_PROJETIL 0.03f
#define CHANGE_TIME_ANIMATION_PLAYER01 0.1f

//Jogador
#define PUSH_BAU 0.75f
#define PUSH_CAIXOTE 0.75f
#define PUSH_PLATAFORMA 1.0f
#define PUSH_INIMIGO 1.0f

/*
 * TAMANHO COLIDIVEL X: 29/51 DP TAMANHO DA TEXTURA
 * TAM.X = 41
 * TAM.Y = 51
 */
 //JOGADOR 01
#define TAMANHO_DA_TEXTURA_JOGADOR01_X 130.0f
#define TAMANHO_DA_TEXTURA_JOGADOR01_Y 104.5098f
#define TAMANHO_COLIDIVEL_JOGADOR01_X 73.9215f
#define TAMANHO_COLIDIVEL_JOGADOR01_Y 102.0f
#define SPEED_JOGADOR01 300.0f


//Inimigo
#define ENEMY_LIVES 3l

//INIMIGO01
#define VELINI01 300.0f;
#define CAMINI01 "Texture/tux_from_linux.png"
#define TAMANHO_DA_TEXTURA_INIMIGO01_X 70.3125f
#define TAMANHO_DA_TEXTURA_INIMIGO01_Y 90.0f
#define TAMANHO_COLIDIVEL_INIMIGO01_X 70.3125f
#define TAMANHO_COLIDIVEL_INIMIGO01_Y 90.0f

//PROJETIL
#define VELOCIDADE_PROJETIL 900.0f
#define TEMPO_VIDA_PROJETIL_JOGADOR 5.0f
#define PROJECTILE_DAMAGE 1l

//BARRA DE VIDA
#define TEMPO_INVUNERABILIDADE 2.0f



//Obstaculo e Inimigo
#define PUSH_INIMIGO_OBST 0.5f
#define PUSH_INIMIGO_PLATAFORMA 0.5f

//OBSTACULO 01 - BAU
#define BAU_SIZE_X 64.0f
#define BAU_SIZE_Y 64.0f

//CAMINHOS
#define BARRA_DE_VIDA "Texture/CCC.png"

#include "Gerenciador_Grafico.h"
#include "Lista.h"

using namespace Gerenciador;

namespace ent
{
    class Entidade
    {
    protected:

        unsigned long int id;
        string key; //id para Corpo
        string path;
        Vector2D<float> tam_tex;
        Vector2D<float> pos;

        static Gerenciador_Grafico* control;

    public:

        Entidade(const string c = "");
        virtual ~Entidade();

        void setID(const unsigned long ID);
        const unsigned long int getID() const;

        virtual void setTexture(const string t) = 0;
        const string getTexture() const;

        virtual void setSizeTexture(const Vector2D<float> v);
        virtual void setSizeTexture(const float x, const float y);
        const Vector2D<float> getSizeTexture() const;

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

    class EntidadeColidivel:
        public Entidade
    {
    protected:

        bool colidiu;
        Vector2D<unsigned long int> hcollision;
        Vector2D< unsigned long int> vcollision;
        Vector2D<float> tam;

    public:

        EntidadeColidivel(const string c = "");
        virtual ~EntidadeColidivel();

        void setColisao(const bool c);
        const bool getColisao() const;

        void restartCollisions();
        void setHorizontalCollision(const Vector2D<unsigned long int> v);
        void setHorizontalCollision(const unsigned long int x, const unsigned long int y);
        const Vector2D<unsigned long int> getHorizontalCollision() const;
        void setVerticalCollision(const Vector2D<unsigned long int> v);
        void setVerticalCollision(const unsigned long int x, const unsigned long int y);
        const Vector2D<unsigned long int> getVerticalCollision() const;

        void setSize(const Vector2D<float> v);
        void setSize(const float x, const float y);
        Vector2D<float> getSize() const;
        const Vector2D<float> getHalfSize() const;
        virtual void UpdatePosition() = 0;
        virtual void Move(const Vector2D<float> v) = 0;
        virtual void Move(const float x, const float y) = 0;
    };

    namespace per
    {
        class Personagem:
            public EntidadeColidivel
        {
        protected:
            bool life;
            bool dano;
            bool change_animation;
            bool flag_change_face;

            Vector2D<float> velocidade;
            Vector2D<unsigned long int> cont_imagem;
            Vector2D<unsigned long int> imagem_atual;
            Vector2D<float> width_height;
            Vector2D<float> left_top;

            bool face_certa;
            bool pode_pular;

            //Atributos pra Anima��o
            unsigned long int lestatico;
            unsigned long int landando;
            unsigned long int lsalto;
            unsigned long int lataque;
            unsigned long int ldano;

            float tempo_ciclo;
            float tempo_total;

        public:

            float galho;

        public:

            Personagem(const bool pp = true, const float change_time = 0.3f, const string c = "");
            virtual ~Personagem();

            void Dead(const bool l);
            const bool getLife() const;

            void setDano(const bool d);
            const bool getDano() const;

            const bool getFace() const;

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
        };

        class Barra_de_Vida:
            public Personagem
        {
        private:

            long int vidas;
            bool invulnerable;
            long int damage;
            float time_in;
            float tempo_invulnerabilidade;


        public:

            Barra_de_Vida (const unsigned long int life = QTD_VIDAS_JOG);
            ~Barra_de_Vida ();

            void setTexture(const string t = "Texture/CCC.png");
            const long int getVida() const;
            void Damage(const unsigned long int attack_force);
            const bool getInvulnerable() const;

            void InitialUpdate ();
            void UpdatePosition(); //VOID
            void UpdateAnimacao();
            void UpdateGerenciador ();
            void Update ();
            void Draw ();

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Projectile:
            public Personagem
        {
        private:

            long int damage;
            float tempo_vida;
            float tempo_entre_disparo;
            float timev;
            float speed;

        public:

            Projectile(const long int dano = PROJECTILE_DAMAGE, const bool fc = true, const float lifetime = TEMPO_VIDA_PROJETIL_JOGADOR, const float time_between_shots = 0.2f);
            ~Projectile();

            const long int attackForce() const; //getDano();

            void setTexture(const string t);

            void InitialUpdate ();
            void UpdatePosition();
            void UpdateAnimacao();
            void UpdateGerenciador ();
            void Update ();
            void Draw ();

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);

            const bool operator == (const ent::per::Projectile& p) const;
            const bool operator != (const ent::per::Projectile& p) const;
            void operator=(const ent::per::Projectile& p);
        };

        namespace jog
        {

            class Player:
                public Personagem
            {
            protected:

                Barra_de_Vida vida;
                List<Projectile> FilaProjetil;
                float tempo_entre_disparo;
                float time_projetil;
                unsigned long int cont_projetil;

                float speed; // aceleracao
                float altura_salto;
                bool animacao_disparo; //APENAS QUEM PODER� SOLTA UM PROJETIL

            public:

                Player(const float height_jumper = 1000.0f, const float aceleracao = 200.0f, const bool pp = false, const float change_time = 0.15f, const string c = "Texture/tux_from_linux.png");
                ~Player();

                //M�TODOS DA CLASSE BARRA_DE_VIDA:
                const bool getInvulnerable() const;
                void setTempoCicloLife(const float a);
                void setTextureLife(const string t = "Texture/CCC.png");
                void setSizeLife(Vector2D<float> s);
                void setSizeLife(const float x, const float y);
                void setContImageLife(const Vector2D<unsigned long int> v);
                void setContImageLife(const unsigned long int x, const unsigned long int y);
                void setCurrentImageLife(const Vector2D<unsigned long int> v);
                void setCurrentImageLife(const unsigned long int x, const unsigned long int y);
                void Damage(const unsigned long int attack_force);
                const unsigned long int getVida() const;

                void setSpeed(const float aceleracao);
                const float getSpeed() const;

                void setAlturaSalto(const float& a);
                const float getAlturaSalto() const;

                //M�TODOS DA LISTA PROJETIL
                ent::per::Projectile* getProjetil(const unsigned long int indice) const;
                const unsigned long int getSizeListaProjetil() const;

            };

            class Player01:
                public Player
            {
            private:

                unsigned long int col_estatico;
                unsigned long int col_andando;
                unsigned long int col_ataque;

            public:

                Player01(const float height_jumper = HEIGHTJUMPER, const float aceleracao = 200.0f, const bool pp = true, const float change_time = 0.15f, const string c = "Texture/tux_from_linux.png");
                ~Player01();

                void setTexture(const string t);

                //Update
                void Update(); //Posso Ocultar
                void InitialUpdate();
                void UpdatePosition();
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

            class Player02:
                public Player
            {
            public:

                Player02(const float height_jumper = HEIGHTJUMPER, const float aceleracao = 200.0f, const bool pp = true, const float change_time = 0.15f, const string c = "Texture/tux_from_linux.png");
                ~Player02();

                void setTexture(const string t);

                //Update
                void Update(); //Posso Ocultar
                void InitialUpdate();
                void UpdatePosition();
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
            class Enemy:
                public Personagem
            {

            protected:

                long int vidas;
                float dist_perc;
                float acumulador_dist;
                bool animacao_dano;

            public:

                Enemy(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Enemy();

                void Damage(long int attack_force);
            };

            class Enemy01:
                public Enemy
            {
            public:

                Enemy01(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Enemy01();

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

            class Enemy02:
                public Enemy
            {

            public:

                Enemy02(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Enemy02();

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

            class Enemy03:
                public Enemy
            {
            public:

                Enemy03(const bool pp = true, const float change_time = 0.4f, const string c = "");
                ~Enemy03();

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
        class Obstacle:
            public EntidadeColidivel
        {
        protected:

            Vector2D<float> velocidade;
            float push_jogador;

        public:
            Obstacle(const Vector2D<float> position = Vector2D<float>(700.0f, 772.0f), const Vector2D<float> tamanho = Vector2D<float>(2000.0, 400.0f), const string c = "Texture/MeioChaoGrande.png");
            virtual ~Obstacle();

            void setVelocidade(const Vector2D<float> v);
            void setVelocidade(const float x, const float y);
            const Vector2D<float> getVelocidade() const;

            void setPush(const float p);
            const float getPush() const;

            virtual void setTempoCiclo(const float t);
            virtual const float getTempoCiclo() const;

            virtual void setCurrentImage(const Vector2D<unsigned long int> v);
            virtual void setCurrentImage(const unsigned long int x, const unsigned long int y);
            virtual const Vector2D<unsigned long int> getCurrentImage() const;

            virtual void setContImage(const Vector2D<unsigned long int> v);
            virtual void setContImage(const unsigned long int x, const unsigned long int y);
            virtual const Vector2D<unsigned long int> getContImage() const;

            /*virtual void setTexture(const string t);
            virtual void UpdatePosition();
            virtual void InitialUpdate ();      // TO DO
            virtual void UpdateGerenciador();   // TO DO
            virtual void Update();              // TO DO
            virtual void Draw();

            virtual void Move(const Vector2D<float> v);
            virtual void Move(const float x, const float y);*/
        };

        class Obstacle01:
            public Obstacle
        {
        private:


        public:

            Obstacle01(const Vector2D<float> position = Vector2D<float>(1000.0f, 300.0f), const Vector2D<float> tamanho = Vector2D<float>(64.0, 64.0f), const string c = "Texture/bau.png");
            ~Obstacle01();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//...........TO DO
            void UpdateGerenciador();//........TO DO
            void Update();//...................TO DO
            void Draw();//.....................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Obstacle02:
            public Obstacle
        {
        private:

        public:

            Obstacle02(const Vector2D<float> position = Vector2D<float>(700.0f, 772.0f), const Vector2D<float> tamanho = Vector2D<float>(2000.0, 400.0f), const string c = "Texture/Plataforma_03.png");
            ~Obstacle02();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//............TO DO
            void UpdateGerenciador();//.........TO DO
            void Update();//....................TO DO
            void Draw();//......................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Obstacle03:
            public Obstacle
        {
        private:

        public:

            Obstacle03(const Vector2D<float> position = Vector2D<float>(700.0f, 772.0f), const Vector2D<float> tamanho = Vector2D<float>(2000.0, 400.0f), const string c = "Texture/Plataforma_03.png");
            ~Obstacle03();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//............TO DO
            void UpdateGerenciador();//.........TO DO
            void Update();//....................TO DO
            void Draw();//......................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };

        class Platform:
            public Obstacle
        {
        public:
            Platform(const Vector2D<float> position = Vector2D<float>(1000.0f, 300.0f), const Vector2D<float> tamanho = Vector2D<float>(2000.0, 400.0f), const string c = "Texture/MeioChaoGrande.png");
            ~Platform();

            void setTexture(const string t);

            void UpdatePosition();
            void InitialUpdate ();//...........TO DO
            void UpdateGerenciador();//........TO DO
            void Update();//...................TO DO
            void Draw();//.....................TO DO

            void Move(const Vector2D<float> v);
            void Move(const float x, const float y);
        };
    }
}

#endif // INCLUDED_ENTIDADE_H
