/* operations sur les matrices */

/*
 * fonction : opAddAlloc
 * Description : addition de deux matrices AVEC allocation de
 * memoire pour la matrice resultat
 * remarque : pMatDest n'a pas encore ete initialise
 */
void opAddAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMatDest);


/*
 * fonction : opSubAlloc
 * Description : soustraction de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 *  remarque : pMatDest n'a pas encore ete initialise
 */
void opSubAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3);


/*
 * fonction : opMulAlloc
 * Description : multiplication de deux matrices AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulAlloc(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3);


/*
 * fonction : opMul
 * Description : multiplication de deux matrices SANS allocation de
 *	memoire pour la matrice resultat
 */
void opMul(T_Mat *pMat1,T_Mat *pMat2,T_Mat *pMat3);  


/*
 * fonction : opMulScalAlloc
 * Description : multiplication d'une matrice par scalaire AVEC allocation de
 *	memoire pour la matrice resultat
 */
void opMulScalAlloc(T_Mat *pMat1,double scal,T_Mat *pMat2);


/*
 * fonction : opPuis
 * Description : callul la puissance d'une  matrice 
 * avec allocation dans pMat2
 */
void opPuis(T_Mat *pMat1,int Expo,T_Mat *pMat2);



/*
 * fonction : opNorme_1
 * Description : callul de la norme 1 
 */
double opNorme_1(T_Mat *pMat);





/*
 * fonction : opNorme_2
 * Description : callul de la norme 2 
 */

double opNorme_2(T_Mat *pMat);



/*
 * fonction : opNorme INF
 * Description : callul de la norme INF 
 */
double opNorme_inf(T_Mat *pMat);

/*
 * fonction : opTriangularisation
 * Triangule le systeme AX=B en modifiant les matrices A et B
 */
void opTriang(T_Mat *A, T_Mat *B);

/*
 * fonction : opRemontee
 * A partir d'un systeme trangularisé
 * remonte le resultat X et le stocke dans la matrice colonne X
 */
void opRemontee(T_Mat *A, T_Mat *B, T_Mat* X);

/*
 * fonction opResolutionSystemeLineaire
 * en utilisant la methode de Gauss,
 * resoud le systeme AX=B en triangularisant puis calculant X
 * affiche les valeurs de X, puis libere la memoire. 
 */
void opResSystLin(T_Mat *A, T_Mat *B);
