#include "Principal.h"
#include <fstream>

Principal::Principal():
    cont_ID_aluno(1),
    cont_ID_prof(1),
    cont_ID_disc(1),
    cont_ID_depar(1),
    cont_ID_univer(1),
    Fernando(cont_ID_aluno++),
    AAA(cont_ID_aluno++),
    BBB(cont_ID_aluno++),
    CCC(cont_ID_aluno++),
    DDD(cont_ID_aluno++),
    EEE(cont_ID_aluno++),
    Guilherme(cont_ID_aluno++),
    Einstein(cont_ID_prof++),
    Newton(cont_ID_prof++),
    Simao(cont_ID_prof++),
    Barreto(cont_ID_prof++),
    Computacao1_2006(cont_ID_disc++),
    Introd_Alg_2007(cont_ID_disc++),
    Computacao2_2007(cont_ID_disc++),
    Metodos2_2007(cont_ID_disc++),
    Calculo_III(cont_ID_disc++),
    Fisica_III(cont_ID_disc++),
    DAELN(cont_ID_depar++),
    DAMAT(cont_ID_depar++),
    DAFIS(cont_ID_depar++),
    DAINF(cont_ID_depar++),
    Fisica_Princeton(cont_ID_depar++),
    Matematica_Cambridge(cont_ID_depar++),
    UTFPR(cont_ID_univer++),
    Princeton(cont_ID_univer++),
    Cambridge(cont_ID_univer++),
    UNICAMP(cont_ID_univer++)
{
    inicializar();
    calculo_Idade();
}

void Principal::inicializar()
{
    inicializar_Aluno();
    inicializar_Professor();
    inicializar_Disciplina();
    inicializar_Departamento();
    inicializar_Universidade();
    inicializar_Listas();
    calculo_Idade();
}
Principal::~Principal()
{

}

void Principal::inicializar_Aluno()
{
    Fernando.inicializar(22,1,1997,"Fernando");
    AAA.inicializar(1,1,2000, "AAA");
    BBB.inicializar(2,2,1999, "BBB");
    CCC.inicializar(3,3,1998, "CCC");
    DDD.inicializar(4,4,1997, "DDD");
    EEE.inicializar(5,5,1996, "EEE");
    Guilherme.inicializar(5,7,2001,"Guilhermer");

    Fernando.set_RA(2037831);

    Fernando.set_Universidade(&UTFPR);
    AAA.set_Universidade(&UTFPR);
    BBB.set_Universidade(&UTFPR);
    CCC.set_Universidade(&UTFPR);
    DDD.set_Universidade(&UTFPR);
    EEE.set_Universidade(&UTFPR);
    Guilherme.set_Universidade(&UTFPR);
}

void Principal::inicializar_Professor()
{
    Einstein.inicializar(14, 3, 1879, "Einstein");
    Newton.inicializar(4, 1, 1643, "Newton");
    Simao.inicializar(10, 3, 1979, "Simao");
    Barreto.inicializar(20,12,-200, "Barreto");

    Einstein.set_Departamento(&Fisica_Princeton);
    Newton.set_Departamento(&Matematica_Cambridge);
    Simao.set_Departamento(&DAELN);
    Barreto.set_Departamento(&DAFIS);

    Einstein.set_Universidade(&Princeton);
    Newton.set_Universidade(&Cambridge);
    Simao.set_Universidade(&UTFPR);
    Barreto.set_Universidade(&UTFPR);
}

