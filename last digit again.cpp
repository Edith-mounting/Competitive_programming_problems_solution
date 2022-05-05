#include <iostream>
using namespace std;
int main(){
    long long m,n;
    cin>>m>>n;
    int c=0;
    int x=(n+2)%60;
    if(n==0){
            c=0;
    }
    else if(n==1){
        c=1;
    }
    else{
        int a=0,b=1;
        if(x==0 || x==1){
            c=0;
        }
        else{
            for(int i=0;i<x-1;i++){
                c=a%10+b%10;
                a=b;
                b=c;
            }
            c=c%10-1;
            if(c<0){
                c=c+10;
            }
        }
    }
    int c1=0;
    int x1=(m-1+2)%60;
    if(m-1==0){
            c1=0;
    }
    else if(m-1==1){
        c1=1;
    }
    else{
        int a1=0,b1=1;
        if(x1==0 || x1==1){
            c1=0;
        }
        else{
            for(int i=0;i<x1-1;i++){
                c1=a1%10+b1%10;
                a1=b1;
                b1=c1;
            }
            c1=c1%10-1;
            if(c1<0){
                c1=c1+10;
            }
        }
    }
    if(c-c1<0){
        cout<<c-c1+10;
    }
    else{
        cout<<c-c1;
    }
}