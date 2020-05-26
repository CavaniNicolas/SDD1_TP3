/* -------------------------------------------------------------------------- */
/* Nom du fichier : affichageArbre.h                                          */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : afficher les arbres                                             */
/*                                                                            */
/* Fonctions :                                                                */
/*                                                                            */
/* --------------------- Fonctions d'affichage de l'arbre ------------------- */
/*  - afficherArbre                                                           */
/*  - actuTabFreres                                                           */
/*  - afficherValeur                                                          */
/*  - afficherArbrePost                                                       */
/*  - afficherArbrePref                                                       */
/* -------------------------------------------------------------------------- */


#ifndef AFFARBRE_H
#define AFFARBRE_H


/*════════════════════════════════════════════════════════════════════════════*/
/* --------------------- Fonctions d'affichage de l'arbre ------------------- */
/*════════════════════════════════════════════════════════════════════════════*/


/* -------------------------------------------------------------------------- */
/* afficherArbre                                                              */
/*       Affiche l'arbre de la même manière que la commande tree              */
/*                                                                            */
/* En entrée: arbre (elemArbre_t *) : pointeur sur la racine de l'arbre       */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void afficherArbre(elemArbre_t * arbre);


/* -------------------------------------------------------------------------- */
/* afficherValeur                                                             */
/*       Affiche la valeur contenu dans un élément de l'arbre passé en        */
/*       paramêtre                                                            */
/*                                                                            */
/* En entrée: elemArbre (elemArbre_t *) : element de l'arbre à afficher       */
/*            niveau (int) : niveau dans l'arbre de la valeur a afficher      */
/*            tabFreres (char *) : tableau de booléens Freres pour l'affichage*/
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void afficherValeur(elemArbre_t * elemArbre, int niveau, char * tabFreres);


/* -------------------------------------------------------------------------- */
/* actuTabFreres                                                              */
/*       Actualise le tableau de code Freres pour l'affichage graphique       */
/*       0 : pas de frere                                                     */
/*       1 : des freres avant et après                                        */
/*                                                                            */
/* En entrée: cour (elemArbre_t *) : element courant de l'arbre à actualiser  */
/*            niveau (int) : niveau dans l'arbre de la valeur a actualiser    */
/*            tabFreres (char *) : tableau de booléens Freres pour l'affichage*/
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void actuTabFreres(elemArbre_t * cour, int niveau, char * tabFreres);


/* -------------------------------------------------------------------------- */
/* afficherArbrePost                                                          */
/*       Affiche les valeurs contenues dans l'arbre dans l'ordre postfixé     */
/*                                                                            */
/* En entrée: arbre (elemArbre_t *) : pointeur sur la racine de l'arbre       */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void afficherArbrePost(elemArbre_t * arbre);


/* -------------------------------------------------------------------------- */
/* afficherArbrePref                                                          */
/*       Affiche les valeurs contenues dans l'arbre dans l'ordre préfixé      */
/*                                                                            */
/* En entrée: arbre (elemArbre_t *) : pointeur sur la racine de l'arbre       */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void afficherArbrePref(elemArbre_t * arbre);


#endif
