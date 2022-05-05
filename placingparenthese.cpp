#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll evaluate(ll a,ll b,char c){
    if(c=='+'){
        return a+b;
    }
    else if(c=='-'){
        return a-b;
    }
    else{
        return a*b;
    }
}
int main(){
    string s;
    cin>>s;
    int n;
    n=(s.length()+1)/2;
    int d[n];
    char op[n-1];
    for(int i=0;i<2*n;i+=2){
        d[i/2]=s[i]-'0';
    }
    for(int i=1;i<2*n-1;i+=2){
        op[(i-1)/2]=s[i];
    }
    ll m[n][n];
    ll M[n][n];
    for(int i=0;i<n;i++){
        m[i][i]=d[i];
        M[i][i]=d[i];
    }
    int j;
    ll mi,ma;
    ll  w,x,y,z;
    for(int s=1;s<n;s++){
        for(int i=0;i<n-s;i++){
            j=i+s;
            mi=1000000000000;
            ma=-1000000000000;
            for(int k=i;k<j;k++){
                w=evaluate(M[i][k],M[k+1][j],op[k]);
                x=evaluate(M[i][k],m[k+1][j],op[k]);
                y=evaluate(m[i][k],M[k+1][j],op[k]);
                z=evaluate(m[i][k],m[k+1][j],op[k]);

                mi=min(mi,w);
                mi=min(mi,x);
                mi=min(mi,y);
                mi=min(mi,z);

                ma=max(ma,w);
                ma=max(ma,x);
                ma=max(ma,y);
                ma=max(ma,z);
            }
            m[i][j]=mi;
            M[i][j]=ma;
        }
    }
    cout<<M[0][n-1]<<endl;
}