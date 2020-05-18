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

		notation = (char *)calloc(taille+1, sizeof(char));

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

	} else {
		printf("Erreur mémoire lors de l'allocation d'un nouvel élément\n");
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
	if (arbre != NULL) {

		char fin = 0;
		int niveau = 0;
		int * tabFreres = (int *)calloc(255, sizeof(int));

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


// variante graphique
// "╠══ "
// "║   "
// "╚══ "
// "    "
void afficherValeur(elemArbre_t * elemArbre, int niveau, int * tabFreres) {
	int i = 0;
	for (i=0; i<niveau; i++) {

		if (tabFreres[i] == 0)
			printf("    ");
		else
			printf("│   ");
	}

	if (elemArbre->frere != NULL)
		printf("├── ");
	else
		printf("└── ");

	printf("%c\n", elemArbre->valeur);
}
/*Fonctions a demander a l'utilisateur de la bibliotheque :
inserer un element
liberer un element
afficher un element, cette fonction doit retourner une chaine caractere correspondant a la valeur (qui peut etre de nimporte quel type)*/


void actuTabFreres(elemArbre_t * cour, int niveau, int * tabFreres) {
	if (cour != NULL) {
		if (cour->frere == NULL)
			tabFreres[niveau] = 0;
		else
			tabFreres[niveau] = 1;
	}
}


void afficherArbrePost(elemArbre_t * arbre) {
	char fin = 0;

	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);

	if (pileArbre != NULL) {
		printf("Représentation postfixée :\n\t");
		while (!fin) {

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


char * creerRepresPost(elemArbre_t * arbre) {
	char fin = 0;
	int nbElem = 0;

	elemArbre_t * cour = arbre;
	pile_t * pileArbre = initPile(10);
	char * represPost = (char *)calloc(100, sizeof(char));

	if (pileArbre != NULL && represPost != NULL) {
		while (!fin) {

			while (cour != NULL) {
				empiler(pileArbre, cour);
				cour = cour->fils;
			}

			depiler(pileArbre, &cour);
			ajouterValeurRepres(represPost, cour, nbElem);
			nbElem += 2;
			cour = cour->frere;

			if (estVidePile(pileArbre) && cour == NULL) {
				fin = 1;
			}
		}

	} else {
		free(represPost);
	}
	libererPile(pileArbre);

	return represPost;
}


// attention a la taille max de represPost
void ajouterValeurRepres(char * repres, elemArbre_t * elemArbre, int nbElem) {
	int compteur = 0;
	elemArbre_t * cour = elemArbre->fils;

	repres[nbElem] = elemArbre->valeur;

	while (cour != NULL) {
		compteur ++;
		cour = cour->frere;
	}

	// fonction a modifier pour pouvoir prendre en compte les fratries de 10 et plus
	if (compteur > 9) {
		compteur = 9;
	}

	repres[nbElem+1] = compteur + '0';
}


void afficherRepres(char * repres) {
	int i = 0;

	printf("Représentation postfixée :\n\t");

	while (repres[i] != '\0') {
		printf("(%c,%c)", repres[i], repres[i+1]);
		i += 2;
	}
	printf("\n");
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



elemArbre_t * rechercherValeur(elemArbre_t * arbre, char valeur) {
	char fin = 0;
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


void insererFils(elemArbre_t * arbre, char valeurPere, char nouvValeur) {

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
	}
}




void libererArbre(elemArbre_t ** arbre) {
	char fin = 0;

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
	}

	libererPile(pileArbre);

	(*arbre) = NULL;
}
