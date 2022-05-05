#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=5;
    int c=0;
    while(n/a >0){
        c+=n/a;
        a=a*5;
    }
    cout<<c<<endl;
}