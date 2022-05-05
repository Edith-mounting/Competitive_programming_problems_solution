#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a[100];
    int n=100;
    for(int i=0;i<n;i++)a[i]=0;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+')a[i]=s[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]!=0 && i!=n-1)cout<<a[i]-48<<"+";
        else if(a[i]!=0 && i==n-1)cout<<a[i]-48;
    }
}