
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
void matAllouer(T_Mat *pMat, int NbLig, int NbCol);

/*
 * fonction matNbLig
 * Description: retourne le nombre de lignes de la matrice
 *   reperee par pMat
 */
int matNbLig(T_Mat *pMat);

/*
 * fonction matNbCol
 * Description: retourne le nombre de colonnes de la matrice
 *   reperee par pMat
 */
int matNbCol(T_Mat *pMat);

/*
 * fonction matAccElt
 * Description: retourne la valeur de  l'element en position (Lig,Col)
 *    de la matrice pointee par pMat
 */
double matAccElt(T_Mat *pMat,int Lig, int Col);

/*
 * fonction matModifElt
 * Description: Affecte Val a l'element en position (Lig,Col) de 
 *  la matrice reperee par pMat
 */
void matModifElt(T_Mat *pMat, int Lig, int Col,double Val);


/*
 * fonction : matLiberer
 * Description : Affiche a l'ecran le contenu de la matrice reperee par pMAt
 */
void matLiberer(T_Mat *pMat);


/*
 * fonction : matUnite
 * Description : cree une matrice unite de dimension Dim reperer par pMat 
 */
void matUnite(T_Mat *pMat, int Dim);


/*
 * fonction : matInit
 * Description : initialise une matrice deja creee a une valeur Val donnee
 */
void matInit(T_Mat *pMat, double Val);


/*
 * fonction : matCopy
 * Description : copie une matrice, repere par pMat1 dans une autre
 *	reperee par pMat2 
 */
void matCopy(T_Mat *pMat1, T_Mat *pMat2);


/* 
 * fonction matPermLig
 * Description : permute deux lignes de la matrice  : lig1 et lig2
 *                teste si L1 = L2
 */

void matPermLig(T_Mat *pMat, int lig1, int lig2);

/*
 * fonction : matCombLin
 * Description : effectue une combinaison linéaire de la ligne 1 et affecte le résultat dans la ligne 2
 *          Combinaison linéaire :    L2 <- a * L1 + b
 */

void matCombLin(T_Mat *pMat, int lig1, double a, double b, int lig2);