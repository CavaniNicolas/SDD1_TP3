/* -------------------------------------------------------------------------- */
/* Nom du fichier : affichageArbre.c                                          */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : afficher les arbres                                             */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "pilefile/pile.h"
#include "affichageArbre.h"


/*════════════════════════════════════════════════════════════════════════════*/
/* --------------------- Fonctions d'affichage de l'arbre ------------------- */
/*════════════════════════════════════════════════════════════════════════════*/


void afficherArbre(elemArbre_t * arbre) {
	if (arbre != NULL) {

		char   fin       = 0;
		int    niveau    = 0;
		char * tabFreres = (char *)calloc(255, sizeof(char));

		if (tabFreres != NULL) {

			elemArbre_t * cour = arbre;
			pile_t * pileArbre = initPile(10);

			actuTabFreres(cour, niveau, tabFreres);

			if (pileArbre != NULL) {
				printf("Arbre :\n.\n");
				while (!fin) {

					while (cour != NULL) {
						afficherValeur(cour, niveau, tabFreres);

						empiler(pileArbre, cour);
						cour = cour->fils;
						niveau += 1;
						actuTabFreres(cour, niveau, tabFreres);
					}

					if (!estVidePile(pileArbre)) {
						depiler(pileArbre, &cour);
						niveau -= 1;
						cour = cour->frere;
						actuTabFreres(cour, niveau, tabFreres);

					} else {
						fin = 1;
					}	
				}
				libererPile(pileArbre);
			}
		}
		free(tabFreres);
	}
}


// variante graphique ╠══ ║ ╚══ 
void afficherValeur(elemArbre_t * elemArbre, int niveau, char * tabFreres) {
	int i = 0;

	for (i=0; i<niveau; i++) {

		if (tabFreres[i] == 0) {
			printf("    ");
		}
		else {
			printf("│   ");
		}
	}

	if (elemArbre->frere != NULL) {
		printf("├── ");
	}
	else {
		printf("└── ");
	}

	printf("%c\n", elemArbre->valeur);
}


void actuTabFreres(elemArbre_t * cour, int niveau, char * tabFreres) {
	if (cour != NULL) {

		if (cour->frere == NULL) {
			tabFreres[niveau] = 0;
		}
		else {
			tabFreres[niveau] = 1;
		}

	}
}


void afficherArbrePost(elemArbre_t * arbre) {
	char fin = 0; /* Booléen de fin, 1 actions finies, 0 on continue */

	elemArbre_t * cour = arbre; /* Pointeur courant pour parcourir l'arbre */
	pile_t * pileArbre = initPile(10); /* Pile utilisée pour parcourir l'arbre */

	/* Si l'allocation mémoire est réussie alors : */
	if (pileArbre != NULL) {

		printf("Représentation postfixée :\n\t");
		/* Tant qu'on a pas finit les actions */
		while (!fin) {

			/* Parcours en profondeur de l'arbre, on descend le plus possible
			dans les fils */
			while (cour != NULL) {
				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			/* On dépile un élément, on l'affiche et on se place sur son frère */
			/* Puisque tous les éléments de l'arbre rentrent dans la pile, on peut
			les afficher au fur et à mesure que l'on dépile */
			depiler(pileArbre, &cour);
			printf("%c ", cour->valeur);
			cour = cour->frere;

			/* On s'arrète quand on a parcouru tout l'arbre */
			if (estVidePile(pileArbre) && cour == NULL) {
				fin = 1;
			}
		}

		printf("\n");
		/* Il faut libérer la mémoire utilisée par la pile */
		libererPile(pileArbre);

	}
}


void afficherArbrePref(elemArbre_t * arbre) {
	char fin = 0;

	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);

	if (pileArbre != NULL) {
		printf("Représentation préfixée :\n\t");
		while (!fin) {

			while (cour != NULL) {
				printf("%c ", cour->valeur);

				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			if (!estVidePile(pileArbre)) {
				depiler(pileArbre, &cour);
				cour = cour->frere;

			} else {
				fin = 1;
			}
		}

		printf("\n");
		libererPile(pileArbre);

	}
}
