#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    if(n==0){
        cout<<1;
    }
    else{
        int p=n%4;
        switch(p){
            case 1:cout<<8;
                break;
            case 2:cout<<4;
                break;
            case 3:cout<<2;
                break;
            case 0:cout<<6;
                break;
        }
    }
}