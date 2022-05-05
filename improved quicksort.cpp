#include <iostream>
#define ll long long
using namespace std;
void swap(ll *xp,ll *yp) 
{ 
    ll temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void partition(ll a[],int l,int r,int *m){
    ll x=a[l];
    int j=l;
    for(int i=l+1;i<r;i++){
        if(a[i]<=x){
            j++;
            swap(a[j],a[i]);
        }
    }
    swap(a[l],a[j]);
    m[1]=j;
    j=l;
    x=a[m[1]];
    for(int i=l+1;i<m[1];i++){
        if(a[i]<x){
            j++;
            swap(a[j],a[i]);
        }
    }
    m[0]=j;
}
void quicksort(ll *a,int l,int r){
    if(l>=r)return ;
    int m[2]={0,0};
    partition(a,l,r,m);
    quicksort(a,l,m[0]-1);
    quicksort(a,m[1]+1,r);
}

int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    int l=0;
    quicksort(a,l,n);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
