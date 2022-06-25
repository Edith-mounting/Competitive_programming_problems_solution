#include <bits/stdc++.h>
using namespace std;
#define int long long

int isPalindrome(string s) {
    vector<char> v;
    for(char i:s){
        if( (i <= 'z' && i >= 'a') || (i >= 'A' && i <= 'Z') ){
            if( (i >= 'A' && i <= 'Z')){
                v.push_back((char)((i - 'A') + 'a'));
            }
            else{
                v.push_back(i);
            }
        }
    }
    for(char i:v){
        cout << i <<" ";
    }
    cout << "\n";
    int n = v.size();
    for(int i = 0; i < n/2; i++){
        if( v[i] != v[n - i - 1]){
            return 0;
        }
    }
    return 1;
}


int32_t main(){
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);

}