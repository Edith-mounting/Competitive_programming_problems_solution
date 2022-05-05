#include <iostream>
#include <cmath>
#include <vector>
#define int long long int
using namespace std;
int n=1e7 +5;
int32_t main(){
    vector<int> prime(n,0);
    prime[2]=1;
    prime[3]=2;
    prime[4]=2;
    vector<bool> seive(n,true);

    for(int i=2;i<n;i++){
        if(seive[i]){
            for(int j=i*2;j<n;j+=i){
                seive[j]=false;
            }
        }
    }
    for(int i=5;i<n;i++){
        prime[i]=prime[i-1]+seive[i];
    }
    int w;
    cin>>w;
    while(w--){
        int x;
        cin>>x;
        if(x==2){
            cout<<1;
        }
        else if(x==3){
            cout<<2;
        }
        else if(x==4){
            cout<<2;
        }
        else{
            cout<<prime[x]-prime[x/2]+1;
        }
        cout<<"\n";
    }
}