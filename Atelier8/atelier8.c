/*
	- Équipe 4
		3801873 Gojak Zlatan
		3700119 Capy Alexandre
		3803083 Zhang Xu
*/
#include <stdio.h>
#include <math.h>

//Listes des fonctions
double f(double x){return exp(x)-4;}
double fprime(double x){return exp(x);}

double g(double x){return sin(x-3.);}
double gprime(double x){return cos(x-3.);}

double h(double x){return 162*x*x*x-18*x-3;}
double hprime(double x){return 486*x*x-18;}

double p(double x){return 2*x*x-x*x*x-2*x*x*x*x+5*x*x*x*x*x;}
double pprime(double x){return 4*x-3*x*x-8*x*x*x-5*x*x*x*x;}


int bissec(double *z, double (*f)(double), double a, double b, double eps)
{
    double a1, b1, m, fa1, fb1, fm;
    if (b<a)
    {
        a1 = b;
        b1 = a;

    }else
    {
        a1 = a;
        b1 = b;
    }

    fa1 = f(a1);
    fb1 = f(b1);
    if(fa1*fb1 > 0.){return 0;}
    do
    {
        m = (a1 + b1)/2.;
        fm = f(m);
        if (fa1*fm < 0.)
        {
            b1 = m;
            fb1 = fm;
        }else
        {
            a1 = m;
            fa1 = fm;
        }
    } while (fabs(b1 - a1)>eps);
    *z = a1;
    return 1;
}

int newton(double *z, double (*f) (double), double (*fprime)(double), double a, double b, double eps)
{
    double x_plus_un = (a * b)/2.0;
    double x, fprimeX;

    do
    {
        x = x_plus_un;
        fprimeX = fprime(x);

        if(fabs(fprimeX) <= eps)
        {
            return 0;
        }

        x_plus_un = x - (f(x) / fprimeX);
    }while(fabs(x_plus_un - x) > eps);

    *z = x_plus_un;
    return 1;
}

int findzero(double *z, double (*f)(double),double(*fprime)(double), double a, double b, double eps)
{
    double x0;

    if(!bissec(&x0, f, a, b, 0.1))
    {
        return 0;
    }
    return newton(z, f, fprime, x0, x0, eps);
}

int main(void)
{
    double z;
    printf("=====L’algorithme procède par dichotomie=====\n");

    bissec(&z,f ,1.0, 1.5, 10e-8);
    printf("f %le\n", z);

    bissec(&z,g ,-0.5, 0.5, 10e-8);
    printf("g %le\n", z);    
    
    bissec(&z,h ,-1/3, 1.0, 10e-8);
    printf("h %le\n", z);

    bissec(&z,p ,-1.5, 0.5, 10e-8);
    printf("p %le\n", z);
    printf("\n");

    
    printf("=====L’algorithme est basé sur la méthode de Newton=====\n");

    newton(&z, f, fprime, 1.0, 1.5, 10e-8);
    printf("f %le\n", z);

    newton(&z, g, gprime, -0.5, 0.5, 10e-8);
    printf("g %le\n", z);

    newton(&z, h, hprime, -1/3, 1, 10e-8);
    printf("h %le\n", z);

    newton(&z, p, pprime, -1.5, 0.5, 10e-8);
    printf("p %le\n", z);
    printf("\n");

    printf("=====L’algorithme findZero=====\n");

    findzero(&z, f, fprime, 1.0, 1.5, 10e-8);
    printf("f %le\n", z);

    findzero(&z, g, gprime, -0.5, 0.5, 10e-8);
    printf("g %le\n", z);

    findzero(&z, h, hprime, -1/3, 1, 10e-8);
    printf("h %le\n", z);

    findzero(&z, p, pprime, -1.5, 0.5, 10e-8);
    printf("p %le\n", z);
    printf("\n");
    
    return 0;
}
