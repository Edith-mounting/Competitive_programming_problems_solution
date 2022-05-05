#include <bits/stdc++.h>

using namespace std;
#define int long long

void solveBetweenTwoIndices(int i1, int i2, int &ans, int &ind1, int &ind2, 
                                vector<int> &a){
    int temp = 1;
    int temp2;
    for(int i = i1 + 1; i < i2; i++){
        temp*= a[i];
    }
    if(temp > ans){
        ans = temp;
        ind1 = i1 + 1;
        ind2 = i2 - 1;
    }
    else{
        int temp1 = 1;
        for(int i = i1 + 1; i < i2; i++){
            if(a[i] < 0){
                if( ans < temp1){
                    ans = temp1;
                    ind1 = i1 + 1;
                    ind2 = i - 1;
                }
                temp1*= a[i];
                temp2 = temp/temp1;
                if( ans < temp2){
                    ans = temp2;
                    ind1 = i + 1;
                    ind2 = i2 - 1;
                }
                break;
            }
            else{
                temp1*=a[i];
            }
        }
        temp1 = 1;
        for(int i = i2 - 1; i >= i1 + 1; i--){
            if(a[i] < 0 ){
                if( ans < temp1){
                    ans = temp1;
                    ind1 = i + 1;
                    ind2 = i2 - 1;
                }
                temp1*= a[i];
                temp2 = temp/temp1;
                if( ans < temp2){
                    ans = temp2;
                    ind1 = i1 + 1;
                    ind2 = i - 1;
                }
                break;
            }
            else{
                temp1*=a[i];
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> v;
    v.push_back(-1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if( a[i] == 0){
            v.push_back(i);
        }
    }
    v.push_back(n);
    int ans = 1;
    int index1, index2;
    for(int i = 0; i < v.size() - 1; i++){
        solveBetweenTwoIndices( v[i], v[i + 1], ans, index1, index2, a);
    }
    if(ans == 1){
        cout << n << " " << 0 << "\n";
    }
    else{
        cout << index1 << " " << (n - index2 - 1) << "\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }    
}