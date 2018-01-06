#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Board.h"
#include "regle_de_deplacement.c"
#include "Menacer.c"

bool deplacerBlanc(configuration *board, int x1, int y1 ,int x2, int y2) /// Le déplacement pour les blancs
{
    int x = x1, y = y1;
    int i, j, cpt;
    bool cont = true, boucle = true;
    char piece = board->board[x1-1][y1-1];
    bool deplacer = false;
    switch(piece)
    {
        case 'F' :
            if((x1 != x2) && (y1 != y2))
            {
                if(x1 < x2 && y1 < y2)
                {
                    i = 1;
                }
                if(x1 > x2 && y1 < y2)
                {
                    i = 3;
                }
                if(x1 > x2 && y1 > y2)
                {
                    i = 5;
                }
                if(x1 < x2 && y1 > y2)
                {
                    i = 7;
                }
                while ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8) && cont && boucle)
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(i == 1)
                    {
                        if((x >= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 3)
                    {
                        if((x <= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 5)
                    {
                        if((x <= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 7)
                    {
                        if((x >= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(((board->board[x-1][y-1] != 0) && (x != x2) && (y != y2)) || ((x == x2) && (y == y2) && (board->board[x-1][y-1] > 0)))
                    {
                        cont = false;
                    }
                }
                if(cont && (x == x2) && (y == y2))
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
            break;
        case 'T' :
            if(((x1 != x2) && (y1 == y2)) || ((y1 != y2) && (x1 == x2)))
            {
                if(x1 < x2)
                {
                    i = 0;
                }
                if(x1 > x2)
                {
                    i = 4;
                }
                if(y1 < y2)
                {
                    i = 2;
                }
                if(y1 > y2)
                {
                    i = 6;
                }
                while ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8) && cont && boucle)
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(i == 0)
                    {
                        if(x >= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 2)
                    {
                        if(y >= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 4)
                    {
                        if(x <= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 6)
                    {
                        if(y <= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(((board->board[x-1][y-1] != 0) && (x != x2)) || ((board->board[x-1][y-1] != 0) && (y != y2)) || ((x == x2) && (y == y2) && (board->board[x-1][y-1] > 0)))
                    {
                        cont = false;
                    }
                }
                if(cont && (x == x2) && (y == y2))
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                    if((x1 == 1) && (y1 == 8) && (board->roque[0] == 0))
                    {
                        board->roque[0] = -1;
                    }
                    if((x1 == 1) && (y1 == 1) && (board->roque[1] == 0))
                    {
                        board->roque[1] = -1;
                    }
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case 'D' :
            if(((x1 != x2) && (y1 == y2)) || ((y1 != y2) && (x1 == x2)) || ((x1 != x2) && (y1 != y2)))
            {
                if((x1 < x2) && (y1 == y2))
                {
                    i = 0;
                }
                if((x1 > x2) && (y1 == y2))
                {
                    i = 4;
                }
                if((y1 < y2) && (x1 == x2))
                {
                    i = 2;
                }
                if((y1 > y2) && (x1 == x2))
                {
                    i = 6;
                }
                if(x1 < x2 && y1 < y2)
                {
                    i = 1;
                }
                if(x1 > x2 && y1 < y2)
                {
                    i = 3;
                }
                if(x1 > x2 && y1 > y2)
                {
                    i = 5;
                }
                if(x1 < x2 && y1 > y2)
                {
                    i = 7;
                }
                while ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8) && cont && boucle)
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(i == 0)
                    {
                        if(x >= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 2)
                    {
                        if(y >= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 4)
                    {
                        if(x <= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 6)
                    {
                        if(y <= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 1)
                    {
                        if((x >= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 3)
                    {
                        if((x <= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 5)
                    {
                        if((x <= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 7)
                    {
                        if((x >= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(((board->board[x-1][y-1] != 0) && (x != x2)) || ((board->board[x-1][y-1] != 0) && (y != y2)) || ((board->board[x-1][y-1] != 0) && (x != x2) && (y != y2)) || ((x == x2) && (y == y2) && (board->board[x-1][y-1] > 0)))
                    {
                        cont = false;
                    }
                }
                if(cont && (x == x2) && (y == y2))
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case 'R' :
            if((caseMenacer(*board, x2, y2) == 0) && (((x1 != x2) && (y1 == y2)) || ((y1 != y2) && (x1 == x2)) || ((x1 != x2) && (y1 != y2))))
            {
                if((x1 < x2) && (y1 == y2))
                {
                    i = 0;
                }
                if((x1 > x2) && (y1 == y2))
                {
                    i = 4;
                }
                if((y1 < y2) && (x1 == x2))
                {
                    i = 2;
                }
                if((y1 > y2) && (x1 == x2))
                {
                    i = 6;
                }
                if((x1 < x2) && (y1 < y2))
                {
                    i = 1;
                }
                if((x1 > x2) && (y1 < y2))
                {
                    i = 3;
                }
                if((x1 > x2) && (y1 > y2))
                {
                    i = 5;
                }
                if((x1 < x2) && (y1 > y2))
                {
                    i = 7;
                }
                if ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8))
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if((x == x2) && (y == y2) && (board->board[x-1][y-1] > 0))
                    {
                        cont = false;
                    }
                }
                if((x == x2) && (y == y2) && cont)
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                    if(board->roque[0] == 0)
                    {
                        board->roque[0] = -1;
                    }
                    if(board->roque[1] == 0)
                    {
                        board->roque[1] = -1;
                    }
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case 'C' :
            cont = false;
            if((x1 != x2) && (y1 != y2))
            {
                if((x2 == x1 + 1) && (y2 == y1 + 2))
                {
                    i = 2;
                    cont = true;
                }
                if((x2 == x1 + 1) && (y2 == y1 - 2))
                {
                    i = 5;
                    cont = true;
                }
                if((x2 == x1 - 1) && (y2 == y1 + 2))
                {
                    i = 1;
                    cont = true;
                }
                if((x2 == x1 - 1) && (y2 == y1 - 2))
                {
                    i = 6;
                    cont = true;
                }
                if((x2 == x1 + 2) && (y2 == y1 + 1))
                {
                    i = 3;
                    cont = true;
                }
                if((x2 == x1 + 2) && (y2 == y1 - 1))
                {
                    i = 4;
                    cont = true;
                }
                if((x2 == x1 - 2) && (y2 == y1 + 1))
                {
                    i = 0;
                    cont = true;
                }
                if((x2 == x1 - 2) && (y2 == y1 - 1))
                {
                    i = 7;
                    cont = true;
                }
                if (cont && (x + DeplacementCavalier[i][0] >= 1) && (x + DeplacementCavalier[i][0] <= 8) && (y + DeplacementCavalier[i][1] >= 1) && (y + DeplacementCavalier[i][1] <= 8))
                {
                    x = x + DeplacementCavalier[i][0];
                    y = y + DeplacementCavalier[i][1];
                    if((x == x2) && (y == y2) && (board->board[x-1][y-1] > 0))
                    {
                        cont = false;
                    }
                }
                if((x == x2) && (y == y2) && cont)
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case 'P' :
            cont = false;
            cpt = 1;
            if(((x2 == x1 + 1) || (x2 == x1 + 2)) && ((y2 == y1 + 1) || (y2 == y1 - 1) || (y2 == y1)))
            {
                if((x2 == x1 + 2) && ( x1 == 2) && (y2 == y1))
                {
                    i = 0;
                    cont = true;
                    cpt = 2;
                }
                if((x2 == x1 + 1) && (y2 == y1))
                {
                    i = 0;
                    cont = true;
                }
                if((x2 == x1 + 1) && (y2 == y1 + 1) && (board->board[x2-1][y2-1] < 0))
                {
                    i = 1;
                    cont = true;
                }
                if((x2 == x1 + 1) && (y2 == y1 - 1) && (board->board[x2-1][y2-1] < 0))
                {
                    i = 7;
                    cont = true;
                }
                j = 0;
                while (cont && (j < cpt) && (x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8))
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(((board->board[x-1][y-1] != 0) && (x != x2)) || ((board->board[x-1][y-1] != 0) && (y != y2)) || ((y1 != y2) && (x == x2) && (y == y2) && (board->board[x-1][y-1] > 0)) || ((board->board[x-1][y-1] != 0) && (y1 == y2)))
                    {
                        cont = false;
                    }
                    j++;
                }
                if((x == x2) && (y == y2) && cont)
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        default :
            deplacer = false;
            //printf("Déplacement impossible!\n");
    }
    if(deplacer)
    {
        board->turn ++;
    }
    return deplacer;
}

bool deplacerNoir(configuration *board, int x1, int y1 ,int x2, int y2) /// Le déplacement pour les noires
{
    int x = x1, y = y1;
    int i, j, cpt;
    bool cont = true, boucle = true;
    char piece = board->board[x1-1][y1-1];
    bool deplacer = false;

    switch(piece)
    {
        case -'F' :
            if((x1 != x2) && (y1 != y2))
            {
                if(x1 < x2 && y1 < y2)
                {
                    i = 1;
                }
                if(x1 > x2 && y1 < y2)
                {
                    i = 3;
                }
                if(x1 > x2 && y1 > y2)
                {
                    i = 5;
                }
                if(x1 < x2 && y1 > y2)
                {
                    i = 7;
                }
                while ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8) && cont && boucle)
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(i == 1)
                    {
                        if((x >= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 3)
                    {
                        if((x <= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 5)
                    {
                        if((x <= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 7)
                    {
                        if((x >= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(((board->board[x-1][y-1] != 0) && (x != x2) && (y != y2)) || ((x == x2) && (y == y2) && (board->board[x-1][y-1] < 0)))
                    {
                        cont = false;
                    }
                }
                if(cont && (x == x2) && (y == y2))
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
            break;
        case -'T' :
            if(((x1 != x2) && (y1 == y2)) || ((y1 != y2) && (x1 == x2)))
            {
                if(x1 < x2)
                {
                    i = 0;
                }
                if(x1 > x2)
                {
                    i = 4;
                }
                if(y1 < y2)
                {
                    i = 2;
                }
                if(y1 > y2)
                {
                    i = 6;
                }
                while ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8) && cont && boucle)
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(i == 0)
                    {
                        if(x >= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 2)
                    {
                        if(y >= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 4)
                    {
                        if(x <= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 6)
                    {
                        if(y <= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(((board->board[x-1][y-1] != 0) && (x != x2)) || ((board->board[x-1][y-1] != 0) && (y != y2)) || ((x == x2) && (y == y2) && (board->board[x-1][y-1] < 0)))
                    {
                        cont = false;
                    }
                }
                if(cont && (x == x2) && (y == y2))
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                    if((x1 == 8) && (y1 == 8) && (board->roque[2] == 0))
                    {
                        board->roque[2] = -1;
                    }
                    if((x1 == 8) && (y1 == 1) && (board->roque[3] == 0))
                    {
                        board->roque[3] = -1;
                    }
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case -'D' :
            if(((x1 != x2) && (y1 == y2)) || ((y1 != y2) && (x1 == x2)) || ((x1 != x2) && (y1 != y2)))
            {
                if((x1 < x2) && (y1 == y2))
                {
                    i = 0;
                }
                if((x1 > x2) && (y1 == y2))
                {
                    i = 4;
                }
                if((y1 < y2) && (x1 == x2))
                {
                    i = 2;
                }
                if((y1 > y2) && (x1 == x2))
                {
                    i = 6;
                }
                if(x1 < x2 && y1 < y2)
                {
                    i = 1;
                }
                if(x1 > x2 && y1 < y2)
                {
                    i = 3;
                }
                if(x1 > x2 && y1 > y2)
                {
                    i = 5;
                }
                if(x1 < x2 && y1 > y2)
                {
                    i = 7;
                }
                while ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8) && cont && boucle)
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(i == 0)
                    {
                        if(x >= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 2)
                    {
                        if(y >= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 4)
                    {
                        if(x <= x2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 6)
                    {
                        if(y <= y2)
                        {
                            boucle = false;
                        }
                    }
                    if(i == 1)
                    {
                        if((x >= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 3)
                    {
                        if((x <= x2) || (y >= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 5)
                    {
                        if((x <= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(i == 7)
                    {
                        if((x >= x2) || (y <= y2))
                        {
                            boucle = false;
                        }
                    }
                    if(((board->board[x-1][y-1] != 0) && (x != x2)) || ((board->board[x-1][y-1] != 0) && (y != y2)) || ((board->board[x-1][y-1] != 0) && (x != x2) && (y != y2)) || ((x == x2) && (y == y2) && (board->board[x-1][y-1] < 0)))
                    {
                        cont = false;
                    }
                }
                if(cont && (x == x2) && (y == y2))
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case -'R' :
            if((caseMenacer(*board, x2, y2) == 0) && (((x1 != x2) && (y1 == y2)) || ((y1 != y2) && (x1 == x2)) || ((x1 != x2) && (y1 != y2))))
            {
                if((x1 < x2) && (y1 == y2))
                {
                    i = 0;
                }
                if((x1 > x2) && (y1 == y2))
                {
                    i = 4;
                }
                if((y1 < y2) && (x1 == x2))
                {
                    i = 2;
                }
                if((y1 > y2) && (x1 == x2))
                {
                    i = 6;
                }
                if((x1 < x2) && (y1 < y2))
                {
                    i = 1;
                }
                if((x1 > x2) && (y1 < y2))
                {
                    i = 3;
                }
                if((x1 > x2) && (y1 > y2))
                {
                    i = 5;
                }
                if((x1 < x2) && (y1 > y2))
                {
                    i = 7;
                }
                if ((x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8))
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if((x == x2) && (y == y2) && (board->board[x-1][y-1] < 0))
                    {
                        cont = false;
                    }
                }
                if((x == x2) && (y == y2) && cont)
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                    if(board->roque[2] == 0)
                    {
                        board->roque[0] = -1;
                    }
                    if(board->roque[3] == 0)
                    {
                        board->roque[1] = -1;
                    }
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case -'C' :
            cont = false;
            if((x1 != x2) && (y1 != y2))
            {
                if((x2 == x1 + 1) && (y2 == y1 + 2))
                {
                    i = 2;
                    cont = true;
                }
                if((x2 == x1 + 1) && (y2 == y1 - 2))
                {
                    i = 5;
                    cont = true;
                }
                if((x2 == x1 - 1) && (y2 == y1 + 2))
                {
                    i = 1;
                    cont = true;
                }
                if((x2 == x1 - 1) && (y2 == y1 - 2))
                {
                    i = 6;
                    cont = true;
                }
                if((x2 == x1 + 2) && (y2 == y1 + 1))
                {
                    i = 3;
                    cont = true;
                }
                if((x2 == x1 + 2) && (y2 == y1 - 1))
                {
                    i = 4;
                    cont = true;
                }
                if((x2 == x1 - 2) && (y2 == y1 + 1))
                {
                    i = 0;
                    cont = true;
                }
                if((x2 == x1 - 2) && (y2 == y1 - 1))
                {
                    i = 7;
                    cont = true;
                }
                if (cont && (x + DeplacementCavalier[i][0] >= 1) && (x + DeplacementCavalier[i][0] <= 8) && (y + DeplacementCavalier[i][1] >= 1) && (y + DeplacementCavalier[i][1] <= 8))
                {
                    x = x + DeplacementCavalier[i][0];
                    y = y + DeplacementCavalier[i][1];
                    if((x == x2) && (y == y2) && (board->board[x-1][y-1] < 0))
                    {
                        cont = false;
                    }
                }
                if((x == x2) && (y == y2) && cont)
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        case -'P' :
            cont = false;
            cpt = 1;
            if(((x2 == x1 - 1) || (x2 == x1 - 2)) && ((y2 == y1 + 1) || (y2 == y1 - 1) || (y2 == y1)))
            {
                if((x2 == x1 - 2) && ( x1 == 7) && (y2 == y1))
                {
                    i = 4;
                    cont = true;
                    cpt = 2;
                }
                if((x2 == x1 - 1) && (y2 == y1))
                {
                    i = 4;
                    cont = true;
                }
                if((x2 == x1 - 1) && (y2 == y1 + 1) && (board->board[x2-1][y2-1] > 0))
                {
                    i = 3;
                    cont = true;
                }
                if((x2 == x1 - 1) && (y2 == y1 - 1) && (board->board[x2-1][y2-1] > 0))
                {
                    i = 5;
                    cont = true;
                }
                j = 0;
                while (cont && (j < cpt) && (x + DeplacementGenerale[i][0] >= 1) && (x + DeplacementGenerale[i][0] <= 8) && (y + DeplacementGenerale[i][1] >= 1) && (y + DeplacementGenerale[i][1] <= 8))
                {
                    x = x + DeplacementGenerale[i][0];
                    y = y + DeplacementGenerale[i][1];
                    if(((board->board[x-1][y-1] != 0) && (x != x2)) || ((board->board[x-1][y-1] != 0) && (y != y2)) || ((y1 != y2) && (x == x2) && (y == y2) && (board->board[x-1][y-1] < 0)) || ((board->board[x-1][y-1] != 0) && (y1 == y2)))
                    {
                        cont = false;
                    }
                    j++;
                }
                if((x == x2) && (y == y2) && cont)
                {
                    board->board[x2-1][y2-1] = board->board[x1-1][y1-1];
                    board->board[x1-1][y1-1] = 0;
                    deplacer = true;
                }
                else
                {
                    //printf("Déplacement impossible!\n");
                }
            }
            else
            {
                //printf("Déplacement impossible!\n");
            }
        break;
        default :
            deplacer = false;
            //printf("Déplacement impossible!\n");
    }
    if(deplacer)
    {
        board->turn ++;
    }
    return deplacer;
}

bool petitRock(configuration *board) /// La réalisation du petit rock pour les blancs et les noires
{
    bool deplacer = false;

    if((board->turn % 2) == 0)
    {
        if(board->roque[0] == 0)
        {
            if((board->board[0][5] == 0) && (board->board[0][6] == 0) && (board->board[0][4] == 'R') && (board->board[0][7] == 'T') && (caseMenacer(*board, 1, 5) == 0) && (caseMenacer(*board, 1, 6) == 0) && (caseMenacer(*board, 1, 7) == 0) && (caseMenacer(*board, 1, 8) == 0))
            {
                board->board[0][6] = board->board[0][4];
                board->board[0][5] = board->board[0][7];
                board->board[0][4] = 0;
                board->board[0][7] = 0;
                board->roque[0] = 1;
                board->roque[1] = -1;
                deplacer = true;
            }
        }
    }
    else
    {
        if(board->roque[2] == 0)
        {
            if((board->board[7][5] == 0) && (board->board[7][6] == 0) && (board->board[7][4] == -'R') && (board->board[7][7] == -'T') && (caseMenacer(*board, 8, 5) == 0) && (caseMenacer(*board, 8, 6) == 0) && (caseMenacer(*board, 8, 7) == 0) && (caseMenacer(*board, 8, 8) == 0))
            {
                board->board[7][6] = board->board[7][4];
                board->board[7][5] = board->board[7][7];
                board->board[7][4] = 0;
                board->board[7][7] = 0;
                board->roque[2] = 1;
                board->roque[3] = -1;
                deplacer = true;
            }
        }
    }
    if(deplacer)
    {
        board->turn ++;
    }
    else
    {
        //printf("Déplacement impossible!\n");
    }
    return deplacer;
}

bool grandRock(configuration *board) /// La réalisation du grand rock pour les blancs et les noires
{
    bool deplacer = false;

    if((board->turn % 2) == 0)
    {
        if(board->roque[1] == 0)
        {
            if((board->board[0][1] == 0) && (board->board[0][2] == 0) && (board->board[0][3] == 0) && (board->board[0][4] == 'R') && (board->board[0][0] == 'T') && (caseMenacer(*board, 1, 1) == 0) && (caseMenacer(*board, 1, 2) == 0) && (caseMenacer(*board, 1, 3) == 0) && (caseMenacer(*board, 1, 4) == 0) && (caseMenacer(*board, 1, 5) == 0))
            {
                board->board[0][2] = board->board[0][4];
                board->board[0][3] = board->board[0][0];
                board->board[0][4] = 0;
                board->board[0][0] = 0;
                board->roque[1] = 1;
                board->roque[0] = -1;
                deplacer = true;
            }
        }
    }
    else
    {
        if(board->roque[3] == 0)
        {
            if((board->board[7][1] == 0) && (board->board[7][2] == 0) && (board->board[7][3] == 0) && (board->board[7][4] == -'R') && (board->board[7][0] == -'T') && (caseMenacer(*board, 8, 1) == 0) && (caseMenacer(*board, 8, 2) == 0) && (caseMenacer(*board, 8, 3) == 0) && (caseMenacer(*board, 8, 4) == 0) && (caseMenacer(*board, 8, 5) == 0))
            {
                board->board[7][2] = board->board[7][4];
                board->board[7][3] = board->board[7][0];
                board->board[7][4] = 0;
                board->board[7][0] = 0;
                board->roque[3] = 1;
                board->roque[2] = -1;
                deplacer = true;
            }
        }
    }
    if(deplacer)
    {
        board->turn ++;
    }
    else
    {
        //printf("Déplacement impossible!\n");
    }
    return deplacer;
}

void transformerPiant(configuration *board, int x, int y) /// La tansformation manuel des pions
{
    int transf;
    if(((board->turn % 2) == 1) && (board->board[x][y] == 'P'))
    {
        printf("Transformer votre pion vers:\n\t1- Dame.\n\t2- Tour.\n\t3- Fou.\n\t4- Cavalier.\nVotre choix: ");
        LIRE_B:
            scanf("%d", &transf);
            switch(transf)
            {
                case 1:
                    board->board[x][y] = 'D';
                break;
                case 2:
                    board->board[x][y] = 'T';
                break;
                case 3:
                    board->board[x][y] = 'F';
                break;
                case 4:
                    board->board[x][y] = 'C';
                break;
                default :
                    goto LIRE_B;
            }
    }
    if(((board->turn % 2) == 0) && (board->board[x][y] == -'P'))
    {
        printf("Transformer votre pion vers:\n\t1- Dame.\n\t2- Tour.\n\t3- Fou.\n\t4- Cavalier.\nVotre choix: ");
        LIRE_N:
            scanf("%d", &transf);
            switch(transf)
            {
                case 1:
                    board->board[x][y] = -'D';
                break;
                case 2:
                    board->board[x][y] = -'T';
                break;
                case 3:
                    board->board[x][y] = -'F';
                break;
                case 4:
                    board->board[x][y] = -'C';
                break;
                default :
                    goto LIRE_N;
            }
    }
}

bool roiEchec(configuration board) /// Détecter si le rois est en echec
{
    int x, y;
    bool echec = false;

    if((board.turn % 2) == 0)
    {
        for(x = 0 ; x <= 7 ; x ++)
        {
            for(y = 0 ; y <= 7 ; y ++)
            {
                if((board.board[x][y] == 'R') && (caseMenacer(board, x + 1, y + 1) != 0))
                {
                    echec = true;
                }
            }
        }
    }
    else
    {
        for(x = 0 ; x <= 7 ; x ++)
        {
            for(y = 0 ; y <= 7 ; y ++)
            {
                if((board.board[x][y] == -'R') && (caseMenacer(board, x + 1, y + 1) != 0))
                {
                    echec = true;
                }
            }
        }
    }

    return echec;
}

void dupliquerConfiguration(configuration board, configuration *echequier) /// Copier une configuration dans une autre
{
    int x ,y;
    for(x = 0 ; x <= 7 ; x ++)
    {
        for(y = 0 ; y <= 7 ; y ++)
        {
            echequier->board[x][y] = board.board[x][y];
        }
    }
    echequier->roque[0] = board.roque[0];
    echequier->roque[1] = board.roque[1];
    echequier->roque[2] = board.roque[2];
    echequier->roque[3] = board.roque[3];
    echequier->turn = board.turn;
    echequier->val = board.val;
}

configuration deplacementManuele(configuration board) /// Le déplacement manuel dans le cas d'un humain
{
    char cmd[5];
    int x1, y1, x2, y2;
    bool deplacer = false;
    configuration echequier;
    char cmdArena[5];

    dupliquerConfiguration(board, &echequier);
    if((board.turn % 2) == 0)
    {
        if(roiEchec(board))
        {
            printf("Echec !");
        }
        printf("\n- Tour des blancs\n");
        while(!deplacer)
        {
            printf("Entrée votre déplacement: ");
            scanf("%s", cmd);
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
                    if(deplacer && (x2 == 8))
                    {
                        transformerPiant(&board, x2 - 1, y2 - 1);
                    }
                }
            }
            if(deplacer)
            {
                board.turn--;
                if(roiEchec(board))
                {
                    deplacer = false;
                    dupliquerConfiguration(echequier, &board);
                }
                else
                {
                    board.turn++;
                }

                getCMD(echequier, board, &cmdArena);
                //printf("\n-------------- %c%c%c%c%c ----------------\n\n", cmdArena[0], cmdArena[1], cmdArena[2], cmdArena[3], cmdArena[4]);
            }
            if(!deplacer)
            {
                printf("Déplacement impossible!\n");
            }
        }
    }
    else
    {
        if(roiEchec(board))
        {
            printf("Echec !\n");
        }
        printf("\n- Tour des noirs\n");
        while(!deplacer)
        {
            printf("Entrée votre déplacement: ");
            scanf("%s", cmd);
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
                    deplacer = deplacerNoir(&board, x1, y1, x2, y2);
                    if(deplacer && (x2 == 1))
                    {
                        transformerPiant(&board, x2 - 1, y2 - 1);
                    }
                }
            }
            if(deplacer)
            {
                board.turn--;
                if(roiEchec(board))
                {
                    deplacer = false;
                    dupliquerConfiguration(echequier, &board);
                }
                else
                {
                    board.turn++;
                }

                getCMD(echequier, board, &cmdArena);
                //printf("\n-------------- %c%c%c%c%c ----------------\n\n", cmdArena[0], cmdArena[1], cmdArena[2], cmdArena[3], cmdArena[4]);
            }
            if(!deplacer)
            {
                printf("Déplacement impossible!\n");
            }
        }
    }
    //deplacer = false;
    return board;
}

int positions_positive(configuration config ,int tab[100][2]){
    int i=0,j=0;
    int p=0;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(config.board[i][j]>0){
                tab[p][0]=i;
                tab[p][1]=j;
                p++;
            }
        }
    }
    return p;
}

int positions_negative(configuration config ,int tab[100][2]){
    int i=0,j=0;
    int p=0;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(config.board[i][j]<0){
                tab[p][0]=i;
                tab[p][1]=j;
                p++;
            }
        }
    }
    return p;
}

int positions_vide_negative(configuration config ,int tab[100][2]){
    int i=0,j=0;
    int p=0;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(config.board[i][j]<=0){
                tab[p][0]=i;
                tab[p][1]=j;
                p++;
            }
        }
    }
    return p;
}

int positions_vide_positive(configuration config ,int tab[100][2]){
    int i=0,j=0;
    int p=0;
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(config.board[i][j]>=0){
                tab[p][0]=i;
                tab[p][1]=j;
                p++;
            }
        }
    }
    return p;
}

int cout_possible (configuration t[], configuration config ,int type) /// Générer tous les couts possibles
{
    int p=0,i=0,k=0,r=0,u=0,y=0,p2=0;
    int tab2[100][2],tab3[100][2],tab1[100][2];
    int pionPos;
    configuration conf;
    configuration confD, confT, confF, confC;
    if(type==1){
        p=positions_positive(config ,tab1);
        p2=positions_vide_negative(config ,tab2);
    }
    else {
        p=positions_negative(config ,tab3);
        p2=positions_vide_positive(config ,tab2);
    }
    for(i=0;i<p;i++){
            for(k=0;k<p2;k++){

                for (u=0;u<8;u++) for(y=0;y<8;y++) conf.board[u][y] = config.board[u][y];
                for(y=0;y<4;y++)  conf.roque[y] = config.roque[y];
                conf.turn=config.turn;
                conf.val=config.val;
                if(type==1){
                    if(deplacerBlanc(&conf, tab1[i][0]+1, tab1[i][1]+1 ,tab2[k][0]+1, tab2[k][1]+1)){
                        conf.turn--;
                        if(!roiEchec(conf))
                        {
                            conf.turn++;
                            for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = conf.board[u][y];
                            for(y=0;y<4;y++)  t[r].roque[y] = conf.roque[y];
                            t[r].turn=conf.turn;
                            t[r].val=conf.val;
                            r++;

                            for(pionPos = 0 ; pionPos <= 7 ; pionPos++)
                            {
                                if(conf.board[7][pionPos] == 'P')
                                {
                                    dupliquerConfiguration(conf, &confD);
                                    confD.board[7][pionPos] = 'D';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confD.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confD.roque[y];
                                    t[r].turn=confD.turn;
                                    t[r].val=confD.val;
                                    r++;

                                    dupliquerConfiguration(conf, &confT);
                                    confT.board[7][pionPos] = 'T';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confT.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confT.roque[y];
                                    t[r].turn=confT.turn;
                                    t[r].val=confT.val;
                                    r++;

                                    dupliquerConfiguration(conf, &confF);
                                    confF.board[7][pionPos] = 'F';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confF.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confF.roque[y];
                                    t[r].turn=confF.turn;
                                    t[r].val=confF.val;
                                    r++;

                                    dupliquerConfiguration(conf, &confC);
                                    confC.board[7][pionPos] = 'C';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confC.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confC.roque[y];
                                    t[r].turn=confC.turn;
                                    t[r].val=confC.val;
                                    r++;
                                }
                            }
                        }
                    }
                }else{
                    if(deplacerNoir(&conf, tab3[i][0]+1, tab3[i][1]+1 ,tab2[k][0]+1, tab2[k][1]+1)){
                        conf.turn--;
                        if(!roiEchec(conf))
                        {
                            conf.turn++;
                            for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = conf.board[u][y];
                            for(y=0;y<4;y++)  t[r].roque[y] = conf.roque[y];
                            t[r].turn=conf.turn;
                            t[r].val=conf.val;
                            r++;

                            for(pionPos = 0 ; pionPos <= 7 ; pionPos++)
                            {
                                if(conf.board[0][pionPos] == -'P')
                                {
                                    dupliquerConfiguration(conf, &confD);
                                    confD.board[0][pionPos] = -'D';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confD.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confD.roque[y];
                                    t[r].turn=confD.turn;
                                    t[r].val=confD.val;
                                    r++;

                                    dupliquerConfiguration(conf, &confT);
                                    confT.board[0][pionPos] = -'T';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confT.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confT.roque[y];
                                    t[r].turn=confT.turn;
                                    t[r].val=confT.val;
                                    r++;

                                    dupliquerConfiguration(conf, &confF);
                                    confF.board[0][pionPos] = -'F';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confF.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confF.roque[y];
                                    t[r].turn=confF.turn;
                                    t[r].val=confF.val;
                                    r++;

                                    dupliquerConfiguration(conf, &confC);
                                    confC.board[0][pionPos] = -'C';
                                    for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = confC.board[u][y];
                                    for(y=0;y<4;y++)  t[r].roque[y] = confC.roque[y];
                                    t[r].turn=confC.turn;
                                    t[r].val=confC.val;
                                    r++;
                                }
                            }
                        }
                    }
                }
            }
    }
    for (u=0;u<8;u++) for(y=0;y<8;y++) conf.board[u][y] = config.board[u][y];
    for(y=0;y<4;y++)  conf.roque[y] = config.roque[y];
    conf.turn=config.turn;
    conf.val=config.val;
    if(petitRock(&conf)) {
        for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = conf.board[u][y];
        for(y=0;y<4;y++)  t[r].roque[y] = conf.roque[y];
        t[r].turn=conf.turn;
        t[r].val=conf.val;
        r++;
    }
    for (u=0;u<8;u++) for(y=0;y<8;y++) conf.board[u][y] = config.board[u][y];
    for(y=0;y<4;y++)  conf.roque[y] = config.roque[y];
    conf.turn=config.turn;
    conf.val=config.val;
    if(grandRock(&conf)) {
        for (u=0;u<8;u++) for(y=0;y<8;y++)  t[r].board[u][y] = conf.board[u][y];
        for(y=0;y<4;y++)  t[r].roque[y] = conf.roque[y];
        t[r].turn=conf.turn;
        t[r].val=conf.val;
        r++;
    }
    return r;
}
