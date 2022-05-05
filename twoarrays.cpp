#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long a[n];
    long long b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    long long a1[n/2],a2[n/2],b1[n/2],b2[n/2];
    long long z=0;
    for(int i=0;i<n/2;i++){
        a1[i]=a[i];
        b1[i]=b[i];
    }
    for(int i=n-1;i>n/2;i--){
        a2[n-1-i]=a[i];
        b2[n-1-i]=b[i];
    }
    int i,j,k,l=0;
    while(m--){
        if(a1[i]>=a2[j] && a1[i]>=b1[k] && a1[i]>=b2[l]){
            z+=a1[i];
            if(i+1<n/2)i++;
            else a1[i]=-99999999;
        }
        else if(a2[j]>=a1[i] && a2[j]>=b1[k] && a2[j]>=b2[l]){
            z+=a2[j];
            if(j+1<n/2)j++;
            else a2[j]=-99999999;
        }
        else if(b1[k]>=a1[i] && b1[k]>=a2[j] && b1[k]>=b2[l]){
            z+=b1[k];
            if(k+1<n/2)k++;
            else b1[k]=-99999999;
        }
        else{
            z+=b2[l];
            if(l+1<n/2)l++;
            else b2[l]=-99999999;
        }
    }
    cout<<z;
}