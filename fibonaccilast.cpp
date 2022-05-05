#include <iostream>
using namespace std;
int main(){
    int n;
    long long c=0;
    cin>>n;
    if(n==0){
        c=0;
    }
    else if(n==1){
        c=1;
    }
    else{
        long long a=0,b=1;
        for(int i=0;i<n-1;i++){
            c=a%10+b%10;
            a=b%10;
            b=c%10;
        }
        c=c%10;
    }
    cout<<c;
}