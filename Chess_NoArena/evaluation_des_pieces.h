#ifndef EVALUATION_DES_PIECES_H_INCLUDED
#define EVALUATION_DES_PIECES_H_INCLUDED

// Pinalite pour le pion isole
int PawnIsolated = -30;

// Pinalite pour le pion doublé
int PawnDouble = -30;

// Pour valoriser une tour sur une colonne ouverte
int RookOpenFile = 70;

// Pour valoriser une tour sur une colonne semi ouverte
int RookSemiOpenFile = 50;

// Pour valoriser une reine sur une colonne ouverte
int QueenOpenFile = 50;

// Pour valoriser une reine sur une colonne semi ouverte
int QueenSemiOpenFile = 30;

// La valeur d'un pair de fous
int BishopPair = 50;

// L'evaluation de l'echequier
// Les positions sont comme suit : a1, b1, c1, ...
//                                 a2, b2, c2, ...
//Donc un pion sur d2 pour les blancs est evalue a -50, si il bouge a d4, il est a 90, ...

int PawnTable[64] = {
	0	    ,  	0   	,   0   	,   0   	,   0   	,  	0	    ,	0	    ,	0	    ,
	50	    ,  	50	    ,   0	    ,   -10     ,   -10     ,  	0	    ,	50	    ,	50	    ,
	25	    ,  	0	    ,  	0	    ,  	25	    ,  	25	    ,  	0	    ,	0	    ,	25	    ,
	0	    ,  	0	    ,  	50	    ,  	90	    ,  	90	    ,  	50	    ,	0	    ,	0	    ,
	25	    ,  	25	    ,  	25	    ,  	50	    ,  	50	    ,  	25	    ,	25	    ,	25	    ,
	50      ,  	50	    ,  	50	    ,  	90	    ,  	90	    ,  	50	    ,	50	    ,	50	    ,
	90	    ,   90 	    ,  	90	    ,  	90	    ,  	90	    ,  	90	    ,	90	    ,	90	    ,
	0	    ,  	0	    ,  	0	    ,  	0	    ,  	0	    ,  	0	    ,	0	    ,	0
};

int KnightTable[64] = {
	0   	,	-50	    ,	0	    ,	0	    ,	0	    ,	0	    ,	-50 	,	0   	,
	0   	,	0	    ,	0	    ,	25	    ,	25	    ,	0	    ,	0	    ,	0   	,
	0	    ,	0	    ,	50	    ,	50	    ,	50	    ,	50	    ,	0	    ,	0	    ,
	0	    ,	25	    ,	50	    ,	90	    ,	90	    ,	50	    ,	25	    ,	0   	,
	25	    ,	50	    ,	70	    ,	90	    ,	90	    ,	70	    ,	50	    ,	25	    ,
	25	    ,  	50	    ,	50	    ,	90	    ,	90	    ,	50	    ,	50	    ,	25	    ,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25	    ,	0	    ,	0   	,
	0	    ,	0	    ,	0	    ,	0	    ,	0	    ,	0	    ,	0	    ,	0
};

int BishopTable[64] = {
	0	    ,	0	    ,	-50	    ,	0	    ,	0	    ,	-50	    ,	0	    ,	0   	,
	0	    ,  	0	    ,	0	    ,	50	    ,	50	    ,	0	    ,	0	    ,	0	    ,
	0	    ,	0	    ,	50	    ,	70	    ,	70	    ,	50  	,	0	    ,	0	    ,
	0	    ,	50	    ,	70	    ,	90	    ,	90	    ,	70	    ,	50	    ,	0   	,
	0	    ,	50	    ,	70	    ,	90	    ,	90	    ,	70	    ,	50	    ,	0   	,
	0	    ,	0	    ,	50	    ,	70	    ,	70	    ,	50	    ,	0	    ,	0   	,
	0	    ,	0	    ,	0	    ,	50	    ,	50	    ,	0   	,	0	    ,	0   	,
	0	    ,	0   	,	0	    ,	0	    ,	0	    ,	0   	,	0	    ,	0
};

int RookTable[64] = {
    0   	,	0	    ,	25  	,	50	    ,	50	    ,	25	    ,	0	    ,	0	    ,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25	    ,	0	    ,	0   	,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25	    ,	0	    ,	0	    ,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25  	,	0	    ,	0   	,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25	    ,	0	    ,	0	    ,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25	    ,	0	    ,	0	    ,
	90	    ,	90	    ,	90	    ,	90	    ,	90	    ,	90	    ,	90	    ,	90	    ,
	0	    ,	0	    ,	25	    ,	50	    ,	50	    ,	25	    ,	0	    ,	0
};

// l'evaluation du roi pendant la fin de partie
int KingE[64] = {
	-500    ,	-50	    ,	0   	,	0   	,	0   	,	0   	,	-50	    ,	-500	,
	-50     ,	0	    ,	50 	    ,	50	    ,	50	    ,	50	    ,	0   	,	-50     ,
	0	    ,	50	    ,	90	    ,	90	    ,	90	    ,	90	    ,	50	    ,	0	    ,
	0	    ,	50	    ,	90	    ,	99	    ,	99	    ,	90	    ,	50	    ,	0	    ,
	0	    ,	50	    ,	90	    ,	99	    ,	99	    ,	90	    ,	50	    ,	0	    ,
	0	    ,	50	    ,	90	    ,	90	    ,	90	    ,	90	    ,	50	    ,	0	    ,
	-50     ,	0	    ,	50	    ,	50	    ,	50	    ,	50	    ,	0	    ,	-50	    ,
	-500 	,	-50	    ,	0	    ,	0	    ,	0	    ,	0	    ,	-50	    ,	-500
};

// L'evaluation du roi pendant l'ouverture, on donne la priorite au petit roque (plus sucurise)
int KingO[64] = {
	0	    ,	25	    ,	25	    ,	-50     ,	-50 	,	0	    ,	50	    ,	25	    ,
	-300	,	-300	,	-300	,	-300	,	-300	,	-300	,	-300	,	-300	,
	-500	,	-500	,	-500	,	-500	,	-500	,	-500	,	-500	,	-500	,
	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,
	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,
	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,
	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,
	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700	,	-700
};

#endif // EVALUATION_DES_PIECES_H_INCLUDED
