#include <iostream>
#include "hash.cpp"

int main()
{

    int max_posicoes;
    int max_itens;
    int opcao;

    bool busca = false;

    int ra;
    string nome;

    cout << "Programa de tabela hash" << endl;

    cout << "Qual é a quantidade de alunos?" << endl;
    cin >> max_posicoes;

    cout << "Qual é a máxima quantidade de alunos?" << endl;
    cin >> max_itens;

    cout << "O fator de carga é " << (float)max_posicoes / (float)max_itens << endl;

    Aluno aluno;
    Hash hash = Hash(max_posicoes, max_itens);

    do
    {
        cout << "Escolha uma opção" << endl;
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Imprimir" << endl;
        cout << "4 - Buscar" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o nome do aluno" << endl;
            cin >> nome;

            cout << "Digite o RA do aluno" << endl;
            cin >> ra;

            aluno = Aluno(nome, ra);

            hash.inserir(aluno);

            cout << "Inserir" << endl;
            break;
        case 2:

            cout << "Digite o RA do aluno a ser removido" << endl;
            cin >> ra;

            aluno = Aluno(" ", ra);

            hash.remover(aluno);
            break;
        case 3:
            hash.imprimir();
            break;
        case 4:
            cout << "Digite o ra do aluno a ser buscado" << endl;
            cin >> ra;

            aluno = Aluno(" ", ra);
            hash.buscar(aluno, busca);
            if (busca)
            {
                cout << "Aluno encontrado: " << aluno.obternome() << endl;
                cout << "ra do aluno encontrado: " << aluno.obterRa() << endl;
            }
            else
            {
                cout << "Aluno não encontrado" << endl;
            }
            break;
        case 0:
            cout << "Sair" << endl;
            cout << "Até mais" << endl;
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
        }

    } while (opcao != 0);
}