#include <iostream>
#define ll long long
#define N 200005
using namespace std;
long merge(ll arr[],int l,int mid,int r){
    int temp[N];
    int i=l;
    int j=mid+1;
    int k=0;
    ll swaps=0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
            swaps+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }
    int p=0;
    for(int m=l;m<=r;m++){
        arr[m]=temp[p];
        p++;
    }
    return swaps;
}
long mergesortcount(ll arr[],int l,int r){
    ll count=0;
    if(l<r){
        int mid=(l+r)/2;
        count+=mergesortcount(arr,l,mid);
        count+=mergesortcount(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
        return count;
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<mergesortcount(a,0,n-1)<<"\n";
    }
}