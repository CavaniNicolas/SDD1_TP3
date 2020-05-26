/* -------------------------------------------------------------------------- */
/* Nom du fichier : represPost.h                                              */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : Créer et Afficher la representation postfixée d'un arbre        */
/*                                                                            */
/* Fonctions :                                                                */
/*                                                                            */
/* -------------- Fonctions liées à la representation postfixée ------------- */
/*  - creerRepresPost                                                         */
/*  - ajouterValeurRepres                                                     */
/*  - compterFils                                                             */
/*  - afficherRepres                                                          */
/* -------------------------------------------------------------------------- */


#ifndef REPRESPOST_H
#define REPRESPOST_H


/*════════════════════════════════════════════════════════════════════════════*/
/* -------------- Fonctions liées à la representation postfixée ------------- */
/*════════════════════════════════════════════════════════════════════════════*/


/* -------------------------------------------------------------------------- */
/* creerRepresPost                                                            */
/*       Creer la representation postfixée de l'arbre et la stock dans un     */
/*       tableau contigue                                                     */
/*                                                                            */
/* En entrée: arbre (elemArbre_t *) : pointeur sur la racine de l'arbre       */
/*                                                                            */
/* En sortie: represPost (char *) : pointeur sur le tableau contigue          */
/*                                  contenant la representation postfixée     */
/* -------------------------------------------------------------------------- */
char * creerRepresPost(elemArbre_t * arbre);


/* -------------------------------------------------------------------------- */
/* ajouterValeurRepres                                                        */
/*       Remplie le tableau (la representation) avec la valeur courante       */
/*       Le tableau est agrandit si il n'est pas assez grand                  */
/*                                                                            */
/* En entrée: repres (char **) : chaine de caractere, representation (prefixée*/
/*                            ou postfixée)                                   */
/*            elemArbre (elemArbre_t *) : element courant dont la valeur est  */
/*                                        à inserer dans la representation    */
/*            nbElem (int *) : compteur, indice pour remplir le tableau       */
/*                           (par adresse)                                    */
/*            taille (int *) : taille du tableau repres (par adresse)         */
/*                                                                            */
/* En sortie: codeErreur (char) : booléen d'erreur, 1 si erreur 0 sinon       */
/* -------------------------------------------------------------------------- */
char ajouterValeurRepres(char ** repres, elemArbre_t * elemArbre, int * nbElem,
							int * taille);


/* -------------------------------------------------------------------------- */
/* compterFils                                                                */
/*       Compte le nombre de fils de l'élément passé en paramètre             */
/*                                                                            */
/* En entrée: elemArbre (elemArbre_t *) : élément dont il faut compter le     */
/*                                        nombre de fils                      */
/*                                                                            */
/* En sortie: compeur (int) : nombre de fils de l'élément                     */
/* -------------------------------------------------------------------------- */
int compterFils(elemArbre_t * elemArbre);


/* -------------------------------------------------------------------------- */
/* afficherRepres                                                             */
/*       Affiche la representation passée en parametre                        */
/*                                                                            */
/* En entrée: repres (char *) : chaine de caracteres, representation          */
/*                              (prefixée ou postfixée)                       */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void afficherRepres(char * repres);


#endif
