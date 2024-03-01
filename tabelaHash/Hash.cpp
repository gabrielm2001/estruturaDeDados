#include <iostream>
#include "Hash.h"

using namespace std;

int Hash::funcaoHash(Aluno aluno)
{
        return (aluno.obterRa() % max_posicoes);
}

Hash::Hash(int tam_vetor, int max)
{
        qtd_itens = 0;
        max_posicoes = tam_vetor;
        max_itens = max;
        estrutura = new Aluno[max_posicoes]; //***
}

Hash::~Hash()
{
        delete[] estrutura;
}

void Hash::inserir(Aluno aluno)
{
        if (!estaCheia())
        {
                int posicao = funcaoHash(aluno);

                estrutura[posicao] = aluno;
                qtd_itens++;
        }
}

void Hash::remover(Aluno aluno)
{
        if (!estaVazia())
        {
                int posicao = funcaoHash(aluno);

                if (estrutura[posicao].obterRa() != -1)
                {
                        estrutura[posicao] = Aluno(" ", -1);
                        qtd_itens--;
                }
        }
}

void Hash::imprimir()
{
        cout << "Tabela Hash [ \n";
        for (int i = 0; i < max_posicoes; i++)
        {
                if (estrutura[i].obterRa() != -1)
                {
                        cout << estrutura[i].obterRa() << ": " << estrutura[i].obternome() << endl;
                }
        }

        cout << " ]\n";
}

void Hash::buscar(Aluno &aluno, bool &busca)
{
        int posicao = funcaoHash(aluno);
        if (estrutura[posicao].obterRa() != -1 && estrutura[posicao].obterRa() == aluno.obterRa())
        {
                aluno = estrutura[posicao];
                busca = true;
        }
        else
        {
                busca = false;
        }
}

bool Hash::estaCheia()
{
        return (qtd_itens == max_itens);
}

bool Hash::estaVazia()
{
        return (qtd_itens == 0);
}

int Hash::obterTamanho()
{
        return qtd_itens;
}
