#include "Board.h"

void affich(configuration conf ) /// Afficher l'echequier
{
	int i, j, k;
	printf("\t");
	for (i=0;  i<8; i++)
		printf("   %c  ", i+'a');

    printf("\n");
    printf("\n");

    printf("\t|-----");
	for (i=0;  i<6; i++)
		printf("|-----");
    printf("|-----|");

    printf("\n");



	for(i=8; i>0; i--)  {
		printf("    %d   ", i);

        for (j=0; j<8; j++)

            if ( conf.board[i-1][j] < 0 )
                printf("| %cn  ", -conf.board[i-1][j]);
            else if ( conf.board[i-1][j] > 0 )
                printf("| %cb  ", conf.board[i-1][j]);
            else
                //printf("|     ");
                printf("| %c   ", conf.board[i-1][j]);

            printf("|   %d\n", i);

            printf("\t|-----");
            for (k=0;  k<6; k++)
                printf("|-----");
            printf("|-----|");

            printf("\n");
	}

	printf("\n\t");

	for (i=0;  i<8; i++)
		printf("   %c  ", i+'a');

    printf("\n");

}
