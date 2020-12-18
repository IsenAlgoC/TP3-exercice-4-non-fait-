#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define NBmaxnote 30
#include < math.h >


int main() {
	float Note[NBmaxnote] = { -2 }, note, x = 0, moy=0, somme = 0, max=0, min=20, Ecartype;
	int nnote = 0;/*nombre de note*/
	int nabsent = 0;/*nombre d'absent*/

	for (int i = 0; i < NBmaxnote; i++) {
		printf("Entrer  la note no %d  :\n", i + 1);/*l'utilisateur entre une note*/
		scanf_s("%f", &note);
		if (note > 20 || note < 0) {
			int ch;

			_cputs("éléve absent ou voulez-vous arrêter la saisie des notes ? ,/A/O/N \n");
			do
			{
				ch = _getch();
				ch = toupper(ch);
			} while ((ch != 'A') && (ch != 'O') && (ch != 'N'));
			switch (ch) {
			case 'A':
				printf("élève absent \n");
				Note[i] = -1;
				nabsent += 1;
				continue;/*l'élève absent n'est pas pris en compte dans le calcul de la moyenne et du nombre de note valide*/
			case 'O':
				x = 1;
				break;/*arret de l'ajout des notes*/
			case 'N':
				printf("redonner la note %d \n", i + 1);
				scanf_s("%f", &note);
			}
		}
		if (x == 1) {
			break;
		}
		nnote += 1;
		Note[i] = note;
		somme += note;
		moy = somme / (nnote);
	}
	printf("ls nombre de note valide est %d \n", nnote);
	printf("l nombre d'absent est %d \n", nabsent);
	printf("la moyenne est %.2f \n", moy);
	/*algorithme de comparaison*/
	for (int i = 0; i <( nnote+nabsent); i++)/*le plus grand element*/
	{
		if (Note[i] == -1)
		{
			continue;
		}
		if (max < Note[i])
		{
			max = Note[i];
		}
		if (min > Note[i])
			min = Note[i];
	}
	printf("Le plus grand élément est %f \n", max);/*le plus petit element*/
	printf("Le plus petit élément est %f \n", min);

	/*écart type */
	Ecartype = 0;
	float  difference = 0;
	for (int i = 0; i < (nnote+nabsent); i++)
	{
		if (Note[i] == -1)
		{
			continue;
		}
		difference +=(Note[i] - moy)* (Note[i] - moy);

	}
	Ecartype = (1 / (nnote - 1))*(difference);

	printf("La valeur de l'écart type est %.2f", Ecartype);
	/*affichage du tableau de note */
	for (int i = 0; i < (nnote + nabsent); i++)
	{
		printf("Numero Note : %d  Valeur note : % .2lf\n", i+1, Note[i]);
	}
	/*option*/
	float Copynote[NBmaxnote] = { -2 };/*copie du tableau de note*/
	float Indice[NBmaxnote] = { -2 };/*tableau qui contient les indices*/
	float  tmp, tmp1; // variabes temporaire qui vont nous permettre de permuter les notes  
	for (int i = 0; i < (nnote - nabsent); i++) {
		Copynote[i] = Note[i];
		Indice[i] = (i + 1);

	}

	for (int i = 0; i < (nnote - nabsent); i++) {
		for (int j = 0; j < (nnote - nabsent - 1 - i); j++) {
			if (Copynote[j] < Copynote[j + 1]) {
				tmp = Copynote[j];
				Copynote[j] = Copynote[j + 1];
				Copynote[j + 1] = tmp;

				tmp1 = Indice[j];
				Indice[j] = Indice[j + 1];
				Indice[j + 1] = tmp1;
			}
		}
	}

	for (int i = 0; i < (nnote + nabsent); i++) {
		printf("Numero note : %f || Rang : %d || Valeur note : %.2f\n", Indice[i], i + 1, Copynote[i]);
	}
}


