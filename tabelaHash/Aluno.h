#include <iostream>

using namespace std;

class Aluno
{
private:
    string nome;
    int ra;
public:
    Aluno();
    Aluno(string nome, int ra);

    int obterRa();
    string obternome();
};