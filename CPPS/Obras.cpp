#include <iostream>
#include <string>

#include "../HPPS/Obras.hpp"

using namespace std;
// implementacao dos metodos e do construtor da classe Obra

Obras::Obras(string vtitulo, string vautor, string vsubGenero, string vmidia, int vanoPublicacao){
    titulo = vtitulo;
    autor = vautor;
    midia = vsubGenero;
    subGenero = vmidia;
    anoPublicacao = vanoPublicacao;
}

string Obras::getTitulo() const {
    return titulo;
}

string Obras::getAutor() const {
    return autor;
}

string Obras::getsubGenero() const {
    return subGenero;
}

int Obras::getAnoPublicacao() const {
    return anoPublicacao;
}

string Obras::getMidia() const {
    return midia;
}
