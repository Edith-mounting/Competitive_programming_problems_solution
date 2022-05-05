#include <iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int c=0;
    int x=(n+2)%60;
    if(n==0){
            cout<<0;
    }
    else if(n==1){
        cout<<1;
    }
    else{
        int a=0,b=1;
        if(x==0 || x==1){
            cout<<0;
        }
        else{
            for(int i=0;i<x-1;i++){
                c=a%10+b%10;
                a=b;
                b=c;
            }
            c=c%10-1;
            if(c<0){
                c=c+10;
            }
            cout<<c;
        }
    }
}