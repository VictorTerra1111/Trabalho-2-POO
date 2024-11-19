#include <iostream>
#include <list>
#include <string>
#include "../HPPS/Obras.hpp"
#include "../HPPS/File_manage.hpp"
#include "../HPPS/perguntas.hpp"
#include "../HPPS/Menu.hpp"

using namespace std;

/*
    Titulo: Coleção de Obras de ficção Científica
    Autores: João Victor Terra & Raul Costa
    Disciplina: Programação Orientada a Objetos
*/

int main()
{
    list<Obras> lista = ReadInfo(); // le as informacoes do arquivo e as coloca na lista

    try
    {
        menu(lista);
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

    return 0;
}
