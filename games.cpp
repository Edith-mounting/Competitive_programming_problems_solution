#include <iostream>
using namespace std;
int main(){
    int n,k=0;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=x;
        b[i]=y;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((a[i]==b[j]) && j!=i)k++;
        }
    }
    cout<<k;
}