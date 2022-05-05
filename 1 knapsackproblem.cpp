#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n,w;
    cin>>n>>w;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int p[n+1][w+1];
    for(int i=0;i<n+1;i++){
        p[i][0]=0;
    }
    for(int i=0;i<w+1;i++){
        p[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(j<a[i]){
                p[i][j]=p[i-1][j];
            }
            else{
                p[i][j]=max(b[i]+p[i-1][j-a[i]],p[i-1][j]);
            }
        }
    }
    cout<<p[n-1][w]<<'\n';
    }
}