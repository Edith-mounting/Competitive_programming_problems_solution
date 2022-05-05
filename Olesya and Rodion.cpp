#include <iostream>
#include <string>
#define ll long long 
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    string s;
    if(n>1){
        if(t!=10){
            while(n--){
                s=s+to_string(t);
            }
            cout<<s;
        }
        else{
            while(n--){
                s=s+to_string(t/10);
            }
            cout<<s;
        }
    }
    else{
        if(t==10){
            cout<<-1;
        }
        else cout<<t;
    }
}