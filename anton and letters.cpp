#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    set<char> sr;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            sr.insert(s[i]);
        }
    }
    cout<<sr.size();
}