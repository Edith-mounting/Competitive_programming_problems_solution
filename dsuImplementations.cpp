#include <bits/stdc++.h>

using namespace std;
vector<int> par;
vector<int> sz;

int find(int a){
    if(a == par[a]){
        return a;
    }
    else return par[a] = find(par[a]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if( a == b){
        return ;
    }
    if(sz[a] < sz[b]){
        swap( a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}
int main(){
    int n;
    cin >> n;
    par.resize(n);
    sz.resize(n);
    for(int i = 0; i < n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}