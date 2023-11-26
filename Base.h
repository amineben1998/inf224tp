#ifndef BASE_H
#define BASE_H

#include<iostream>
#include<string>
#include<memory>

/**
 * @brief Classe de base pour la gestion des fichiers multimédias.
 * 
 * Cette classe fournit des fonctionnalités de base pour les fichiers multimédias tels que les photos et les vidéos.
 */
class Base {
   
    private:
        std::string nomFichier; ///< Nom du fichier multimédia.
        std::string cheminFichier; ///< Chemin du fichier multimédia.

    public:

        /**
         * @brief Constructeur par défaut de la classe Base.
         */
        Base();

        /**
         * @brief Constructeur prenant un nom de fichier et un chemin.
         * @param nomFichier Le nom du fichier multimédia.
         * @param cheminFichier Le chemin du fichier multimédia.
         */
        Base(std::string nomFichier, std::string cheminFichier);

        /**
         * @brief Destructeur virtuel de la classe Base.
         */
        virtual ~Base();

        /**
         * @brief Obtient le nom du fichier multimédia.
         * @return Le nom du fichier.
         */
        std::string getNomFichier() const;

        /**
         * @brief Obtient le chemin du fichier multimédia.
         * @return Le chemin du fichier.
         */
        std::string getCheminFichier() const;

        /**
         * @brief Modifie le nom du fichier multimédia.
         * @param nomFichier Le nouveau nom du fichier.
         */
        void setNomFichier(std::string nomFichier);

        /**
         * @brief Modifie le chemin du fichier multimédia.
         * @param cheminFichier Le nouveau chemin du fichier.
         */
        void setCheminFichier(std::string cheminFichier);

        /**
         * @brief Affiche les détails du fichier multimédia dans un flux de sortie.
         * @param sortie Le flux de sortie où afficher les détails.
         * @details Cette méthode doit être redéfinie dans les classes dérivées pour afficher les détails spécifiques du fichier multimédia.
         */
        virtual void affichage(std::ostream& sortie) const;

        /**
         * @brief Méthode pure virtuelle pour jouer le fichier multimédia.
         * @details Cette méthode doit être implémentée dans les classes dérivées pour permettre la lecture spécifique du fichier multimédia.
         */
        virtual void jouer() const = 0;
};

/**
 * @brief Alias pour std::shared_ptr<Base>.
 */
typedef std::shared_ptr<Base> BasePtr;

#endif
