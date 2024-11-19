#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iomanip>
#include "../HPPS/Obras.hpp"
#include "../HPPS/perguntas.hpp"

using namespace std;

// implementacao do HPP perguntas

int acharMaisAntigo(list<Obras> lista)
{                                             // funcao para pergunta 1 que percorre a lista e retorna a obra mais antiga
    list<Obras>::iterator it = lista.begin(); // iterador que aponta para o inicio da lista
    int resposta = lista.begin()->getAnoPublicacao();
    while (it != lista.end())
    {
        if (resposta > it->getAnoPublicacao())
        {
            resposta = it->getAnoPublicacao();
        }
        ++it;
    }
    return resposta;
}

string livroOuFilme(list<Obras> lista)
{ // retorna uma string com o nome do tipo de obra que possui mais ocorrencias na lista, filmes ou livros
    int livros = 0, filmes = 0;

    for (list<Obras>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        if (it->getMidia() == "Livro")
            livros++;
        if (it->getMidia() == "Filme")
            filmes++;
    }
    if (livros > filmes)
        return "livros";
    else
        return "filmes";
}

string Subgenero(list<Obras> lista)
{                                             // funcao que retorna o subgenero de ficcao cientifica com mais ocorrencias na lista
    list<Obras>::iterator it = lista.begin(); // iterador que aponta para o inicio da lista
    string subgeneroMaisFrequente;
    int maxFreq = 0;
    list<string> subgeneros;

    while (it != lista.end())
    {
        subgeneros.push_back(it->getsubGenero());
        ++it;
    }

    // frequencia de cada genero
    for (list<string>::iterator subIt = subgeneros.begin(); subIt != subgeneros.end(); ++subIt)
    {
        int freq = count(subgeneros.begin(), subgeneros.end(), *subIt);
        if (freq > maxFreq)
        {
            maxFreq = freq;
            subgeneroMaisFrequente = *subIt;
        }
    }

    if (!subgeneroMaisFrequente.empty())
    {
        return subgeneroMaisFrequente;
    }

    return "Nenhum subgênero encontrado."; // erro
}

string nemFilmesNemLivros(list<Obras> lista)
{ // retorna uma string que mostra que outros tipos de midia existem na lista
    string res = "";

    for (list<Obras>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        if (it->getMidia() != "Filme" && it->getMidia() != "Livro")
        {
            res += "Obra: " + it->getTitulo() + " Tipo: " + it->getMidia() + "\n";
        }
    }
    if (res.empty())
    {
        return "Nenhuma obra que nao seja filme nem livro."; // erro
    }
    return res;
}

string acharMaisNovo(list<Obras> lista)
{ // encontra a obra mais recente da lista
    int ano = lista.begin()->getAnoPublicacao();
    string titulo = lista.begin()->getTitulo();
    string subG = lista.begin()->getsubGenero();
    for (list<Obras>::iterator it = lista.begin(); it != lista.end(); ++it)
    {
        if (ano < it->getAnoPublicacao())
        {
            ano = it->getAnoPublicacao();
            titulo = it->getTitulo();
            subG = it->getsubGenero();
        }
    }
    return titulo + " do subgenero " + subG;
}

void tabelaDados(list<Obras> lista)
{ // imprime a tabela com todos os dados atuais
    string input;
    list<Obras>::iterator it = lista.begin(); // iterador que aponta para o inicio da lista

    cout << "\033[2J\033[1;1H"; // limpa o terminal
    cout
        << " " << left << setw(150) << setfill('_') << " "
        << endl
        << "|" << left << setw(45) << setfill(' ') << "TITULO"
        << "|" << left << setw(45) << setfill(' ') << "AUTOR"
        << "|" << left << setw(20) << setfill(' ') << "MIDIA"
        << "|" << left << setw(20) << setfill(' ') << "SUBGEN"
        << "|" << left << setw(20) << setfill(' ') << "ANO" << endl;

    while (it != lista.end())
    {
        cout
            << "|" << left << setw(150) << setfill('_') << " " << endl
            << "|" << left << setw(45) << setfill(' ') << it->getTitulo()
            << "|" << left << setw(45) << setfill(' ') << it->getAutor()
            << "|" << left << setw(20) << setfill(' ') << it->getMidia()
            << "|" << left << setw(20) << setfill(' ') << it->getsubGenero()
            << "|" << left << setw(20) << setfill(' ') << it->getAnoPublicacao() << endl;
        ++it;
    }
    cout << "|" << left << setw(150) << setfill('_') << " " << endl;
    cout << "Pressione ENTER para voltar a tela inicial.";
    getline(cin, input);
}
