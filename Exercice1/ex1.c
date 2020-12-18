#include <stdio.h>
#define carre(x) (x)*(x)/*macro modifié*/

int main() {
	int Nb = 5;
	printf("on a carre(Nb)=%d \n", carre(5));
	printf("on a carre(Nb+1)= %d", carre(5 + 1));
	/* provblème de priorité */
	/*le code est modifié on a la bonne valeur */

	return 0;
}