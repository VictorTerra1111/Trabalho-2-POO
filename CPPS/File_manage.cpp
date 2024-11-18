#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "../HPPS/Obras.hpp"
#include "../HPPS/File_manage.hpp"

using namespace std;
// funcao que le as informacoes do arquivo e as coloca em uma list STL

list<Obras> ReadInfo()
{
    string titulo, autor, subGenero, midia; // variaveis para armazenar os valores do arquivo
    int anoPublicacao;
    list<Obras> lista; // lista para retornar os objetos lidos

    ifstream infile;
    infile.open("TXTS/Data_bank.txt"); // abre o arquivo data_bank.txt

    if (!infile)
    {
        cerr << "ERROR IN FILE" << endl; // codigo de erro
    }
    // EXEMPLO DE LEITURA: Alien Filme Ridley_Scott 1979 Horror_Cósmico
    while (infile >> titulo >> midia >> autor >> anoPublicacao >> subGenero)
    {
        Obras piece(titulo, midia, autor, anoPublicacao, subGenero);
        lista.push_back(piece);
    } // le todas as informacoes de cada objeto e adiciona a lista
    
    infile.close(); // fecha o arquivo

    return lista; // retorna a lista
}
