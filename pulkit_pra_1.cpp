#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a , a + n);
    int i = 0 , j = n-1;
    int ans = 0;
    while(i < j){
        if(a[i] + a[j] <= k){
            i++;
            j--;
            ans++;
        }
        else{
            j--;
            ans++;
        }
    }
    if(i == j){
        ans++;
    }
    cout<<ans<<"\n";
}