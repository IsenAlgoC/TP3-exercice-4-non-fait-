#include <stdio.h>
#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	printf("o a carre(Nb)=%d \n", carre(5));
	printf("on a carre(Nb+1)= %d", carre(5 + 1));
	/* provbl�me de priorit� */
	/*le code modifi� est */

	return 0;
}