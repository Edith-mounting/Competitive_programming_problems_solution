#include <iostream>
using namespace std;
bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int temp = n;
    int ans =0;
    while(temp>0){
        if(isprime(temp%10)){
            ans+=temp%10;
        }
        temp/=10;
    }
    cout<<ans<<"\n";
}