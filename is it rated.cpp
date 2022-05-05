#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],m=0;
    set<int> s;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x!=y && m==0){
            cout<<"rated";
            m=1;
        }
        else{
            a[i]=x;
            s.insert(x);
        }
    }
    if(m!=1){
        if(s.size()==n)cout<<"unrated";
        else cout<<"maybe";
    }
    
}