#include <iostream>
#include <vector>
#define ll long long

using namespace std;
void greedycalculator(ll n){
    ll a[n];
    a[1-1]=0;
    a[2-1]=1;
    a[3-1]=1;
    vector<ll> v[n];
    v[1-1].push_back(1);
    v[2-1].push_back(1);
    v[2-1].push_back(2);
    v[3-1].push_back(1);
    v[3-1].push_back(3);
    for(int i=3;i<n;i++){
        a[i]=1000000;
        int x;
        if(a[i-1]+1<a[i]){
            a[i]=a[i-1]+1;
            x=i-1;
        }
        if((i+1)%2==0){
            if(a[(i+1)/2 - 1]+1<a[i]){
                a[i]=a[(i+1)/2 - 1]+1;
                x=(i+1)/2 -1;
            }
        }
        if((i+1)%3==0){
            if(a[(i+1)/3 - 1]+1<a[i]){
                a[i]=a[(i+1)/3 - 1]+1;
                x=(i+1)/3 -1;
            }
        }
        for(int m=0;m<v[x].size();m++){
            v[i].push_back(v[x][m]);
        }
        v[i].push_back(i+1);   
    }
    cout<<a[n-1]<<endl;
    for(int i=0;i<v[n-1].size();i++){
        cout<<v[n-1][i]<<" ";
    }
    cout<<endl;
}
int main(){
    ll n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        cout<<1<<endl;
    }
    else{
    greedycalculator(n);
    }
}