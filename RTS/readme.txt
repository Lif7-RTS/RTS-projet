Panique à la mine
====Description====
Panique à la mine est un RTS qui fait s'opposer des nains et des blobs, 
controlez soit des nains, soit des blobs et combattez leur ennemi
avec comme objectifs principale de détruire leur batiment principale.

====Pré-requis=====
Ce logiciel nécéssite les bibliothèques: SDL, SDL_Image, SDL_TTF pour
fonctionner

====Arborescence===
bin/ -> dossier contenant le jeu compilé.
bin/data/ -> contient les fichiers ressources nécessaire au jeu
bin/regression/ -> contient le test de regression compilé
doc/ -> contient la doc (en html), Diagrammes des modules, 
	guide d'utilisation et présentation powerpoint du jeu.
src/ -> fichiers source du projet
lib/ -> librairies nécessaires à la compilation du projet
include -> contient les includes des bibliothèques nécessaires a la 
	compilation du projet  
====Compilation====	
make all & default -> compile le jeu et les tests de regressions
make jeu ->  compile seulement le jeu
make regression -> compile tests de regressions
make clean -> supprime obj/*.o et bin/PaniqueAlaMine.exe et bin/regression/test.exe

====Attention ===

Test de regression bancale == bloque forcément  a la création UniteBase...

====Auteurs====
Adrien Baud & Diego Roussel 
Dans le cadre de l'UE de LIF7, Université Lyon 1, 2014-2015.