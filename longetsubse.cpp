#include <iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1==s2)cout<<-1;
    else{
        if(s1.length()>s2.length()){
            cout<<s1.length();
        }
        else cout<<s2.length();
    }
}