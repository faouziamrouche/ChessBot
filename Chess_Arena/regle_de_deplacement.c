
// Les vecteurs des deplacements pour chaque type de piece ...

// Les differentes possibilités de deplacement du pieces : fou (indices impairs), tour (indices pairs), reine et roi (indices pairs et impairs) ...
int DeplacementGenerale[8][2] = { {+1,0} , {+1,+1} , {0,+1} , {-1,+1} , {-1,0} , {-1,-1} , {0,-1} , {+1,-1} };

// Le deplacement particulier du cavalier
int DeplacementCavalier[8][2] = { {-2,+1} , {-1,+2} , {+1,+2} , {+2,+1} , {+2,-1} , {+1,-2} , {-1,-2} , {-2,-1} };


/** Explication (pour plus de detail voir la fonction "deplacer" dans le fichier "deplacement.c") :

ex. :
- Pour le cavalier :
La_nouvelle_positio[1] = La_position_courante[1] + DeplacementCavalier[i][1];
La_nouvelle_positio[2] = La_position_courante[2] + DeplacementCavalier[i][2];
// telque : 0 <= i <= 7

- Pour le fou :
while ((La_position_courante[1] + DeplacementGenerale[i][1] >= 0) && (La_position_courante[1] + DeplacementGenerale[i][1] <= 7) && (La_position_courante[2] + DeplacementGenerale[i][2] >= 0) && (La_position_courante[2] + DeplacementGenerale[i][2] <= 7))
{
	La_nouvelle_positio[1] = La_position_courante[1] + DeplacementGenerale[i][1];
	La_nouvelle_positio[2] = La_position_courante[2] + DeplacementGenerale[i][2];
	// telque : 0 <= i <= 7 et i est impaire
}

- Pour la tour :
while ((La_position_courante[1] + DeplacementGenerale[i][1] >= 0) && (La_position_courante[1] + DeplacementGenerale[i][1] <= 7) && (La_position_courante[2] + DeplacementGenerale[i][2] >= 0) && (La_position_courante[2] + DeplacementGenerale[i][2] <= 7))
{
	La_nouvelle_positio[1] = La_position_courante[1] + DeplacementGenerale[i][1];
	La_nouvelle_positio[2] = La_position_courante[2] + DeplacementGenerale[i][2];
	// telque : 0 <= i <= 7 et i est paire
}

- Pour la rien :
while ((La_position_courante[1] + DeplacementGenerale[i][1] >= 0) && (La_position_courante[1] + DeplacementGenerale[i][1] <= 7) && (La_position_courante[2] + DeplacementGenerale[i][2] >= 0) && (La_position_courante[2] + DeplacementGenerale[i][2] <= 7))
{
	La_nouvelle_positio[1] = La_position_courante[1] + DeplacementGenerale[i][1];
	La_nouvelle_positio[2] = La_position_courante[2] + DeplacementGenerale[i][2];
	// telque : 0 <= i <= 7
}

- Pour le roi :
if ((La_position_courante[1] + DeplacementGenerale[i][1] >= 0) && (La_position_courante[1] + DeplacementGenerale[i][1] <= 7) && (La_position_courante[2] + DeplacementGenerale[i][2] >= 0) && (La_position_courante[2] + DeplacementGenerale[i][2] <= 7))
{
	La_nouvelle_positio[1] = La_position_courante[1] + DeplacementGenerale[i][1];
	La_nouvelle_positio[2] = La_position_courante[2] + DeplacementGenerale[i][2];
	// telque : 0 <= i <= 7
}
**/
