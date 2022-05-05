#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<char> st;
    stack<int> st2;
    bool b=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
            st2.push(i+1);    
        }
        else if(s[i]==')'){
            if(st.empty()){
                cout<<i+1<<endl;
                b=false;
                break;
            }
            else{
                if(st.top()=='('){
                    st.pop();
                    st2.pop();
                }
                else{
                    cout<<i+1<<endl;
                    b=false;
                    break;
                }
            }
        }
        else if(s[i]=='}'){
            if(st.empty()){
                cout<<i+1<<endl;
                b=false;
                break;  
            }
            else{
                if(st.top()=='{'){
                    st.pop();
                    st2.pop();
                }
                else{
                    cout<<i+1<<endl;
                    b=false;
                    break;
                }
            }
        }
        else if(s[i]==']'){
            if(st.empty()){
                cout<<i+1<<endl;
                b=false;
                break;
            }
            else{
                if(st.top()=='['){
                    st.pop();
                    st2.pop();
                }
                else{
                    cout<<i+1<<endl;
                    b=false;
                    break;
                }
            }
        }
        else{
            continue;
        }
    }
    if(b){
        if(st2.empty()){
            cout<<"Success"<<endl;
        }
        else{
            cout<<st2.top()<<endl;
        }
    }
}