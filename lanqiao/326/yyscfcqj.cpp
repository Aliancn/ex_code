#include <stdio.h>

double a, b, c, d;

double f(double x)
{
    return ((a * x + b) * x + c) * x + d;
}

int main()
{
    double left, right, mid;

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    for (double range = -100.0; range < 101.0; ++range)
    {
        left = range;
        right = range + 1;

        if (f(left) == 0)
            printf("%.2lf ", left);
        else if (f(left) * f(right) < 0)
        {
            do {
                mid = (left + right) / 2;
                if (f(mid) == 0)
                    break;
                else if (f(left) * f(mid) < 0)
                    right = mid;
                else if (f(mid) * f(right) < 0)
                    left = mid;
            } while (right - left >= 0.001);
            printf("%.2lf ", mid);
        }
    }

    return 0;
}