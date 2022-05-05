#include <iostream>
#include <stack>
using namespace std;
int main(){
    int x;
    cin>>x;
    int a[x];
    stack<int> s;
    for(int i=0;i<x;i++)cin>>a[i];
    cout<<-1<<" ";
    s.push(a[0]);
    for(int i=1;i<x;i++){
        while(!s.empty() && (s.top()>=a[i]))s.pop();
        if(!s.empty())cout<<s.top()<<" ";
        else cout<<-1<<" ";
        s.push(a[i]);
    }
}