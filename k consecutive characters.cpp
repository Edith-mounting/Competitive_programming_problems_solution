#include <iostream>
#include <stack>
#include <string>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    stack<ll> s1;
    stack<char> s2;
    bool b=true;
    while(b){
        const string pr=s;
        ll p=1;
        char c=s[0];
        for(ll i=1;i<s.length();i++){
            if(s[i]==c)p++;
            else{
                if(p%k!=0){
                    s1.push(p%k);
                    s2.push(c);
                }
                p=1;
                c=s[i];
            }
        }
        s1.push(p%k);
        s2.push(c);
        s="";
        while(!s1.empty()){
            s=string(s1.top(),s2.top())+s;
            s1.pop();
            s2.pop();
        }
        if(pr==s)b=false;
        else b=true; 
    }
    cout<<s;
    
}