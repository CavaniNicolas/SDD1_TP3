/* -------------------------------------------------------------------------- */
/* Nom du fichier : represPost.c                                              */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : Créer et Afficher la representation postfixée d'un arbre        */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "pilefile/pile.h"
#include "represPost.h"
#include "fctChaines.h"


/*════════════════════════════════════════════════════════════════════════════*/
/* -------------- Fonctions liées à la representation postfixée ------------- */
/*════════════════════════════════════════════════════════════════════════════*/


char * creerRepresPost(elemArbre_t * arbre) {
	char fin    = 0;   /* Booléen de fin */
	int  nbElem = 0;   /* Indice pour remplir le tableau au fur et à mesure */
	int  taille = 100; /* Taille du tableau */

	/* Init de la pile et des pointeurs nécessaires */
	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);
	char * represPost = (char *)malloc(taille * sizeof(char));

	/* Si pas de problème de mémoire alors */
	if (pileArbre != NULL && represPost != NULL) {
		while (!fin) {

			// Parcours classqiue de l'arbre
			while (cour != NULL) {
				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			// Chaque valeur est ajoutée a la representation
			depiler(pileArbre, &cour);
			ajouterValeurRepres(&represPost, cour, &nbElem, &taille);
			cour = cour->frere;

			/* On s'arrète si la manip est finie ou si represPost a été free */
			if ((estVidePile(pileArbre) && cour == NULL) && represPost != NULL) {
				fin = 1;
			}
		}

		/* Fin de chaine + redimmension pour economiser la mémoire */
		represPost[nbElem] = '\0';
		ecoTailleChaine(&represPost, nbElem+1);

	} else {
		free(represPost);
	}
	libererPile(pileArbre);

	return represPost;
}


char ajouterValeurRepres(char ** repres, elemArbre_t * elemArbre, int * nbElem, int * taille) {
	int  i          = 0;
	char codeErreur = 0;

	// On compte le nombre de fils de l'élément
	int compteur = compterFils(elemArbre);
	char * compteurChar = entierEnChaine(compteur);
	int tailleChar = tailleChaine(compteurChar);

	// Il faut peut être redimmensionner le tableau s'il est trop petit
	while (*nbElem > (*taille - tailleChar - 4)) {
		codeErreur = agrandirChaine(repres, taille);
	}

	// S'il n'y a pas eu d'erreur lors de l'aggrandissement de la chaine
	if (!codeErreur) {

		// La representation est directement remplie "(valeur,nbFils)(..."
		(*repres)[*nbElem] = '(';
		(*repres)[*nbElem+1] = elemArbre->valeur;
		(*repres)[*nbElem+2] = ',';
		*nbElem += 3;

		// Ce qui permet alors d'entrer dans le tableau de caractères un nombre
		// de fils supérieur ou égal à 10 (car plus de 1 seul caractère)
		while (compteurChar[i] != '\0') {
			(*repres)[*nbElem] = compteurChar[i];
			*nbElem += 1;
			i++;
		}

		(*repres)[*nbElem] = ')';
		*nbElem += 1;

	}

	// On libère la chaine qui contenait le nombre de fils de l'élément
	free(compteurChar);

	return codeErreur;
}


int compterFils(elemArbre_t * elemArbre) {
	int compteur = 0;
	// On se place sur le premier fils
	elemArbre_t * cour = elemArbre->fils;

	// On parcourt tous les freres et incremente le compteur
	while (cour != NULL) {
		compteur ++;
		cour = cour->frere;
	}

	return compteur;
}


void afficherRepres(char * repres) {
	printf("%s\n", repres);
}
