/* ------------------------------------------------ */
/* Nom du fichier : arbre.h                         */
/* Date de creation : Avril 2020                    */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31) */
/* Objectif : manipuler les arbres                  */
/* Fonctions :                                      */
/*  - recupNotaAlgebrique                           */
/*  - creerElemArbre                                */
/*  - creerArbreNotaAlgebrique                      */
/*  - charFinChaine                                 */
/*  - tailleChaine                                  */
/*  - copierChaine                                  */
/*  - afficherArbre                                 */
/*  - afficherValeur                                */
/*  - libererArbre                                  */
/* ------------------------------------------------ */

#ifndef ARBRE_H
#define ARBRE_H


typedef struct elemArbre{
	char valeur;
	struct elemArbre * fils;
	struct elemArbre * frere;
} elemArbre_t;


/* ------------------------------------------------------------------------- */
/* recupNotaAlgebrique                                                       */
/*              Recupere la notation algébrique dans un fichier              */
/*                                                                           */
/* En entrée : filename (char *) : nom du fichier contenant la notation      */
/*                                                                           */
/* En sortie : notation (char *) : chaine de caractères, notation algebrique */
/* ------------------------------------------------------------------------- */
char * recupNotaAlgebrique(char * filename);


/* ------------------------------------------------------------------------- */
/* creerElemArbre                                                            */
/*       Creer un nouvel element vide dans l'arbre                           */
/*                                                                           */
/* En entrée : (void)                                                        */
/*                                                                           */
/* En sortie : elemArbre (elemArbre_t *) : element créé                      */
/* ------------------------------------------------------------------------- */
elemArbre_t * creerElemArbre();


/* ------------------------------------------------------------------------- */
/* creerArbreNotaAlgebrique                                                  */
/*          Creer un arbre à partir d'une notation algébrique                */
/*                                                                           */
/* En entrée : notation (char *) : notation algébrique                       */
/*                                                                           */
/* En sortie : arbre (elemArbre_t *) pointeur sur la racine de l'arbre       */
/* ------------------------------------------------------------------------- */
elemArbre_t * creerArbreNotaAlgebrique(char * notation);


/* ------------------------------------------------------------------------- */
/* charFinChaine                                                             */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* En entrée : chaine (char *) : chaine de charactères                       */
/*             taille (int *)  : taille de la chaine                         */
/*                                                                           */
/* En sortie :                                                               */
/* ------------------------------------------------------------------------- */
void charFinChaine(char * chaine, int * taille);


/* ------------------------------------------------------------------------- */
/* tailleChaine                                                              */
/*                                                                           */
/* En entrée :                                                               */
/*                                                                           */
/* En sortie :                                                               */
/* ------------------------------------------------------------------------- */
int tailleChaine(char * chaine);


/* ------------------------------------------------------------------------- */
/* copierChaine                                                              */
/*                                                                           */
/* En entrée :                                                               */
/*                                                                           */
/* En sortie :                                                               */
/* ------------------------------------------------------------------------- */
void copierChaine(char * chaine1, char * chaine2);


/* ------------------------------------------------------------------------- */
/* afficherArbre                                                             */
/*                                                                           */
/* En entrée :                                                               */
/*                                                                           */
/* En sortie :                                                               */
/* ------------------------------------------------------------------------- */
void afficherArbre(elemArbre_t * arbre);


/* ------------------------------------------------------------------------- */
/* afficherValeur                                                            */
/*                                                                           */
/* En entrée :                                                               */
/*                                                                           */
/* En sortie :                                                               */
/* ------------------------------------------------------------------------- */
void afficherValeur(elemArbre_t * elemArbre);


/* ------------------------------------------------------------------------- */
/* libererArbre                                                              */
/*                                                                           */
/* En entrée :                                                               */
/*                                                                           */
/* En sortie :                                                               */
/* ------------------------------------------------------------------------- */
void libererArbre(elemArbre_t ** arbre);


#endif
