#include <iostream>
using namespace std;
int main(){
    int x=1;
    string s;
    cin>>s;
    for(int i=1;i<s.length();i++){
        bool t=true;
        for(int j=0;j<i;j++){
            if(s[i]==s[j]){
                t=false;
                break;
            }
        }
        if(t)x++;
    }
    if(x%2==1)cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
}