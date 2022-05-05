#include <iostream>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll k;
        int d0,d1;
        cin>>k>>d0>>d1;
        ll p=0;
        p=(d0+d1);
        k=k-2;
        if(k==1){
            p=p+(d0+d1)%10;
        }
        else if(k>1){
            k--;
            p=p+(d0+d1)%10;
            int m=k%4;
            p+=((6*(d0+d1))%10 +(8*(d0+d1))%10 +(4*(d0+d1))%10 +(2*(d0+d1))%10)*(k/4);
            if(m==1){
                p+=(2*(d0+d1))%10;
            }
            else if(m==2){
                p+=(4*(d0+d1))%10 +(2*(d0+d1))%10;
            }
            else if(m==3){
                p+=(8*(d0+d1))%10 +(4*(d0+d1))%10 +(2*(d0+d1))%10;
            }
        }
        //cout<<p;
        if(p%3==0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}