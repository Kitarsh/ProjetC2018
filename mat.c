#include "mat.h"

void matAllouer(T_Mat *pMat, int NbLig, int NbCol){
	pMat->NbLig = NbLig;
	pMat->NbCol = NbCol;
	pMat->Elts = (double*) malloc(sizeof(double)*NbLig*NbCol);
}

int matNbLig(T_Mat *pMat){
	return(pMat->NbLig);
}

int matNbCol(T_Mat *pMat){
	return(pMat->NbCol);
}

double matAccElt(T_Mat *pMat,int Lig, int Col){
	return((pMat->Elts)[Col + Lig*(pMat->NbCol)]);
}

void matModifElt(T_Mat *pMat, int Lig, int Col,double Val){
	(pMat->Elts)[Col+Lig*(pMat->NbCol)]=Val;
}

void matLiberer(T_Mat *pMat){
	free(pMat->Elts);
}

void matUnite(T_Mat *pMat, int Dim){
	matAllouer(pMat,Dim,Dim);
	for(int lig = 0; lig < Dim; lig++){
        matModifElt(pMat, lig, lig, 1);
    }
}

void matInit(T_Mat *pMat, double Val){
	//on suppose que pMat est deja alloue
	for(int lig = 0; lig < (pMat->NbLig); lig++){
		for(int col=0; col<(pMat->NbCol);col++){
			matModifElt(pMat, lig, col, Val);
		}
    }
}

void matCopy(T_Mat *pMat1, T_Mat *pMat2){
	//copie mat1 dans mat2
	//if((pMat1->NbLig!=pMat2->NbLig)||(pMat1->NbCol!=pMat2->NbCol)){
		//erreur ??
	//}
	for(int lig = 0; lig < (pMat1->NbLig); lig++){
		for(int col=0; col<(pMat1->NbCol);col++){
			matModifElt(pMat2, lig, col, matAccElt(pMat1,lig,col));
		}
    }
}

