Panique à la mine
====Description====
Panique à la mine est un RTS qui se fait opposer des nains et des blobs, 
controlez soit des nains, soit des blobs et combattez leur ennemi
avec comme objectifs principale de détruire leur batiment principale.

====Pré-requis=====
Ce logiciel nécéssite les bibliothèques: SDL, SDL_Image, SDL_TTF pour
fonctionner

====Compilation====
pour compiler sous windows: utiliser le MakefileWin ( renommer le en Makefile)
pour compiler sous Linux: utiliser le MakefileLinux ( renommer le en Makefile)

	
make all & default -> compile le jeu et les tests de regressions
make jeu ->  compile seulement le jeu
make regression -> compile tests de regressions
make clean -> supprime obj/*.o et bin/PaniqueAlaMine.exe et bin/regression/test.exe

====Auteurs====
Adrien Baud & Diego Roussel 
Dans le cadre de l'UE de LIF7, Université Lyon 1, 2014-2015.