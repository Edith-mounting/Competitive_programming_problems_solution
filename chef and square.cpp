#include <iostream>
#include <cmath>
#define endl '\n'
#define ll long long
using namespace std;
bool prime(int x){
    int m=0;
    for(ll i=2;i<x;i++){
        if(x%i==0){
            m++;
            break;
        }
    }
    if(m==1)return false;
    else return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n==2){
            cout<<-1<<endl;
        }
        else{
            bool b=prime(n);
            if(b){
                ll m=(n-1)/2;
                cout<<m*m<<endl;
            }
            else{
                int l=5000;
                int k=sqrt(n);
                ll lh,ph;
                for(int p=2;p<=k+1;p++){
                    if(n%p==0){
                        if(p%2==1 && (n/p)%2==1){
                            lh=p;
                            ph=n/lh;
                        }
                        else if(p%2==0 && (n/p)%2==0){
                            lh=p;
                            ph=n/lh;
                        }

                    }
                }
                if(ph%2==1 && lh%2==1 ){
                    ll bd=abs((ph-lh)/2);
                    if(ph==lh){
                        cout<<-1<<endl;
                    }
                    else cout<<bd*bd<<endl;
                }
                else if(ph%2==0 && lh%2==0){
                    ll bd=abs((ph-lh)/2);
                    if(ph==lh){
                        cout<<-1<<endl;
                    }
                    else cout<<bd*bd<<endl;
                }
                else cout<<-1<<endl;
            }
        }

    }
}