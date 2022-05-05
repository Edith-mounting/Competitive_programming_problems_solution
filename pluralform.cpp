#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(s[s.length()-1]=='s'){
        s+="es";
    }
    else{
        s+='s';
    }
    cout<<s;
}