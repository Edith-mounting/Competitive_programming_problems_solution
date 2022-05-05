#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int p=0;
        for(int i=0;i<n;i++){
            if(b[i]==a[0])p+=b[i];
        }
        for(int i=1;i<m+1;i++){
            int k=0,g=0;
            for(int j=0;j<n;j++){
                if(a[j]==i){
                    k+=b[j];
                    g=1;
                }
            }
            if(k<p && g==1)p=k;
        }
        cout<<p;
    }
}