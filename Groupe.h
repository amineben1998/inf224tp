#ifndef GROUPE_H
#define GROUPE_H

#include <iostream>
#include <list>
#include <memory>
#include "Base.h"

using namespace std;

class Groupe : public std::list<BasePtr> {
   private:
    string idGroupe{};

   public:
    Groupe(){};

    Groupe(string idGroupe) { this->idGroupe = idGroupe; }

    ~Groupe() {
        cout << "Le Groupe de media " << this->getGroupeId() << " est detruit"
             << endl;
    }

    string getGroupeId() const { return this->idGroupe; };

    void setGroupeId(string idGroupe) { this->idGroupe = idGroupe; }

    void affichage(ostream &sortie) const {
       
        for (auto &it : *this) it->affichage(sortie);
    }
};

typedef std::shared_ptr<Groupe> GroupePtr;

#endif