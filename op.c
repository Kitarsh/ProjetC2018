#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mat.h"
#include "err.h"
#include "op.h"

void opAddAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMatDest)
{
    //-------------------------------------------------------------------------
    //recuperer les valeurs de lignes et de colonnes et tester que les matrices
    //sont de la meme taille.
    //-------------------------------------------------------------------------
    int nbLig_1, nbLig_2, nbCol_1, nbCol_2;
    nbLig_1 = matNbLig(pMat1);
    nbLig_2 = matNbLig(pMat2);
    nbCol_1 = matNbCol(pMat1);
    nbCol_2 = matNbCol(pMat2);
    if(nbLig_1 != nbLig_2 || nbCol_1 != nbCol_2)
    {
        errMsg(1);
    }
    //
    //--------------------------------
    //allouer pMatDest
    //--------------------------------
    matAllouer(pMatDest, nbLig_1, nbCol_1);
    //
    //-----------------------------------------------
    //boucle for pour ajouter et ranger dans pMatDest
    //-----------------------------------------------
    for(int i = 0; i < nbLig_1; i++)
    {
        for(int j = 0; j < nbCol_1; j++)
        {
            matModifElt(pMatDest, i, j, (matAccElt(pMat1, i, j) + matAccElt(pMat2, i, j)));
        }
    }
}


void opSubAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3)
{
    //-------------------------------------------------------------------------
    //recuperer les valeurs de lignes et de colonnes et tester que les matrices
    //sont de la meme taille.
    //-------------------------------------------------------------------------
    int nbLig_1, nbLig_2, nbCol_1, nbCol_2;
    nbLig_1 = matNbLig(pMat1);
    nbLig_2 = matNbLig(pMat2);
    nbCol_1 = matNbCol(pMat1);
    nbCol_2 = matNbCol(pMat2);
    if(nbLig_1 != nbLig_2 || nbCol_1 != nbCol_2)
    {
        errMsg(1);
    }
    //
    //--------------------------------
    //allouer pMat3
    //--------------------------------
    matAllouer(pMat3, nbLig_1, nbCol_1);
    //
    //-----------------------------------------------
    //boucle for pour soustraire et ranger dans pMat3
    //-----------------------------------------------
    for(int i = 0; i < nbLig_1; i++)
    {
        for(int j = 0; j < nbCol_1; j++)
        {
            matModifElt(pMat3, i, j, (matAccElt(pMat1, i, j) - matAccElt(pMat2, i, j)));
        }
    }
}


void opMulAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3)
{
    //-------------------------------------------------------------------------
    //recuperer les valeurs de lignes et de colonnes et tester que les matrices
    //sont de la meme taille et que les tailles de matrices correspondent pour 
    //une multiplication.
    //-------------------------------------------------------------------------
    int nbLig_1, nbLig_2, nbCol_1, nbCol_2;
    double valTmp;
    nbLig_1 = matNbLig(pMat1);
    nbLig_2 = matNbLig(pMat2);
    nbCol_1 = matNbCol(pMat1);
    nbCol_2 = matNbCol(pMat2);
    if(nbCol_1 != nbLig_2)
    {
        errMsg(2);
    }
    //
    //--------------------------------
    //allouer pMat3
    //--------------------------------
    matAllouer(pMat3, nbLig_1, nbCol_2);
    //
    //-----------------------------------------------
    //boucle for pour multiplier et ranger dans pMat3
    //-----------------------------------------------
    for(int i = 0; i < nbLig_1; i++)
    {
        for(int j = 0; j < nbCol_2; j++)
        {
            valTmp = 0;
            for(int k = 0; k < nbCol_1; k++)
            {
                valTmp += matAccElt(pMat1, i, k)*matAccElt(pMat2, k, j);
            }
            matModifElt(pMat3, i, j, valTmp);
        }
    }
}


