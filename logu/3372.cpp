#include<iostream>
using namespace std;


int _m,_n;
long long a[100000+5],d[400000+5],b[400000+5];
int num_ans;

void build (int l,int r,int p){
    if(l==r){
        d[p]=a[l];
        return ;
    }
    int m = l+ ((r-l)>>1);
    build(l,m,2*p);
    build(m+1,r,2*p+1);
    d[p]=d[2*p]+d[2*p+1];
    // cout<<"d "<<p<<" "<<d[p]<<endl;
    return ;
}

void added(int l,int r,int c,int s,int t,int p){
    if(l<=s && r>=t){
        d[p]+=(t-s+1)*c;
        b[p]+=c;
        return ;
    }
    int m = s + ((t-s)>>1);
    if(b[p] && s!=t){
        d[2*p] += b[p]*(m-s+1),d[2*p+1]+= b[p]*(t-m);
        b[p*2] += b[p];
        b[p*2+1]+= b[p];
        b[p]=0; 
    }
    if(l<=m) added(l,r,c,s,m,p*2);
    if(r>m) added(l,r,c,m+1,t,p*2+1);
    d[p] = d[p*2] + d[p*2+1];
}


long long getsum(int l,int r,int s,int t,int p){
    // printf("in::%d,%d,%d,%d,%d\n",l,r,s,t,p);
    if(l<=s && r>=t ){
        return d[p];
    }
    int m = s+ ((t-s)>>1);
    long long sum=0;
    if(b[p]){
        d[p*2]+=b[p]*(m-s+1),d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p];
        b[p*2+1]+=b[p];
        b[p]=0;
    }
    // printf("%d: ",1);
    if(l<=m) sum+=getsum(l,r,s,m,2*p);
    //  printf("%d: ",2);
    if(r>m) sum+=getsum(l,r,m+1,t,2*p+1);
    // cout<<"d "<<p<<" "<<sum; 
    // printf("%d,%d,%d,%d,%d\n",l,r,s,t,p);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    cin>>_n>>_m;
    for(int i=1;i<=_n;i++){
        cin>>a[i];
    }
    build(1,_n,1);
    
    for(int i=1;i<=_m;i++){
        int temp;
        cin>>temp ;
        int x,y,k;
        if(temp==1){
            cin>>x>>y>>k;
            added(x,y,k,1,_n,1);
        }
        else{
            // cout<<2<<endl;
            cin>>x>>y;
            // cout<<getsum(x,y,1,n,1)<<endl;
            printf("%ld\n",getsum(x,y,1,_n,1));
        }
    }
    return 0;

}