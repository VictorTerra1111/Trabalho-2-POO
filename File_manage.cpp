#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Obras.hpp"
#include "File_manage.hpp"

using namespace std;
// funcao que le as informacoes do arquivo e as coloca em uma list STL

list<Obras> ReadInfo()
{
    string titulo, autor, subGenero, midia; // variaveis para armazenar os valores do arquivo
    int anoPublicacao;
    list<Obras> lista; // lista para retornar os objetos lidos

    ifstream infile; 
    infile.open("Data_bank.txt"); // abre o arquivo data_bank.txt 

    if (!infile)
    { 
        cerr << "ERROR IN FILE: READ INFO" << endl; // codigo de erro
    }

    while(infile >> titulo >> autor >> subGenero >> anoPublicacao >> midia){
        Obras piece(titulo, autor, subGenero, midia, anoPublicacao); 
        lista.push_back(piece);
    } // le todas as informacoes de cada objeto e adiciona a lista
    infile.close(); // fecha o arquivo

    return lista; // retorna a lista
}
