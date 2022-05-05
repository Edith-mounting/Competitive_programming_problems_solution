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
#define mod 1000000007
using namespace std;

bool check(string a){
    int n = a.length();
    for(int i=1; i<n; i++){
        if(a[i]==a[i-1]){
            return true;
        }
    }
    return false;
}
int solve(){
    int n;
    cin >> n;
    string a = to_string(n);
    map<string, bool> visited;
    queue<string> q;
    queue<int> count;
    count.push(1);
    q.push(a);
    if(check(a)){
        return 0;
    }
    while(!q.empty()){
        string x = q.front(); q.pop();
        int y = count.front(); count.pop();
        int m = x.length();
        m--;
        char lst = x[m];
        int x_value = stoi(x);
        for(auto i: x){
            int tmp = (i-'0')* x_value;
            string tmp_str = to_string(tmp);
            if(tmp_str[0]==lst || check(tmp_str)){
                return y;
            }
            if(!visited[tmp_str]){
                visited[tmp_str] = true;
                q.push(tmp_str);
                count.push(y+1);
            }
        }
    }
    return -1;
}

int32_t main(){
    int t = 1;
    // cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}