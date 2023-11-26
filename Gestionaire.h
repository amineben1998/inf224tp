#ifndef GESTIONAIRE_H
#define GESTIONAIRE_H

#include <map>
#include <string>
#include "Groupe.h"
#include "Base.h"
#include "Film.h"
#include "Photo.h"
#include "Video.h"
#include <iostream>



class Gestionaire{
    private:
        std::map<std::string, GroupePtr> tableGroupe;
        std::map<std::string, BasePtr> tableBase;

    public:
        
        PhotoPtr creerPhoto(std::string nomPhoto, std::string cheminPhoto, double longitude, double latitude){
            PhotoPtr pointeur(new Photo(nomPhoto,cheminPhoto,longitude,latitude));
            tableBase.insert(make_pair(nomPhoto, pointeur));
            return pointeur;
        }
        VideoPtr creerVideo(std::string nomFichier, std::string cheminFichier, int duree){
            VideoPtr pointeur(new Video(nomFichier,cheminFichier,duree));
            tableBase.insert(make_pair(nomFichier,pointeur));
            return pointeur;

        }
        FilmPtr creerFilm(std::string nomFilm,std::string cheminFilm, int duree,int nombreChapitre){
            FilmPtr pointeur(new Film(nomFilm,cheminFilm,duree,nombreChapitre));
            tableBase.insert(make_pair(nomFilm,pointeur));
            return pointeur;


        }
        GroupePtr creerGroupe(std::string idGroupe){
             GroupePtr pointeur(new Groupe(idGroupe));
             tableGroupe.insert(make_pair(idGroupe, pointeur));
             return pointeur;
        }
        void affichageBase(std::ostream& sortie, std::string nom) const{
            auto it = tableBase.find(nom);
            if(it != tableBase.end()) {
                it->second->affichage(sortie);
            }
            else {
                cout << "--Multimedia :" << nom << " est introuvable"<< endl;
            }
        }

        void affichageGroupe(std::ostream & sortie ,std::string nom){
             auto it = tableGroupe.find(nom);

            if(it != tableGroupe.end()) {
                it->second->affichage(sortie);
            }
            else {
                cout << " le groupe  multimedia " << nom << " est introuvable " << endl;
            }
        }
        
        void lancer(std::string nomFichier) const{
            auto it = tableBase.find(nomFichier);
            if (it != tableBase.end()) it->second->jouer();
            else 
               std::cout<<" le fichier :" << nomFichier << " introuvable" << std::endl;
        }
        void supprimerBase(std::string nomFichier){
             auto it = tableBase.find(nomFichier);
             if (it != tableBase.end()) {
                   tableBase.erase(it); 
             } else {
                   std::cout << "Le fichier: " << nomFichier << " introuvable" << std::endl;
            }   
        }
        void supprimerGroupe(std::string idGroupe){
             auto it = tableGroupe.find(idGroupe);
             if (it != tableGroupe.end()) {
                tableGroupe.erase(it); 
             }else {
                std::cout << "Le groupe : " << idGroupe << " introuvable" << std::endl;
            }   
        }

        const std::map<std::string, BasePtr>& getTableBase() const {
        return tableBase;
        }

        const std::map<std::string, GroupePtr>& getTableGroupe() const {
        return tableGroupe;
        }



};

#endif 