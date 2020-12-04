#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

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

int main(void)
{
    float tab[SIZE*SIZE] =
        {1.0, 3.0, 3.0,
        9.0, 5.0, 8.0,
        7.0, 4.0, 9.0};

    inv_gj(tab, SIZE);  

    print(tab, SIZE);
}