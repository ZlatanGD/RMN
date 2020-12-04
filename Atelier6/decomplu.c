/*
	- Équipe 3
		3804887 Achek Ranya
		3801873 Gojak Zlatan
		3007353 Dondon Thomas
		3802787 Friguet Nicolas
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define testSize 2

void decomp_LU(float *a, int n)
{
    int i,j,k;
    float aux, aux2;
    for(i=0; i<n-1; i++)
    {
        aux = *(a + i*n + i);
        for(k=i+1; k<n; k++)
            *(a + i*n + k) /= aux;
        for(k=i+1; k<n; k++)
        {
            aux2 = *(a + k*n + i);
            for(j=i+1; j<n; j++)
                *(a + k*n + j) -= aux2 * *(a + i*n +j);
        }
    }
}

void print(float *matrice, int n)
{
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == 0)
            {
                printf("\n");
            }
            printf("%f ", *(matrice + i*n +j));
        }
    }printf("\n\n");
}

void prodmatmat(float *a,float *b,float *p,int n){
  int x;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      x = i*n + j;
      *(p+x) = 0;
      for(int k = 0;k<n;k++){
        *(p+x) += *(a+i*n+k) * *(b+k*n+j);
      }
    }
  }
}

float inv_gj(float *a, int n)
{
    float aux;
    int i,j,k;
    for(i=0; i<n; i++)
    {
        aux = *(a + n*i +i);
        for(j=0; j<n; j++)
            *(a + n*i + j) /= aux;
        *(a + n*i +i) = 1.0/aux;
        for(k=0; k<n; k++)
            if(k!=i)
            {
                aux = *(a + n*k +i);
                for(j=0; j<n; j++)
                    *(a + n*k +j) -= aux * *(a + n*i +j);
                *(a + n*k + i) = - aux* *(a + n*i +i);
            }
    }
}

int main(void)
{
        
float tab[SIZE*SIZE] = 
    {1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 
    1.0, -1.0, 1.0, -1.0, 1.0,
    1.0, -2.0, 4.0, -8.0, 16,
    1.0, -3.0, 9.0, -27.0, 81.0};

printf("\n La matrice A: \n");
print(tab, SIZE);

decomp_LU(tab, SIZE);
printf("\nLa matrice A, decomposé: \n");
print(tab, SIZE);

float tabsup[SIZE*SIZE] = 
    {1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 1.0, -2.0,
    0.0, 0.0, 0.0, 0.0, 1};

printf("La matrice U: \n");
print(tabsup, SIZE);


float tabinf[SIZE*SIZE] = 
    {1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, -1.0, 0.0, 0.0, 0.0,
    1.0, -2.0, 2.0, 0.0, 0.0,
    1.0, -3.0, 6.0, -6.0, 0.0,
    1.0, -4.0, 12.0, -24.0, 24.0};

printf("La matrice L: \n");
print(tabinf, SIZE);

float res[SIZE*SIZE];
float res2[SIZE*SIZE];


prodmatmat(tabinf, tabsup, res, SIZE);
printf("Porduit matriciel de LU, bien egale à A: \n");
print(res, SIZE);

inv_gj(tabinf, SIZE);
printf("Inverse de L: \n");
print(tabinf, SIZE);

inv_gj(tabsup, SIZE);
printf("Inverse de U: \n");
print(tabsup, SIZE);

printf("Porduit des inverse de L et U: \n");
prodmatmat(tabsup, tabinf, res2, SIZE);
print(res2, SIZE);

float matriceA[SIZE*SIZE] = 
    {1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 
    1.0, -1.0, 1.0, -1.0, 1.0,
    1.0, -2.0, 4.0, -8.0, 16,
    1.0, -3.0, 9.0, -27.0, 81.0};

printf("L'inverse de la matrice A, bien égale au produit des inverse des matrices L et U\n");
inv_gj(matriceA, SIZE);
print(matriceA, SIZE);


}