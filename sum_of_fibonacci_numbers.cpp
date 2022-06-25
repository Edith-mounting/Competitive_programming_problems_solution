#include <bits/stdc++.h>
using namespace std;
#define int long long

int fibsum(int a) {
    vector<int> fib;
    int x = 1, b = 1;
    fib.push_back(x);
    fib.push_back(b);
    int c;
    for(int i = 2; i <= 40; i++){
        c = x + b;
        fib.push_back(c);
        x = b;
        b = c;
    }
    int ans = 0;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int len = q.size();
        while(len--){
            int temp = q.front();
            q.pop();
            if(temp == 0){
                return ans;
            }
            for(int j = fib.size(); j >= 0; j--){
                if( temp - fib[j] >= 0){
                    q.push(temp - fib[j]);
                }
            }
        }
        ans++;
    }
    return ans;
}


int32_t main(){
    int n;
    cin >> n;
    cout << fibsum(n);
}