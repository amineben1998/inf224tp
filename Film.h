#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <memory>

/**
 * @brief Classe représentant un film.
 * 
 * Cette classe hérite de la classe Video pour fournir des fonctionnalités spécifiques aux films.
 */
class Film : public Video {
private:
    int *tableau = nullptr; ///< Tableau des chapitres du film.
    int nombreChapitre;     ///< Nombre de chapitres du film.

public:
    /**
     * @brief Constructeur par défaut de la classe Film.
     */
    Film();

    /**
     * @brief Constructeur prenant un nom de film, un chemin, une durée et un nombre de chapitres pour le film.
     * @param nomFilm Le nom du fichier film.
     * @param cheminFilm Le chemin du fichier film.
     * @param duree La durée du film.
     * @param nombreChapitre Le nombre de chapitres du film.
     */
    Film(std::string nomFilm, std::string cheminFilm, int duree, int nombreChapitre);

    /**
     * @brief Constructeur de copie de la classe Film.
     */
    Film(const Film &from);

    /**
     * @brief Redéfinition de l'opérateur = pour la classe Film.
     */
    Film &operator=(const Film &from);

    /**
     * @brief Destructeur de la classe Film.
     */
    ~Film();

    /**
     * @brief Obtient le tableau des chapitres du film.
     * @return Un pointeur constant vers le tableau des chapitres.
     */
    int const *getTableau() const;

    /**
     * @brief Obtient le nombre de chapitres du film.
     * @return Le nombre de chapitres du film.
     */
    int getNombreChapitre() const;

    /**
     * @brief Modifie le tableau des chapitres du film.
     * @param tableau Le nouveau tableau des chapitres.
     * @param nombreChapitre Le nouveau nombre de chapitres.
     */
    void setTableau(int const *tableau, int nombreChapitre);

    /**
     * @brief Affiche les détails du film dans un flux de sortie.
     * @param s Le flux de sortie où afficher les détails.
     */
    void affichage(std::ostream &s) const override;
};

/**
 * @brief Alias pour std::shared_ptr<Film>.
 */
typedef std::shared_ptr<Film> FilmPtr;

#endif
