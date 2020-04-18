/* ------------------------------------------------ */
/* Nom du fichier : main.c                          */
/* Date de creation : Avril 2020                    */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31) */
/* Objectif : main pour la manipulation d'arbres    */
/* Fonctions :                                      */
/*  - main                                          */
/* ------------------------------------------------ */

#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"


int main() {
	char * notation = recupNotaAlgebrique("notaAlgebrique.txt");
	elemArbre_t * arbre = NULL;

	if (notation != NULL) {
		printf("%s\n", notation);
		arbre = creerArbreNotaAlgebrique(notation);
		
		if (arbre != NULL) {
			afficherArbre(arbre);
			libererArbre(&arbre);
		}
	}

	free(notation);
	return 0;
}
