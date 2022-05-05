#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[k];
    for(int i =0;i<k;i++){
        cin >> a[i];
    }
    sort(a , a + k);
    int curr = 0;
    int index = k - 1;
    int ans = 0;
    while((curr < n) && (curr < a[index]) && (index>=0)){
        curr += (n - a[index]);
        index--;
        ans++;
    }
    cout<< ans <<"\n";
}
int main(){
    int t;
    cin>> t;
    while(t--){
        solve();    
    }
}