#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    int t,tl;
    cin>>t;
    tl=t;
    while(t--){
        int n;
        cin>>n;
        ll a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        ll k=0;
        ll cl=0;
        while(true){
            if(k<n){
                int i=k,j=0;
                ll c=0;
                while(true){
                    if(i<n && j<n){
                        c+=a[i][j];
                    }
                    else{
                        break;
                    }
                    i++,j++;
                }
            cl=max(cl,c);
            k++;
            }
            else{
                break;
            }
        }
        k=1;
        while(true){
            if(k<n){
                int j=k,i=0;
                ll c=0;
                while(true){
                    if(i<n && j<n){
                        c+=a[i][j];
                    }
                    else{
                        break;
                    }
                    i++,j++;
                }
            cl=max(cl,c);
            k++;
            }
            else{
                break;
            }
        }
        cout<<"Case #"<<tl-t<<": ";
        cout<<cl<<"\n";
        
    }
}