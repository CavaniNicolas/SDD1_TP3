/* -------------------------------------------------------------------------- */
/* Nom du fichier : fctChaines.h                                              */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : Traiter les chaines de caractères                               */
/*                                                                            */
/* Fonctions :                                                                */
/*                                                                            */
/* ------------- Fonctions utilitaires de traitement de chaines ------------- */
/*  - charFinChaine                                                           */
/*  - tailleChaine                                                            */
/*  - copierChaine                                                            */
/*  - agrandirChaine                                                          */
/*  - ecoTailleChaine                                                         */
/*  - entierEnChaine                                                          */
/*  - inverserChaine                                                          */
/* -------------------------------------------------------------------------- */


#ifndef FCTCHAINES_H
#define FCTCHAINES_H


/*════════════════════════════════════════════════════════════════════════════*/
/* ------------- Fonctions utilitaires de traitement de chaines ------------- */
/*════════════════════════════════════════════════════════════════════════════*/


/* -------------------------------------------------------------------------- */
/* charFinChaine                                                              */
/*     Supprime les characteres de fin de chaine \r et \n si ils existent     */
/*     et modifie la taille de la chaine en consequent                        */
/*                                                                            */
/* En entrée: chaine (char *) : chaine de charactères                         */
/*            taille (int *)  : taille de la chaine                           */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void charFinChaine(char * chaine, int * taille);


/* -------------------------------------------------------------------------- */
/* tailleChaine                                                               */
/*     Calcul la longueur d'une chaine de caracteres, \0 n'est pas compté     */
/*                                                                            */
/* En entrée: chaine (char *) : chaine de caracteres a mesurer                */
/*                                                                            */
/* En sortie: taille (int) : taille de la chaine                              */
/* -------------------------------------------------------------------------- */
int tailleChaine(char * chaine);


/* -------------------------------------------------------------------------- */
/* copierChaine                                                               */
/*             Copie la chaine de caracteres chaine2 dans chaine1             */
/*                                                                            */
/* En entrée: chaine1 (char *) : chaine copiée, celle a remplir               */
/*             chaine2 (char *) : chaine à copier                             */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void copierChaine(char * chaine1, char * chaine2);


/* -------------------------------------------------------------------------- */
/* agrandirChaine                                                             */
/*       Agrandit la chaine de caractères si celle ci est trop petite         */
/*       Si le redimmensionnement n'est pas possible, la chaine est libérée   */
/*       et le codeErreur est retourné                                        */
/*                                                                            */
/* En entrée: chaine (char **) : pointeur sur la chaine à redimmensionner     */
/*                               (passé par addresse)                         */
/*            taille (int *) : taille actuelle de la chaine (par adresse)     */
/*                                                                            */
/* En sortie: codeErreur (char) : booléen d'erreur, 1 si erreur 0 sinon       */
/* -------------------------------------------------------------------------- */
char agrandirChaine(char ** chaine, int * taille);


/* -------------------------------------------------------------------------- */
/* ecoTailleChaine                                                            */
/*       Redimmensionne la chaine de caractère pour libérer la mémoire non    */
/*       utilisée en fin de chaine si cela est possible. Sinon, ne fait rien  */
/*       à la chaine et le codeErreur est retourné                            */
/*                                                                            */
/* En entrée: chaine (char **) : pointeur sur la chaine à redimmensionner     */
/*                               (passé par addresse)                         */
/*            nvTaille (int) : nouvelle taille de la chaine de caractères     */
/*                                                                            */
/* En sortie: codeErreur (char) : booléen d'erreur, 1 si erreur 0 sinon       */
/* -------------------------------------------------------------------------- */
char ecoTailleChaine(char ** chaine, int nvTaille);


/* -------------------------------------------------------------------------- */
/* entierEnChaine                                                             */
/*       Transforme un entier passé en paramètre en chaine de caractères      */
/*       La chaine contenant cet entier est allouée dans cette fonction       */
/*                                                                            */
/* En entrée: entier (int) : entier à transformer                             */
/*                                                                            */
/* En sortie: chaine (char *) : contient l'entier passé en paramètre          */
/* -------------------------------------------------------------------------- */
char * entierEnChaine(int entier);


/* -------------------------------------------------------------------------- */
/* inverserChaine                                                             */
/*       Inverse la chaine de caractères                                      */
/*                                                                            */
/* En entrée: chaine (char *) : chaine à inverser                             */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void inverserChaine(char * chaine);


#endif
