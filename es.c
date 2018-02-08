#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mat.h"
#include "es.h"
#include "err.h"

void esSaisir(T_Mat *pMat)
{
    //**je commente un truc pour tester**
    //-------------------------
    //attribution des variables
    //-------------------------
    int nbLig, nbCol;
    double valTmp;
    //
    //-------------------------------------------------
    //demander la taille de la matrice (Ligne, Colonne)
    //-------------------------------------------------
    printf("Nombre de lignes : ");
    scanf("%d",&nbCol);
    printf("\n\n");
    printf("Nombre de colonnes : ");
    scanf("%d",&nbLig);
    printf("\n\n");
    //
    //-----------------------------------------------------------
    //initialisation de la matrice à 0 avec la taille enregistrée
    //-----------------------------------------------------------
    matAllouer(pMat, nbLig, nbCol);
    matInit(pMat, 0);
    //
    //-------------------------------------------------------------------
    //demander le type de matrice (pleine, diag, tridiag, triinf, trisup)
    //-------------------------------------------------------------------
    printf("Type de matrices (1 pleine, 2 diagonale, 3 tridiag., 4 triang. inf., 5 triang. sup., 6 sym.\n ");
    scanf("%d", &(pMat->Type));
    //---------------------------------------------------------------------------------------
    //distinguer les cas, créer la matrice et remplir la matrice en fonction des cases vides.
    //---------------------------------------------------------------------------------------
    switch(pMat->Type){
        case pleine:
            for(int lig = 0; lig < nbLig; lig++)
            {
                for(int col = 0; col < nbCol; col++)
                {
                    printf("Mat[%d,%d] = ", lig, col);
                    scanf("%lg",&valTmp);
                    printf("\n\n");
                    matModifElt(pMat, lig, col, valTmp);
                }
            }
            break;
        case diag:
            for(int lig = 0; lig < nbLig; lig++)
            {
                printf("Mat[%d,%d] = ", lig, lig);
                scanf("%lg",&valTmp);
                printf("\n\n");
                matModifElt(pMat, lig, lig, valTmp);
            }
            break;
        case tridiag:
            for(int lig = 0; lig < nbLig; lig++)
            {
                if(lig != 0){   
                    printf("Mat[%d,%d] = ", lig , lig - 1);
                    scanf("%lg",&valTmp);
                    printf("\n\n");
                    matModifElt(pMat, lig, lig - 1, valTmp);
                }
                printf("Mat[%d,%d] = ", lig, lig);
                scanf("%lg",&valTmp);
                printf("\n\n");
                matModifElt(pMat, lig, lig, valTmp);
                if(lig != nbLig - 1){
                    printf("Mat[%d,%d] = ", lig , lig + 1);
                    scanf("%lg",&valTmp);
                    printf("\n\n");
                    matModifElt(pMat, lig, lig + 1, valTmp);
                }
            }
            break;
        case triinf:
            for(int lig = 0; lig < nbLig; lig++)
            {
                for(int col = 0; col < nbCol; col++)
                {
                    if(lig >= col){
                        printf("Mat[%d,%d] = ", lig, col);
                        scanf("%lg",&valTmp);
                        printf("\n\n");
                        matModifElt(pMat, lig, col, valTmp);
                    }
                }
            }
            break;
        case trisup:
            for(int lig = 0; lig < nbLig; lig++)
            {
                for(int col = 0; col < nbCol; col++)
                {
                    if(lig <= col){
                        printf("Mat[%d,%d] = ", lig, col);
                        scanf("%lg",&valTmp);
                        printf("\n\n");
                        matModifElt(pMat, lig, col, valTmp);
                    }
                }
            }
            break;
        case sym:
            for(int lig = 0; lig < nbLig; lig++)
            {
                for(int col = 0; col < nbCol; col++)
                {
                    if(lig <= col){
                        printf("Mat[%d,%d] = ", lig, col);
                        scanf("%lg",&valTmp);
                        printf("\n\n");
                        matModifElt(pMat, lig, col, valTmp);
                        if((lig != col) && ((lig + col * nbCol) < (nbLig * nbCol))){
                            matModifElt(pMat, col, lig, valTmp);
                        }
                    }
                }
            }
            break;
    }
    printf("%lf\n",matAccElt(pMat,0,0));
    printf("%lf\n",matAccElt(pMat,0,1));
    printf("%lf\n",matAccElt(pMat,1,0));
    printf("%lf\n",matAccElt(pMat,1,1));
    esAfficher(pMat);
}

void esAfficher(T_Mat *pMat){
    for(int i=0; i<pMat->NbLig; i++){
		for(int j=0; j<pMat->NbCol; j++){
			double data = matAccElt(pMat,i,j);
			if(data-(int)data==0){ //si la donne est entiere, on affiche un entier
				printf("%d\t",(int)data);
			}
			else{ //sinon on affiche un double
				printf("%f\t",data);
			}
		}
		printf("\n");
	}
}
