#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        x=x-1;
        if(x==0 && x!=n-1){
            a[x+1]+=a[x]-y;
        }
        else if(x==n-1 && x!=0){
            a[x-1]+=y-1;
        }
        else{
            a[x-1]+=y-1;
            a[x+1]+=a[x]-y;
        }
        a[x]=0;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<endl;
}