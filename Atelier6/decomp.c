#include <stdio.h>
#include <stdlib.h>

void decomp_LU(float *a, int n)
{
    int i,j,k,il;
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