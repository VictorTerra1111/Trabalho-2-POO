#include <iostream>
#include <string>
#include "../HPPS/Menu.hpp"
#include "../HPPS/perguntas.hpp"
#include "../HPPS/Obras.hpp"

using namespace std;

bool menu(list<Obras> lista)
{
    string input;
    int mode = 0;

    string questions[7] = {
        " Qual a obra mais antiga da coleção?", " Há mais livros ou filmes nesta coleção?",
        " Qual o sub gênero que mais se repete?", " Quais obras não são filmes e nem livros? O que elas são?",
        "Qual a obra mais nova da coleção? A que sub gênero ela pertence?", " Tabela de todas as obras da coleção.", "Sair."};

    do
    {
        cout << "\033[2J\033[1;1H"; // limpa o terminal
        cout << "==================================================" << endl;
        cout << "Navegue no menu com W (cima) e S (baixo), digite W ou S e então aperte ENTER. Para selecionar a opção, aperte ENTER." << endl;
        // Imprime o menu com ">" no local selecionado
        for (int i = 0; i < 7; ++i)
        {
            if (i == mode)
            {
                cout << "\t> " << questions[i] << endl;
            }
            else
            {
                cout << "\t- " << questions[i] << endl;
            }
        }
        cout << "==================================================" << endl;

        getline(cin, input);

        if (cin.fail())
        {
            throw runtime_error("ERRO AO LER ENTRADA");
        }

        if (input == "w")
        {
            mode = (mode == 0) ? 6 : mode - 1; // Move para cima
        }
        else if (input == "s")
        {
            mode = (mode == 6) ? 0 : mode + 1; // Move para baixo
        }
        else if (input.empty())
        {
            switch (mode)
            {
            case 0:
                cout << "==================================================" << endl;
                cout << "|  A obra mais antiga desta coleção é de " << acharMaisAntigo(lista) << "  |" << endl;
                cout << "==================================================" << endl;
                cout << " Digite ENTER para continuar." << endl;

                getline(cin, input);
                break;
            case 1:
                cout << "==================================================" << endl;
                cout << "|  Há mais " << livroOuFilme(lista) << " nesta lista   |" << endl;
                cout << "==================================================" << endl;
                cout << " Digite ENTER para continuar." << endl;

                getline(cin, input);
                break;
            case 2:
                cout << "==================================================" << endl;
                cout << "|  " << Subgenero(lista) << "  |" << endl;
                cout << "==================================================" << endl;
                cout << " Digite ENTER para continuar." << endl;

                getline(cin, input);
                break;
            case 3:
                cout << "==================================================" << endl;
                cout << "As obras que não são nem filme nem livro são" << endl
                     << nemFilmesNemLivros(lista);
                cout << "==================================================" << endl;
                cout << " Digite ENTER para continuar." << endl;

                getline(cin, input);
                break;
            case 4:
                cout << "==================================================" << endl;
                cout << "|  " << acharMaisNovo(lista) << "  |" << endl;
                cout << "==================================================" << endl;
                cout << " Digite ENTER para continuar." << endl;

                getline(cin, input);
                break;
            case 5:
                tabelaDados(lista);
                break;
            case 6:
                cout << "==================================================" << endl;
                cout << "|  saindo......  |" << endl;
                cout << "==================================================" << endl;
                return true;
                break;
            default:
                cout << "==================================================" << endl;
                cout << "|  esta não é uma opção válida  |" << endl;
                cout << "==================================================" << endl;
                cout << " Digite ENTER para continuar." << endl;

                getline(cin, input);
                break;
            }
        }

    } while (true);

    return true;
}