#include<iostream>
using namespace std;

const int maxn = 3e7;
int d[maxn];
char s[maxn];
int cnt ;

void init (){
    cnt =0;
    s[0]='#';
    char ch=getchar();
    while(ch>='a' && ch<='z'){
        s[++cnt]=ch;
        s[++cnt]='#';
        ch=getchar();
    }
    s[++cnt]='\0';
}
int main(){
    int n;
    cin>>n;
    init();
    int ans =0;
    for(int i=0,l=0,r=-1;i<cnt;i++){
        int k=(i>r)?1:min(d[l+r-i],r-i);
        while(i-k>=0&&i+k<cnt&&s[i-k]==s[i+k]) k++;
        k--;
        d[i]=k;
        if(i+k>r) l=i-k,r=i+k;
        ans = max(ans,d[i]);
    }
    cout<<ans<<endl;
    return 0;
}
