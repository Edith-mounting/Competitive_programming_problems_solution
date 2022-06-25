#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers){
    int ans = 0;
    map<int, int> mp;
    for(int i:numbers){
        mp[i]++;
    }
    for(auto i:mp){
        if(i.first != numbers[0]){
            if(i.first != numbers[1]){
                ans+=i.second;
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solution(a)<< "\n";
}