#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED

#include <string>
using namespace std;

class Tuile {
private:
    string _nom;
    int _skin_x, _skin_y;
    string _propriete;
public:
    Tuile();
    Tuile(const string& nom, int skin_x, int skin_y, const string& propriete);
    void afficher() const;
    int getSkinX() const { return _skin_x; }
    int getSkinY() const { return _skin_y; }
    void setPropriete(const string& propriete);
    string getNom() const { return _nom; }
    string getPropriete() const { return _propriete; }
};

#endif // TUILE_H_INCLUDED