void opMul(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3)
{
    //-------------------------------------------------------------------------
    //recuperer les valeurs de lignes et de colonnes et tester que les matrices
    //sont de la meme taille et que les tailles de matrices correspondent pour 
    //une multiplication.
    //-------------------------------------------------------------------------
    int nbLig_1, nbLig_2, nbCol_1, nbCol_2;
    double valTmp;
    nbLig_1 = matNbLig(pMat1);
    nbLig_2 = matNbLig(pMat2);
    nbCol_1 = matNbCol(pMat1);
    nbCol_2 = matNbCol(pMat2);
    if(nbCol_1 != nbLig_2)
    {
        errMsg(2);
    }
    //
    //-----------------------------------------------
    //boucle for pour multiplier et ranger dans pMat3
    //-----------------------------------------------
    for(int i = 0; i < nbLig_1; i++)
    {
        for(int j = 0; j < nbCol_1; j++)
        {
            valTmp = 0;
            for(int k = 0; k < nbCol_1; k++)
            {
                valTmp += matAccElt(pMat1, i, k)*matAccElt(pMat2, k, j);
            }
            matModifElt(pMat3, i, j, valTmp);
        }
    }

}


void opMulScalAlloc(T_Mat *pMat1,double scal,T_Mat *pMat2)
{
    //--------------------------------
    //allouer pMat2
    //--------------------------------
    int nbLig_1, nbCol_1;
    nbLig_1 = matNbLig(pMat1);
    nbCol_1 = matNbCol(pMat1);
    matAllouer(pMat2, nbLig_1, nbCol_1);
    //
    //--------------------------------------------------
    //boucle for pour multiplier et ranger dans pMat2
    //--------------------------------------------------
    for(int i = 0; i < nbLig_1; i++)
    {
        for(int j = 0; j < nbCol_1; j++)
        {
            matModifElt(pMat2, i, j, (matAccElt(pMat1, i, j) * scal));
        }
    }
}


void opPuis(T_Mat *pMat1,int Expo,T_Mat *pMat2)
{
    //--------------------------------------------------
    //Verifier que pMat2 est de meme dimension que pMat1
    //--------------------------------------------------
    int nbLig_1, nbLig_2, nbCol_1, nbCol_2;
    nbLig_1 = matNbLig(pMat1);
    nbCol_1 = matNbCol(pMat1);
    matAllouer(pMat2, nbLig_1, nbCol_1);
    nbLig_2 = matNbLig(pMat2);
    nbCol_2 = matNbCol(pMat2);
    if(nbLig_1 != nbLig_2 || nbCol_1 != nbCol_2)
    {
        errMsg(1);
    }
    if(nbLig_1 != nbCol_1)
    {
        errMsg(3);
    }
    //
    //--------------------------------
    //allouer pMatTmp et initialiser en matrice identitée
    //--------------------------------
    T_Mat tmp;
    matUnite(&tmp, nbLig_1);
    //
    //--------------------------------------------------
    //boucle for de puissance. détail : enchainement de mult(t1, tTmp, tres) et cpy(tres, tTmp)
    //--------------------------------------------------
    for(int i = 0; i < Expo; i++)
    {
        opMul(pMat1, &tmp, pMat2);
        matCopy(pMat2, &tmp);
    }
    matLiberer(&tmp);
}


double opNorme_1(T_Mat *pMat)
{
    //----------------------------
    //initialisation des variables
    //----------------------------
    double output;
    //
    //----------------
    //boucle de calcul
    //----------------  
    for(int i = 0; i < pMat->NbLig; i++)
    {
        for(int j = 0; j < pMat->NbCol; j++)
        {
            output += abs(matAccElt(pMat, i, j));
        }
    }
    return(output);
}


double opNorme_2(T_Mat *pMat)
{
    //----------------------------
    //initialisation des variables
    //----------------------------
    double output;
    //
    //----------------
    //boucle de calcul
    //----------------
    for(int i = 0; i < pMat->NbLig; i++)
    {
        for(int j = 0; j < pMat->NbCol; j++)
        {
            output += pow(abs(matAccElt(pMat, i, j)), 2);
        }
    }
    output = sqrt(output);
    return(output);
}


double opNorme_inf(T_Mat *pMat)
{
    //----------------------------
    //initialisation des variables
    //----------------------------
    double output = 0;
    double tmp;
    //
    //----------------
    //boucle de calcul
    //----------------
    for(int i = 0; i < pMat->NbLig; i++)
    {
        for(int j = 0; j < pMat->NbCol; j++)
        {
            tmp = matAccElt(pMat, i, i);
            if(abs(tmp) > output)
            {
                output = abs(tmp);
            }
        }
    }
    return(output);
}

