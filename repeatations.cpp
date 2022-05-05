#include <iostream>
#define ll long long
using namespace std;
int main(){
    string s;
    cin>>s;
    ll max=0,localmax=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i+1]==s[i]){
            localmax+=1;
        }
        else{
            if(max<localmax){
                max=localmax;
            }
            localmax=1;
        }
    }
    if(max<localmax){
        max=localmax;
    }
    cout<<max;
}