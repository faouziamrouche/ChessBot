#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

typedef struct configuration{
	char board[8][8];		// L'echiquier
	int val;			// Estimation de la configuration
	int turn;			// Le numero du tour de joueur, on l'incremente chaque fois qu'on joue
	int roque[4];           //roque[0] et roque[1] pour les blancs, roque[2] et roque[3] pour les noire
                            // Vau 0 si le roque est possible, -1 s'il est impossible, 1 s'il est effectuer
                            //roque[0] et roque[2] pour le petit roque
                            //roque[1] et roque[3] pour le grand roque
} configuration;


#endif // BOARD_H_INCLUDED
