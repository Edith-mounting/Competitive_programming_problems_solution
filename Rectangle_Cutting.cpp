#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;


string countIslands(string a[])
{
    string s = a[0];
    string t = a[1];
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    int start = 0, len = INT_MAX;
    while (right < s.size()) {
        char c = s[right];
        right++;
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }
        while (valid == need.size()) {
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            char d = s[left];
            left++;
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }                    
        }
    }
    return s.substr(start, len);
}

// main function
int main()
{
    string a[2];
    for(int i = 0; i < 2; i++){
        cin >> a[i];
    }
    cout << countIslands(a);
}
