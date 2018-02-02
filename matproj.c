#include "op.h"
#include "es.h"
#include "mat.h"

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
		scanf("%c",&input); //input du choix
		switch(input){
			case 'A':
			case 'a': //Addition
				T_mat *t1,*t2,*t_res;
				printf("1ere matrice\n");
				printf("\n");
				esSaisir(t1);
				printf("2e matrice\n");
				printf("\n");
				esSaisir(t2);
				opAddAlloc(t1,t2,t_res);
				esAfficher(t_res);
				break;
			case 'S':
			case 's': //Soustraction
				T_mat *t1,*t2,*t_res;
				printf("1ere matrice\n");
				printf("\n");
				esSaisir(t1);
				printf("2e matrice\n");
				printf("\n");
				esSaisir(t2);
				opSubAlloc(t1,t2,t_res);
				esAfficher(t_res);
				break;
			case 'm':
			case 'M': //Multiplication
				T_mat *t1,*t2,*t_res;
				printf("1ere matrice\n");
				printf("\n");
				esSaisir(t1);
				printf("2e matrice\n");
				printf("\n");
				esSaisir(t2);
				break;
			case 'p':
			case 'P': //Puissance d'une matrice
				T_mat *t1,*t_res;
				printf("la matrice\n");
				printf("\n");
				esSaisir(t1);
				int exposant;
				printf("Exposant: ");
				scanf("%d",&exposant); //saisie de l'exposant
				opPuis(t1,exposant,t_res);
				esAfficher(t_res);
				break;
			case 'q':
			case 'Q': //Quitter
				keep=0; //le programme s'arrêtera.
				break;
		}
	}
}
