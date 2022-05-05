#include <iostream>
#include <stack>
#include <algorithm>
#define endl "\n"
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    stack<int> s1,s2,s3;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]==1)s1.push(i+1);
        else if(a[i]==2)s2.push(i+1);
        else s3.push(i+1);
    }
    int t=s1.size();
    if(s2.size()>=s3.size()){
        if(s3.size()<t){
            t=s3.size();
        }
    }
    else{
        if(s2.size()<t)t=s2.size();
    }
    cout<<t<<endl;
    for(int i=0;i<t;i++){
        cout<<s1.top()<<" "<<s2.top()<<" "<<s3.top()<<endl;
        s1.pop();
        s2.pop();
        s3.pop();
    }
}