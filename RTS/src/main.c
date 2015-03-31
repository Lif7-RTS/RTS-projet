#include <stdlib.h>
#include <stdio.h>
#include "unite.h"
#include "uniteBase.h"
#include "case.h"

int main(){
    sCase* c;
    c = (sCase*) malloc(sizeof(sCase));
    initCase(c, 10,10,1);
    free(c);
    return 1;
}
