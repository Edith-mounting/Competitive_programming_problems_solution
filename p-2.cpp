#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a[2];
        cin>>a[0]>>a[1];
        int x[2];
        cin>>x[0]>>x[1];
        sort(a,a+2);
        sort(x,x+2);
        if(a[1]==x[1] && a[0]+x[0]==a[1]){
            cout<<"Yes"<<"\n";
        }
        else{
            cout<<"No"<<"\n";
        }
    }
}