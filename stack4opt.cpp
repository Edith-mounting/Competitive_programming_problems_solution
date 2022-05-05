#include <iostream>
#include <stack>
using namespace std;
int main(){
    string x,y;
    cin>>x;
    int k=x.length();
    stack<char> s;
    for(int i=0;i<k;i++){
        if(!s.empty()){
            if(s.top()>=x[i] &&(i!=k-1)){
                s.push(x[i]);
            }
            else if(i==k-1){
                if(x[i]<=s.top()){
                    y+=x[i];
                }
                else{
                    while(s.top()<=x[i]){
                        y+=s.top();
                        s.pop();
                    }
                }
            }
            else{
                while(s.top()<x[i] && s.top()<=x[i+1]){
                    y+=s.top();
                    s.pop();
                }
                s.push(x[i]);
            }
        }
        else{
            s.push(x[i]);
        }
    }
    while(!s.empty()){
        y+=s.top();
        s.pop();
    }
    cout<<y; 
}