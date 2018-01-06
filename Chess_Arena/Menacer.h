#ifndef MENACER_H_INCLUDED
#define MENACER_H_INCLUDED




int mencer(configuration board, char piecesMenacante[20], int posPiecesMenacente[20][2], int *indiceCourant,int x, int y, int direction,int block,int *cpt);
int caseMenacer(configuration board, int xDest, int yDest);

#endif // MENACER_H_INCLUDED