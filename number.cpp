#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll x;
    cin>>x;
    string s=to_string(x);
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')cout<<1;
        else if(s[i]=='2')cout<<2;
        else if(s[i]=='3')cout<<3;
        else if(s[i]=='4')cout<<4;
        else if(s[i]=='5')cout<<4;
        else if(s[i]=='6')cout<<3;
        else if(s[i]=='7')cout<<2;
        else if(s[i]=='8')cout<<1;
        else if(s[i]=='9')cout<<0;
        else cout<<0;
    }
}