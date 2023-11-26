#include "Film.h"
#include <ostream>

Film::Film(): Video() {}

Film::Film(std::string nomFilm, std::string cheminFilm, int duree, int nombreChapitre): Video(nomFilm, cheminFilm, duree) {
    this->tableau = new int[nombreChapitre];
    this->nombreChapitre = nombreChapitre;
    for(int i = 0; i < nombreChapitre; i++) {
        this->tableau[i] = 0;
    }    
}

Film::Film(const Film & from):Video(from){
    nombreChapitre = from.nombreChapitre;
    if (from.tableau) tableau = new int(*from.tableau);
    else tableau = nullptr;
    
}

// D'apres la redefinition de l'operateur = (Vu au cours)
Film& Film::operator=(const Film& from){
    Video::operator = (from);
    nombreChapitre = from.nombreChapitre;
//vérifie si les pointeurs tableau de l'objet courant et de l'objet source sont valides (non nuls).    
    if (tableau && from.tableau)
        *tableau = *from.tableau;
    else{
        delete tableau;
        if (from.tableau) tableau = new int(*from.tableau);
        else tableau = nullptr;
    }
    return *this;
}


Film::~Film() {
    delete [] tableau;
}

void Film::setTableau(int const* tableau, int nombre) {
    for(int i = 0; i < nombre; i++) {
        this->tableau[i] = tableau[i];
    }
    this->nombreChapitre=nombre;
}

void Film::affichage(std::ostream& sortie) const {
    Video::affichage(sortie);
    for(int i = 0; i < this->nombreChapitre; i++) {
        sortie << this->tableau[i] << "--";
    }
    sortie << std::endl;
}

int const* Film::getTableau() const {
    return tableau;
}

int Film::getNombreChapitre() const {
    return nombreChapitre;
}
    
