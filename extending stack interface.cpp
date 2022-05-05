#include <iostream>
#include <stack>
#define ll long long
using namespace std;
int main(){
    ll q;
    cin>>q;
    stack<int> st1;
    stack<int> st2;
    while(q--){
        string s;
        cin>>s;
        if(s=="push"){
            int n;
            cin>>n;
            st1.push(n);
            if(st2.empty()){
                st2.push(n);
            }
            else{
                if(n>=st2.top()){
                    st2.push(n);
                }
                else{
                    st2.push(st2.top());
                }
            }
        }
        else if(s=="pop"){
            st1.pop();
            st2.pop();
        }
        else{
            cout<<st2.top()<<endl;
        }
    }
}