#include <iostream>
#include <string>
#include <list>
#include "Obras.hpp"
#include "perguntas.hpp"

using namespace std;

int acharMaisAntigo(list<Obras> lista){
    list<Obras>::iterator it = lista.begin(); // iterador que aponta para o inicio da lista
    int resposta = lista.begin()->getAnoPublicacao();
    while (it != lista.end()){
        ++it;
        int atual = it->getAnoPublicacao();
        if(resposta > atual) {
            resposta = atual;
        }
    }
    return resposta;
}
string livroOuFilme(list<Obras> lista){
    int livros = 0, filmes = 0;
    list<Obras>::iterator it = lista.begin(); // iterador que aponta para o inicio da lista

    for(it; it != lista.end(); ++it){
        if(it->getMidia() == "Livro") livros++;
        if(it->getMidia() == "Filme") filmes++;
    }
    if(livros > filmes) return "livros";
    else return "filmes";
}
