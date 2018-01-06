#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include "Board.h"
#include "initialisation.c"
#include "affichage.c"
#include "deplacement.c"
//#include "Menacer.c"
#include "estimation.c"
#define MAX 1
#define MIN -1
#define INFINI 10000
#define LIGHT			0
#define DARK			1
#define EMPTY			6

void copier( struct configuration *c1, struct configuration *c2 ) /// Copier la configuration c1 dans c2
{
	int i, j;

	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
			c2->board[i][j] = c1->board[i][j];
	for(i=0;i<4;i++)
        c2->roque[i] = c1->roque[i];
	c2->turn = c1->turn;
	c2->val = c1->val;
}

int parse_move(char *s)
{
	int from, to, i;

	if (s[0] < 'a' || s[0] > 'h' ||
			s[1] < '0' || s[1] > '9' ||
			s[2] < 'a' || s[2] > 'h' ||
			s[3] < '0' || s[3] > '9')
		return -1;
    else return 1;
}

void getCMD(configuration board1, configuration board2,char *x1,char *y1,char *x2,char *y2,char *z) ///
{
    int i, j, x, y;
    bool get = false;

    if((board1.board[0][0] == 'T') && (board1.board[0][4] == 'R') && (board2.board[0][0] == 0) && (board2.board[0][4] == 0))
    {
        *x1 = 'e';
        *y1 = '1';
        *x2 = 'c';
        *y2 = '1';
        get = true;
    }
    if((board1.board[7][0] == -'T') && (board1.board[7][4] == -'R') && (board2.board[7][0] == 0) && (board2.board[7][4] == 0))
    {
        *x1 = 'e';
        *y1 = '8';
        *x2 = 'c';
        *y2 = '8';
        get = true;
    }
    if((board1.board[0][7] == 'T') && (board1.board[0][4] == 'R') && (board2.board[0][7] == 0) && (board2.board[0][4] == 0))
    {
        *x1 = 'e';
        *y1 = '1';
        *x2 = 'g';
        *y2 = '1';
        get = true;
    }
    if((board1.board[7][7] == -'T') && (board1.board[7][4] == -'R') && (board2.board[7][7] == 0) && (board2.board[7][4] == 0))
    {
        *x1 = 'e';
        *y1 = '8';
        *x2 = 'g';
        *y2 = '8';
        get = true;
    }
    if(!get)
    {
        for(i = 0 ; i <= 7 ; i++)
        {
            for(j = 0 ; j <= 7 ; j++)
            {
                if((board1.board[i][j] != 0) && (board2.board[i][j] == 0))
                {
                    x = i;
                    y = j;
                    *y1 = i + '1';
                    *x1 = j + 'a';
                }
            }
        }
        for(i = 0 ; i <= 7 ; i++)
        {
            for(j = 0 ; j <= 7 ; j++)
            {
                if((board1.board[i][j] != board2.board[i][j]) && ((x != i) || (y != j)))
                {
                    *y2 = i + '1';
                    *x2 = j + 'a';
                }
            }
        }
        //printf("1 %c , 2 %c ,3 %c,4 %c \n");
    }
    *z=NULL;
            for(j = 0 ; j <= 7 ; j++)
            {
                if(board1.board[1][j]==-'P' ){
                    switch(board2.board[0][j]){
                        case -'T' : *z = 'T';
                            break;
                        case -'C' : *z = 'C';
                            break;
                        case -'F' : *z = 'F';
                            break;
                        case -'D' : *z = 'D';
                            break;
                    }

                }

                if(board1.board[6][j]=='P'){
                    switch(board2.board[7][j]){
                        case 'T' : *z = 'T';
                            break;
                        case 'C' : *z = 'C';
                            break;
                        case 'F' : *z = 'F';
                            break;
                        case 'D' : *z = 'D';
                            break;
                    }

                }
            }
}

int egal(char c1[8][8], char c2[8][8] ) /// Teste si les conf c1 et c2 sont égales
{
	int i, j;

	for (i=0; i<8; i++)
		for (j=0; j<8; j++)
			if (c1[i][j] != c2[i][j]) return 0;
	return 1;
} // egal

/* Teste si conf représente une fin de partie et retourne dans 'cout' la valeur associée */
int feuille( struct configuration conf, int *cout )
{
	//int i, j, rbx, rnx, rby, rny;

	*cout = 0;
    int i=0,j=0,pasroiN=0,pasroiB=0;
    int p=0;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(conf.board[i][j]== 'R'){
               pasroiB=1;
            }
        }
    }
	// Si victoire pour les Blancs cout = +10000
	for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(conf.board[i][j]== -'R'){
               pasroiN=1;
            }
        }
    }
    if(!pasroiB) {
        *cout = -10000;
        return 1;
    }
    if(!pasroiN) {
        *cout = +10000;
        return 1;
    }
	// Sinon ce n'est pas une config feuille
	return 0;
}  // feuille

