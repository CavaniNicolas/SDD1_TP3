
#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"


int main() {
	char * notation = recupNotaAlgebrique("notaAlgebrique.txt");
	if (notation != NULL) {
		printf("%s\n", notation);
	}

	free(notation);
	return 0;
}
