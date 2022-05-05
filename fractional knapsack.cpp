#include <iostream>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;
int main(){
    int n;
    ll W;
    cin>>n>>W;
    double x=0;
    ll v[n];
    ll w[n];
    double ratio[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
        cin>>w[i];
        ratio[i]=(double)v[i]/w[i];
    }
    while(W>0){
        double k=0;
        int index=0;
        for(int i=0;i<n;i++){
            if(ratio[i]-k>0){
                k=(double)ratio[i];
                index=i;
            }
        }
        int a=min(w[index],W);
        x+=a*(double)k;
        ratio[index]=0;
        W=W-a;
    }
    cout<<fixed;
    cout<<setprecision(4);
    cout<<x;
}