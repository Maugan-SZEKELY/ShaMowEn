#include "Tuile.h"
#include <iostream>
using namespace std;

Tuile::Tuile(){}
Tuile::Tuile(const string& nom, int skin_x, int skin_y, const string& propriete)
{
    _nom = nom;
    _skin_x = skin_x;
    _skin_y = skin_y;
    _propriete = propriete;
}

void Tuile::afficher() const {
    cout << _nom << ": x=" << _skin_x
         << ", y=" << _skin_y
         << ", " << _propriete << endl;
}

void Tuile::setPropriete(const string& propriete) {
    _propriete = propriete;
}
