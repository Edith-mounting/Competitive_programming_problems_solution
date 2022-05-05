#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int a[m][5]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[j][s[i][j]-'A']++;
        }
    }
    for(int i=0;i<m;i++){
        sort(a[i],a[i]+5);
    }
    ll k=0;
    for(int i=0;i<m;i++){
        k+=a[i][4]*(b[i]);
    }
    cout<<k;
}