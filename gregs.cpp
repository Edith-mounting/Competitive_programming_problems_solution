#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(i%3==0){
            a+=t;
        }
        else if(i%3==1){
            b+=t;
        }
        else{
            c+=t;
        }
    }
    if(a>b && a>c){
        cout<<"chest";
    }
    else if(b>c && b>a){
        cout<<"biceps";
    }
    else{
        cout<<"back";
    }
}