#include <iostream>
using namespace std;
int main(){
    int x,a=0,b=0;
    cin>>x;
    string s;
    cin>>s;
    for(int i=0;i<x;i++){
        if(s[i]=='A')a++;
        else b++;
    }
    if(a>b)cout<<"Anton";
    else if(a==b) cout<<"Friendship";
    else cout<<"Danik";
}