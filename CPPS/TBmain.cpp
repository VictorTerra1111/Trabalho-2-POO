#include <iostream>
#include <list>
#include <string>
#include "../HPPS/Obras.hpp"
#include "../HPPS/File_manage.hpp"
#include "../HPPS/perguntas.hpp"

using namespace std;

int main()
{
    bool runner = true;
    int numPergunta;
    int outras_respostas = 0;

    list<Obras> lista = ReadInfo(); // le as informacoes do arquivo e as coloca na lista

    while (runner)
    {
        cout << "1) Qual a obra mais antiga da coleção?" << endl;
        cout << "2) Há mais livros ou filmes nesta coleção?" << endl;
        cout << "3) Quais os livros da coleção e qual o sub gênero que mais se repete?" << endl;
        cout << "4) Quais obras não são filmes e nem livros? O que elas são?" << endl;
        cout << "5) Qual a obra mais nova da coleção? A que sub gênero ela pertence?" << endl;
        cout << "6) Sair" << endl << endl;
        cout << "Digite aqui: ";
        cin >> numPergunta;
        switch (numPergunta)
        {
        case 1:
                cout << "A obra mais antiga desta coleção é de " << acharMaisAntigo(lista) << endl;
            break;
        case 2:
                cout << "Há mais " << livroOuFilme(lista) << " nesta lista." << endl;
            break;
        case 3:
                cout << " caso 3" << endl;

            break;
        case 4:
                cout << " caso 4" << endl;

            break;
        case 5:
                cout << " caso 5" << endl;

            break;
        case 6:
                cout << " saindo" << endl;
            runner = false;
            break;

        default:
            cout << "esta não é uma opção válida" << endl;
            break;
        }
    }

    return 0;
}