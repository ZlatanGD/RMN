/*
	- Équipe 4D
		3007353 Dondon Thomas
		3801873 Gojak Zlatan
		3800061 Monteiro Philippe
*/

//Exercice2

#include <stdio.h>
#include <stdlib.h>
#include <fenv.h>


void gauss_det(double *a, int n, double *det){
    int i,j,k;
    double aux, aux2;
    *det = 1;
    for(i=0;i<n-1;i++){
        aux = *(a + i*n + i);
        *det *= aux;
        for(k=i+1; k<n; k++)
            *(a + i*n + k) /= aux;
        for(k=i+1;k<n;k++){
            //printf("Test1");
            aux2 = *(a + k*n + i);
            for(j=i+1;j<n;j++)
                *(a + k*n + j) -= aux2 * *(a + i*n + j);
        }
    }
    *det *= *(a + n*n - 1);
}

void init_hilbert(double *h, int n){
    printf("\nVoici la matrice de Hilbert\n");
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(j == 0)
            {
                printf("|");
            }
            *(h+i*n+j)=((double)1/(double)(i+j+1));
            printf("%lf ",*(h+i*n+j));
            if(j == n-1)
            {
                printf("|\n");
            }
        }
    }printf("\n");
}

int main(){
    int choix;
    printf("Choisissez le mode d’arrondi: 0 zero, 1 arr, 2 moinsinf, 3 plusinf. \n");
    scanf("%d",&choix);
    switch(choix){
        case 0 : fesetround(FE_TOWARDZERO); break;
        case 1 : fesetround(FE_TONEAREST); break;
        case 2 : fesetround(FE_DOWNWARD); break;
        case 3 : fesetround(FE_UPWARD); break;
    };

    double mat[]={10,0,-5,15,-2,7,3,0,8,14,1,2,0,-21,1,-1};
    double nvmat[11*11];
    int taille=4;
    int tailleHilbert=11;
    double det;
    gauss_det(mat,taille,&det);
    printf("Le determinant vaut: %.2f\n",det);
    init_hilbert(nvmat,tailleHilbert);

    gauss_det(nvmat,tailleHilbert,&det);
    printf("Le determinant hilbert vaut: %lf\n",det);

    return 0;
}