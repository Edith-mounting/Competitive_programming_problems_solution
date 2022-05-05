#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define ll long long
#define M 1e9 +7
using namespace std;
vector<int> adj[100001];
bool b[100001];
int powd(int k1,int p1){
    if(p1==0){
        return 1;
    }
    else if(p1%2==0){
        int t=powd(k1,p1/2);
        return t*t;
    }
    else{
        int t=powd(k1,p1/2);
        return p1*t*t;
    }
}
int dfs(int cur){
    int count=1;
    if(!b[cur]){
        count++;
        b[cur]=true;
        for(int nb:adj[cur]){
            if(b[nb])continue;

            dfs(nb);
        }
    }
    return count;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int a,b,col;//if col=0(blue) else red
        if(col==1){
            continue;
        }
        else{
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=false;
    }
    ll count=1;
    for(int i=1;i<=n;i++){
        int pli=dfs(i);
        count+=powd(pli,k);
    }
    ll ans=powd(n,k)-count;
    cout<<ans;
}