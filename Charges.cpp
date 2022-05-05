#include <iostream>
#include <cmath>
#define int long long int
using namespace std;
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            a[i]=c-'0';
        }
        int q[k];
        for(int i=0;i<k;i++){
            cin>>q[i];
        }
        int init=0;
        for(int i=1;i<n;i++){
            init++;
            if(a[i]==a[i-1]){
                init++;
            }
        }
        if(n==1){
            for(int i=0;i<k;i++){
                cout<<0<<"\n";
            }
            continue;
        }
        if(n==2){
            for(int i=0;i<k;i++){
                a[q[i]-1]=1-a[q[i]-1];
                if(a[0]==a[1]){
                    cout<<2;
                }
                else{
                    cout<<1;
                }
                cout<<"\n";
            }
            continue;
        }
        for(int i=0;i<k;i++){
            int count=0;
            if((q[i]-1)>0){
                if(a[q[i]-2]==a[q[i]-1]){
                    count--;
                }
                else{
                    count++;
                }
            }
            if((q[i]-1)<n-1){
                if(a[q[i]]==a[q[i]-1]){
                    count--;
                }
                else{
                    count++;
                }
            }
            init+=count;
            a[q[i]-1]=1-a[q[i]-1];
            // for(int j=0;j<n;j++){
            //     cout<<a[j]<<" ";
            // }
            //cout<<count<<" ";
            cout<<init<<"\n";
        }
    }
}