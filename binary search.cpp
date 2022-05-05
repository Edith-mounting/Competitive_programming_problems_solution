#include <iostream>
#define ll long long
using namespace std;
ll binarysearch(ll a[],int p,int r,ll k){
    if(p<=r){
        int mid=(p+r)/2;
        if(a[mid]==k){
            return mid;
        }
        else if(a[mid]>k){
            return binarysearch(a,p,mid-1,k);
        }
        else if(a[mid]<k){
            return binarysearch(a,mid+1,r,k);
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    ll b[k];
    for(int i=0;i<k;i++){
        cin>>b[i];
    }
    for(int i=0;i<k;i++){
        int s=binarysearch(a,0,n-1,b[i]);
        cout<<s<<" ";
    }
}