void Principal::inicializar_Disciplina()
{
    Computacao1_2006.set_Nome("Computacao_I_2006");
    Computacao1_2006.incluir_Aluno(&AAA);
    Computacao1_2006.incluir_Aluno(&CCC);
    Computacao1_2006.incluir_Aluno(&Fernando);

    Introd_Alg_2007.set_Nome("Introducao_de_Algoritmo_2007");
    Introd_Alg_2007.incluir_Aluno(&AAA);
    Introd_Alg_2007.incluir_Aluno(&EEE);
    Introd_Alg_2007.incluir_Aluno(&Fernando);
    Introd_Alg_2007.incluir_Aluno(&BBB);
    Introd_Alg_2007.incluir_Aluno(&Guilherme);

    Computacao2_2007.set_Nome("Computacao_II_2007");
    Computacao2_2007.incluir_Aluno(&EEE);
    Computacao2_2007.incluir_Aluno(&BBB);
    Computacao2_2007.incluir_Aluno(&DDD);
    Computacao2_2007.incluir_Aluno(&AAA);
    Computacao2_2007.incluir_Aluno(&Guilherme);

    Metodos2_2007.set_Nome("Metodos_II_2007");
    Metodos2_2007.incluir_Aluno(&AAA);

    Calculo_III.set_Nome("Calculo_III");
    Calculo_III.incluir_Aluno(&Fernando);
    Calculo_III.incluir_Aluno(&Guilherme);

    Fisica_III.set_Nome("Fisica_III");
    Fisica_III.incluir_Aluno(&Fernando);
    Fisica_III.incluir_Aluno(&Guilherme);

    Computacao1_2006.set_Departamento(&DAINF);
    Introd_Alg_2007.set_Departamento(&DAINF);
    Computacao2_2007.set_Departamento(&DAINF);
    Metodos2_2007.set_Departamento(&DAMAT);
    Calculo_III.set_Departamento(&DAMAT);
    Fisica_III.set_Departamento(&DAFIS);
}

void Principal::inicializar_Departamento()
{
    DAELN.set_Nome("DAELN");
    DAMAT.set_Nome("DAMAT");
    DAFIS.set_Nome("DAFIS");
    DAINF.set_Nome("DAINF");
    Fisica_Princeton.set_Nome("Fisica_PRINCETON");
    Matematica_Cambridge.set_Nome("Matematica_CAMBRIDGE");

    DAMAT.incluir_Disciplina(&Metodos2_2007);
    DAMAT.incluir_Disciplina(&Calculo_III);
    DAFIS.incluir_Disciplina(&Fisica_III);
    DAINF.incluir_Disciplina(&Computacao1_2006);
    DAINF.incluir_Disciplina(&Computacao2_2007);
    DAINF.incluir_Disciplina(&Introd_Alg_2007);

    DAELN.set_Universidade(&UTFPR);
    DAMAT.set_Universidade(&UTFPR);
    DAFIS.set_Universidade(&UTFPR);
    DAINF.set_Universidade(&UTFPR);
    Fisica_Princeton.set_Universidade(&Princeton);
    Matematica_Cambridge.set_Universidade(&Cambridge);
}

void Principal::inicializar_Universidade()
{
    UTFPR.set_Nome("UTFPR");
    Cambridge.set_Nome("Universidade_de_Cambridge");
    Princeton.set_Nome("Universidade_de_Princeton");
    UNICAMP.set_Nome("UNICAMP");

    UTFPR.incluir_Departamento(&DAELN);
    UTFPR.incluir_Departamento(&DAMAT);
    UTFPR.incluir_Departamento(&DAFIS);
    UTFPR.incluir_Departamento(&DAINF);

    Cambridge.incluir_Departamento(&Matematica_Cambridge);
    Princeton.incluir_Departamento(&Fisica_Princeton);
}

