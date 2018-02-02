#include "mat.h"

typedef struct
  { int Type;
    int NbLig;
    int NbCol;
    double *Elts;
  }T_Mat;

/*
 * fonction matAllouer
 * Description: Initialise la structure reperee par pMat
 *   pour qu'elle puisse contenir une matrice ayant
 *   Nblig lignes et NbCol colones 
 */
void matAllouer(T_Mat *pMat, int NbLig, int NbCol){
	pMat->NbLig = NbLig;
	pMat->NbCol = NbCol;
	pMat->Elts = (double*) malloc(sizeof(double)*NbLig*NbCol);
}

/*
 * fonction matNbLig
 * Description: retourne le nombre de lignes de la matrice
 *   reperee par pMat
 */
int matNbLig(T_Mat *pMat){
	return(pMat->NbLig);
}

/*
 * fonction matNbCol
 * Description: retourne le nombre de colonnes de la matrice
 *   reperee par pMat
 */
int matNbCol(T_Mat *pMat){
	return(pMat->NbCol);
}

/*
 * fonction matAccElt
 * Description: retourne la valeur de  l'element en position (Lig,Col)
 *    de la matrice pointee par pMat
 */
double matAccElt(T_Mat *pMat,int Lig, int Col){
	return((pMat->Elts)[Col + Lig*(pMat->NbCol)]);
}

/*
 * fonction matModifElt
 * Description: Affecte Val a l'element en position (Lig,Col) de 
 *  la matrice reperee par pMat
 */
void matModifElt(T_Mat *pMat, int Lig, int Col,double Val){
	(pMat->Elts)[Col+Lig*(pMat->NbCol)]=Val;
}


/*
 * fonction : matLiberer
 * Description : libère la place occupée par la matrice repérée par pMat
 */
void matLiberer(T_Mat *pMat){
	free(pMat->Elts);
}


/*
 * fonction : matUnite
 * Description : cree une matrice identite de dimension Dim reperer par pMat 
 */
void matUnite(T_Mat *pMat, int Dim){
	matAllouer(pMat,Dim,Dim);
	for(int lig = 0; lig < Dim; lig++){
        matModifElt(pMat, lig, lig, 1);
    }
}


/*
 * fonction : matInit
 * Description : initialise une matrice deja creee a une valeur Val donnee
 */
void matInit(T_Mat *pMat, double Val){
	for(int lig = 0; lig < (pMat->NbLig); lig++){
		for(int col=0; col<(pMat->NbCol);col++){
			matModifElt(pMat, lig, col, Val);
		}
    }
}


/*
 * fonction : matCopy
 * Description : copie une matrice, repere par pMat1 dans une autre
 *	reperee par pMat2 
 */
void matCopy(T_Mat *pMat1, T_Mat *pMat2){
	//if((pMat1->NbLig!=pMat2->NbLig)||(pMat1->NbCol!=pMat2->NbCol)){
		//erreur ??
	//}
	for(int lig = 0; lig < (pMat1->NbLig); lig++){
		for(int col=0; col<(pMat1->NbCol);col++){
			matModifElt(pMat2, lig, col, matAccElt(pMat1,lig,col));
		}
    }
}

