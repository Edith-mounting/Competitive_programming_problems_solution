#include <iostream>
#include <algorithm>
using namespace std;

int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int pairAndSum(int arr[], int n)
{
    int ans = 0;  // Initialize result

    for(int i = 0;i<32;i++){
        int k = 0;
        for(int j = 0; j < n; j++){
            if(arr[j]&(1 << i)){
                k++;
            }
        }
        if(k>=2){
            ans += (1<<i);
        }
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans = pairAndSum(a,n);
        cout<<ans<<"\n";
    }
}