#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 100000;
int m;
int b[M];
int order(int x){
    for(int i = 0 ; i < m ; i++){
        if(x == b[i]){
            return i;
        }
    }
    return 0;
}
static bool comp(int x,int y){
    vector<int> v1,v2;
    while(x>0){
        v1.push_back(x%10);
        x/=10;
    }
    while(y>0){
        v2.push_back(y%10);
        y/=10;
    }
    reverse(v1.begin() , v1.end());
    reverse(v2.begin() , v2.end());
    int p , q;
    for(int i = 0 ; i < min(v1.size() , v2.size()) ; i++){
        p = order(v1[i]);
        q = order(v2[i]);
        if(p != q){
            return p < q; 
        }
    }
    return v1.size() < v2.size();
}
int main(){
    // n = number of elements in first array
    // m = number of elements in second array
    int n;
    cin >>n >> m;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    for(int i = 0 ; i < m ; i++) cin>>b[i];
    sort(a , a + n, comp);
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}