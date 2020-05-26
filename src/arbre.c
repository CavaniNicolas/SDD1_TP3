/* -------------------------------------------------------------------------- */
/* Nom du fichier : arbre.c                                                   */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : Manipuler les arbres                                            */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "pilefile/pile.h"
#include "arbre.h"
#include "fctChaines.h"


/*════════════════════════════════════════════════════════════════════════════*/
/* ------------- Fonctions de création de la notation algébrique ------------ */
/*════════════════════════════════════════════════════════════════════════════*/


char * recupNotaAlgebrique(char * filename) {
	FILE * file = fopen(filename, "r");
	int  taille = 100;

	char caractere = 0;
	int i = 0;

	char * notation = (char *)calloc(taille, sizeof(char));;

	if (file != NULL && notation != NULL) {

		do {
			caractere = fgetc(file);

			if (caractere >= 33 && caractere <= 126) {

				if (i == taille - 2) {
					agrandirChaine(&notation, &taille);
				}

				if (notation != NULL) {
					notation[i] = caractere;
					i++;
				}
			}

		} while (caractere != EOF && notation != NULL);

		notation[i] = '\0';
		ecoTailleChaine(&notation, i+1);

		fclose(file);
	}
	return notation;
}



/*════════════════════════════════════════════════════════════════════════════*/
/* ------------ Fonctions de création et de traitement de l'arbre ----------- */
/*════════════════════════════════════════════════════════════════════════════*/


elemArbre_t * creerElemArbre() {
	elemArbre_t * elemArbre = (elemArbre_t *)malloc(sizeof(elemArbre_t));

	if (elemArbre != NULL) {
		elemArbre->fils = NULL;
		elemArbre->frere = NULL;

	} else {
		printf("Erreur mémoire lors de l'allocation d'un nouvel élément\n");
	}

	return elemArbre;
}


elemArbre_t * creerArbreNotaAlgebrique(char * notation) {
	int i          = 0;
	int codeErreur = 0;
	int taille     = tailleChaine(notation);

	pile_t * pileArbre = initPile(taille/2);

	elemArbre_t * arbre = creerElemArbre();
	elemArbre_t * cour = arbre;
	elemArbre_t * nouvElem = NULL;
	empiler(pileArbre, cour);

	if (arbre != NULL && pileArbre != NULL) {
		while (notation[i] != '\0' && codeErreur == 0) {

			if (notation[i] == '*') {

				nouvElem = creerElemArbre();
				if (nouvElem != NULL) {
					cour->fils = nouvElem;
					cour = nouvElem;

				} else {
					codeErreur = 1;
				}

			} else if (notation[i] == '+') {

				depiler(pileArbre, &cour);
				nouvElem = creerElemArbre();

				if (nouvElem != NULL) {
					cour->frere = nouvElem;
					cour = nouvElem;
					empiler(pileArbre, cour);

				} else {
					codeErreur = 1;
				}

			} else if (notation[i] == '(') {
				empiler(pileArbre, cour);

			} else if (notation[i] == ')') {
				depiler(pileArbre, &cour);

			} else {
				cour->valeur = notation[i];
			}
			i++;
		}

		libererPile(pileArbre);

		if (codeErreur == 1) {
			libererArbre(&arbre);
		}

	}
	return arbre;
}


elemArbre_t * rechercherValeur(elemArbre_t * arbre, char valeur) {
	char fin    = 0;
	char trouve = 0;

	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);

	if (pileArbre != NULL) {
		while (!fin) {

			while (cour != NULL && !trouve) {

				if (cour->valeur == valeur) {
					trouve = 1;

				} else {
					empiler(pileArbre, cour);
					cour = cour->fils;
				}
			}

			if (!estVidePile(pileArbre) && !trouve) {
				depiler(pileArbre, &cour);
				cour = cour->frere;

			} else {
				fin = 1;
			}
		}
		libererPile(pileArbre);
	}

	if (!trouve) {
		printf("La valeur n'a pas été trouvée\n");
		cour = NULL;
	}
	return cour;
}


char insererFils(elemArbre_t * arbre, char valeurPere, char nouvValeur) {
	char codeErreur = 0;

	elemArbre_t * nouvElem = creerElemArbre();

	if (nouvElem != NULL) {
		nouvElem->valeur = nouvValeur;

		elemArbre_t * cour = rechercherValeur(arbre, valeurPere);
		elemArbre_t ** prec = &cour->fils;
		cour = cour->fils;

		if (cour != NULL) {

			while (cour != NULL) {
				prec = &cour->frere;
				cour = cour->frere;
			}

		}
		*prec = nouvElem;

	} else {
		codeErreur = 1;
	}
	return codeErreur;
}


char libererArbre(elemArbre_t ** arbre) {
	char fin = 0;
	char codeErreur = 0;

	elemArbre_t * prec = *arbre;
	elemArbre_t * cour = *arbre;
	pile_t * pileArbre = initPile(10);


	if (*arbre != NULL && pileArbre != NULL) {
		while (!fin) {

			while (cour != NULL) {
				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			if (!estVidePile(pileArbre)) {
				depiler(pileArbre, &cour);
				prec = cour;
				cour = cour->frere;
				free(prec);

			} else {
				fin = 1;
			}
		}

	} else {
		codeErreur = 1;
	}

	libererPile(pileArbre);

	(*arbre) = NULL;

	return codeErreur;
}
