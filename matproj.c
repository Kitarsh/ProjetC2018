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
		printf("Puissance d'une matrice..................: P\n");
		printf("Quitter le programme.....................: Q\n");
		printf("\n");
		printf("Votre choix=====================> ");
		char input;
		scanf(" %c",&input); //input du choix
		T_Mat t1,t2,t_res;
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
			case 'q':
			case 'Q':{ //Quitter
				keep=0; //le programme s'arrêtera.
				break;
			}
		}
	}
}
