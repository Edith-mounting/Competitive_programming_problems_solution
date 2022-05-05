#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int x=s1.length(),y=s2.length();
    int a[x+1][y+1];
    for(int i=0;i<x+1;i++){
        a[i][0]=0;
    }
    for(int i=0;i<y+1;i++){
        a[0][i]=0;
    }
    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            if(s1[i]==s2[j]){
                a[i][j]=1+a[i-1][j-1];
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    cout<<a[x][y]<<"\n";
    stack<char> st;
    for(int i=x;i>=0;){
        for(int j=y;j>=0;){
            if(a[i][j]==a[i-1][j]){
                i--;
            }
            else if(a[i][j]==a[i][j-1]){
                j--;
            }
            else{
                st.push(s1[i]);
                i--;
                j--;
            }
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<"\n";
}