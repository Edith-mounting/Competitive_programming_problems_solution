#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int n,k,l=0;
    cin>>n>>k;
    string s1;
    for(int i=0;i<=k;i++){
        s1+=to_string(i);
    }
    string a[n];
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        string s;
        s=to_string(x);
        sort(s.begin(),s.end());
        a[i]=s;
    }
    for(int i=0;i<n;i++){
        if(a[i]==s1)l++;
    }
    cout<<l;

}