#include <iostream>
#include <stddef.h>
#include "Aluno.h"
#include "ArvoreBinaria.h"

using namespace std;

ArvoreBinaria::ArvoreBinaria()
{
  raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
  deletarArvore(raiz);
}

void ArvoreBinaria::deletarArvore(No *atual)
{
  if (atual != NULL)
  {
    imprimirPreOrdem(atual->esquerda);
    imprimirPreOrdem(atual->direita);
    delete atual;
  }
}

void ArvoreBinaria::inserir(Aluno aluno)
{
  No *noNovo = new No;
  noNovo->aluno = aluno;
  noNovo->direita = NULL;
  noNovo->esquerda = NULL;
  if (raiz == NULL)
  {
    raiz = noNovo;
  }
  else
  {
    No *temp = raiz;
    while (temp != NULL)
    {

      if (temp->aluno.obterRa() > noNovo->aluno.obterRa())
      {
        if (temp->esquerda == NULL)
        {
          temp->esquerda = noNovo;
          break;
        }
        temp = temp->esquerda;
      }
      else
      {
        if (temp->direita == NULL)
        {
          temp->direita = noNovo;
          break;
        }
        temp = temp->direita;
      }
    }
  }
};

void ArvoreBinaria::buscar(Aluno &aluno, bool &busca)
{
  busca = false;
  No *atual = raiz;

  while (atual != NULL)
  {
    if (aluno.obterRa() < atual->aluno.obterRa())
    {
      atual = atual->esquerda;
    }
    else if (aluno.obterRa() > atual->aluno.obterRa())
    {
      atual = atual->direita;
    }
    else
    {
      aluno = atual->aluno;
      busca = true;
      break;
    }
  }
}

void ArvoreBinaria::remover(Aluno aluno)
{
  removerBusca(aluno, raiz);
}

void ArvoreBinaria::removerBusca(Aluno aluno, No *&atual)
{
  if (aluno.obterRa() < atual->aluno.obterRa())
  {
    removerBusca(aluno, atual->esquerda);
  }
  else if (aluno.obterRa() > atual->aluno.obterRa())
  {
    removerBusca(aluno, atual->direita);
  }
  else
  {
    deletarNo(atual);
  }
}

void ArvoreBinaria::deletarNo(No *&atual)
{
  No *temp = atual;

  if (atual->esquerda == NULL)
  {
    atual = atual->direita;
    delete temp;
  }
  else if (atual->direita == NULL)
  {
    atual = atual->esquerda;
    delete temp;
  }
  else
  {
    Aluno alunoSucessor;
    obterSucessor(alunoSucessor, atual);
    atual->aluno = alunoSucessor;
    removerBusca(alunoSucessor, atual->direita);
  }
}

void ArvoreBinaria::obterSucessor(Aluno &alunoSucessor, No *temp)
{
  temp = temp->direita;
  while (temp->esquerda != NULL)
  {
    temp = temp->esquerda;
  }

  alunoSucessor = temp->aluno;
}

void ArvoreBinaria::imprimirPreOrdem(No *atual)
{
  if (atual != NULL)
  {
    cout << atual->aluno.obterRa() << ": ";
    cout << atual->aluno.obternome() << endl;

    imprimirPreOrdem(atual->esquerda);
    imprimirPreOrdem(atual->direita);
  }
}

void ArvoreBinaria::imprimirEmOrdem(No *atual)
{
  if (atual != NULL)
  {
    imprimirPreOrdem(atual->esquerda);
    cout << atual->aluno.obterRa() << ": ";
    cout << atual->aluno.obternome() << endl;
    imprimirPreOrdem(atual->direita);
  }
}

void ArvoreBinaria::imprimirPosOrdem(No *atual)
{
  if (atual != NULL)
  {
    imprimirPreOrdem(atual->esquerda);
    imprimirPreOrdem(atual->direita);
    cout << atual->aluno.obterRa() << ": ";
    cout << atual->aluno.obternome() << endl;
  }
}

bool ArvoreBinaria::estaCheia()
{
  try
  {
    No *no;
    no = new No;
    return false;
  }
  catch (const std::exception &e)
  {
    return true;
  }
}

bool ArvoreBinaria::estaVazia()
{
  return raiz == NULL;
}

int ArvoreBinaria::tamanho()
{
  return qtd_itens;
}