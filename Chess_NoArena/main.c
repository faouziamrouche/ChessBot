#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Board.h"
#include "initialisation.c"
#include "affichage.c"
#include "deplacement.c"
#include "estimation.c"
#include "MinMax.c"

int main()
{
    int choix;
    configuration board;

    MODE:
        printf("Veuillez-vous choisisé le mode du jeu:\n\t1- Homme - Homme\n\t2- Homme - Machine\nVotre chiox: ");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1:
                init(&board);
                affich(board);
                while(true)
                {
                    board = deplacementManuele(board);
                    affich(board);
                }
            break;
            case 2:
                MachineIA();
            break;
            default :
                goto MODE;
            break;
        }

    return 0;
}
