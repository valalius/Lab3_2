#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define eps 0.0001

double f (double x);
double half(double x1, double x2, int n_count, int N);
double chord(double x1, double x2, int n_count, int N);

int main()
{
    int N, method, n_count=0;
    double x1, x2;
    double result;
    clock_t time;
    double total_t;

    printf(" Choose the preferable method:");
    printf("\n\t For interval halving press 1");
    printf("\n\t For chords press 2");
    printf("\n Your choice: ");
    scanf("%u", &method);
    while (method!=1&&method!=2)
    {
        scanf("%u", &method);
    }

    printf(" Please enter the following:");
    do
    {
        printf("\n\tX1: ");
        scanf("%lf", &x1);
        printf("\n\tX2: ");
        scanf("%lf", &x2);
    } while (f(x1)*f(x2)>0);

    printf("\n\tN: ");
    scanf("%u", &N);

    system("cls");
    switch (method)
    {
        time=clock();
        case 1:
        {
            result = half(x1,x2, n_count, N);
        }
        break;

        case 2:
        {
            result = chord(x1, x2, n_count, N);
        }
        break;

    }
    time=clock()-time;
    total_t = ((double)time)/CLOCKS_PER_SEC;
    printf ("Time spent: %.2lf seconds\n", total_t);
    return 0;
}

double half(double x1, double x2, int n_count, int N)
{
    double xi;
    unsigned int choice, const_n;
    const_n=N;

    do
    {
        n_count++;
        xi=(x1+x2)/2;
        if(f(xi)*f(x1)>0)
        {
            x1=xi;
        }
        else
        {
            x2=xi;
        }
        if (n_count%N==0)
        {
            printf (" Number of completed iterations: %u", n_count);
            printf ("\n Current X is: %.3lf", xi);
            printf ("\n Current f(x)= %.3lf", f(xi));
            printf ("\n\n What do you want to do next?");
            printf ("\n\t 1. Continue with the same number of iterations");
            printf ("\n\t 2. Count till the root is found");
            printf ("\n\t 3. Exit end show current result");
            printf ("\n Your answer: ");
            scanf ("%u", &choice);
            printf ("--------------------------------------------------------\n");
            while (choice!=1&&choice!=2&&choice!=3)
            {
                scanf("%u", &choice);
            }
;           if(choice == 1)
            {
                 N=N+const_n;
            }
            if(choice == 2)
            {
                N=N+n_count;
            }
            if(choice == 3)
            {
                break;
            }
        }
    }while(fabs(x1-x2)>=eps);
    printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
    return xi;
}

double chord (double x1, double x2, int n_count, int N)
{
    double xi, xl;
    unsigned int choice, const_n;
    const_n=N;

    do{
        n_count++;
        xl=xi;
        xi=x2-f(x2)*(x1-x2)/(f(x1)-f(x2));
        x1=x2;
        x2=xl;

            if (n_count%N==0)
            {
                printf (" Number of completed iterations: %u", n_count);
                printf ("\n Current X is: %.3lf", xi);
                printf ("\n Current f(x): %.3lf", f(xi));
                printf ("\n\n What do you want to do next?");
                printf ("\n\t 1. Continue with the same number of iterations");
                printf ("\n\t 2. Count till the root is found");
                printf ("\n\t 3. Exit end show current result");
                printf ("\n Your answer: ");
                scanf ("%u", &choice);
                printf ("--------------------------------------------------------\n");
                while (choice!=1&&choice!=2&&choice!=3)
                {
                    scanf("%u", &choice);
                }
                if(choice == 1)
                {
                    N=N+const_n;
                }
                if(choice == 2)
                {
                    N=N+n_count;
                }
                if(choice == 3)
                {
                break;
                }
            }
        }while(fabs(xi-x2)>eps);
        printf ("\nX= %.3lf\tf(x)= %.3lf\n", xi, f(xi));
        return xi;
}

double f (double x)
{
    double y;
    y=0.5*pow((x+250),3)-pow((x-125),2)+500;
    return y;
}
