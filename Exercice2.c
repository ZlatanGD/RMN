#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    double start,stop;
    start=clock();
    
    int n;
    printf("Rentrer la dimension de votre matrice.\n");
    scanf("%d",&n);

    //printf("Matrice A\n");
    //double *a = malloc((sizeof(double))*n*n);
    double a[n*n];
    for(int i = 0; i<n;i++)
    {
        for(int g = 0; g<n;g++)
        {
            *(a+i*n+g) = (rand()%(3)-1);
            printf("%.1f ",*(a+i*n+g));

        }printf("\n");
    }
    free(a);
    printf("\n");

    //double *b = malloc((sizeof(double))*n*n);
    double b[n*n];
    for(int j = 0; j<n;j++)
    {
        for(int k = 0; k<n;k++)
        {
            *(b+j*n+k) = (rand()%(3)-1);
            printf("%.1f ",*(b+j*n+k));

        }printf("\n");
    }
    free(b);

    /*double *p*n;
    p = malloc((sizeof(double))*n);
    free(p);*/

    //printf("\n");
    stop=clock();
    double k;
    k= (stop-start)/1000 ;
    printf("Le temps d'exucution est T=%f. \n",k);

    return 0;
}
/*
Les resultats, en utilisant la formulation optimisé:
Pour n=10, T=0.325000
Pour n=100, T=8.141000
Pour n=500, T=183.541000

Les resultats, en utilisant la formulation classique:
Pour n=10, T=0.304000
Pour n=100, T=10.580000
Pour n=500, T=282,415

On se rend compte, qu'en augmentant la taille de la matrice,
la formulation optimisé plus efficace que la formulation classique.
*/