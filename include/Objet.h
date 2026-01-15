#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include "Image.h"
#include "Tuile.h"
#include "Dictionnaire.h"
using namespace std;

class Objet {
private:
    Image _image;
    int _x, _y;
    Tuile _tuile;
public:
    Objet(const Image& objets, const string& nom, const Dictionnaire& dictionnaire, int x, int y);
    void dessiner() const;
    void cacher();
    int getX() const;
    int getY() const;
    string getPropriete() const;
};

#endif // OBJET_H_INCLUDED
