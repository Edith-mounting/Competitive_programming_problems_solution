#include <bits/stdc++.h>
using namespace std;

int min( int a, int b, int c){
    return min( a, min( b, c));
}

vector<int> solve( int a, int b, int c, int n){
    int x[3];
    x[0] = a, x[1] = b, x[2] = c;
    sort( x, x + 3);
    vector<int> v(n);
    int k;
    for(int i = 0; i < n; i++){
        k = min( x[0], x[1], x[2]);
        v[i] = k;
        if(k == x[0]){
            k = min( x[0]*x[0], x[0]*x[1], x[0]*x[2]);
            x[0] = k;
        }
        else if(k == x[1]){
            k = min( x[1]*x[0], x[1]*x[1], x[1]*x[2]);
            x[1] = k;
        }
        else{
            k = min( x[2]*x[0], x[2]*x[1], x[2]*x[2]);
            x[2] = k;
        }
    }
    return v;
}

int32_t main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<int> v = solve( a, b, c, d);
    for( int i:v){
        cout << i << " ";
    }
}