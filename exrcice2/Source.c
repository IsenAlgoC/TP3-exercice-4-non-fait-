

#include <stdio.h>
#include <math.h>

int main() {
	int nombre = 2868838400;
	int nbit, noctet;
	noctet = sizeof(nombre);
	printf("le nombre d'octet est %d", sizeof(nombre));
	nbit = noctet*8;
	printf("le nombre de bit utilisé est  %d ", nbit);
	for (int i = 0;i<nbit; i++) {
		int tmp;
		tmp = (nombre & 1);
		if (tmp == 1)
		{
			printf("bit %d :on \n", i+1);/*, afficher ON quand le bit vaut 1*/
		}
		else 
		{
			printf("bit %d :off \n", i+1);/* OFF quand il vaut 0*/
		}
		nombre >>= 1;/*décalage à droite du nombre pour lire le prochain bit*/
	}
	printf("merci \n Bye");/*affichage du message de courtoisie et du bye*/

	return 0;
}

