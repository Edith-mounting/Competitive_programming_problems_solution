
#include <bits/stdc++.h>
using namespace std;

int countSubStr(string s, int n, int k)
{
    int count = 0;
	map<int,int> mp;
    if(k == 2){
        for(int i = 0; i < n; i++){
            if((s[i] - '0')%2 == 0){
                count += (i + 1);
            }
        }
        return count;
    }
    int rem = 0;
    mp[0] = 1;
    for(int i = n - 1; i >= 0; i--){
        rem = rem*10 + (s[i] - '0');
        rem%=k;
        mp[rem]++;
    }
    for(auto i:mp){
        count += (i.second*(i.second - 1))/2;
    }
	return count;
}

int main()
{
	int n,k;
    string s;
    cin >> n >> k >> s;
	cout << countSubStr(s, n, k);
}
