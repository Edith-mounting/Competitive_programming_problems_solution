#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    int z,m=0;
    int i=0;
    for(i=1;i<=10;i++){
        z=(x*i-y)/10;
        m=x*i/10;
        if((z*10==x*i-y) || (10*m==x*i)){
            break;
        }
        else{
            z=0;
            m=0;
        }
    }
    cout<<i;
}