#include <iostream>
using namespace std;
int main(){
    string s;
    int k=0;
    cin>>s;
    for(int i=0;i<s.length()-1;i++){
        if(abs(s[i+1]-s[i])>13){
            if(s[i]>s[i+1]){
                k+=abs(s[i]-'z')+abs(s[i+1]-'a')+1;
            }
            else{
                k+=abs(s[i]-'a')+abs(s[i+1]-'z')+1;
            }
        }
        else{
            k+=abs(s[i]-s[i+1])+1;
        }
    }
    cout<<k;
}