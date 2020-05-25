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
	while (*nbElem > (*taille - tailleChar + 4)) {
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
/*Fonctions a demander a l'utilisateur de la bibliotheque :
inserer un element
liberer un element
afficher un element, cette fonction doit retourner une chaine caractere correspondant a la valeur (qui peut etre de nimporte quel type)*/


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
	char fin = 0;

	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);

	if (pileArbre != NULL) {

		printf("Représentation postfixée :\n\t");
		while (!fin) {

			// Parcours classique de l'arbre (en profondeur)
			while (cour != NULL) {
				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			depiler(pileArbre, &cour);
			printf("%c", cour->valeur);
			cour = cour->frere;

			if (estVidePile(pileArbre) && cour == NULL) {
				fin = 1;
			}
		}

		printf("\n");
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
				printf("%c", cour->valeur);

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
