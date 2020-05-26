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

	elemArbre_t * cour = arbre; /* Pointeur courant pour parcourir l'arbre */
	pile_t * pileArbre = initPile(10); /* Pile utilisée pour parcourir l'arbre */
	/* represPost : Tableau contenant la representation postfixée de l'arbre */
	char * represPost = (char *)malloc(taille * sizeof(char));

	/* Si les allocations mémoires ont réussies alors : */
	if (pileArbre != NULL && represPost != NULL) {

		/* Tant qu'on a pas finit les actions */
		while (!fin) {

			/* Parcours en profondeur de l'arbre, on descend le plus possible
			dans les fils */
			while (cour != NULL) {
				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			/* On dépile un élément, on l'insère et on se place sur son frère */
			/* Puisque tous les éléments de l'arbre rentrent dans la pile, on peut
			les ajouter à represPost au fur et à mesure que l'on dépile */
			depiler(pileArbre, &cour);
			ajouterValeurRepres(&represPost, cour, &nbElem, &taille);
			cour = cour->frere;

			/* On s'arrète si :
			- la manip est finie (soit que la pile est vide et cour == NULL)
			- ou si represPost a été free (cad lors d'un ajout d'une valeur,
			l'aggrandissement du tableau était nécessaire mais n'a pas aboutie) */
			if ((estVidePile(pileArbre) && cour == NULL) && represPost != NULL) {
				fin = 1;
			}
		}

		/* Fin de chaine + redimmension pour economiser la mémoire */
		represPost[nbElem] = '\0';
		ecoTailleChaine(&represPost, nbElem+1);

	/* Il faut libérer la mémoire utilisée par le tableau si la pile n'a pas pu être allouée */
	} else {
		free(represPost);
	}
	/* Il faut libérer la mémoire utilisée par la pile dans tous les cas */
	libererPile(pileArbre);

	/* Retourn represPost ou NULL */
	return represPost;
}


char ajouterValeurRepres(char ** repres, elemArbre_t * elemArbre, int * nbElem, int * taille) {
	int  i          = 0; /* Compteur pour parcourir compteurChar */
	char codeErreur = 0; /* Code d'erreur, 0 si pas d'erreur, 1 sinon */

	/* On compte le nombre de fils de l'élément */
	int compteur = compterFils(elemArbre);
	/* Ce nombre est transformé de entier à chaine de caractères, cela va être utile si la
	fratrie contient plus de 10 frères (cad plus de un caractère char à inserer à la repres) */
	char * compteurChar = entierEnChaine(compteur);
	/* On compte la taille de compteurChar pour savoir combien de cases il va
	falloir remplir dans repres */
	int tailleChar = tailleChaine(compteurChar);

	/* Il faut peut être redimmensionner le tableau s'il est trop petit */
	while (*nbElem > (*taille - tailleChar - 4)) {
		codeErreur = agrandirChaine(repres, taille);
	}

	/* S'il n'y a pas eu d'erreur lors de l'aggrandissement de la chaine */
	if (!codeErreur) {

		/* La representation est directement remplie avec des '(' ',' ')'
		"(valeur,nbFils)(valeur,nbFils)(..." */
		(*repres)[*nbElem] = '(';
		(*repres)[*nbElem+1] = elemArbre->valeur;
		(*repres)[*nbElem+2] = ',';
		*nbElem += 3;

		/* Ce qui permet alors d'entrer dans le tableau de caractères un nombre
		de fils supérieur ou égal à 10 (car plus de 1 seul caractère) */
		while (compteurChar[i] != '\0') {
			(*repres)[*nbElem] = compteurChar[i];
			*nbElem += 1;
			i++;
		}

		(*repres)[*nbElem] = ')';
		*nbElem += 1;

	}

	/* On libère la chaine qui contenait le nombre de fils de l'élément */
	free(compteurChar);

	/* Retourne le code erreur */
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
