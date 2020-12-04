#include <stdio.h>
#include <math.h>

//fonction valeur absolue
double absolue(double a) {
    if(a < 0) a=-a;
    return a;
}

double f(double a, double x0, double e, double xs){

    int cpt=1;
    double xn=x0;
    double xnPlus1= (((4. * xn - (3 * a - 2.)) * xn - a) * xn - 2. * a)/(-2. - 2. * a + xn * (- (4. * a - 3.) + 5. * xn));
    double diff=absolue(xnPlus1-xn);
    printf("1 : %.15lf \n", x0);
    for(int i=2;diff>=e;i++){
        cpt++;
        xn=xnPlus1;
        xnPlus1=(((4. * xn - (3 * a - 2.)) * xn - a) * xn - 2. * a)/(-2. - 2. * a + xn * (- (4. * a - 3.) + 5. * xn));
        printf("%d %.15lf \n",cpt, xnPlus1);
        diff=absolue(xnPlus1-xn);
        printf("==-Le rapport : %lf -==\n", (fabs(xnPlus1 - xs))/(fabs(xn-xs)));
        //printf("==- Avec log: %lf -==\n", (-log10(fabs((xnPlus1 - xs)/xs))));
    }
    return xnPlus1;
}

int main(){
    double a;
    printf("\nLa valeur de a =");
    scanf("%lf",&a);
    
    double x0;
    printf("\nLa valeur de x0 =");
    scanf("%lf",&x0);
    
    double e;
    printf("\nLa valeur de e =");
    scanf("%lf",&e);

    double xs;
    printf("\nLa valeur de xs =");
    scanf("%lf",&xs);
    
    double res=f(a,x0,e,xs);
    printf("\nRésultat = %.15lf\n",res);
}