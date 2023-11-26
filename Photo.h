#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
#include "Base.h"

/**
 * @brief Classe représentant un fichier photo.
 * 
 * Cette classe hérite de la classe Base pour fournir des fonctionnalités spécifiques aux fichiers photo.
 */
class Photo : public Base {
private:
    double longitude{}; ///< Longitude de la photo.
    double latitude{};  ///< Latitude de la photo.

public:
    /**
     * @brief Constructeur par défaut de la classe Photo.
     */
    Photo() : Base() {}

    /**
     * @brief Constructeur prenant un nom de fichier, un chemin, une longitude et une latitude pour la photo.
     * @param nomPhoto Le nom du fichier photo.
     * @param cheminPhoto Le chemin du fichier photo.
     * @param longitude La longitude de la photo.
     * @param latitude La latitude de la photo.
     */
    Photo(std::string nomPhoto, std::string cheminPhoto, double longitude, double latitude) : Base(nomPhoto, cheminPhoto) {
        this->longitude = longitude;
        this->latitude = latitude;
    }

    /**
     * @brief Destructeur de la classe Photo.
     */
    ~Photo() {
        std::cout << "Cette photo est détruite : " << this->getNomFichier() << std::endl;
    }

    /**
     * @brief Obtient la longitude de la photo.
     * @return La longitude de la photo.
     */
    double getLongitude() const {
        return longitude;
    }

    /**
     * @brief Obtient la latitude de la photo.
     * @return La latitude de la photo.
     */
    double getLatitude() const {
        return latitude;
    }

    /**
     * @brief Modifie la longitude de la photo.
     * @param longitude La nouvelle longitude de la photo.
     */
    void setLongitude(double longitude) {
        if (longitude > 0) {
            this->longitude = longitude;
        } else {
            this->longitude = 0;
        }
    }

    /**
     * @brief Modifie la latitude de la photo.
     * @param latitude La nouvelle latitude de la photo.
     */
    void setLatitude(double latitude) {
        if (latitude > 0) {
            this->latitude = latitude;
        } else {
            this->latitude = 0;
        }
    }

    /**
     * @brief Affiche les détails de la photo dans un flux de sortie.
     * @param sortie Le flux de sortie où afficher les détails.
     */
    void affichage(std::ostream &sortie) {
        Base::affichage(sortie);
        sortie << "Latitude : " << this->latitude << " | Longitude : " << this->longitude << std::endl;
    }

    /**
     * @brief Méthode pour ouvrir la photo avec ImageJ.
     * @details Cette méthode utilise ImageJ pour ouvrir et afficher la photo.
     */
    void jouer() const {
        std::string command = "imagej " + this->getCheminFichier() + " &";
        system(command.data());
    }

};

/**
 * @brief Alias pour std::shared_ptr<Photo>.
 */
typedef std::shared_ptr<Photo> PhotoPtr;

#endif
