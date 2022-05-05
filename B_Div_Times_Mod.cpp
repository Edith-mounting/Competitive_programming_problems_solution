#include <iostream>
#include <algorithm>
using namespace std;

#define int long long 
#define inf 1000000000000000000

int32_t main()
{
	int n,k;
    cin>>n>>k;
    int ans=inf;
    for(int i=k-1;i>=1;i--){
        if((n*k)%i==0){
            int comp=(n*k)/i +i;
            if(comp%k ==i){
                // cout<<i<<" ";
                ans=min(ans,comp);
            }
        }
    }
    //cout<<"\n";
    cout<<ans<<"\n";
}