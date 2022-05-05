#include <iostream>
#include <algorithm>
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    if(n==10 || n==11 || n==12 || n==1){
        cout<<"winter";
    }
    else if(n==2 || n==3 || n==4 || n==5){
        cout<<"summer";
    }
    else if(n==6 || n==7 || n==8 || n==9){
        cout<<"rainy";
    }
    else{
        cout<<"invalid";
    }
    cout<<"\n";
}