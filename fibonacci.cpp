#include <iostream>
using namespace std;
int main(){
    int n;
    long long c=0;
    cin>>n;
    if(n==0){
        cout<<0;
    }
    else if(n==1){
        cout<<1;
    }
    else{
        long long a=0,b=1;
        for(int i=0;i<n-1;i++){
            c=a+b;
            a=b;
            b=c;
        }
        cout<<c;
    }
}