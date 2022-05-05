#include <iostream>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='z'){
            a++;
        }
        if(s[i]=='n'){
            b++;
        }
    }
    for(int i=0;i<b;i++){
        cout<<1<<" ";
    }
    for(int i=0;i<a;i++){
        cout<<0<<" ";
    }
}