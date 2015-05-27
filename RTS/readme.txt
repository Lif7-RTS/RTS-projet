Panique � la mine
====Description====
Panique � la mine est un RTS qui fait s'opposer des nains et des blobs, 
controlez soit des nains, soit des blobs et combattez leur ennemi
avec comme objectifs principale de d�truire leur batiment principale.

====Pr�-requis=====
Ce logiciel n�c�ssite les biblioth�ques: SDL, SDL_Image, SDL_TTF pour
fonctionner

====Arborescence===
bin/ -> dossier contenant le jeu compil�.
bin/data/ -> contient les fichiers ressources n�cessaire au jeu
bin/regression/ -> contient le test de regression compil�
doc/ -> contient la doc (en html), Diagrammes des modules, 
	guide d'utilisation et pr�sentation powerpoint du jeu.
src/ -> fichiers source du projet
lib/ -> librairies n�cessaires � la compilation du projet
include -> contient les includes des biblioth�ques n�cessaires a la 
	compilation du projet  
====Compilation====	
make all & default -> compile le jeu et les tests de regressions
make jeu ->  compile seulement le jeu
make regression -> compile tests de regressions
make clean -> supprime obj/*.o et bin/PaniqueAlaMine.exe et bin/regression/test.exe

====Attention ===

Test de regression bancale == bloque forc�ment  a la cr�ation UniteBase...

====Auteurs====
Adrien Baud & Diego Roussel 
Dans le cadre de l'UE de LIF7, Universit� Lyon 1, 2014-2015.