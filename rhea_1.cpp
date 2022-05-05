#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int k=min(b,min(c,d));
    b-=k;
    c-=k;
    d-=k;
    int l=min(a,b);
    int ans=234*k+l*12;
    cout<<ans<<"\n";
}