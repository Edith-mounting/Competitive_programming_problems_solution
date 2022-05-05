#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        string s = to_string(n);
        int ans = INT32_MAX;
        int m = s.length();
        bool b2 = false;
        for(int i = m - 1 ; i >= 0 ; i--){
            if(s[i] == '0'){
                b2 =  true;
                for(int j = i - 1 ; j>=0 ; j--){
                    if(s[j] == '0' || s[j] == '5'){
                        ans = min(ans , m - j - 1 );
                        break;
                    }
                    
                }
            }
            if(b2){
                break;
            }
        }
        b2 = false;
        for(int i = m - 1 ; i >= 0 ; i--){
            if(s[i] == '5'){
                b2 = true;
                for(int j = i - 1 ; j>=0 ; j--){
                    if(s[j] == '2' || s[j] == '7'){
                        ans = min(ans , m - j - 1 );
                        break;
                    }
                    
                }
            }
            if(b2){
                break;
            }
        }
        cout << (ans - 1)  <<"\n";
    }
}