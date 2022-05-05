#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

int main(){   
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool b=true;
        stack<int> x;
        char a[]={'[',']','{','}','(',')'};
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')x.push(4);
            else if(s[i]=='{')x.push(2);
            else if(s[i]=='[')x.push(0);
            else{
                if(!x.empty()){
                    if(a[x.top()+1]==s[i]){
                            x.pop();
                        }
                    else{
                        b=false;
                        break;
                        }
                }
                else {
                     b=false;
                     break;
                 }
            }
        }
        if(b && x.empty())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    return 0;
}