#include <iostream>
#define ll long long
using namespace std;
int main(){
    ll n,s,c=0;
    cin>>n>>s;
    c+=s/n;
    if(s%n!=0){
        c++;
    }
    cout<<c<<endl;
}