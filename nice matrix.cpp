#include <bits/stdc++.h>
#define ll long long
#define p 1000000007
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        ll count=0;
        for(int j=0;j<m/2;j++){
            for(int i=0;i<n/2;i++){
                ll s=(a[i][j]+a[i][m-j-1]+a[n-i-1][j]+a[n-i-1][m-j-1]);
                s=s/4;
                count+=abs(a[i][j]-s)+abs(a[i][m-j-1]-s)+abs(a[n-i-1][j]-s)+abs(a[n-i-1][m-j-1]-s);
            }
        }
        int i=n,j=m;
        if(n%2!=0){
            for(int j=0;j<m/2;j++){
            count+=abs(a[n/2][j]-a[n/2][m-1-j]);}
        }
        if(m%2!=0){
            for(int i=0;i<n/2;i++){
            count+=abs(a[i][m/2]-a[n-1-i][m/2]);}
        }
        cout<<count<<"\n";
        
    }
}