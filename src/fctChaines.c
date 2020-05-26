/* -------------------------------------------------------------------------- */
/* Nom du fichier : fctChaines.c                                              */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : Traiter les chaines de caractères                               */
/* -------------------------------------------------------------------------- */

#include <stdlib.h>
#include "fctChaines.h"


/*════════════════════════════════════════════════════════════════════════════*/
/* ------------- Fonctions utilitaires de traitement de chaines ------------- */
/*════════════════════════════════════════════════════════════════════════════*/


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


char agrandirChaine(char ** chaine, int * taille) {
	char codeErreur = 0;

	int nvTaille = (3 * *taille) / 2 + 1;
	char * nvChaine = (char *)realloc(*chaine, nvTaille * sizeof(char));

	if (nvChaine != NULL) {
		*chaine = nvChaine;
		*taille = nvTaille;

	} else {
		codeErreur = 1;
		free(*chaine);
	}

	return codeErreur;
}


char ecoTailleChaine(char ** chaine, int nvTaille) {
	char codeErreur = 0;
	char * nvChaine = (char *)realloc(*chaine, nvTaille * sizeof(char));

	if (nvChaine != NULL) {
		*chaine = nvChaine;

	} else {
		codeErreur = 1;
	}

	return codeErreur;
}


char * entierEnChaine(int entier) {
	int i       = 0;
	int taille  = 1;
	int entier2 = entier;

	if (entier2 > 0) {

		while (entier2 > 0) {
			taille ++;
			entier2 = entier2 / 10;
		}

	} else {
		taille = 2;
	}

	char * chaine = (char *)malloc(taille * sizeof(char));

	if (chaine != NULL) {

		for (i=0; i<taille; i++) {
			chaine[i] = (entier % 10) + '0';
			entier = entier / 10;
		}
		i--;

		chaine[i] = '\0';
	}

	inverserChaine(chaine);

	return chaine;
}


void inverserChaine(char * chaine) {
	int  taille  = tailleChaine(chaine);
	char charTmp = 0;

	for (int i=0; i<taille/2; i++) {
		charTmp = chaine[i];
		chaine[i] = chaine[taille-i-1];
		chaine[taille-i-1] = charTmp;
	}
}
