#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n,q;
        cin>>n>>q;
        long long a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        while(q--){
            int x1,x2,t=0;
            long long y;
            cin>>x1>>x2>>y;
            for(int i=0;i<n-1;i++){
                if((y<=a[i+1] && y>=a[i]) || (y>=a[i+1] && y<=a[i])){
                    if(x1<=i+1 && x2>=i+2){
                        t++;
                    }
                }
            }
            cout<<t<<endl;
        }
    }
}