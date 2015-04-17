/**
* \file race.h
* \brief structure race
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 16/04/2015
* structure des races du jeu, contenant les specificites de chaque race
*/
#ifndef _RACE
#define _RACE

typedef struct SRace Race;
struct SRace{
    int nourritureMax[2];
    int mithril[2];
    int pierre[2];
};


Race races = {{10,11},{50,75},{100,120}};

#endif /* _RACE */
