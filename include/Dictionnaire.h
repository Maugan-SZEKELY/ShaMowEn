#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include <vector>
#include "Tuile.h"
using namespace std;

class Dictionnaire {
private:
    vector<Tuile> _tuiles;
public:
    Dictionnaire(const string& nom_fichier);
    void afficher() const;

    // true si l’élément a été trouvé, false sinon
    // L’objet Tuile trouvé est renvoyé par un paramètre résultat (R).
    bool recherche(const string& nom_tuile, Tuile& tuile_trouvee) const;
};

#endif // DICTIONNAIRE_H_INCLUDED
