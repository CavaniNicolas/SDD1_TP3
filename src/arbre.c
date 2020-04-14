
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"


char * recupNotaAlgebrique(char * filename) {
	FILE * file = fopen(filename, "r");
	char * notation = (char *)malloc(255 * sizeof(char));

	if (file != NULL) {
		fgets(notation, 255, file);

		fclose(file);
	}
	return notation;
}