void Principal::inicializar_Listas()
{
    LAluno.incluir_Aluno(&Fernando);
    LAluno.incluir_Aluno(&AAA);
    LAluno.incluir_Aluno(&BBB);
    LAluno.incluir_Aluno(&CCC);
    LAluno.incluir_Aluno(&DDD);
    LAluno.incluir_Aluno(&EEE);
    LAluno.incluir_Aluno(&Guilherme);

    LProfessor.incluir_Professor(&Einstein);
    LProfessor.incluir_Professor(&Newton);
    LProfessor.incluir_Professor(&Simao);
    LProfessor.incluir_Professor(&Barreto);

    LDisciplina.incluir_Disciplina(&Computacao1_2006);
    LDisciplina.incluir_Disciplina(&Introd_Alg_2007);
    LDisciplina.incluir_Disciplina(&Computacao2_2007);
    LDisciplina.incluir_Disciplina(&Metodos2_2007);
    LDisciplina.incluir_Disciplina(&Calculo_III);
    LDisciplina.incluir_Disciplina(&Fisica_III);

    LDepartamento.incluir_Departamento(&DAELN);
    LDepartamento.incluir_Departamento(&DAMAT);
    LDepartamento.incluir_Departamento(&DAFIS);
    LDepartamento.incluir_Departamento(&DAINF);
    LDepartamento.incluir_Departamento(&Matematica_Cambridge);
    LDepartamento.incluir_Departamento(&Fisica_Princeton);

    LUniversidade.incluir_Universidade(&UTFPR);
    LUniversidade.incluir_Universidade(&Princeton);
    LUniversidade.incluir_Universidade(&Cambridge);
    LUniversidade.incluir_Universidade(&UNICAMP);
}

void Principal::calculo_Idade()
{
    Einstein.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Newton.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Simao.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Fernando.calculo_Idade(dia_atual, mes_atual, ano_atual);
    AAA.calculo_Idade(dia_atual, mes_atual, ano_atual);
    BBB.calculo_Idade(dia_atual, mes_atual, ano_atual);
    CCC.calculo_Idade(dia_atual, mes_atual, ano_atual);
    DDD.calculo_Idade(dia_atual, mes_atual, ano_atual);
    EEE.calculo_Idade(dia_atual, mes_atual, ano_atual);
    Guilherme.calculo_Idade(dia_atual, mes_atual, ano_atual);
}

void Principal::Menu()
{
    int op = -1;

    while(op != 5)
    {
        system("cls");
        cout << "1 - Cadastrar.........................." << endl;
        cout << "2 - Executar..........................." << endl;
        cout << "3 - Gravar............................." << endl;
        cout << "4 - Recuperar.........................." << endl;
        cout << "5 - Sair..............................." << endl;
        cout << "Informe uma opcao: ";
        cin >> op;
        switch(op)
        {
        case 1:
            {
                menu_Cadastrar();
                break;
            }
        case 2:
            {
                menu_Executar();
                break;
            }
        case 3:
            {
                menu_Gravar();
                break;
            }
        case 4:
            {
                menu_Recuperar();
                break;
            }
        case 5:
            {
                cout << "FIM!!!" << endl;
                break;
            }
        default:
            {
                cout << "Opcao Invalida!!!";
                system("Pause");
            }
        }
    }
}

void Principal::menu_Cadastrar()
{
    int op = -1;

    while(op != 6)
    {
        system("cls");

        cout << "1 - Cadastrar Aluno...................." << endl;
        cout << "2 - Cadastrar Professor................" << endl;
        cout << "3 - Cadastrar Disciplina..............." << endl;
        cout << "4 - Cadastrar Departamento............." << endl;
        cout << "5 - Cadastrar Universidade............." << endl;
        cout << "6 - Sair..............................." << endl;
        cout << "Informe uma opcao: ";
        cin >> op;

        switch(op)
        {
        case 1:
            {
                cadastrar_Aluno();
                break;
            }
        case 2:
            {
                cadastrar_Professor();
                break;
            }
        case 3:
            {
                cadastrar_Disciplina();
                break;
            }
        case 4:
            {
                cadastrar_Departamento();
                break;
            }
        case 5:
            {
                cadastrar_Universidade();
                break;
            }
        case 6:
            {
                cout << "FIM!!!" << endl;
            }
        default:
            {
                cout << "Opcao Invalida!!!" << endl;
            }
        }
    }
}

