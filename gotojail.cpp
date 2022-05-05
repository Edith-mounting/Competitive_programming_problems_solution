#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    int x=0;
    bool bl=false;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            x++;
            if(x==3){
                bl=true;
                break;
            }
        }
        else{
            x=0;
        }
    }
    if(bl){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}