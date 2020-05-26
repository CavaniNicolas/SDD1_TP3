/* -------------------------------------------------------------------------- */
/* Nom du fichier : arbre.h                                                   */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : Manipuler les arbres                                            */
/*                                                                            */
/* Fonctions :                                                                */
/*                                                                            */
/* ------------- Fonctions de création de la notation algébrique ------------ */
/*  - recupNotaAlgebrique                                                     */
/*                                                                            */
/* ------------ Fonctions de création et de traitement de l'arbre ----------- */
/*  - creerElemArbre                                                          */
/*  - creerArbreNotaAlgebrique                                                */
/*  - rechercherValeur                                                        */
/*  - insererFils                                                             */
/*  - libererArbre                                                            */
/* -------------------------------------------------------------------------- */


#ifndef ARBRE_H
#define ARBRE_H


/* -------------------------------------------------------------------------- */
/* struct elemArbre (typedef elemArbre_t) : Structure d'un élément de l'arbre */
/*       valeur (char)               : valeur de cet element                  */
/*       fils   (struct elemArbre *) : pointeur sur le fils de cet element    */
/*       frere  (struct elemArbre *) : pointeur sur le frere de cet element   */
/* -------------------------------------------------------------------------- */
typedef struct elemArbre{
	char valeur;
	struct elemArbre * fils;
	struct elemArbre * frere;
} elemArbre_t;



/*════════════════════════════════════════════════════════════════════════════*/
/* ------------- Fonctions de création de la notation algébrique ------------ */
/*════════════════════════════════════════════════════════════════════════════*/


/* -------------------------------------------------------------------------- */
/* recupNotaAlgebrique                                                        */
/*       Recupere la notation algébrique dans un fichier                      */
/*                                                                            */
/* En entrée: filename (char *) : nom du fichier contenant la notation        */
/*                                                                            */
/* En sortie: notation (char *) : chaine de caractères, notation algebrique   */
/* -------------------------------------------------------------------------- */
char * recupNotaAlgebrique(char * filename);



/*════════════════════════════════════════════════════════════════════════════*/
/* ------------ Fonctions de création et de traitement de l'arbre ----------- */
/*════════════════════════════════════════════════════════════════════════════*/


/* -------------------------------------------------------------------------- */
/* creerElemArbre                                                             */
/*       Creer un nouvel element vide dans l'arbre                            */
/*       La valeur de cet element n'est pas initilisée                        */
/*                                                                            */
/* En entrée: (void)                                                          */
/*                                                                            */
/* En sortie: elemArbre (elemArbre_t *) : element créé                        */
/* -------------------------------------------------------------------------- */
elemArbre_t * creerElemArbre();


/* -------------------------------------------------------------------------- */
/* creerArbreNotaAlgebrique                                                   */
/*       Creer un arbre à partir d'une notation algébrique                    */
/*                                                                            */
/* En entrée: notation (char *) : notation algébrique                         */
/*                                                                            */
/* En sortie: arbre (elemArbre_t *) pointeur sur la racine de l'arbre         */
/* -------------------------------------------------------------------------- */
elemArbre_t * creerArbreNotaAlgebrique(char * notation);


/* -------------------------------------------------------------------------- */
/* rechercherValeur                                                           */
/*       Recherche dans l'arbre l'élément contenant la valeur passée          */
/*                                                                            */
/* En entrée: arbre (elemArbre_t *) : pointeur sur la racine de l'arbre       */
/*            valeur (char) : valeur à rechercher dans l'arbre                */
/*                                                                            */
/* En sortie: cour (elemArbre_t *) : pointeur sur l'element contenant la      */
/*                           valeur, NULL si la valeur n'a pas été trouvée    */
/* -------------------------------------------------------------------------- */
elemArbre_t * rechercherValeur(elemArbre_t * arbre, char valeur);


/* -------------------------------------------------------------------------- */
/* insererFils                                                                */
/*       Insère un fils contenant nouvValeur à l'élément contenant valeurPere */
/*       s'il existe                                                          */
/*                                                                            */
/* En entrée: arbre (elemArbre_t *) : pointeur sur la racine de l'arbre       */
/*            valeurPere (char) : valeur à chercher dans l'arbre pour y       */
/*                                inserer le fils                             */
/*            nouvValeur (char) : valeur du nouvel element fils               */
/*                                                                            */
/* En sortie: codeErreur (char) : booléen d'erreur, 1 si erreur 0 sinon       */
/* -------------------------------------------------------------------------- */
char insererFils(elemArbre_t * arbre, char valeurPere, char nouvValeur);


/* -------------------------------------------------------------------------- */
/* libererArbre                                                               */
/*            Libere la memoire, free tous les éléments de l'arbre            */
/*                                                                            */
/* En entrée: arbre (elemArbre_t **) : pointeur sur la racine de l'arbre      */
/*                                     passé par adresse                      */
/*                                                                            */
/* En sortie: codeErreur (char) : booléen d'erreur, 1 si erreur 0 sinon       */
/* -------------------------------------------------------------------------- */
char libererArbre(elemArbre_t ** arbre);


#endif
