#include <iostream>
#include <algorithm>
using namespace std;

int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        int c = (n+1)/2;
        int xi = c - x;
        int yi = c - y;
        int ans = absk(absk(xi) - absk(yi));
        ans = ans%2;
        cout<<ans<<"\n";
    }
}