#ifndef OBRAS_HPP
#define OBRAS_HPP

#include <string>

using namespace std;
// classe Obras sem implementacao
class Obras
{
private:
    string titulo;
    string autor;
    string midia;
    string subGenero;
    int anoPublicacao;

public:
    Obras(string vtitulo = "null", string vmidia = "null", string vautor = "null", int vanoPublicacao = 0, string vsubGenero = "null");

    string getTitulo() const;
    string getAutor() const;
    string getsubGenero() const;
    string getMidia() const;
    int getAnoPublicacao() const;
};

#endif
