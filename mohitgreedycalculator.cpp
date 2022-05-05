#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
#define pb push_back
void solve(int n)
{ 
    vi ans;
    vi temp(n + 1);
    for (int i = 1; i < temp.size(); i++)
    {
        temp[i] = temp[i - 1] + 1;
        if (i % 2 == 0) 
            temp[i] = min(1 + temp[i / 2], temp[i]); 
        if (i % 3 == 0) 
            temp[i] = min(1 + temp[i / 3], temp[i]);
    }
    int idx = n;
    while (idx > 1) 
    {
        ans.pb(idx);
        if (temp[idx - 1] == temp[idx] - 1)
          idx = idx - 1;
        else if (idx % 2 == 0 && (temp[idx / 2] == temp[idx] - 1))
            idx = idx / 2; 
        else if (idx % 3 == 0 && (temp[idx / 3] == temp[idx] - 1))
            idx = idx / 3; 
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout<<ans.size()-1<<endl;
    for (ll x : ans) 
        cout << x << " "; 
    cout << endl;
    }
    int main()
    {
        ll n;
        cin >>n;
        solve(n);
    }