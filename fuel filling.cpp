#include <iostream>
using namespace std;
int main(){
    int d,m,n;
    cin>>d>>m>>n;
    int a[n+2];
    a[0]=0;
    for(int i=1;i<n+1;i++)cin>>a[i];
    a[n+1]=d;
    int x=0,y=0,t=0;
    while(x<=n){
        y=x;
        while(x<=n && a[x+1]-a[y]<=m){
            x++;
        }
        if(y==x){
            t=-1;
            break;
        }
        if(x<=n)t++;
    }
    cout<<t;
}