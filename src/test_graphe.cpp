#include "partie.hpp"
#include "melangeur.hpp"

#include <iostream>
#include <cstdlib>
#include <sstream>

int main() {

  //n'hésitez pas à ajouter vos propres tests

  //test de la fonction voisine
  std::cout << "=== positions voisines de {0,3} ===" << std::endl ;

  std::cout << "attendu : {-1,3}" << std::endl ;
  std::cout << voisine({0,3}, 0) << std::endl ;
  std::cout << "attendu : {0,4}" << std::endl ;
  std::cout << voisine({0,3}, 1) << std::endl ;
  std::cout << "attendu : {1,3}" << std::endl ;
  std::cout << voisine({0,3}, 2) << std::endl ;
  std::cout << "attendu : {0,2}" << std::endl ;
  std::cout << voisine({0,3}, 3) << std::endl ;

  //création d'un plateau
  Plateau p ;
  //spécification de la dimension du plateau
  p.ajouter({0,0}, {9,9}) ;

  //placement d'un arbre
  //le dernier paramètre est le numéro du joueur (inutile pour un arbre)
  p.amenager({1,1}, Amenagement::ARBRE, 0) ;

  //placement d'un producteur
  p.amenager({3,7}, Amenagement::PRODUCTEUR_AVOCAT, 0) ;

  //placement d'une boutique
  p.amenager({8,2}, Amenagement::BOUTIQUE_ECHALOTE, 1) ;

  //dessin du plateau dans la console
  std::cout << p << std::endl ;

  // Tests des tuiles spécifiques

  Position pos;
  pos = {1, 1};
  if (p.tuiles.find(pos) != p.tuiles.end()) {
    const Tuile& tuile = p.tuiles.at(pos);
    std::cout << "Tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
    std::cout << "Amenagement : " << nom_amenagement(tuile.amenagement) << std::endl;
    std::cout << "Joueur : " << tuile.joueur << std::endl;
  } 

  else {
    std::cout << "Aucune tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
  }

  pos = {3, 7};
  if (p.tuiles.find(pos) != p.tuiles.end()) {
    const Tuile& tuile = p.tuiles.at(pos);
    std::cout << "Tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
    std::cout << "Amenagement : " << nom_amenagement(tuile.amenagement) << std::endl;
    std::cout << "Joueur : " << tuile.joueur << std::endl;
  } 

  else {
    std::cout << "Aucune tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
  }

  pos = {8, 2};
  if (p.tuiles.find(pos) != p.tuiles.end()) {
    const Tuile& tuile = p.tuiles.at(pos);
    std::cout << "Tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
    std::cout << "Amenagement : " << nom_amenagement(tuile.amenagement) << std::endl;
    std::cout << "Joueur : " << tuile.joueur << std::endl;
  } 
    
  else {
    std::cout << "Aucune tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
  }

  pos = {0, 0};
  if (p.tuiles.find(pos) != p.tuiles.end()) {
    const Tuile& tuile = p.tuiles.at(pos);
    std::cout << "Tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
    std::cout << "Amenagement : " << nom_amenagement(tuile.amenagement) << std::endl;
    std::cout << "Joueur : " << tuile.joueur << std::endl;
  } 
    
  else {
    std::cout << "Aucune tuile trouvée à la position {" << pos.first << ", " << pos.second << "}" << std::endl;
  }
    

  //dessin du plateau dans une image
  //il est également possible d'écrire un fichier png
  //pour que ça fonctionne, il faut avoir librsvg-2.0
#ifndef NO_GRAPHICS
  p.dessiner("plateau.svg", 100) ;
#endif
  
  return 0 ;
}
