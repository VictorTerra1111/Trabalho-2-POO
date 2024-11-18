#include <iostream>
#include <list>
#include <string>
#include "../HPPS/Obras.hpp"
#include "../HPPS/File_manage.hpp"
#include "../HPPS/perguntas.hpp"

using namespace std;
/*
    Titulo: Coleção de Obras de ficção Científica
    Autores: João Victor Terra & Raul Costa
    Disciplina: Programação Orientada a Objetos
*/

int main()
{
    bool runner = true;
    int numPergunta;
    try
    {
        list<Obras> lista = ReadInfo(); // le as informacoes do arquivo e as coloca na lista
        while (runner)
        {
            try
            {
                cout << "1) Qual a obra mais antiga da coleção?" << endl;
                cout << "2) Há mais livros ou filmes nesta coleção?" << endl;
                cout << "3) Qual o sub gênero que mais se repete?" << endl;
                cout << "4) Quais obras não são filmes e nem livros? O que elas são?" << endl;
                cout << "5) Qual a obra mais nova da coleção? A que sub gênero ela pertence?" << endl;
                cout << "6) Tabela de todas as obras da coleção." << endl;
                cout << "7) Sair" << endl
                     << endl;
                cout << "Digite aqui: ";
                cin >> numPergunta;

                if (cin.fail())
                {
                    throw runtime_error("ERRO AO LER OPCOES");
                }
                switch (numPergunta)
                {
                case 1:
                    cout << "-----------------------" << endl;
                    cout << "|  A obra mais antiga desta coleção é de " << acharMaisAntigo(lista) << "  |" << endl;
                    cout << "-----------------------" << endl;
                    break;
                case 2:
                    cout << "-----------------------" << endl;
                    cout << "|  Há mais " << livroOuFilme(lista) << " nesta lista   |" << endl;
                    cout << "-----------------------" << endl;
                    break;
                case 3:
                    cout << "-----------------------" << endl;
                    cout << "|  " << Subgenero(lista) << "  |" << endl;
                    cout << "-----------------------" << endl;
                    break;
                case 4:
                    cout << "-----------------------" << endl;
                    cout << "As obras que não são nem filme nem livro são" << endl
                         << nemFilmesNemLivros(lista);
                    cout << "-----------------------" << endl;
                    break;
                case 5:
                    cout << "-----------------------" << endl;
                    cout << "|  " << acharMaisNovo(lista) << "  |" << endl;
                    cout << "-----------------------" << endl;
                    break;
                case 6:
                    tabelaDados(lista);
                    break;
                case 7:
                    cout << "-----------------------" << endl;
                    cout << "|  saindo  |" << endl;
                    cout << "-----------------------" << endl;
                    runner = false;
                    break;
                default:
                    cout << "-----------------------" << endl;
                    cout << "|  esta não é uma opção válida  |" << endl;
                    cout << "-----------------------" << endl;
                    break;
                }
            }
            catch (runtime_error &e)
            {
                cerr << "ERRO: " << e.what() << endl;
                cin.clear();
                cin.ignore();
            }
            catch (exception &e)
            {
                cerr << "ERRO: " << e.what() << endl;
            }
        }
    }
    catch (exception &e)
    {
        cerr << "ERRO: " << e.what() << endl;
        return 1;
    }
    return 0;
}
