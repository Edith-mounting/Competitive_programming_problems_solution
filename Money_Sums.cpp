#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int countIslands(string a[])
{
    int m1 = 100;
    int mod = 1000000007;
    vector<int> fact(m1,0);
    fact[0] = 1;
    for(int i = 1; i < m1; i++){
        fact[i] = (fact[i - 1]*i)%mod;
    }
    int num = 0;
    int n = a[0].length();
    for(int i = 0; i < n; i++){
        num = num*10 + (a[0][i] - '0');
    }
    string s = "";
    while(num > 0){
        s = to_string(num%2) + s;
        num/=2;
    }
    n = s.length();
    int m = a[1].length();
    int ans = 0;
    int j;
    for(j = 0; j < n; j++){
        if(a[1][j] != s[j]){
            ans++;
        }
    }
    for(int i = j; i < m; i++){
        if(a[1][i] == '1'){
            ans++;
        }
    }
    return ans;
}

int main()
{
    string a[2];
    for(int i = 0; i < 2; i++){
        cin >> a[i];
    }
    cout << countIslands(a);
}
