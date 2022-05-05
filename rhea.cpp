#include <iostream>
#include <algorithm>
using namespace std;
char solve(){
    int k,n;
    cin>>k>>n;
    string sl="";
    int m=k;
    int mlk=0;
    while(m>0){
        sl+=to_string(m%2);
        m/=2;
        mlk++;
    }
    if(mlk>=n){
        return sl[n-1];
    }
    return '0';
}
int32_t main(){
    char c=solve();
    if(c=='0'){
        cout<<0;
    }
    else{
        cout<<1;
    }
    cout<<"\n";
}