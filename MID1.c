#include<stdio.h>
#include<math.h>
#include"timer.h"
//#include"eqns.c"

double pi_bbp (int n);
double pi_leibniz (int n);
int adjust_rep_count (int count, double time, double tmin, double tmax);

int main(void)
{
    double pi;
    double to1 = 0.000001, abserr;
    int i, ileibniz, ibbp;
    i=1;

    do //calc pi using leibniz
    {
        pi = pi_leibniz(i);
        abserr = fabs (pi - M_PI);
        printf("%8d %20.15f %20.15f\n", i, pi, abserr);
        i *= 2;
    }
    while (abserr > to1);
    ileibniz = i/2;
    printf("ileibniz = %8d\n", ileibniz);

    i = 1;
    do //calc pi using bbp
    {
        pi = pi_bbp(i);
        abserr = fabs (pi - M_PI);
        printf("%8d %20.15f %20.15f\n", i, pi, abserr);
        i *= 2;
    }
    while (abserr > to1);
    ibbp = i/2;
    printf("ibbp = %8d\n\n\n", ibbp);

    double time, time1, time2;
    int m;
    double tmax = 2.;
    double tmin = 1.;
    int count = 1000;

    printf("BBP Time - \n");
    printf("     Time per Iteration     Total Time     Iterations\n");

    do //time for bbp function
    {
        timer_start();
        for (m = 0; m < count; m++)
        {
            pi_bbp(ibbp);
        }
        time = timer_stop();
        time1 = time / count;
        printf(" %10.6f usec     %10.6f sec     %10d\n", time1 * 0.000001, time, count);
         count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
    printf("\n\n");
    count = 1000;
    printf("Leibniz Time -\n");
    printf("     Time per Iteration     Total Time     Iterations\n");

    do
    {
        timer_start();
        for (m = 0; m < count; m++)
        {
            pi_leibniz (ileibniz);
        }
        time = timer_stop();
        time2 = time / count;
        printf(" %10.6f usec     %10.6f sec     %10d\n", time2 * 0.000001, time, count);
        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
    printf("\n\n");
    double tt = time2 / time1;
    printf("Ratio of Methods - %10.2f\n\n", tt);

    return 0;
}
