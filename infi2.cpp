#include <iostream>
#include <stack>
#include <string>
using namespace std;
   
int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    stack<int> sp;
    int i;
    for(i=0;i<s.length();){
        if(s[i]=='+'){
            while(!st.empty()){
                if(st.top()=='*'){
                    int mn=sp.top();
                    sp.pop();
                    int mx=sp.top();
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
                int mn= sp.top(); 
                sp.pop();  
                int mx = sp.top(); 
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
        int k=sp.top();
        sp.pop();
        int l=sp.top();
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
    cout<<sp.top();
}