void Principal::cadastrar_Aluno()
{
    Aluno* aluno;
    char nomea[100];
    int ra;

    cout << "Qual o nome do aluno: ";
    cin >> nomea;

    cout << endl << "Qual e o RA: ";
    cin >> ra;

    aluno = new Aluno(cont_ID_aluno++, ra);
    aluno->set_Nome(nomea);
    LAluno.incluir_Aluno(aluno);
}

void Principal::cadastrar_Professor()
{
    Professor* prof;
    char nomep[150];

    cout << "Informe o nome do professor: ";
    cin >> nomep;

    prof = new Professor(cont_ID_prof++);
    prof->set_Nome(nomep);

    LProfessor.incluir_Professor(prof);
}

void Principal::cadastrar_Disciplina()
{
    Disciplina* disc;
    char nomed[150];

    cout << "Informe o nome da Disciplina: ";
    cin >> nomed;

    disc = new Disciplina(cont_ID_disc++);
    disc->set_Nome(nomed);

    LDisciplina.incluir_Disciplina(disc);
}

void Principal::cadastrar_Departamento()
{
    Departamento* depart;
    char nomed[150];

    cout << "Informe o nome do Departamento: ";
    cin >> nomed;

    depart = new Departamento(cont_ID_depar++);
    depart->set_Nome(nomed);

    LDepartamento.incluir_Departamento(depart);
}

void Principal::cadastrar_Universidade()
{
    Universidade* univer;
    char nomeu[150];

    cout << "Informe o nome da Universidade: ";
    cin >> nomeu;

    univer = new Universidade(cont_ID_univer);
    univer->set_Nome(nomeu);

    LUniversidade.incluir_Universidade(univer);
}

void Principal::menu_Executar()
{
    int op = -1;

    while(op != 6)
    {
        system("cls");
        cout << "1 - Executar Lista de Alunos..........." << endl;
        cout << "2 - Executar Lista de Professores......" << endl;
        cout << "3 - Executar Lista de Disciplinas......" << endl;
        cout << "4 - Executar Lista de Departamento....." << endl;
        cout << "5 - Executar Lista de Universidades...." << endl;
        cout << "6 - Sair..............................." << endl;
        cout << "Informe uma opcao: ";
        cin >> op;

        switch(op)
        {
        case 1:
            {
                printf("\n");
                LAluno.listar_Aluno();
                system("pause");
                break;
            }
        case 2:
            {
                printf("\n");
                LProfessor.listar_Professor();
                system("pause");
                break;
            }
        case 3:
            {
                printf("\n");
                LDisciplina.listar_Disciplinas();
                system("pause");
                break;
            }
        case 4:
            {
                printf("\n");
                LDepartamento.listar_Departamento();
                system("pause");
                break;
            }
        case 5:
            {
                printf("\n");
                LUniversidade.listar_Universidade();
                system("pause");
                break;
            }
        case 6:
            {
                cout << "FIM" << endl;
                break;
            }
        default:
            {
                cout << "opcao invalida!!!" << endl;
                break;
            }
        }
    }
}

void Principal::menu_Gravar()
{
    int op = -1;

    while(op != 6)
    {
        system("cls");
        cout << "0 - Gravar Tudo...................." << endl;
        cout << "1 - Gravar Alunos.................." << endl;
        cout << "2 - Gravar Professores............." << endl;
        cout << "3 - Gravar Disciplinas............." << endl;
        cout << "4 - Gravar Departamentos..........." << endl;
        cout << "5 - Gravar Universidades..........." << endl;
        cout << "6 - Sair..........................." << endl;
        cout << "Informe uma opcao: ";
        cin >> op;

        switch(op)
        {
        case 0:
            {
                menu_Gravar_Tudo();
                break;
            }
        case 1:
            {
                menu_Gravar_Alunos();
                break;
            }
        case 2:
            {
                menu_Gravar_Professor();
                break;
            }
        case 3:
            {
                menu_Gravar_Disciplina();
                break;
            }
        case 4:
            {
                menu_Gravar_Departamento();
                break;
            }
        case 5:
            {
                menu_Gravar_Universidade();
                break;
            }
        case 6:
            {
                cout << "FIM!!!" << endl;
                break;
            }
        default:
            {
                cout << "Opcao Invalida!!!" << endl;
                system("pause");
                break;
            }
        }
    }
}

