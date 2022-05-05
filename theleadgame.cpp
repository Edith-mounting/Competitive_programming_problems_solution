#include <iostream>
using namespace std;
int main(){
    int n,a=0,b=0,p=0,q=0;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        p+=x;
        q+=y;
        if(p>q){
            if(p-q>a){
                a=p-q;
                b=1;
            }
        }
        else{
            if(q-p>a){
                a=q-p;
                b=2;
            }
        }
    }
}