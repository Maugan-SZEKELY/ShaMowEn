#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED

#include <vector>
#include "Objet.h"
using namespace std;

class Niveau {
private:
    vector<Objet> _objets;
    int _nb_bonus;
public:
    Niveau(const Image& objets, const string& nom_fichier, const Dictionnaire& dictionnaire);
    void dessiner() const;
    bool caseEstLibre(int x, int y) const;
    void testerBonusEtPrendre(int x, int y);
    bool gagne() const;
};

#endif // NIVEAU_H_INCLUDED
