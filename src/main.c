/* -------------------------------------------------------------------------- */
/* Nom du fichier : main.c                                                    */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : main pour la manipulation d'arbres                              */
/* Fonctions :                                                                */
/*  - main                                                                    */
/* -------------------------------------------------------------------------- */

#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include "affichageArbre.h"
#include "represPost.h"


int main() {
	/* la notation algébrique de l'arbre que l'on souhaite créer */
	char * notation = recupNotaAlgebrique("notaAlgebrique.txt");
	elemArbre_t * arbre = NULL; /* Pointeur sur la racine de l'arbre */

	if (notation != NULL) {
		printf("Notation Algébrique :\n\t%s\n", notation);
		arbre = creerArbreNotaAlgebrique(notation);

		/* Les fonctions suivantes sont utilisables si arbre != NULL */
		if (arbre != NULL) {
			/* On affiche l'arbre de différentes manières */
			afficherArbre(arbre);
			afficherArbrePost(arbre);
			afficherArbrePref(arbre);

			/* On créer la représentation postfixé de l'arbre */
			char * represPost = creerRepresPost(arbre);
			/* Et on l'affiche s'il n'y a pas eu d'erreur */
			if (represPost != NULL) {
				printf("Représentation postfixée :\n\t");
				afficherRepres(represPost);
			}

			/* On recherche la valeur 'f' dans l'arbre et on la remplace par un '5' */
			elemArbre_t * cour = rechercherValeur(arbre, 'f');
			if (cour != NULL) {
				cour->valeur = '5';
				afficherArbre(arbre);
			}

			/* On insère différentes valeurs dans l'arbre et on l'affiche*/
			insererFils(arbre, 'b', '2');
			insererFils(arbre, 'j', '2');
			insererFils(arbre, 'b', 'x');
			insererFils(arbre, 'b', '1');
			insererFils(arbre, 'b', '3');
			afficherArbre(arbre);

			/* On libère de la mémoire la représentation et l'arbre */
			free(represPost);
			libererArbre(&arbre);

		/* Si arbre == NULL */
		} else {
			printf("L'arbre est vide\n");
		}
	}

	/* On libère de la mémoire la notation algébrique */
	free(notation);

	return 0;
}
