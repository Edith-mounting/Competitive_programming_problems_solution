#include <iostream>
#include <stack>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    stack<char> a[k];
    for(long long i=0;i<n;i++){
        long long p=0;
        a[i%k].push(s[i]);
        for(long long j=1;j<k;j++){
            if(a[j].empty()){
                break;
            }
            else{
                if(a[j-1].top()==a[j].top())p++;
            }
        }
        if(p==k-1){
            for(long long j=0;j<k;j++){
                a[j].pop();
            }
        }
    }
    string sl="";
    long long p;
    if(n%k==0)p=k-1;
    else p=n%k-1;
    stack<char> sn;
    while(!a[0].empty()){
        for(long long i=p;i>=0;i--){
            sn.push(a[i].top());
            a[i].pop();
        }
        p=k-1;
    }
    while(!sn.empty()){
        cout<<sn.top();
        sn.pop();
    }
}
