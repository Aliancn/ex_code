#include <iostream>
#include <cstring>
using namespace std;

struct my_int
{
    int len = 0;
    int num[100];
    my_int operator+(const my_int b) const
    {
        my_int c;
        c.len = max(len, b.len);
        for (int i = 1; i <= max(len, b.len); i++)
        {
            c.num[i] = num[i] + b.num[i];
        }
        int temp = 0;
        for (int i = 1; i <= max(len, b.len)+1; i++)
        {
            c.num[i]+=temp;
            temp = c.num[i] / 10;
            c.num[i] %= 10;
        }
        if (c.num[len + 1])
            c.len++;
        return c;
    }
    my_int()
    {
        len = 0;
        memset(num, 0, sizeof(num));
    }
    my_int(string in)
    {
        len = in.length();
        memset(num, 0, sizeof(num));
        for (int i =0;i<len;i++)
        {
            num[len-i] = (int)in[i] - '1' + 1;
        }
    }
    bool operator <( const my_int b)const {
        if (len>b.len) return false;
        if(len<b.len) return true;
        if(len==b.len){
            for(int i=len ;i>0;i--){
                if(num[i]>b.num[i]) return false;
                if(num[i]<b.num[i]) return true;
            }
            if(num[1]==b.num[1]) return false;
            return true;
        }
    }
};

int main()
{
    // 请在此输入您的代码
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    string _a, _n, _b;
    cin >> _a >> _b >> _n;
    my_int sum;
    my_int a(_a), b(_b), n(_n);
    long long day = 1;
    long long ans = 0;
    while (sum < n)
    {
        if (day <= 5)
        {
            sum =sum+a;
        }
        else
        {
            sum =sum+ b;
            if (day == 7)
                day = 0;
        }
        day++;
        ans++;
        // cout<<"ans_now: "<<ans<<endl;
    }
    cout << ans;
    return 0;
}