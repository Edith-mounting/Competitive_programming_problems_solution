#include <iostream>
using namespace std;
int main(){
    int n,x=1;
    cin>>n;
    string y;
    cin>>y;
    n=n-1;
    while(n--){
        string s;
        cin>>s;
        if(y!=s){
            x++;
            y=s;
        }
    }
    cout<<x;
}