int minmax( struct configuration conf, int mode, int niv)
{
 	int n, i, score, score2;
 	struct configuration T[100];

   	if ( feuille(conf, &score) )
		return score;

   	if ( niv == 0 )
		return evaluation( conf );
    if ( mode == MAX ) {
            score = -INFINI;
   	}else{
            score = +INFINI;
    }
    if ( mode == MAX ) {
	   n = cout_possible( T, conf, MAX);
	   for ( i=0; i<n; i++ ) {
        score2 = minmax( T[i], MIN, niv-1);
		if (score2 > score) score = score2;
	   }
	}
	else  { // mode == MIN
	   n=cout_possible(T, conf, MIN);
	   for ( i=0; i<n; i++ ) {
   	    	score2 = minmax( T[i], MAX, niv-1);
		if (score2 < score) score = score2;
	   }
	}

    if ( score == +INFINI ) score = +10000;
    if ( score == -INFINI ) score = -10000;
	return score;
} /// sans alpha beta


int main()
{
    xboard();
    return 0;
}

void xboard() /// L'interface de comunication avec le logiciel ARENA
{
	int sx, dx, n, i, j, score, cout, cout2, hauteur;
    int computer_side;
    int choix=0;
    int xside,side;
    struct configuration T[100];
    char line[256], command[256];
    char cmd[5], str[5];
    int x1, y1, x2, y2,z;
    bool deplacer = false;
    // FILE *file;
    // file=fopen("C:\\Users\\Anis\\Desktop\\test.txt","w+");
    configuration board;
    signal(SIGINT, SIG_IGN);
    printf("\n");
    init(&board);
    int cpt,r;
    configuration tab_conf[100];
    hauteur=3;
    computer_side= DARK;
    int debut = 0;
	for (;;) {
		fflush(stdout);
		if (computer_side==DARK && debut == 1) {
            //printf("move b2b4\n");
			n=cout_possible( T, board, MIN );
            printf("thamer %d\n", n);
            score = +INFINI;
            j = -1;
            for (i=0; i<n; i++) {
                cout = minmax( T[i], MAX, hauteur);
                printf("estimation %d\n", cout);
                if ( cout < score ) {
                    score = cout;
                    j = i;
                }
            }
            if ( j != -1 ) {
                getCMD(board, T[j], &x1, &y1, &x2, &y2, &z);
                copier( &T[j], &board );
                board.val = score;
            }
			printf("move %c%c%c%c%c\n", x1,y1,x2,y2,z);
            computer_side=LIGHT;
			continue;
		}
		if (!fgets(line, 256, stdin))
			return;
		if (line[0] == '\n')
			continue;
		sscanf(line, "%s", command);
		if (!strcmp(command, "xboard"))
			continue;
		if (!strcmp(command, "new")) {
			init(&board);
            affich(board);
			computer_side = DARK;
			continue;
		}
		if (!strcmp(command, "quit"))
			return;
		if (!strcmp(command, "force")) {
			computer_side = EMPTY;
			continue;
		}
		if (!strcmp(command, "white")) {
			side = LIGHT;
			xside = DARK;
			computer_side = DARK;
			continue;
		}
		if (!strcmp(command, "black")) {
			side = DARK;
			xside = LIGHT;
			computer_side = LIGHT;
			continue;
		}
		if (!strcmp(command, "st")) {

			continue;
		}
		if (!strcmp(command, "sd")) {

			continue;
		}
		if (!strcmp(command, "time")) {

			continue;
		}
		if (!strcmp(command, "otim")) {
			continue;
		}
		if (!strcmp(command, "go")) {
			computer_side = DARK;
			continue;
		}
		if (!strcmp(command, "hint")) {

			continue;
		}
		if (!strcmp(command, "undo")) {

			continue;
		}
		if (!strcmp(command, "remove")) {

			continue;
		}
		if (!strcmp(command, "post")) {

			continue;
		}
		if (!strcmp(command, "nopost")) {

			continue;
		}
		if(parse_move(line)==1){
            sprintf(cmd, "%s",line);
           //printf("mehdi %c %c %c %c\n",cmd[0], cmd[1], cmd[2], cmd[3]);
                       if(strcmp(cmd, "0-0-0") == 0)
                {
                    deplacer = grandRock(&board);
                }
                else
                {
                    if(strcmp(cmd, "0-0") == 0)
                    {
                        deplacer = petitRock(&board);
                    }
                    else
                    {
                        x1 = cmd[1] - '1' + 1;
                        y1 = cmd[0] - 'a' + 1;
                        x2 = cmd[3] - '1' + 1;
                        y2 = cmd[2] - 'a' + 1;
                        deplacer = deplacerBlanc(&board, x1, y1, x2, y2);
                    }
                }
            debut = 1;
            affich(board);
            computer_side=DARK;
        }
	}
}
