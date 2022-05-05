#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a[26]={};
    string t="";
    for(int i=0;i<s.length();i++){
        a[s[i]-'A']++;
    }
    int c1=0;
    for(int i=0;i<26;i++){
        if(a[i]%2==1){
            c1++;
        }
    }
    if(c1>1){
        cout<<"NO SOLUTION"<<"\n";
    }
    else{
        for(int i=0;i<26;i++){
            if(a[i]%2==0){
                for(int j=0;j<a[i]/2;j++){
                    t+=(char)(i+'A');
                }
            }
        }
        cout<<t;
        for(int i=0;i<26;i++){
            if(a[i]%2==1){
                for(int j=0;j<a[i];j++){
                    cout<<(char)(i+'A');
                }
            }
        }
        reverse(t.begin(),t.end());
        cout<<t;
    }
}