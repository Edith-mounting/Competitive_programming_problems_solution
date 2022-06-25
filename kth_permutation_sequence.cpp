#include <bits/stdc++.h>
using namespace std;

bool isValid( int i, int j, int n, int m){
    if(i>=n || i < 0 || j >= m || j < 0){
        return false;
    }
    return true;
}
vector<int> par, sz;
const static bool comp( vector<int> a, vector<int> b){
    return a[2] < b[2];
}
int find_set( int a){
    if( a == par[a]) return a;
    return par[a] = find_set( par[a]);
}
void merge( int a, int b){
    a = find_set( a);
    b = find_set( b);
    if( a == b) return;
    if(sz[a] < sz[b]){
        swap( a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}
int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = { -1, 1, 1, -1, 2, -2, 2, -2};
void solve1( string &nums){
    int n=nums.size();
    int j=-1;
    for(int i=n-1;i>=1;i--){
        if(nums[i]>nums[i-1]){
            j=i;
            break;
        }
    }
    if(j==-1){
        return ;
    }
    int k=-1;
    for(int i=n-1;i>=j;i--){
        if(nums[i]>nums[j-1]){
            k=i;
            break;
        }
    }
    swap(nums[k], nums[j - 1]);
    //reverse nums from index j to n-1
    for(int i=j;i<(n+j)/2;i++){
        swap(nums[i], nums[n-i+j-1]);
    }
    // cout << s <<"\n";
}
string solve(int A, int B){
    string temp = "";
    for(int i = 1; i <= A; i++){
        temp += to_string( i);
    }
    B--;
    while(B--){
        solve1( temp);
    }
    return temp;
}
int32_t main(){
    int a, b;
    cin >> a >> b;
    cout << solve( a, b);
}