#include "Base.h"
#include <iostream>



Base::Base(){
    this->nomFichier="";
    this->cheminFichier="";
}

Base::Base(std::string nomFichier,std::string cheminFichier){
    this->nomFichier=nomFichier;
    this->cheminFichier=cheminFichier;
}

Base::~Base(){}
std::string Base::getNomFichier() const {
    return nomFichier;
}
std::string Base::getCheminFichier() const {
    return cheminFichier;
}
void  Base::setNomFichier(std::string nomFichier){
    this->nomFichier=nomFichier;
}
void Base::setCheminFichier(std::string cheminFichier){
    this->cheminFichier=cheminFichier;
}
void Base::affichage(std::ostream& sortie) const{
    sortie<<"Nom du fichier :"<< this->nomFichier <<"  Chemin du fichier /:  "<< this->cheminFichier<<std::endl;
}


