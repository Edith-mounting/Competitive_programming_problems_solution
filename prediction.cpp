#include <iostream>
using namespace std;
bool prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    int n,m,t=0;
    cin>>n>>m;
    if(m<=n){
        cout<<"NO";
    }
    else if(!prime(m)){
        cout<<"NO";
    }
    else{
        for(int i=n+1;i<m;i++){
            if(prime(i)){
                t=1;
                break;
            }
        }
        if(t==1)cout<<"NO";
        else cout<<"YES";
    }
}