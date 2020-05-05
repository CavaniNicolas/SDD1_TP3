/* -------------------------------------------------------------------------- */
/* Nom du fichier : arbre.c                                                   */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : manipuler les arbres                                            */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "pilefile/pile.h"
#include "arbre.h"


char * recupNotaAlgebrique(char * filename) {
	FILE * file = fopen(filename, "r");
	int    taille = 0;
	char   ligne[255];
	char * notation = NULL;

	if (file != NULL) {
		fgets(ligne, 255, file);

		taille = tailleChaine(ligne);
		charFinChaine(ligne, &taille);

		notation = (char *)malloc((taille+1) * sizeof(char));

		if (notation != NULL) {
			copierChaine(notation, ligne);
		}

		fclose(file);
	}
	return notation;
}


// enleve les characteres de fin de chaine \r et \n
void charFinChaine(char * chaine, int * taille) {
	if (chaine[*taille-1] == '\n') {
		chaine[*taille-1] = '\0';
		(*taille) -= 1;
	}

	if (chaine[*taille-1] == '\r') {
		chaine[*taille-1] = '\0';
		(*taille) -= 1;
	}
}

//Renvoie la taille de la chaine passée en parametre
//ne compte pas le '\0'
int tailleChaine(char * chaine) {
	int taille = 0;

	while (chaine[taille] != '\0') {
			taille++;
	}
	return taille;
}


void copierChaine(char * chaine1, char * chaine2) {
	int i = 0;

	while (chaine2[i] != '\0') {
		chaine1[i] = chaine2[i];
		i++;
	}
}


elemArbre_t * creerElemArbre() {
	elemArbre_t * elemArbre = (elemArbre_t *)malloc(sizeof(elemArbre_t));

	if (elemArbre != NULL) {
		elemArbre->fils = NULL;
		elemArbre->frere = NULL;
	}

	return elemArbre;
}


elemArbre_t * creerArbreNotaAlgebrique(char * notation) {
	int i = 0;
	int codeErreur = 0;
	int taille = tailleChaine(notation);

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


void afficherArbre(elemArbre_t * arbre) {
	char fin = 0;

	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);

	if (pileArbre != NULL) {
		while (!fin) {

			while (cour != NULL) {
				afficherValeur(cour);

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
		libererPile(pileArbre);
	}
}


void afficherValeur(elemArbre_t * elemArbre) {
	printf("%c", elemArbre->valeur);
}


void libererArbre(elemArbre_t ** arbre) {
	char fin = 0;

	elemArbre_t * cour = *arbre;
	pile_t * pileArbre = initPile(10);
	pile_t * pileArbreLiberation = initPile(10);

	if (*arbre != NULL && pileArbre != NULL && pileArbreLiberation != NULL) {
		while (!fin) {

			while (cour != NULL) {
				empiler(pileArbreLiberation, cour);

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
	}

	libererPile(pileArbre);

	while (!estVidePile(pileArbreLiberation)) {
		depiler(pileArbreLiberation, &cour);
		free(cour);
	}

	libererPile(pileArbreLiberation);
	(*arbre) = NULL;
}
