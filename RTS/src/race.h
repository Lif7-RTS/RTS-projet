/**
* \file race.h
* \brief structure race
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 16/04/2015
* structure des races du jeu, contenant les specificites de chaque race
*/

struct SRace{
    int nourritureMax[2];
    int mithril[2];
    int pierre[2];
};
typedef struct SRace Race;

Race r = {{10,11},{50,75},{100,120}};
