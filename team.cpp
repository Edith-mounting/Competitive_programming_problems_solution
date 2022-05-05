#include <iostream>
using namespace std;
int main(){
    int n,s=0;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            if(b==1)s++;
            else if(b==0 && c==1)s++;
        }
        else{
            if(b==1 && c==1)s++;
        }
    }
    cout<<s;
}