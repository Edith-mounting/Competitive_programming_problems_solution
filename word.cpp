#include <iostream>
#include <string>
using namespace std;
int main(){
    int p=0,q=0;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>96)p++;
        else q++;
    }
    if(p>=q){
        for(int i=0;i<s.length();i++){
            if(s[i]>96)cout<<s[i];
            else cout<<(char)(s[i]+32);
        }
    }
    else{
        for(int i=0;i<s.length();i++){
            if(s[i]<96)cout<<s[i];
            else cout<<(char)(s[i]-32);
        }
    }
}