void Principal::menu_Gravar_Alunos()
{
    //ofstream Gravar
    ofstream gravar_Aluno("Aluno.dat", ios::out);
    int i;

    if(!gravar_Aluno)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        return;
    }

    for(i = 0; i < LAluno.get_Tamanho(); i++)
    {
        Aluno* aux = LAluno.get_Aluno(i);
        gravar_Aluno << aux->get_ID() << " " << aux->get_RA() << " " << aux->get_Nome() << endl;
    }

    gravar_Aluno.close();
}

void Principal::menu_Gravar_Professor()
{
    ofstream arq;
    int i;

    arq.open("Professor.dat", ios::out);

    if(!arq)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        return;
    }

    for(i = 0; i < LProfessor.get_Tamanho(); i++)
    {
        Professor* aux = LProfessor.get_Professor(i);
        arq << aux->get_ID() << " " << aux->get_Nome() << endl;
    }
    arq.close();
}

void Principal::menu_Gravar_Disciplina()
{
    ofstream arq_disc;
    int i;

    arq_disc.open("Disciplina.dat", ios::out);

    if(!arq_disc)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        return;
    }

    for(i = 0; i < LDisciplina.get_Tamanho(); i++)
    {
        Disciplina* aux = LDisciplina.get_Disciplina(i);
        arq_disc << aux->get_ID() << " " << aux->get_Nome() << endl;
    }
    arq_disc.close();
}

void Principal::menu_Gravar_Departamento()
{
    ofstream arq_depart;
    int i;

    arq_depart.open("Departamento.dat", ios::out);

    if(!arq_depart)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        return;
    }

    for(i = 0; i < LDepartamento.get_Tamanho(); i++)
    {
        Departamento* aux = LDepartamento.get_Departamento(i);
        arq_depart << aux->get_ID() << " " << aux->get_Nome() << endl;
    }
}

void Principal::menu_Gravar_Universidade()
{
    ofstream arq_univer;
    int i;

    arq_univer.open("Universidade.dat", ios::out);

    if(!arq_univer)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        return;
    }

    for(i = 0; i < LUniversidade.get_Tamanho(); i++)
    {
        Universidade* aux = LUniversidade.get_Universidade(i);
        arq_univer << aux->get_ID() << " " << aux->get_Nome() << endl;
    }



}

void Principal::menu_Gravar_Tudo()
{
        menu_Gravar_Alunos();
        menu_Gravar_Professor();
        menu_Gravar_Disciplina();
        menu_Gravar_Departamento();
        menu_Gravar_Universidade();
}

void Principal::menu_Recuperar()
{
    int op = -1;

    while(op != 6)
    {
        system("cls");
        cout << "0 - Recuperar Tudo.............." << endl;
        cout << "1 - Recuperar Alunos............" << endl;
        cout << "2 - Recuperar Professores......." << endl;
        cout << "3 - Recuperar Disciplinas......." << endl;
        cout << "4 - Recuperar Departamentos....." << endl;
        cout << "5 - Recuperar Universidades....." << endl;
        cout << "6 - Sair........................" << endl;
        cout << "Informe uma opcao: ";
        cin >> op;

        switch(op)
        {
        case 0:
            {
                menu_Recuperar_Tudo();
                break;
            }
        case 1:
            {
                menu_Recuperar_Alunos();
                break;
            }
        case 2:
            {
                menu_Recuperar_Professores();
                break;
            }
        case 3:
            {
                menu_Recuperar_Disciplinas();
            }
        case 4:
            {
                menu_Recuperar_Departamentos();
                break;
            }
        case 5:
            {
                menu_Recuperar_Universidades();
                break;
            }
        case 6:
            {
                cout << "FIM!!!" << endl;
                break;
            }
        default:
            {
                cout << endl << "Opcao Invalida" << endl;
            }
        }
    }
}

