#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;
int main(){
    int t,tes=0;
    cin>>t;
    tes=t;
    while(t--){
        cout<<"Case "<<tes-t<<":"<<endl;
        int n,q;
        cin>>n>>q;
        stack<int> a[n];
        while(q--){
            string s;
            cin>>s;
            if(s=="push"){
                int m,n;
                cin>>m>>n;
                a[m-1].push(n);
            }
            else if(s=="top"){
                int k;
                cin>>k;
                if(a[k-1].empty()){
                    cout<<"Empty!"<<endl;
                }
                else cout<<a[k-1].top()<<endl;
            }
            else if(s=="put"){
                int m,n;
                cin>>m>>n;
                stack<int> st;
                while(!a[m-1].empty()){
                    st.push(a[m-1].top());
                    a[m-1].pop();
                }
                while(!st.empty()){
                    a[n-1].push(st.top());
                    st.pop();
                }
            }
            else{
                int p;
                cin>>p;
                if(!a[p-1].empty()){
                    a[p-1].pop();
                }
            }
        }
    }
}