#include "Principal.h"

/*
Slide 02 - 1)Conceito de encapsulamento de metodos e suas desvantagens
           2)Valor por Default nos métodos que sao atribui nos atributos da class
           3)Troca o printf(saida) por cout(printf moderno) e uso de cin(entrada) em vez do scanf.Ideia de fluxo de saida e entrada
           4)Construção de uma class Principal
           5)Uso de static(ser alterado em um objeto dessa class sera alterado nos outros objetos)
             e const(esse valor sera iniciado e nunca será alterado ao decorrer do andamento do projeto)
             em 3 atributos no arquivo Principal.h
           6)Conceito da função-membro destrutora que e chamada no final depois da main automaticamente
           7)Relacionamento entre classes de Agregação(Ex.: o objeto Principal tem instanciado 3 Objetos da class Pessoa
             de tal forma que esses objetos estão agregados em Principal)
           8)Relacionamento entre classes de Associação(Ex.: )
*/

using namespace std;

int main()
{
    Principal obj;
    obj.Executar();
}
