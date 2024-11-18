#include <iostream>
#include <string>
#include <list>
#include "../HPPS/Obras.hpp"
#include "../HPPS/perguntas.hpp"

using namespace std;

int acharMaisAntigo(list<Obras> lista)
{
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
{
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
{
    list<Obras>::iterator it = lista.begin(); // iterador que aponta para o inicio da lista
    string subgeneroMaisFrequente;
    int maxFreq = 0;
    list<string> subgeneros;

    while (it != lista.end()){
        subgeneros.push_back(it->getsubGenero());
        ++it;
    }

        // frequencia de cada genero
        for (list<string>::iterator subIt = subgeneros.begin(); subIt != subgeneros.end(); ++subIt)
        {
        int freq = count(subgeneros.begin(), subgeneros.end(), *subIt);
        if (freq > maxFreq){
            maxFreq = freq;
            subgeneroMaisFrequente = *subIt;
        }
    }

    if (!subgeneroMaisFrequente.empty()){
        return subgeneroMaisFrequente;
    }

    return "Nenhum subgênero encontrado."; // erro
}
string nemFilmesNemLivros(list<Obras> lista){
    string res = "";
    
    for (list<Obras>::iterator it = lista.begin(); it != lista.end(); ++it){
        if (it->getAutor() != "Filme" && it->getAutor() != "Livro"){
            res += "Obra: " + it->getTitulo() + " Tipo: " + it->getAutor() + "\n";
        }
    }
    if (res.empty()) {
        return "Nenhuma obra que nao seja filme nem livro."; // erro
    }
    return res;
}
string acharMaisNovo(list<Obras> lista){
    int ano = lista.begin()->getAnoPublicacao();
    string titulo = lista.begin()->getTitulo();
    string subG = lista.begin()->getsubGenero();
    for(list<Obras>::iterator it = lista.begin();it!= lista.end();++it){
         if (ano < it->getAnoPublicacao()){
            ano = it->getAnoPublicacao();
            titulo = it->getTitulo();
            subG = it->getsubGenero();
        }
    }
    return titulo + " do subgenero " + subG;
}
