#include <iostream>
#include <stack>
#include <string>
using namespace std;


class MyStack{
    int stacktop;
    int stacklength;
    int* stack;
    public:
        MyStack(){
            stacklength=1;
            stacktop=1;
            stack=new int[1];
        }
        void push(int x){
            if(stacktop==stacklength-1){
                int* x=new int[stacklength*2];
                for(int i=0;i<stacklength;i++){
                    *(x+i)=stack[i];
                }
                delete [] stack;
                stacklength=stacklength*2;
                stack=x;
            }
            else{
                stacktop++;
                *(stack+stacktop)=x;
            }
        }
        void pop(){
            if(stacktop!=-1){
                stacktop--;
            }
        }
        int peek(){
            if(stacktop!=-1){
                return *(stack+stacktop);
            }
            else return -1;
        }
        bool empty(){
            if(stacktop==-1)return true;
            else return false;
        }
};

int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    MyStack sp;
    int i;
    for(i=0;i<s.length();){
        if(s[i]=='+'){
            while(!st.empty()){
                if(st.top()=='*'){
                    int mn=sp.peek();
                    sp.pop();
                    int mx=sp.peek();
                    sp.pop();
                    char sx=st.top();
                    st.pop();
                    if(sx=='+'){
                        sp.push(mn+mx);
                    }
                    else{
                        sp.push(mn*mx);
                    }
                }
                else break;
            }
            st.push(s[i]);
            i++;
        }
        else if(s[i]==' '){
            i++;
            continue;
        }
        else if(s[i]=='*'){
            st.push(s[i]);
            i++;
        }
        else if(s[i]=='('){
            st.push(s[i]);
            i++;
        }
        else if(s[i]==')'){
            while(st.top()!='(') 
            { 
                int mn= sp.peek(); 
                sp.pop();  
                int mx = sp.peek(); 
                sp.pop();
                char ch = st.top(); 
                st.pop();
                if(ch=='+'){
                    int tu=mn+mx;
                    sp.push(tu);
                }
                else{
                    int tu=mn*mx;
                    sp.push(tu);
                }
            }
            if(!st.empty())st.pop();
            i++; 
        }
        else{
            int p = 0; 
            while(i<s.length() && isdigit(s[i])){ 
                p = (p*10) + (s[i]-48); 
                i++; 
            }
            sp.push(p); 
        } 
    }

    while(!st.empty()){
        int k=sp.peek();
        sp.pop();
        int l=sp.peek();
        sp.pop();
        if(st.top()=='+'){
            int j=k+l;
            sp.push(j);
        }
        else{
            int j=k*l;
            sp.push(j);
        }
        st.pop();
    }
    cout<<sp.peek()<<endl;
}