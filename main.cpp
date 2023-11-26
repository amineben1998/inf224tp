//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include<memory>
#include "Base.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Groupe.h"
#include "Gestionaire.h"
#include <sstream>
#include "tcpserver.h"

using namespace std;


//int main(int argc, const char* argv[])
//{
    
    /**
    Video *b1 = new Video("amine",":Lenovo",125);
    Video *b2=new Video("yassine",":Lenovo",125);
    Photo *b3 = new Photo("yassine", "D:\\donnes-perso\\telecoms-paris\\premiere-periode\\inf224\\learning\\tpexam\\Multimedia/docker-logo", 125.5, 125.5);
    b2->affichage(std::cout);
    b1->affichage(std::cout);
    b3->affichage(std::cout);
    std::cout<< b1->getCheminFichier()<< std::endl;
    std::cout<< b1->getCheminVideo();
    b3->jouer();**/

   /**
    int i=0;
    Base ** multimedias= new Base* [10];
    multimedias[i++]= new Video("amine",":Lenovo",125);
    multimedias[i++]=new Video("yassine",":Lenovo",125);
    multimedias[i++]=new Photo("docker-logo","C:/Users/LeNoVo/Multimedia/docker-logo.png", 125.5, 125.5);
    multimedias[i++]=new Film("yassine",":Lenovo",125,10);
    for(int j=0 ;j<4;j++){
        multimedias[j]->affichage(std::cout);
    }

  
    Film* film = new Film("vid1.mp4","vid1.mp4",10,10);
    int chapiters[3]={1,2,3};
    film->setTableau(chapiters,3);

    Film film2 = *film;
    int new_chapiters[3]={4,5,6};
    film2.setTableau(new_chapiters,3);
    film2.setNomFichier("vid2.mp4");
    film->affichage(cout);
    film2.affichage(cout);


    film->affichage(cout);
    Film film3(*film);
    film3.setTableau(new_chapiters,3);
    film3.affichage(cout);
    film->affichage(cout);*/


    //test question 8 et 9 avec la declaration de nouveau types grace a typedef std::shared_ptr<Truc> TrucPtr;
   /* Groupe*group1 = new Groupe("premier groupe");
    Groupe *group2 = new Groupe("deuxieme groupe");

    shared_ptr<Base> Photo1(new Photo("docker-logo", "docker-logo.png", 20, 15));
    shared_ptr<Base> Video1(new Video("tennis", "Multimedia/tennis.mp4", 50));
    shared_ptr<Base> Video2(new Video("soccer", "Multimedia/soccer.mp4", 50));

    group1->push_back(Video1);
    group1->push_back(Photo1);
    group1->push_back(Video2);
    group2->push_back(Video2);
    group2->push_back(Photo1);

    group1->affichage(cout);
    group2->affichage(cout);
    //suppression des derniers elements de group1 et group2
    group1->pop_back();
    group2->pop_back();

    //Affichge apres la suppression des elements
    group1->affichage(cout);
    group2->affichage(cout);

    delete group1;
    delete group2;
      

     VideoPtr video3(new Video("soccer", "Multimedia/soccer.mp4", 50));
     PhotoPtr Photo3(new Photo("docker-logo", "docker-logo.png", 20, 15));
     video3->affichage(cout);
     Photo3->affichage(cout);*/

/*
    Gestionaire *gestionaire = new Gestionaire();
    PhotoPtr photo1(gestionaire->creerPhoto("docker-logo", "Multimedia/docker-logo.png", 20, 15));
    VideoPtr video1(gestionaire->creerVideo("soccer", "Multimedia/soccer.mp4", 50));
    GroupePtr groupe1(gestionaire->creerGroupe("Gallerie personnelle"));
   groupe1->push_back(photo1);
   groupe1->push_back(video1);
   gestionaire->affichageBase(cout,"docker-logo");
   gestionaire->affichageBase(cout,"soccer");
   gestionaire->affichageBase(cout,"tennis");
   gestionaire->affichageGroupe(cout,"Gallerie personnelle");
   gestionaire->supprimerObjet("soccer"); 
   gestionaire->affichageGroupe(cout,"Gallerie personnelle");
   gestionaire->jouer("docker-logo.png");

    
    return 0;
};

*/


int main(int argc, const char* argv[])
{
   Gestionaire *gestionaire = new Gestionaire();
   PhotoPtr photo1(gestionaire->creerPhoto("docker-logo", "Multimedia/docker-logo.png", 20, 15));
   VideoPtr video1(gestionaire->creerVideo("soccer", "Multimedia/soccer.mp4", 50));
   GroupePtr groupe1(gestionaire->creerGroupe("Gallerie personnelle"));
   groupe1->push_back(photo1);
   groupe1->push_back(video1);
   gestionaire->affichageBase(cout,"docker-logo");
   gestionaire->affichageBase(cout,"soccer");
   gestionaire->affichageBase(cout,"tennis");
   gestionaire->affichageGroupe(cout,"Gallerie personnelle");
    
};
