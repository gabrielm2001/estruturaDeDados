#include <iostream>
#include "Aluno.cpp"

using namespace std;

class Hash{
    private:
        int max_itens;
        int max_posicoes;
        int qtd_itens;

        Aluno *estrutura;
        int funcaoHash(Aluno aluno);
    public:
        Hash(int tam_vetor, int max);
        ~Hash();
        void inserir(Aluno aluno);
        void remover(Aluno aluno);
        void imprimir();
        void buscar(Aluno &aluno, bool &busca);
        bool estaCheia();
        bool estaVazia();
        int obterTamanho();

};