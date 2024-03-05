#include <iostream>
#include "Aluno.h"

    Aluno::Aluno(){
        nome = " ";
        ra = -1;
    }

    Aluno::Aluno(string nome, int ra){
        this->nome = nome;
        this->ra = ra;
    }

    int Aluno::obterRa(){
        return ra;
    }

    string Aluno::obternome(){
        return nome;
    }