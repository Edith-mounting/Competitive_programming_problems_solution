#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//vector<int> ar;
// int solve(){
//     int s=0;
//     for(int i=0;i<ar.size();i++){
//         s+=ar[i];
//     }
//     return s;
// }

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    int dp[n];
    if(n==1){
        ans=a[0];
    }
    else if(n==2){
        ans=max(a[0],a[1]);
    }
    else{
        dp[0]=a[0];
        dp[1]=a[1];
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }
        ans=dp[n-1];
    }
    cout<<ans<<"\n";
}