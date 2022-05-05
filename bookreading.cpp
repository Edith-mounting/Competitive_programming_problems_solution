#include <iostream>
using namespace std;
int main(){
    int n,t,c=0;
    cin>>n>>t;
    int a[n];
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        a[i]=86400-l;
    }
    for(int i=0;i<n;i++){
        if(t>0){
            t=t-a[i];
            c++;
        }
    }
    cout<<c<<endl;
}