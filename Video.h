#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include "Base.h"

/**
 * @brief Classe représentant un fichier vidéo.
 * 
 * Cette classe hérite de la classe Base pour fournir des fonctionnalités spécifiques aux fichiers vidéo.
 */
class Video : public Base {
private:
    int duree{}; ///< Durée de la vidéo en secondes.

public:

    /**
     * @brief Constructeur par défaut de la classe Video.
     */
    Video() : Base() {}

    /**
     * @brief Constructeur prenant un nom de fichier, un chemin et une durée pour la vidéo.
     * @param nomFichier Le nom du fichier vidéo.
     * @param cheminFichier Le chemin du fichier vidéo.
     * @param duree La durée de la vidéo en secondes.
     */
    Video(std::string nomFichier, std::string cheminFichier, int duree) : Base(nomFichier, cheminFichier) {
        this->duree = duree;
    }

    /**
     * @brief Destructeur de la classe Video.
     */
    ~Video() {
        std::cout << "Cette vidéo est détruite : " << this->getNomVideo() << std :: endl;
    }

    /**
     * @brief Obtient la durée de la vidéo.
     * @return La durée de la vidéo en secondes.
     */
    int getDureeVideo() const {
        return duree;
    }

    /**
     * @brief Modifie la durée de la vidéo.
     * @param duree La nouvelle durée de la vidéo en secondes.
     */
    void setDureeVideo(int duree) {
        if (duree > 0) {
            this->duree = duree;
        } else {
            this->duree = 0;
        }
    }

    /**
     * @brief Modifie le nom de la vidéo.
     * @param nomVideo Le nouveau nom de la vidéo.
     */
    void setNomVideo(std::string nomVideo) {
        Base::setNomFichier(nomVideo);
    }

    /**
     * @brief Modifie le chemin de la vidéo.
     * @param cheminVideo Le nouveau chemin de la vidéo.
     */
    void setCheminVideo(std::string cheminVideo) {
        Base::setCheminFichier(cheminVideo);
    }

    /**
     * @brief Obtient le nom de la vidéo.
     * @return Le nom de la vidéo.
     */
    std::string getNomVideo() const {
        return Base::getNomFichier();
    }

    /**
     * @brief Obtient le chemin de la vidéo.
     * @return Le chemin de la vidéo.
     */
    std::string getCheminVideo() const {
        return Base::getCheminFichier();
    }

    /**
     * @brief Affiche les détails de la vidéo dans un flux de sortie.
     * @param sortie Le flux de sortie où afficher les détails.
     */
    void affichage(std::ostream &sortie) const {
        Base::affichage(sortie);
        sortie << " La durée est " << this->duree << " secondes." << std::endl;
    }

    /**
     * @brief Méthode pour jouer la vidéo.
     * @details Cette méthode utilise le lecteur mpv pour jouer la vidéo.
     */
    void jouer() const {
        std::string chemin = this->getCheminFichier();
        
        std::ifstream file(chemin);
        if (!file) {
            std::cerr << "Échec d'ouverture du fichier : " << chemin << std::endl;
            return;
        }
        
        std::string resultante = "mpv " + chemin + "&";
        system(resultante.data());
    }
};

/**
 * @brief Alias pour std::shared_ptr<Video>.
 */
typedef std::shared_ptr<Video> VideoPtr;

#endif
