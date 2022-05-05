#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        char p=a[0][1],q=a[1][0],r=a[n-1][n-2],s=a[n-2][n-1];
        if(p==q){
            if(r==s){
                if(r==p){
                    cout<<2<<"\n";
                    cout<<n<<" "<<n-1<<"\n";
                    cout<<n-1<<" "<<n<<"\n";
                }
                else{
                    cout<<0<<"\n";
                }
            }
            else{
                cout<<1<<"\n";
                if(r==p){
                    cout<<n<<" "<<n-1<<"\n";
                }
                else{
                    cout<<n-1<<" "<<n<<"\n";
                }
            }
        }
        else if(r==s){
            if(r==1){
                if(p==1){
                    cout<<1<<"\n";
                    cout<<1<<" "<<2<<"\n";
                }
                else{
                    cout<<1<<"\n";
                    cout<<2<<" "<<1<<"\n";
                }
            }
            else{
                if(p==0){
                    cout<<1<<"\n";
                    cout<<1<<" "<<2<<"\n";
                }
                else{
                    cout<<1<<"\n";
                    cout<<2<<" "<<1<<"\n";
                }
            }
        }
        else{
            cout<<2<<"\n";
            if(p==1){
                cout<<1<<" "<<2<<"\n";
                if(s==0){
                    cout<<n-1<<" "<<n<<"\n";
                }
                else{
                    cout<<n<<" "<<n-1<<"\n";
                }
            }
            else{
                cout<<2<<" "<<1<<"\n";
                if(s==0){
                    cout<<n-1<<" "<<n<<"\n";
                }
                else{
                    cout<<n<<" "<<n-1<<"\n";
                }
            }
        }
    }
}