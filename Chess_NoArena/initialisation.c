#include "Board.h"

void init(  configuration *configuration ) /// Initialiser l'echequier: placer tous les pieces dans les positions qui coresponds
{
   	int i, j;

    	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
			configuration->board[i][j] = 0;	// Les cases vides sont initialisées avec 0

	configuration->board[0][0] =  'T'; // Le cas de la tour blanche
	configuration->board[0][1] =  'C'; // Le cas du cavalier blanc
	configuration->board[0][2] = 'F'; // Le cas du fou blanc
	configuration->board[0][3] =  'D'; // Le cas de la dame (reine) blanche
	configuration->board[0][4] =  'R'; // Le cas du roi blanc
	configuration->board[0][5] =  'F'; // Le cas du fou blanc
	configuration->board[0][6] = 'C'; // Le cas du cavalier blanc
	configuration->board[0][7] =  'T'; // Le cas de la tour blanche

	//configuration->board[0][4] =  'R';

	for (j=0; j<8; j++) {
		configuration->board[1][j] = 'P'; // Le cas du pion blanc
        configuration->board[6][j] = -'P'; // Le cas du pion noir
		configuration->board[7][j] = -configuration->board[0][j]; // Placer les pieces noires de façon symétrique au blanc
	}

	configuration->roque[0] = 0;
	configuration->roque[1] = 0;
	configuration->roque[2] = 0;
	configuration->roque[3] = 0;
	configuration->turn = 0;
	configuration->val = 0;

}

