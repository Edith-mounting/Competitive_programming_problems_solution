#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[26]={};
        string s;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int i=0;i<s.length();i++){
                a[s[i]-'a']++;
            }
        }
        bool b=true;
        for(int i=0;i<26;i++){
            if(a[i]%n!=0){
                b=false;
                break;
            }
        }
        if(b){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}