#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int> s;
    int a,b;
    cin>>a;
    for(int i=0;i<a;i++){
        int p;
        cin>>p;
        s.insert(p);
    }
    cin>>b;
    while(b--){
        int q;
        cin>>q;
        s.insert(q);
    }
    if(s.size()==n)cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";
}