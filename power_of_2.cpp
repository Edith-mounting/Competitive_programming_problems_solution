#include <bits/stdc++.h>
using namespace std;
#define int long long

int check(string number){
    string ans = "";
 
    int divisor = 2;
    int idx = 0, temp = 0;
    // int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[idx++] - '0');
 
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
 
        temp = (temp % divisor) * 10 + number[idx++] - '0';
    }
    while(temp >= 2){
        ans += to_string(temp/2);
        temp%=2;
    }
    cout << ans << " " << temp <<"\n";
    if(ans == "1" && temp == 0){
        return 1;
    }
    else if(temp != 0){
        return 0;
    }
    else if(ans.size() != 0){
        return check(ans);
    }
    return 0;
}
int power(string s) {
    return check(s);
}

int32_t main(){
    string s;
    cin >> s;
    cout << power(s);
}