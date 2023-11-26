#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include "tcpserver.h"
#include "Gestionaire.h"

const int PORT = 3331;
const std::string media_path = "./media/";

Gestionaire *gestionaire = new Gestionaire();
PhotoPtr photo1(gestionaire->creerPhoto("docker-logo", "Multimedia/docker-logo.png", 20, 15));
VideoPtr video1(gestionaire->creerVideo("soccer", "Multimedia/soccer.mp4", 50));
GroupePtr groupe1(gestionaire->creerGroupe("Gallerie personnelle"));

int main(int argc, char* argv[]) {
  // Création du serveur TCP
  auto* server = new TCPServer([&](std::string const& request, std::string& response) {
    // Protocole :
    // SEARCH name | Pour trouver le multimédia
    // PLAYBACK name | Pour le jouer
    // Requête envoyée par le client au serveur

    std::cout << "request: " << request << std::endl;
    std::stringstream ss;
    std::istringstream iss(request);
    std::string command;
    iss >> command;

    if (command == "CHERCHER") {
      std::string name;
      iss >> name;
      std::string line;
      gestionaire->affichageBase(ss, name); 
      while (std::getline(ss, line)) {
        response += line;
        response += ";";
      }
    } else if (command == "LANCER") {
      std::string name;
      iss >> name;
      gestionaire->lancer(name);
    }
    else if (command=="SUPPRIMER"){std::string name;
      iss >> name;
      gestionaire->supprimerBase(name);
    }

    return true;
  });

  // Lancement du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;
  int status = server->run(PORT);

  // Gestion des erreurs
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}