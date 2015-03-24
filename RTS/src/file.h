/**
* \file file.h
* \brief structure file
* \author Adrien Baud & Diego Roussel
* \version 1.0
* \date 24/03/2015
*
*Structure representant une file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "uniteBase.h"
#ifndef _FILE
#define _FILE

struct SFile{

};
typedef struct SFile File;


void enfile(File* f,int element);
void defile(File* f);
void regardeTeteFile(File* f);

#endif /* _FILE */
