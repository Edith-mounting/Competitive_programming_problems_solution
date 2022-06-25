#include <bits/stdc++.h>
using namespace std;
#define int long long

void printPowerSet(string set, int set_size, int k, int x)
{
    // Set_size of power set of a set with set_size
    // n is (2^n-1)
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    // Run from counter 000..0 to 111..1
    vector<string> v;
    for (counter = 0; counter < pow_set_size; counter++) {
        string s = "";
        for (j = 0; j < set_size; j++) {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if (counter & (1 << j))
                s += set[j];
        }
        if(s.size() == k){
            v.push_back(s);
        }
    }
    sort( v.begin(), v.end());
    cout << v[x - 1] << "\n";
}
int32_t main(){
    string s;
    cin >> s;
    int k,x;
    cin >> k>> x;
    int n = s.size();
    printPowerSet(s, n, k, x);
}