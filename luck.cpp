#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k,z=0;
    cin>>n>>k;
    int l[n];
    int p[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        l[i]=x;
        p[i]=y;
    }
    int g=l[0];
    if(k!=0){   
        for(int i=1;i<n;i++){
            if(l[i]<g)g=l[i];
            }
    }
    else{
        int g=l[0];
        for(int i=1;i<n;i++){
            if(p[i]==0){
                if(l[i]<g)g=l[i];
            }
        }
    }
    for(int i=0;i<n;i++)z+=l[i];
    cout<<z-2*g;
}