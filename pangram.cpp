#include <iostream>
#include <set>
using namespace std;
int main(){
    int a;
    cin>>a;
    string k;
    cin>>k;
    set<char> s;
    for(int i=0;i<a;i++){
        if(k[i]>96)s.insert(k[i]);
        else s.insert(k[i]+32);
    }
    if(s.size()==26)cout<<"YES";
    else cout<<"NO";
}