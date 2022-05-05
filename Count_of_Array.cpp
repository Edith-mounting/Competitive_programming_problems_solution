#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long
#define mod 1000000007
using namespace std;

int power(int a, int b){
    if(b==0){
        return 1;
    }
    int res = 1;
    while(b>0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = b/2;
    }
    return res%mod;
}

int gcd(int a,int b){
    if(a==0 || b==0){
        return a+b;
    }
    return gcd(b, a%b);
}
int32_t main(){
    int n, m;
    cin >> n >>m;
    int k = 0;
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t<=m){
            k++;
        }   
    }
    vector<int> fact(1000005, 1);
    for(int i=1; i<1000005; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    int ans = (fact[m]*power(fact[m-n], mod-2))%mod;
    for(int i=1; i<=k; i++){
        int tmp1 = (fact[k]*power(fact[k-i],mod-2))%mod;
        tmp1 = (tmp1*power(fact[i],mod-2))%mod;
        tmp1 = (tmp1*fact[m-i])%mod;
        tmp1 = (tmp1*power(fact[m-n],mod -2))%mod;
        if(i%2==0){
            ans = (ans+tmp1)%mod;
        }else{
            ans = (ans-tmp1+mod)%mod;
        }
    }
    cout << ans << '\n';
}