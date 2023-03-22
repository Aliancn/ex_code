#include <iostream>
using namespace std;
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    char one;
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 60; j++)
        {
            cin >> one;
            cout<<one<<" ";
        }
        cout<<endl;
    }
    return 0;
}