#include <iostream>
#include <stack>

using namespace std;
int main(){
    int n,x=0,b=0,c=0,d=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int> s;
    int m=0,l=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            s.push(1);
            x++;
            b=i+1;
        }
        else{
            if(x>m){
                m=x;
                l=b;
            }
            x=0;
            b=0;
        }
    }
    cout<<x<<" "<<b;
}