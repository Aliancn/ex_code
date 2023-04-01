#include <stdio.h>
#define N 100000
 
int b[N];   //定义一个全局变量
 
int gcd(int num1, int num2)   //求最大公约数
{
    return num2 == 0 ? num1 : gcd(num2, num1 % num2);
}
 
int fun(int a[] ,int n)   //判断解是不是有无穷个
{
    int t = a[0];
    for (int i = 1; i < n; i++)
        t = gcd(t, a[i]);
    if (t > 1)   return 1;
    return 0;   //若返回1，则说明有无穷个解
}
 
void judge(int a[], int n)    //判断有多少个解
{
    b[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = a[i - 1]; j < N; j++)
            if (b[j - a[i - 1]] == 1)
                b[j] = 1;//j 比 j - a[i-1] 多了个 a[ i -1 ]
}
 
int result(int b[])   //如果是有穷解的话，判断有多少个结果
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (b[i] != 1)
            count++;
    return count;
}
 
int main()
{
    int n, i, a[101];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (fun(a, n))
        printf("INF\n");
    else
    {
        judge(a, n);
        printf("%d", result(b));
    }
    return 0;
}