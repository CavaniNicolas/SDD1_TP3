/* -------------------------------------------------------------------------- */
/* Nom du fichier : arbre.h                                                   */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : manipuler les arbres                                            */
/* Fonctions :                                                                */
/*  - recupNotaAlgebrique                                                     */
/*  - creerElemArbre                                                          */
/*  - creerArbreNotaAlgebrique                                                */
/*  - charFinChaine                                                           */
/*  - tailleChaine                                                            */
/*  - copierChaine                                                            */
/*  - afficherArbre                                                           */
/*  - initTabFreres                                                           */
/*  - afficherValeur                                                          */
/*  - actuTabFreres                                                           */
/*  - afficherArbrePre                                                        */
/*  - libererArbre                                                            */
/* -------------------------------------------------------------------------- */

#ifndef ARBRE_H
#define ARBRE_H


typedef struct elemArbre{
	char valeur;
	struct elemArbre * fils;
	struct elemArbre * frere;
} elemArbre_t;


/* -------------------------------------------------------------------------- */
/* recupNotaAlgebrique                                                        */
/*              Recupere la notation algébrique dans un fichier               */
/*                                                                            */
/* En entrée : filename (char *) : nom du fichier contenant la notation       */
/*                                                                            */
/* En sortie : notation (char *) : chaine de caractères, notation algebrique  */
/* -------------------------------------------------------------------------- */
char * recupNotaAlgebrique(char * filename);


/* -------------------------------------------------------------------------- */
/* creerElemArbre                                                             */
/*                 Creer un nouvel element vide dans l'arbre                  */
/*                                                                            */
/* En entrée : (void)                                                         */
/*                                                                            */
/* En sortie : elemArbre (elemArbre_t *) : element créé                       */
/* -------------------------------------------------------------------------- */
elemArbre_t * creerElemArbre();


/* -------------------------------------------------------------------------- */
/* creerArbreNotaAlgebrique                                                   */
/*             Creer un arbre à partir d'une notation algébrique              */
/*                                                                            */
/* En entrée : notation (char *) : notation algébrique                        */
/*                                                                            */
/* En sortie : arbre (elemArbre_t *) pointeur sur la racine de l'arbre        */
/* -------------------------------------------------------------------------- */
elemArbre_t * creerArbreNotaAlgebrique(char * notation);


/* -------------------------------------------------------------------------- */
/* charFinChaine                                                              */
/*     Supprime les characteres de fin de chaine \r et \n si ils existent     */
/*     et modifie la taille de la chaine en consequent                        */
/*                                                                            */
/* En entrée : chaine (char *) : chaine de charactères                        */
/*             taille (int *)  : taille de la chaine                          */
/*                                                                            */
/* En sortie : (void)                                                         */
/* -------------------------------------------------------------------------- */
void charFinChaine(char * chaine, int * taille);


/* -------------------------------------------------------------------------- */
/* tailleChaine                                                               */
/*     Calcul la longueur d'une chaine de caracteres, \0 n'est pas compté     */
/*                                                                            */
/* En entrée : chaine (char *) : chaine de caracteres a mesurer               */
/*                                                                            */
/* En sortie : taille (int) : taille de la chaine                             */
/* -------------------------------------------------------------------------- */
int tailleChaine(char * chaine);


/* -------------------------------------------------------------------------- */
/* copierChaine                                                               */
/*             Copie la chaine de caracteres chaine2 dans chaine1             */
/*                                                                            */
/* En entrée : chaine1 (char *) : chaine copiée, celle a remplir              */
/*             chaine2 (char *) : chaine à copier                             */
/*                                                                            */
/* En sortie : (void)                                                         */
/* -------------------------------------------------------------------------- */
void copierChaine(char * chaine1, char * chaine2);


/* -------------------------------------------------------------------------- */
/* afficherArbre                                                              */
/*       Affiche l'arbre de la même manière que la commande tree              */
/*                                                                            */
/* En entrée : arbre (elemArbre_t *) : pointeur sur la racine de l'arbre      */
/*                                                                            */
/* En sortie : (void)                                                         */
/* -------------------------------------------------------------------------- */
void afficherArbre(elemArbre_t * arbre);


/* -------------------------------------------------------------------------- */
/* afficherValeur                                                             */
/*  Affiche la valeur contenu dans un élément de l'arbre passé en paramêtre   */
/*                                                                            */
/* En entrée : elemArbre (elemArbre_t *) : element de l'arbre à aficher       */
/*             niveau (int) : niveau dans l'arbre de la valeur a afficher     */
/*             tabFreres (int *) : tableau de codes Freres pour l'affichage   */
/*                                                                            */
/* En sortie : (void)                                                         */
/* -------------------------------------------------------------------------- */
void afficherValeur(elemArbre_t * elemArbre, int niveau, int * tabFreres);


/* -------------------------------------------------------------------------- */
/* initTabFreres                                                              */
/*       Initialise le tableau de codes Frères pour l'affichage graphique     */
/*       codes dans tabFreres :                                               */
/*       0 : pas de frere                                                     */
/*       1 : des freres avant et après                                        */
/*                                                                            */
/* En entrée : taille (int) : taille du tableau                               */
/*                                                                            */
/* En sortie : tabFreres (int *) : le tableau d'entier contenant que des 0    */
/* -------------------------------------------------------------------------- */
int * initTabFreres(int taille);

//com
void actuTabFreres(elemArbre_t * cour, int niveau, int * tabFreres);


/* -------------------------------------------------------------------------- */
/* afficherArbrePre                                                           */
/*       Affiche les valeurs contenu dans l'arbre dans l'ordre préfixé        */
/*                                                                            */
/* En entrée : arbre (elemArbre_t *) : pointeur sur la racine de l'arbre      */
/*                                                                            */
/* En sortie : (void)                                                         */
/* -------------------------------------------------------------------------- */
void afficherArbrePre(elemArbre_t * arbre);


/* -------------------------------------------------------------------------- */
/* libererArbre                                                               */
/*            Libere la memoire, free tous les éléments de l'arbre            */
/*                                                                            */
/* En entrée : arbre (elemArbre_t **) : pointeur sur la racine de l'arbre     */
/*                                      passé par adresse                     */
/*                                                                            */
/* En sortie : (void)                                                         */
/* -------------------------------------------------------------------------- */
void libererArbre(elemArbre_t ** arbre);


#endif
