#include <bits/stdc++.h>
using namespace std;

string solve(string S, int N){
    vector<int> cnt(26, 0);
    for(auto i: S){
        cnt[i-'a']++;
    }

    int j = 0;
    int i = 0;
    vector<bool> visited(N, false);
    string res = "";
    stack<char> st;
    while(i<N){
        while(cnt[j]==0){
            j++;
        }

        while(!st.empty() && (st.top()-'a')<=j){
            res.push_back(st.top());
            st.pop();
        }

        if( (S[i]-'a') == j){
            res.push_back(S[i]);
            cnt[j]--;
            visited[i] = true;
            i++;
        }else{
            cnt[S[i]-'a']--;
            st.push(S[i]);
            i++;
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    // cout << "Answer is: ";
    return res;
    

}
int32_t main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n);
}