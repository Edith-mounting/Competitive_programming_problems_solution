#include <iostream>
using namespace std;
int main(){
    long long a;
    int b,p=0;
    cin>>a>>b;
    int x[b];
    for(int i=0;i<b;i++){
        cin>>x[i];
        p+=x[i];
    }
    if(a%p==0){
        cout<<a/p;
    }
    else cout<<(a/p)+1;
}