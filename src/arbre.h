
#ifndef ARBRE_H
#define ARBRE_H


typedef struct elemArbre{
	char valeur;
	struct elemArbre * fils;
	struct elemArbre * frere;
} elemArbre_t;


/* ---------------------------------------------------- */
/* recupNotaAlgebrique                                  */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
char * recupNotaAlgebrique(char * filename);


/* ---------------------------------------------------- */
/* creerElemArbre                                       */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
elemArbre_t * creerElemArbre();


/* ---------------------------------------------------- */
/* creerArbreNotaAlgebrique                             */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
elemArbre_t * creerArbreNotaAlgebrique(char * notation);


/* ---------------------------------------------------- */
/* charFinChaine                                        */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
void charFinChaine(char * chaine, int * taille);


/* ---------------------------------------------------- */
/* tailleChaine                                         */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
int tailleChaine(char * chaine);


/* ---------------------------------------------------- */
/* copierChaine                                         */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
void copierChaine(char * chaine1, char * chaine2);


/* ---------------------------------------------------- */
/* afficherArbre                                        */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
void afficherArbre(elemArbre_t * arbre);


/* ---------------------------------------------------- */
/* afficherValeur                                       */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
void afficherValeur(elemArbre_t * elemArbre);


/* ---------------------------------------------------- */
/* libererArbre                                         */
/*                                                      */
/* En entrée :                                          */
/*                                                      */
/* En sortie :                                          */
/* ---------------------------------------------------- */
void libererArbre(elemArbre_t ** arbre);


#endif
