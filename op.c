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
        for(int j = 0; j < NbCol1; j++)
        {
            matModifElt(pMatDest, i, j, (matAccElt(pMat1, i, j) + matAccElt(pMat2, i, j));
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
        for(int j = 0; j < NbCol1; j++)
        {
            matModifElt(pMat3, i, j, (matAccElt(pMat1, i, j) - matAccElt(pMat2, i, j));
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
                valTmp += matAccElt(pMat1, i, k) + matAccElt(pMat2, k, j);
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
                valTmp += matAccElt(pMat1, i, k) + matAccElt(pMat2, k, j);
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
    matAllouer(pMat2, nbLig_1, nbCol_1);
    //
    //--------------------------------------------------
    //boucle for pour multiplier et ranger dans pMat2
    //--------------------------------------------------
    for(int i = 0; i < nbLig_1; i++)
    {
        for(int j = 0; j < nbCol_1; j++)
        {
            matModifElt(pMat2, i, j, (matAccElt(pMat1, i, j) * scal);
        }
    }
}


void opPuis(T_Mat *pMat1,int Expo,T_Mat *pMat2)
{
    //--------------------------------
    //allouer pMatTmp
    //--------------------------------
    //
    //--------------------------------------------------
    //boucle for de puissance. détail : enchainement de mult(t1, tTmp, tres) et cpy(tres, tTmp)
    //--------------------------------------------------
}


double opNorme_1(T_Mat *pMat)
{

}


double opNorme_2(T_Mat *pMat)
{

}


double opNorme_inf(T_Mat *pMat)
{

}