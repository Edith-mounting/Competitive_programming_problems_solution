#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;
int main(){
    int k,m;
    cin>>k;
    stack<int> s1,s2;
    stack<string> s3;
    while(k--){
        int x;
        cin>>x;
        if(x!=-1 && x!=0){
            string st;
            cin>>st;
            s3.push(st);
            if(!s1.empty()){
                if(x<=m){
                    s1.push(x);
                    s2.push(x);
                    m=x;
                }
                else{
                    s1.push(x);
                    s2.push(m);
                }
            }
            else{
                m=x;
                s1.push(m);
                s2.push(m);
            }
        }
        else if(x==0){
            string k;
            cin>>k;
            s1=s1;
            s2=s2;
            s3=s3;
        }
        else{
            int a=0;
            while(s2.top()!=s1.top()){
                s2.pop();
                s1.pop();
                s3.pop();
                a++;
            }
            cout<<a<<" "<<s3.top()<<endl;
            s2.pop();
            s1.pop();
            s3.pop();
            if(!s1.empty())m=s2.top();
        }    
    }
}
