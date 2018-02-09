#include <stdio.h>
#include <stdlib.h>
#include "mat.h"
#include "op.h"
#include "es.h"

void main(){
	int keep=1;
	while(keep){ //Tant que le programme doit continuer de tourner
		printf("Operation souhaitee:\n");
		printf("Addition de deux matrices...............: A\n");
		printf("Soustraction de deux matrices...........: S\n");
		printf("Multiplication de deux matrices.........: M\n");
		printf("Puissance d'une matrice.................: P\n");
		printf("Resolution de systeme lineaire..........: R\n");
		printf("Resolution LU...........................: L\n");
		printf("Quitter le programme.....................: Q\n");
		printf("\n");
		printf("Votre choix=====================> ");
		char input;
		scanf(" %c",&input); //input du choix
		T_Mat t1,t2,t_res;
		T_Mat B,Y,X;
		int exposant;
		switch(input){
			case 'A':
			case 'a':{ //Addition
				//initialiser
				printf("1ere matrice\n");
				printf("\n");
				esSaisir(&t1);
				printf("2e matrice\n");
				printf("\n");
				esSaisir(&t2);
				//additionner
				opAddAlloc(&t1,&t2,&t_res);
				//afficher le resultat
				esAfficher(&t_res);
				//liberer t_res
				matLiberer(&t_res);
				break;
			}
			case 'S':
			case 's':{ //Soustraction
				//initialiser
				printf("1ere matrice\n");
				printf("\n");
				esSaisir(&t1);
				printf("2e matrice\n");
				printf("\n");
				esSaisir(&t2);
				//soustraire
				opSubAlloc(&t1,&t2,&t_res);
				//afficher
				esAfficher(&t_res);
				//liberer t_res
				matLiberer(&t_res);
				break;
			}
			case 'm':
			case 'M':{ //Multiplication
				//initialiser
				printf("1ere matrice\n");
				printf("\n");
				esSaisir(&t1);
				printf("2e matrice\n");
				printf("\n");
				esSaisir(&t2);
				//soustraire
				opMulAlloc(&t1,&t2,&t_res);
				//afficher
				esAfficher(&t_res);
				//liberer t_res
				matLiberer(&t_res);
				break;
			}
			case 'p':
			case 'P':{ //Puissance d'une matrice
				//initialiser
				printf("la matrice\n");
				printf("\n");
				esSaisir(&t1);
				//saisie de l'exposant
				printf("Exposant: ");
				scanf(" %d",&exposant);
				//puissance
				opPuis(&t1, exposant,&t_res);
				//afficher
				esAfficher(&t_res);
				//liberer t_res
				matLiberer(&t_res);
				break;
			}
			case 'r':
			case 'R':
			{
				// resolution de systeme lineaire
				//saisie de la matrice A
				printf("La matrice A\n\n");
				esSaisir(&t1);
				//saisie de la matrice B
				printf("Le vecteur B\n\n");
				esSaisir(&t2);
				//resolution de systeme lineaire
				opResSystLin(&t1, &t2, &t_res);
				//afficher
				esAfficher(&t_res);
				//liberer les variables
				matLiberer(&t1);
				matLiberer(&t2);
				matLiberer(&t_res);
				break;
			}
			case 'l':
			case 'L':{ //resolution LU
				//saisie de la matrice A
				printf("La matrice A\n\n");
				esSaisir(&t1);
				//decomposition LU : L=t2, U=t_res
				opDecompLu(&t1, &t2, &t_res);
				//saisie de la matrice B
				printf("Le vecteur B\n\n");
				esSaisir(&B);
				//Descente pour calculer Y tel que LY=B
				opDescente(&t2, &Y, &B);
				//Remontee pour calculer X tel que UX=Y
				opRemontee(&t_res, &Y, &X);
				//afficher
				esAfficher(&X);
				//liberer les variables
				matLiberer(&t1);
				matLiberer(&t2);
				matLiberer(&t_res);
				matLiberer(&X);
				matLiberer(&Y);
				matLiberer(&B);
				break;
			}
			case 'q':
			case 'Q':{ //Quitter
				keep=0; //le programme s'arrêtera.
				break;
			}
		}
	}
}
