#include <iostream>
using namespace std;
int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i+=2){
            cout<<"2 "<<i+1<<" "<<i+2<<"\n";
            cout<<"1 "<<i+1<<" "<<i+2<<"\n";
            cout<<"2 "<<i+1<<" "<<i+2<<"\n";
            cout<<"2 "<<i+1<<" "<<i+2<<"\n";
            cout<<"1 "<<i+1<<" "<<i+2<<"\n";
            cout<<"2 "<<i+1<<" "<<i+2<<"\n";
        }
    }
}