#include <iostream>
#define ll long long
#define endl '\n' 
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,a=0,b=0,x=0;
        cin>>n;
        k=n*2;
        string s;
        cin>>s;
        for(int i=0;i<k;i++){
            if(i%2==0){
                if(s[i]=='1')a++;
            }
            if(a>(n+b-(i/2)-1)){
                x=i+1;
                break;
            }
            if(i%2==1){if(s[i]=='1')b++;}
            if(a>(n+b-(i/2)-1)){
                x=i+1;
                break;
            }
            if(b>(n+a-(i/2)-1)){
                x=i+1;
                break;
            }
        }
        if(x!=0)cout<<x<<endl;
        else cout<<n*2<<endl;
    }
}