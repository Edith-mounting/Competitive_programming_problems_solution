#include <iostream>
#include <stack>
using namespace std;

int main(){   
    string s;
    cin>>s;
    int p=0;
    stack<int> x;
    char a[]={'[',']','{','}','(',')'};
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){x.push(4);
                        p++;}
        else if(s[i]=='{'){x.push(2);
                        p++;}
        else if(s[i]=='['){x.push(0);
                        p++;}
        else{
            if(!x.empty()){
                if(a[x.top()+1]==s[i]){
                        p--;
                        x.pop();
                    }
                else{
                    p++;
                    }
            }
            else {
                 p++;
             }
        }
    }
    cout<<p;
    return 0;
}