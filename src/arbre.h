
#ifndef ARBRE_H
#define ARBRE_H


typedef char typeArbre;


typedef struct elemArbre{
	typeArbre          valeur;
	struct elemArbre * fils;
	struct elemArbre * frere;
} elemArbre_t;


char * recupNotaAlgebrique(char * filename);



#endif