void Principal::menu_Recuperar_Tudo()
{
    menu_Recuperar_Alunos();
    menu_Recuperar_Professores();
    menu_Recuperar_Disciplinas();
    menu_Recuperar_Departamentos();
    menu_Recuperar_Universidades();
}

void Principal::menu_Recuperar_Alunos()
{
    ifstream recuperar_alunos("Aluno.dat",ios::in);

    if(!recuperar_alunos)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        getchar();
    }
    LAluno.limpar();

    while(!recuperar_alunos.eof())
    {
        Aluno* aux = NULL;
        int id;
        int ra;
        char nomea[150];

        recuperar_alunos >> id >> ra >> nomea;

        if (0 != strcmp(nomea, "" ))
            {
            aux = new Aluno(-1);
            aux->set_ID(id);
            aux->set_RA(ra);
            aux->set_Nome(nomea);
            LAluno.incluir_Aluno(aux);
        }
    }
    recuperar_alunos.close();
}

void Principal::menu_Recuperar_Professores()
{
    ifstream rprofessor("Professor.dat", ios::in);

    if(!rprofessor)
    {
        cerr << "Arquivo não pode ser aberto!!!" << endl;
        fflush(stdin);
        getchar();
    }
    LProfessor.limpa();

    while(!rprofessor.eof())
    {
        char n[150];
        int id;

        rprofessor >> id >> n;

        if( 0 != strcmp(n, ""))
        {
            Professor* aux = new Professor(id);
            aux->set_ID(id);
            aux->set_Nome(n);
            LProfessor.incluir_Professor(aux);
        }
    }
    rprofessor.close();
}

void Principal::menu_Recuperar_Disciplinas()
{
    ifstream rdisciplina("Disciplina.dat", ios::in);

    if(!rdisciplina)
    {
        cerr << "Arquivo nao pode ser aberto!" << endl;
        fflush(stdin);
        getchar();
    }
    LDisciplina.limpa();

    while(!rdisciplina.eof())
    {
        char n[150];
        int id;

        rdisciplina >> id >> n;
        if(0 != strcmp(n, ""))
        {
            Disciplina* aux = new Disciplina(id);
            aux->set_ID(id);
            aux->set_Nome(n);
            LDisciplina.incluir_Disciplina(aux);
        }
    }
    rdisciplina.close();
}

void Principal::menu_Recuperar_Departamentos()
{
    ifstream rdepartamento("Departamento.dat", ios::in);

    if(!rdepartamento)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        getchar();
    }

    LDepartamento.limpa();

    while(!rdepartamento.eof())
    {
        int id;
        char n[150];

        rdepartamento >> id >> n;

        if(0 != strcmp(n, ""))
        {
            Departamento* aux = new Departamento(id);
            aux->set_ID(id);
            aux->set_Nome(n);
            LDepartamento.incluir_Departamento(aux);
        }
    }
    rdepartamento.close();
}

void Principal::menu_Recuperar_Universidades()
{
    ifstream runiversidade("Universidade.dat", ios::in);

    if(!runiversidade)
    {
        cerr << "Arquivo nao pode ser aberto!!!" << endl;
        fflush(stdin);
        getchar();
    }

    LUniversidade.limpa();

    while(!runiversidade.eof())
    {
        int id;
        char n[150];

        runiversidade >> id >> n;

        if(0 != strcmp(n, ""))
        {
            Universidade* aux = new Universidade(id, n);
            LUniversidade.incluir_Universidade(aux);
        }
    }
    runiversidade.close();
}

void Principal::Executar()
{
    Menu();
}
