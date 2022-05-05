#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;i<=1000;i++){
        if(i%8==0){
            cout<<i<<" ";
        }
    }
    return 0;
}