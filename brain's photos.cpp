#include <iostream>

using namespace std;
int main(){
    int m,n,t=0;
    cin>>m>>n;
    char a[m*n];
    for(int i=0;i<m*n;i++){
        cin>>a[i];
        if(a[i]=='C' || a[i]=='M' || a[i]=='Y')t=1;
    }
    if(t==1){
        cout<<"#Color";
    }
    else cout<<"#Black&White";
}