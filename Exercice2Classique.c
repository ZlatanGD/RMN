#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    double start,stop;
    start=clock();

    int n;
    printf("Rentrer la dimension de votre matrice. \n");
    scanf("%d",&n);

    printf("Matrice A\n");
    double a[n][n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
        a[i][j] = (rand()%(3)-1);
        printf("%f ",a[i][j]);
        }
    }
    printf("\n");

    printf("Matrice B\n");
    double b[n][n];
    for(int g = 0; g<n; g++)
    {
        for(int k = 0; k<n; k++)
        {
        b[g][k] = (rand()%(3)-1);
        printf("%f ",b[g][k]);
        }

    }
    printf("\n");

    //double p[n*n];
    stop=clock();
    double k;
    k= (stop-start)/1000 ;
    printf("Le temps d'exucution est T=%f. \n",k);
}