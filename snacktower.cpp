#include <iostream>
#define endl '\n'
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int x=n;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            cout<<x;
            while(int j=i-1 && a[j]<x){
                if(a[j]==x-1){
                    cout<<a[j];
                    x--;
                    j--;
                }
            }
            x--;
            cout<<endl;
        }
        else cout<<endl;
    }
}