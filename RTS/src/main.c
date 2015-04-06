#include <stdlib.h>
#include <stdio.h>
#include "terrain.h"
#include "unite.h"
#include "uniteBase.h"
#include "case.h"

#include <curses.h>

int main(){
    Terrain* ter;
    char* ch;
    ch = (char*) malloc(sizeof(char)*2);
    int x,y;
    ter = (Terrain*) malloc(sizeof(Terrain));
    initTerrain(ter, "carte.txt");
    int tailleX = ter->tailleX;
    int tailleY = ter->tailleY;
    printf("%d %d", tailleX, tailleY);
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    raw();
    noecho();
    keypad(stdscr, TRUE);
    for(y = 0;y < tailleY; y++){
        for(x = 0; x < tailleX; x++){
            ch[0] = ter->tabCase[y*tailleX+x].acces + 65;
            ch[1] = '\0';
            if(ter->tabCase[y*tailleX+x].pierre > 0)
                attron(COLOR_PAIR(1));
            if(ter->tabCase[y*tailleX+x].mithril > 0)
                attron(COLOR_PAIR(2));
            mvprintw(y,x,ch);
            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
        }
    }
    refresh();
    getch();
    endwin();
    detruireTerrain(ter);
    free(ter);
}
