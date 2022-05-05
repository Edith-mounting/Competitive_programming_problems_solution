#include <iostream>
#include <vector>
#define ll long long
using namespace std;
void swap(int &a,int &b){
    int c;
    c=a;
    a=b;
    b=c;
}
int siftdown(int i,int n,ll a[],int &t){
    int minindex=i;
    ll l=2*i+1;
    if(l<n && a[l]<a[minindex]){
        minindex=l;
    }
    ll r=2*i+2;
    if(r<n && a[r]<a[minindex]){
        minindex=r;
    }
    int z;
    if(i!=minindex){
        t++;
        swap(a[i],a[minindex]);
        z=siftdown(minindex,n,a,t);
    }
}
void siftDown(int i,int n,ll b[]){
    int minindex=i;
    ll l=2*i+1;
    if(l<n && b[l]<b[minindex]){
        minindex=l;
    }
    ll r=2*i+2;
    if(r<n && b[r]<b[minindex]){
        minindex=r;
    }
    if(i!=minindex){
        cout<<i<<" "<<minindex<<endl;
        swap(b[i],b[minindex]);
        siftDown(minindex,n,b);
    }
}
int main(){
    int n;
    cin>>n;
    ll a[n];
    ll b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    vector<ll> v1;
    vector<ll> v2;
    int minindex,l,r;
    int t=0,x=0;
    for(int i=n/2 -1;i>=0;i--){
        x=siftdown(i,n,a,t);
    }
    cout<<t<<endl;
    for(int i=n/2 -1;i>=0;i--){
        siftDown(i,n,b);
    }
}