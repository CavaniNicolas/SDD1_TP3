/* -------------------------------------------------------------------------- */
/* Nom du fichier : arbre.h                                                   */
/* Date de creation : Avril 2020                                              */
/* Auteurs : Cavani Nicolas et Leduque Adrien (G31)                           */
/* Objectif : manipuler les arbres                                            */
/* Fonctions :                                                                */
/*  - recupNotaAlgebrique                                                     */
/*  - creerElemArbre                                                          */
/*  - creerArbreNotaAlgebrique                                                */
/*                                                                            */
/*  - libererArbre                                                            */
/*                                                                            */
/*  - creerRepresPost                                                         */
/*  - ajouterValeurRepres                                                     */
/*  - afficherRepres                                                          */
/*  - rechercherValeur                                                        */
/*  - insererFils                                                             */
/*                                                                            */
/*  - afficherArbre                                                           */
/*  - actuTabFreres                                                           */
/*  - afficherValeur                                                          */
/*  - afficherArbrePost                                                       */
/*  - afficherArbrePref                                                       */
/*                                                                            */
/*  - charFinChaine                                                           */
/*  - tailleChaine                                                            */
/*  - copierChaine                                                            */
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


/* -------------------------------------------------------------------------- */
/* recupNotaAlgebrique                                                        */
/*       Recupere la notation algébrique dans un fichier                      */
/*                                                                            */
/* En entrée: filename (char *) : nom du fichier contenant la notation        */
/*                                                                            */
/* En sortie: notation (char *) : chaine de caractères, notation algebrique   */
/* -------------------------------------------------------------------------- */
char * recupNotaAlgebrique(char * filename);


/* -------------------------------------------------------------------------- */
/* actualiserTailleChaine                                                     */
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
char actualiserTailleChaine(char ** chaine, int * taille);


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
/*                                                                            */
/* En entrée: repres (char) : chaine de caractere, representation (prefixée   */
/*                            ou postfixée)                                   */
/*            elemArbre (elemArbre_t *) : element courant dont la valeur est  */
/*                                        à inserer dans la representation    */
/*            nbElem (int) : compteur, indice pour remplir le tableau         */
/*                                                                            */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void ajouterValeurRepres(char * repres, elemArbre_t * elemArbre, int nbElem);


/* -------------------------------------------------------------------------- */
/* afficherRepres                                                             */
/*       Affiche la representation passée en parametre                        */
/*                                                                            */
/* En entrée: repres (char *) : chaine de caracteres, representation          */
/*                              (prefixée ou postfixée)                       */
/* En sortie: (void)                                                          */
/* -------------------------------------------------------------------------- */
void afficherRepres(char * repres);


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




/* ------------- Fonctions utilitaires de traitement de chaines ------------- */


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


#endif