void opTriang(T_Mat *A, T_Mat *B){
	for(int j=0;j<(A->NbCol)-1;j++){
		//trouver le pivot (valeur sur la colonne j qui a la plus grande valeur absolue)
		double max;
		int p = j;
		max = matAccElt(A,p,j);
		for(int i=p+1;i<(A->NbLig);i++){
			if(fabs(matAccElt(A,i,j))>fabs(max)){
				p=i;
				max=matAccElt(A,p,j);
			}
		}
		//la methode echoue si le pivot est nul
		if(max==0){
			errMsg(5);
		}
		//permute les lignes p et j
		matPermLig(A, p, j);
		matPermLig(B, p, j);
		//reecrit les lignes
		for(int i=j+1;i<(A->NbCol);i++){
			double z = -matAccElt(A,i,j)/matAccElt(A,j,j);
			matCombLin(A, j, z, i);
			matCombLin(B, j, z, i);
		}
	}
}

void opRemontee(T_Mat *A, T_Mat *B, T_Mat* X){
	matAllouer(X, A->NbLig, 1);
	for(int i=(X->NbLig)-1; i>=0; i--){
		double tempVal=matAccElt(B,i,0);
		for(int j=i+1;j<(X->NbLig);j++){
			tempVal = tempVal - matAccElt(A,i,j)*matAccElt(X,j,0);
		}
		tempVal = tempVal / matAccElt(A,i,i);
		matModifElt(X, i, 0, tempVal);
	}
}

void opResSystLin(T_Mat *A, T_Mat *B, T_Mat* X){
	if(A->NbLig != A->NbCol){
		errMsg(3);
	}
	if(B->NbCol != 1){
		errMsg(4);
	}
	opTriang(A,B);
	opRemontee(A,B,X);
}

void opDescente(T_Mat *L, T_Mat *Y, T_Mat *B)
{
	matAllouer(Y, B->NbLig, 1);
    double tmp;
    for(int i = 0; i < (L->NbLig); i++)
    {
        tmp = matAccElt(B, i, 0);
        for(int j = 0; j < i; j++){
            tmp -= matAccElt(L, i, j) * matAccElt(Y, j, 0);
        }
        matModifElt(Y, i, 0, tmp);
    }
}


void opDecompLu(T_Mat* A, T_Mat* L, T_Mat* U)
{
    //initialisation de L et U a la matrice identitee
    matUnite(L, (A->NbCol));
    matUnite(U, (A->NbCol));
    //creation et allocation d'une matrice Pivot P
    T_Mat P;
    matAllouer(&P, (A->NbLig), (A->NbCol));
    matUnite(&P, (A->NbCol));
    //selection du pivot
    for(int i = 0; i < (A->NbLig); i++)
    {
        int max_j = i;
        for(int j = i; j < (A->NbLig); j++)
        {
            if(fabs(matAccElt(A, j, i) > fabs(matAccElt(A, max_j, i))))
            {
                max_j = i;
            }
        }
        if(max_j != i)
        {
            for(int k = 0; k < (A->NbLig); k++)
            {
                matPermLig(&P, i, max_j);
            }
        }
    }
    //creation et allocation de la matrice comprenant les inversions de pivots.
    T_Mat A2;
    matAllouer(&A2, (A->NbLig), (A->NbCol));
    opMul(A, &P, &A2);
    //application de l'algorithme LU
    for(int i = 0; i < (A->NbLig); i++)
    {
        for(int j = 0; j < (A->NbCol); j++)
        {
            double s;
            if(j <= i)
            {
                for(int k = 0; k < j; k++)
                {
                    s += matAccElt(L, j, k)*matAccElt(U, k, i);
                    matModifElt(U, j, i, matAccElt(&A2, j, i) - s);
                }
            }
            if(j >= i)
            {
                for(int k = 0; k < i; k++)
                {
                    s += matAccElt(L, j, k)*matAccElt(U, k, i);
                    matModifElt(L, j, i, (matAccElt(&A2, j, i)- s)/matAccElt(U, i, i));
                }
            }
        }
    }
    matLiberer(&A2);
    matLiberer(&P);
}
