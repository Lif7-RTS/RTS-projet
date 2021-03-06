#include <SDL2/SDL.h>
#include <stdio.h>
#include "jeu.h"
#include "define.h"
#include <time.h>

int main(int argc, char** argv)
{
     int i,j=0;
     clock_t tempo;
     float temps;
     int test=0;

     printf("Test sur chargement de la carte :");
     Terrain* terTest = (Terrain*)malloc(sizeof(Terrain));
     initTerrain(terTest, "./data/carte_Regre.txt");
     for(i=0;i<getTailleX(terTest);i++)
     {
          for(j=0; j<getTailleY(terTest); j++)
          {
               if(i==1 && j==0)
               {
                    if(getPierreCase(getCase(terTest, i, j)) <= 0)
                       test++;
               }
               else if(i==0 && j==1)
               {
                    if(getMithrilCase(getCase(terTest, i, j)) <= 0)
                       test++;
               }
               else
               {
                    if(getContenu(getCase(terTest, i, j)) != 0 && getAcces(getCase(terTest, i, j)) != 1)
                         test++;
               }
          }
     }

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test sur creation d'un joueur :");
     test=0;
     Joueur* joueTest=(Joueur*) malloc(sizeof(Joueur));
     initJoueur(joueTest, 1, 1, 1, 1);
     if(getIdJoueur(joueTest)!=1)
          test++;
     if(getPierreJoueur(joueTest) != 75)
          test++;
     if(getMithrilJoueur(joueTest) != 50)
          test++;
     if(getIdRace(joueTest) != 1)
          test++;
     if(getNourritureMax(joueTest) != 10)
          test++;
     if(getNourritureCourante(joueTest) != 1)
          test++;
     if(getCameraX(joueTest) != 1)
          test++;
     if(getCameraY(joueTest) != 1)
          test++;
     if(getBatConstruction(joueTest) != NULL)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test sur chargement BatBase :");
     test=0;
     BatBase* batBaseTest;
     batBaseTest = chargementBatBase();

     if(batBaseTest[1].nomBat[0] != 't' || batBaseTest[1].nomBat[1] != 'o')
          test++;
     if(getTileBat(&batBaseTest[1]) != 12)
          test++;
     if(getVieMaxBat(&batBaseTest[1]) != 100)
          test++;
     if(getTempsConstruct(&batBaseTest[1]) != 100)
          test++;
     if(getTailleCaseX(&batBaseTest[1]) != 2)
          test++;
     if(getTailleCaseY(&batBaseTest[1]) != 2)
          test++;
     if(batBaseTest[1].tabUnitFormable[0] != 0 || batBaseTest[1].tabUnitFormable[1] != 1)
          test++;
     if(getNbUniteFormable(&batBaseTest[1]) != 2)
          test++;
     if(getCoutPierreBat(&batBaseTest[1]) != 100)
          test++;
     if(getCoutMithrilBat(&batBaseTest[1]) != 100)
          test++;
     if(getRaceBat(&batBaseTest[1]) != 0)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test initialisation Batiment :");
     test=0;
     Batiment* batTest = (Batiment*) malloc(sizeof(Batiment));
     initBatiment(batTest, 1, &batBaseTest[1], 0, 1);
     setPosXBat(batTest, 4);
     setPosYBat(batTest, 4);

     if(getIdBat(batTest) != 1)
          test++;
     if(getTypeBat(batTest) == NULL)
          test++;
     if(getVieCouranteBat(batTest) != getVieMaxBat(&batBaseTest[1]))
          test++;
     if(getEnConstruction(batTest) != 0)
          test++;
     if(regardeTeteFile(getTabAttente(batTest)) != NULL)
          test ++;
     if(getPosXBat(batTest) != 4)
          test++;
     if(getPosYBat(batTest) != 4)
          test++;
     if(getTimerBat(batTest) == -1)
          test++;
     if(getIdJoueurBat(batTest) != 1)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test initialisation de la structure UniteBase :");
     test=0;
     UniteBase* uniteBaseTest;
     uniteBaseTest = chargementUniteBase();
     if(getVieMaxUnite(&uniteBaseTest[1]) != 600)
          test++;
     if(getAttaque(&uniteBaseTest[1]) != 70)
          test++;
     if(uniteBaseTest[1].nom[0] != 'r' || uniteBaseTest[1].nom[1] != 'i')
          test++;
     if(getOuvrier(&uniteBaseTest[1]) != 1)
          test++;
     if(getTempsFormation(&uniteBaseTest[1]) != 5)
          test++;
     if(getVitesseAttaque(&uniteBaseTest[1]) != 900)
          test++;
     if(getRessourceMax(&uniteBaseTest[1]) != 500)
          test++;
     if(getTileUnite(&uniteBaseTest[1]) != 13)
          test++;
     if(getVitesse(&uniteBaseTest[1]) !=200)
          test++;
     if(getCoutPierreBat(&uniteBaseTest[1]) != 100)
          test++;
     if(getCoutMithrilBat(&uniteBaseTest[1]) != 50)
          test++;
     if(getPorteeUnite(&uniteBaseTest[1]) != 3)
          test++;
     if(getRaceBat(&uniteBaseTest[1]) != 0)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test initialisation Unite :");
     Unite* uniteTest = (Unite*)malloc(sizeof(Unite));
     initUnite(uniteTest, &uniteBaseTest[1], 1);
     setId(uniteTest, 1);
     setPosX(uniteTest, 2);
     setPosY(uniteTest, 0);
     if(getId(uniteTest) != 1)
          test++;
     if(getIdJoueurUnite(uniteTest) != 1)
          test++;
     if(getPosX(uniteTest) != 2 || getPosY(uniteTest) !=0)
          test++;
     if(getVieCouranteUnite(uniteTest) != getVieMaxUnite(&uniteBaseTest[2]))
          test++;
     if(getDeplacement(uniteTest) != 0)
          test++;
     if(getTypeUnite(uniteTest) == NULL)
          test++;
     if(getEnTravail(uniteTest) != -1)
          test++;
     if(getPierrePorte(uniteTest) !=0 || getMithrilPorte(uniteTest) != 0)
          test++;
     if(getChemin(uniteTest) == NULL)
          test++;
     if(getTimerUnite(uniteTest) == -1)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test initialisation Jeu :");
     test=0;
     Jeu* jeuTest=(Jeu*) malloc(sizeof(Jeu));
     printf("\nLes erreurs sur Affichage sont :\n");
     commencerPartie(jeuTest);
     setNbJoueur(jeuTest,1);
     jeuTest->tableauJoueur=&joueTest;
     setCarteJeu(jeuTest,terTest);
     ajouterTabDyn(getTabUnite(jeuTest), &uniteTest);
     ajouterTabDyn(getTabBat(jeuTest), &batTest);
     jeuTest->tabBatConstructible=batBaseTest;
     jeuTest->tabUniteFormable=uniteBaseTest;
     setVueJoueur(jeuTest, 1);
     setIdSel(jeuTest,NULL);
     printf("Initialisation Jeu : okay! \n");

     printf("Test sauvegarde :");
     sauvegarder(jeuTest, 1);
     printf("sauvegarde faite!\n");

     printf("Test detruir Partie :");
     detruirePartie(jeuTest);
     printf("destruction faite!\n");

     printf("Test charger Partie :");
     charger(jeuTest, 1);
     printf("chargement fait! \n");

     printf("Verif sauvegarde + chargement : ");
     if(getNbJoueur(jeuTest) != 1)
          test++;
     if(getCarteJeu(jeuTest) != terTest)
          test++;
     if(jeuTest->tabBatConstructible != batBaseTest)
          test++;
     if(jeuTest->tabBatConstructible != batBaseTest)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test des fonctions de deplacement d'unit� :");
     test=0;
     setPosX(uniteTest, 4);
     setPosY(uniteTest, 4);
     setPosCibleX(uniteTest, 0);
     setPosCibleY(uniteTest, 0);
     deplacementUnite(uniteTest, terTest);
     if(getPosX(uniteTest) !=4 || getPosY(uniteTest) != 4)
          test++;

     setPosCibleX(uniteTest, 1);
     setPosCibleY(uniteTest, 1);
     deplacementUnite(uniteTest, terTest);
     if(getPosX(uniteTest) ==4 || getPosY(uniteTest) == 4)
          test++;
     if(getPosX(uniteTest) != getPosCibleX(uniteTest) || getPosY(uniteTest) != getPosCibleY(uniteTest))
          test++;
     if(getContenu(getCase(terTest, 1, 1)) != getId(uniteTest))
          test++;

     setPosCibleX(uniteTest, 1);
     setPosCibleY(uniteTest, 0);
     deplacementUnite(uniteTest, terTest);
     if(getPosX(uniteTest) ==4 || getPosY(uniteTest) == 4)
          test++;
     if(getPosX(uniteTest) != getPosCibleX(uniteTest) || getPosY(uniteTest) != getPosCibleY(uniteTest))
          test++;
     if(getContenu(getCase(terTest, getPosCibleX(uniteTest), getPosCibleY(uniteTest))) != getId(uniteTest))
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test des fonctions de r�colte des Unit�s :");
     test=0;
     tempo=clock();
     if(tempo == -1)
     {
          printf("\n erreur d'horloge processeur");
          return -1;
     }
     temps=0;
     while(temps<2)
     {
          temps= ((float) clock()-(float)tempo)/CLOCKS_PER_SEC;
          recolte(uniteTest, jeuTest);
     }
     if(getPierrePorte(uniteTest)==0 && getMithrilPorte(uniteTest)==0)
          test++;

     trouverMinerai(uniteTest, jeuTest);
     if(getPosMineraiX(uniteTest) != 0 || getPosMineraiY(uniteTest)!= 1)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

    printf("Test de la fonction ajouterFileBat : ");
     ajouterFileBat(batTest, jeuTest, 1);
     if(regardeTeteFile(getTabAttente(batTest)) != getUniteFormable(jeuTest,i))
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test de la fonction VerifierTimerBat : ");
     test=0;
     tempo=clock();
     if(tempo == -1)
     {
          printf("\n erreur d'horloge processeur");
          return -1;
     }
     temps=0;
     while(temps<10)
     {
          temps= ((float) clock()-(float)tempo)/CLOCKS_PER_SEC;
          verifierTimerBat(batTest, jeuTest);
     }
     if(regardeTeteFile(getTabAttente(batTest)) != NULL)
          test++;

     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }

     printf("Test des destruction :");
     test=0;
     detruireJeu(jeuTest);
     if(jeuTest != NULL)
          test++;
     if(test != 0)
     {
          printf("erreur\n");
          return test;
     }
     else
     {
          printf("okay!\n");
     }


     printf("Tests de regression termin�s, tout est OK.");
     return 0;
}
