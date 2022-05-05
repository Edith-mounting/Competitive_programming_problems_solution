#include <iostream>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int k=0;
    for(int i=0;i<t.length();i++){
        if(s[k]==t[i]){
            k++;
        }
    }
    cout<<k+1;
}