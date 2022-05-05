#include <iostream>
using namespace std;

struct pi{
    int maxi,mini;
};

pi f(int a[],int low,int high){
    pi ans;
    if(low==high){
        ans.maxi=a[low];
        ans.mini=a[low];
        return ans;
    }
    if(low+1==high){
        if(a[low]>a[high]){
            ans.maxi=a[low];
            ans.mini=a[high];
        }
        else{
            ans.maxi=a[high];
            ans.mini=a[low];
        }
        return ans;
    }
    int k=(low+high)/2;
    pi x1=f(a,low,k);
    pi x2=f(a,k+1,high);
    if(x1.maxi>x2.maxi){
        ans.maxi=x1.maxi;
    }
    else{
        ans.maxi=x2.maxi;
    }
    if(x1.mini<x2.mini){
        ans.mini=x1.mini;
    }
    else{
        ans.mini=x2.mini;
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    pi x=f(a,0,n-1);
    cout<<x.maxi<<" "<<x.mini<<"\n";
}