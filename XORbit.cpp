#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        long long a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        while(q--){
            long long x;
            cin>>x;
            int d=0,f=0;
            for(int i=0;i<n;i++){
                long long h=(x^a[i]);
                long long k=0;
                while(h!=0){
                    if(h%2==1)k++;
                    h=h/2;
                }
                if(k%2==0)d++;
                else f++;
            }
            cout<<d<<" "<<f<<endl;
        }
    }
}