/*
28607223 Loyau-kahn Felix
28607459 El atia Nadia
3801873 Gojak Zlatan
*/

#include <stdlib.h>
#include <stdio.h>

#define N 2

void prodmatmat(double *a,double *b,double *p,int n){
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

int main(int argc, char const *argv[]) {
  int k;
  double *matrice1 = malloc(N*N*sizeof(double));
  double *matrice2 = malloc(N*N*sizeof(double));
  double *final = malloc(N*N*sizeof(double));
  matrice1[0] = 1;
  matrice1[1] = 2;
  matrice1[2] = 3;
  matrice1[3] = 4;
  matrice2[0] = 5;
  matrice2[1] = 6;
  matrice2[2] = 7;
  matrice2[3] = 8;

  prodmatmat(matrice1,matrice2,final,N);
  for (int i = 0;i<N;i++){
    for (int j = 0;j<N;j++){
      k = i*N + j;
      printf("%.1f",final[k]);
    }
    printf("\n");
  }
  return 0;
}
