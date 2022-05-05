#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
    int t,m=0;
    cin>>t;
    m=t;
    while(t--){
        long long n,b,k=0;
        cin>>n>>b;
        int a[n];
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(long long i=0;i<n;i++){
            b=b-a[i];
            if(b>=0)k++;
        }
        cout<<"Case #"<<m-t<<": "<<k<<endl;
    }
}