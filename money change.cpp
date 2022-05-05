#include <iostream>
using namespace std;
int main(){
    int m,k=0;
    cin>>m;
    k+=m/10;
    m=m%10;
    k+=m/5;
    m=m%5;
    k+=m;
    cout<<k;
}