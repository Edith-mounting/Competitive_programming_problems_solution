#include <iostream>
using namespace std;

int main(){
    int m,n,p;
    cin>>m>>n>>p;
    int ans = 0;
    int k = min(m,min(n,p));
    if(k == p){
        m-=p;
        n-=p;
        ans+=k;
        while(m>0 && n>0){
            if(m==1 && n==1){
                break;
            }
            else{
                if(m>n){
                    m-=2;
                    n--;
                }
                else{
                    n-=2;
                    m--;
                }
            }
            ans++;
        }
    }
    else{
        ans+=k;
    }
    cout<<ans<<"\n";
}