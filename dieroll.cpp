#include <iostream>
using namespace std;
int main(){
    int a,b,k=0;
    cin>>a>>b;
    if(a>=b){
        k=7-a;
    }
    else{k=7-b;}
    switch(k){
        case 1:cout<<"1/6";
            break;
        case 2:cout<<"1/3";
            break;
        case 3:cout<<"1/2";
            break;
        case 4:cout<<"2/3";
            break;
        case 5:cout<<"5/6";
            break;
        case 6:cout<<"1/1";
            break;                    
    }
}