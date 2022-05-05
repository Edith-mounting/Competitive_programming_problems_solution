#include <iostream>
using namespace std;
int main(){
    long long n,b,d,k=0,m=0;
    cin>>n>>b>>d;
    long long a[n];
    for(long long i=0;i<n;i++)cin>>a[i];
    for(long long i=0;i<n;i++){
        if(a[i]<=b){
            if(k<=d){
                k+=a[i];
            }
            if(k>d){
                k=0;
                m++;
            }
        }
    }
    cout<<m;
}