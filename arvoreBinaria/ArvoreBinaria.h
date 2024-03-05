#include <iostream>
#include "Aluno.h"

using namespace std;

typedef int TipoItem;

struct No
{
  Aluno aluno;
  No *esquerda;
  No *direita;
};

class ArvoreBinaria
{
private:
  No *raiz;
  int qtd_itens;

public:
  ArvoreBinaria();
  ~ArvoreBinaria();

  void deletarArvore(No *atual);
  No *obterRaiz();

  void inserir(Aluno aluno);

  void remover(Aluno aluno);

  void removerBusca(Aluno aluno, No *&atual);
  void deletarNo(No *&atual);
  void obterSucessor(Aluno &alunoSucessor, No *temp);

  void buscar(Aluno &aluno, bool &busca);

  bool estaCheia();
  bool estaVazia();

  void imprimirPreOrdem(No *atual);
  void imprimirEmOrdem(No *atual);
  void imprimirPosOrdem(No *atual);

  int tamanho();
};
