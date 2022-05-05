#include <iostream>

using namespace std;

template <class T>
class MyStack{
    T stacktop;
    T stacklength;
    T* stack;
    public:
        MyStack(){
            stacklength=1;
            stacktop=1;
            stack=new T[1];
        }
        void push(T x){
            if(stacktop==stacklength-1){
                T* x=new T[stacklength*2];
                for(T i=0;i<stacklength;i++){
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
        T pop(){
            T k=*(stack+stacktop);
            if(stacktop!=-1){
                stacktop--;
            }
            return k;
        }
        T peek(){
            if(stacktop!=-1){
                return *(stack+stacktop);
            }
        }
        bool empty(){
            if(stacktop==-1)return true;
            else return false;
        }
};

int main(){
    string s;
    getline(cin,s);
    MyStack<char> st;
    MyStack<int> sp;
    int i;
    for(i=0;i<s.length();){
        if(s[i]=='+'){
            while(!st.empty()){
                if(st.peek()=='*'){
                    int mn=sp.peek();
                    sp.pop();
                    int mx=sp.peek();
                    sp.pop();
                    char sx=st.peek();
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
            while(!st.empty() && st.peek()=='*'){
                int mn=sp.peek();
                sp.pop();
                int mx=sp.peek();
                sp.pop();
                int tu=mn*mx;
                sp.push(tu);
            }
            st.push(s[i]);
            i++;
        }
        else if(s[i]=='('){
            st.push(s[i]);
            i++;
        }
        else if(s[i]==')'){
            while(st.peek()!='(') 
            { 
                int mn= sp.peek(); 
                sp.pop();  
                int mx = sp.peek(); 
                sp.pop();
                char ch = st.peek(); 
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
        if(st.peek()=='+'){
            int j=k+l;
            sp.push(j);
        }
        else{
            int j=k*l;
            sp.push(j);
        }
        st.pop();
    }
    cout<<sp.peek(); 
}