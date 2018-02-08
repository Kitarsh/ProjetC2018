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
    matAllouer(pMat3, nbLig_1, nbCol_1);
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
    //----------------------------https://stackoverflow.com/questions/3498035/git-add-all-files-modified-deleted-and-untracked
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
	for(int j=0;j<(A->NbCol);j++){
		//trouver le pivot (valeur sur la colonne j qui a la plus grande valeur absolue)
		double max, p;
		p = 0;
		max = matAccElt(A,p,j);
		for(int i=1;i<A->NbLig;i++){
			if(fabs(matAccElt(A,i,j))>fabs(max)){
				p=i;
				max=matAccElt(A,p,j);
			}
		}
		//la methode echoue si le pivot est nul
		if(max==0){
			errMsg(4);
		}
		//permute les lignes p et j
		matPermLig(A, p, j);
		matPermLig(B, p, j);
		//reecrit les lignes
		for(int i=j+1;j<(A->NbCol);i++){
			double z = matAccElt(A,i,i)/matAccElt(A,j,j);
			matCombLin(A, j, z, i);
			matCombLin(B, j, z, i);
		}
	}
}

void opRemontee(T_Mat *A, T_Mat *B, T_Mat* X){
	
}

void opResSystLin(T_Mat *A, T_Mat *B){
	
}
