#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Board.h"

#define DEFAULT -1
#define DIAGONALE_POSITIVE_DROITE 0
#define DIAGONALE_POSITIVE_GAUCHE 1
#define DIAGONALE_NEGATIVE_GAUCHE 2
#define DIAGONALE_NEGATIVE_DROITE 3
#define HORIZENTAL_DROITE 4
#define HORIZENTAL_GAUCHE 5
#define VERTICAL_POSITIVE 6
#define VERTICAL_NEGATIVE 7
#define CAVALIER_HORIZENTAL_POSITIVE_POSITIVE 8
#define CAVALIER_HORIZENTAL_POSITIVE_NEGATIVE 9
#define CAVALIER_HORIZENTAL_NEGATIVE_POSITIVE 10
#define CAVALIER_HORIZENTAL_NEGATIVE_NEGATIVE 11
#define CAVALIER_VERTICAL_POSITIVE_POSITIVE 12
#define CAVALIER_VERTICAL_POSITIVE_NEGATIVE 13
#define CAVALIER_VERTICAL_NEGATIVE_POSITIVE 14
#define CAVALIER_VERTICAL_NEGATIVE_NEGATIVE 15




int mencer(configuration board, char piecesMenacante[20], int posPiecesMenacente[20][2], int *indiceCourant,int x, int y,char piece, int direction,int block,int *cpt){

    int boolean = 1, doIt = 0;

    if((x > 7 || x < 0) || (y > 7 || y < 0))
        return 0;
    else {
		//printf("piece %c\n",piece);
			if(((direction == HORIZENTAL_DROITE) ||
				(direction == HORIZENTAL_GAUCHE) ||
				(direction == VERTICAL_NEGATIVE) ||
				(direction == VERTICAL_POSITIVE))
				 &&
				((block && board.board[x][y] == 'T')  ||
				 (block && board.board[x][y] == -'T') ||
				 (block && board.board[x][y] == 'D')  ||
				 (block && board.board[x][y] == -'D') ||
				 ((*cpt == 1) && board.board[x][y] == 'R')  ||
				 ((*cpt == 1) && board.board[x][y] == -'R'))){
					 	doIt = 1;
					}



			if(((direction == DIAGONALE_POSITIVE_DROITE) ||
				(direction == DIAGONALE_POSITIVE_GAUCHE) ||
				(direction == DIAGONALE_NEGATIVE_GAUCHE) ||
				(direction == DIAGONALE_NEGATIVE_DROITE))
				 &&
				(
				 (block && board.board[x][y] == 'F')  ||
				 (block && board.board[x][y] == -'F') ||
				 (block && board.board[x][y] == 'D')  ||
				 (block && board.board[x][y] == -'D') ||
				 ((*cpt == 1) && board.board[x][y] == 'R')  ||
				 ((*cpt == 1) && board.board[x][y] == -'R')))
						doIt = 1;

			if(((direction == DIAGONALE_POSITIVE_DROITE) ||
				(direction == DIAGONALE_POSITIVE_GAUCHE))
				 &&
				(((*cpt == 1) && board.board[x][y] == -'P')))
						doIt = 1;

			if(((direction == DIAGONALE_NEGATIVE_GAUCHE) ||
				(direction == DIAGONALE_NEGATIVE_DROITE))
				 &&
				(((*cpt == 1) && board.board[x][y] == 'P')))
						doIt = 1;

						if(((direction == HORIZENTAL_DROITE) ||
				(direction == HORIZENTAL_GAUCHE) ||
				(direction == VERTICAL_NEGATIVE) ||
				(direction == VERTICAL_POSITIVE) ||
				(direction == DIAGONALE_POSITIVE_DROITE) ||
				(direction == DIAGONALE_POSITIVE_GAUCHE) ||
				(direction == DIAGONALE_NEGATIVE_GAUCHE) ||
				(direction == DIAGONALE_NEGATIVE_DROITE)) && (*cpt) > 0)
					if(board.board[x][y] != 0) block = 0;

       if(((direction == CAVALIER_HORIZENTAL_POSITIVE_POSITIVE) ||
           (direction == CAVALIER_HORIZENTAL_POSITIVE_NEGATIVE) ||
           (direction == CAVALIER_HORIZENTAL_NEGATIVE_POSITIVE) ||
           (direction == CAVALIER_HORIZENTAL_NEGATIVE_NEGATIVE) ||
           (direction == CAVALIER_VERTICAL_NEGATIVE_NEGATIVE)   ||
           (direction == CAVALIER_VERTICAL_POSITIVE_NEGATIVE)   ||
           (direction == CAVALIER_VERTICAL_NEGATIVE_POSITIVE)   ||
           (direction == CAVALIER_VERTICAL_POSITIVE_POSITIVE))
                          &&
           ((board.board[x][y] == 'C') ||
            (board.board[x][y] == -'C')))
                    doIt = 1;


        if(doIt && ((board.turn)%2) == 0 && board.board[x][y] < 0 && /*piece != (-board.board[x][y]) &&*/ (*cpt) != 0){
            piecesMenacante[*indiceCourant] = -board.board[x][y];
            posPiecesMenacente[*indiceCourant][0] = x;
            posPiecesMenacente[*indiceCourant][1] = y;
            (*indiceCourant)++;
            boolean = 0;
			if((board.board[x][y] == 'C') ||
            (board.board[x][y] == -'C')) block = 0;
        }else
            if(doIt && ((board.turn)%2) == 1 && board.board[x][y] > 0 && piece != board.board[x][y]){
                piecesMenacante[*indiceCourant] = board.board[x][y];
                posPiecesMenacente[*indiceCourant][0] = x;
                posPiecesMenacente[*indiceCourant][1] = y;
                (*indiceCourant)++;
                boolean = 0;
				if((board.board[x][y] == 'C') ||
				(board.board[x][y] == -'C')) block = 0;
            }
    }
	(*cpt)++;


        if (boolean){
            switch(direction){
                    case DIAGONALE_POSITIVE_DROITE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+1,y+1,piece,DIAGONALE_POSITIVE_DROITE,block,cpt);
                        break;

                    case DIAGONALE_POSITIVE_GAUCHE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+1,y-1,piece,DIAGONALE_POSITIVE_GAUCHE,block,cpt);
                        break;

                    case DIAGONALE_NEGATIVE_GAUCHE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-1,y-1,piece,DIAGONALE_NEGATIVE_GAUCHE,block,cpt);
                        break;

                    case DIAGONALE_NEGATIVE_DROITE:
						//printf("block %d\n",block);
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-1,y+1,piece,DIAGONALE_NEGATIVE_DROITE,block,cpt);
                        break;


                    case HORIZENTAL_DROITE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x,y+1,piece,HORIZENTAL_DROITE,block,cpt);
                        break;

                    case HORIZENTAL_GAUCHE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x,y-1,piece,HORIZENTAL_GAUCHE,block,cpt);
                        break;

                    case VERTICAL_POSITIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+1,y,piece,VERTICAL_POSITIVE,block,cpt);
                        break;

                    case VERTICAL_NEGATIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-1,y,piece,VERTICAL_NEGATIVE,block,cpt);
                        break;

                    case CAVALIER_HORIZENTAL_POSITIVE_POSITIVE:
						mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+1,y+2,piece,((*cpt) == 1)?CAVALIER_HORIZENTAL_POSITIVE_POSITIVE:DEFAULT ,block,cpt);
						break;

                    case CAVALIER_HORIZENTAL_POSITIVE_NEGATIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-1,y+2,piece,((*cpt) == 1)?CAVALIER_HORIZENTAL_POSITIVE_NEGATIVE:DEFAULT ,block,cpt);
						break;

                    case CAVALIER_HORIZENTAL_NEGATIVE_POSITIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+1,y-2,piece,((*cpt) == 1)?CAVALIER_HORIZENTAL_NEGATIVE_POSITIVE:DEFAULT,block,cpt);
						break;

                    case CAVALIER_HORIZENTAL_NEGATIVE_NEGATIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-1,y-2,piece,((*cpt) == 1)?CAVALIER_HORIZENTAL_NEGATIVE_NEGATIVE:DEFAULT,block,cpt);
						break;

                    case CAVALIER_VERTICAL_POSITIVE_POSITIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+2,y+1,piece,((*cpt) == 1)?CAVALIER_VERTICAL_POSITIVE_POSITIVE:DEFAULT ,block,cpt);
						break;

                    case CAVALIER_VERTICAL_POSITIVE_NEGATIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x+2,y-1,piece,((*cpt) == 1)?CAVALIER_VERTICAL_POSITIVE_NEGATIVE:DEFAULT ,block,cpt);
						break;

                    case CAVALIER_VERTICAL_NEGATIVE_POSITIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-2,y+1,piece,((*cpt) == 1)?CAVALIER_VERTICAL_NEGATIVE_POSITIVE:DEFAULT ,block,cpt);
						break;

                    case CAVALIER_VERTICAL_NEGATIVE_NEGATIVE:
                        mencer(board,piecesMenacante,posPiecesMenacente,indiceCourant,x-2,y-1,piece,((*cpt) == 1)?CAVALIER_VERTICAL_NEGATIVE_NEGATIVE:DEFAULT ,block,cpt);
						break;
                    default:
                        return 1;
                        break;
                }
		}
            return 1;
}

int caseMenacer(configuration board, int xDest, int yDest) /// Tester si la case séléctionée est menacée par une ou plusieres piece (s) de l'adversere
{



    char piecesMenacante[20], piece;
    int posPiecesMenacente[20][2], indiceCourant = 0;
    int i = 0, cpt = 0;

        for(i = 0 ; i < 16 ; i++){
			piece = board.board[xDest-1][yDest-1];
			mencer(board,piecesMenacante,posPiecesMenacente,&indiceCourant,xDest-1,yDest-1,(piece>0)?piece:(-piece),i,1,&cpt);
			      cpt = 0;
		    }

        return indiceCourant;
}
