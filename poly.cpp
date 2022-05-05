#include <iostream>
using namespace std;
int main(){
    long long n,k=0;
    cin>>n;
    for(long long i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="Icosahedron"){
            k+=20;
        }
        else if(s=="Cube"){
            k+=6;
        }
        else if(s=="Tetrahedron"){
            k+=4;
        }
        else if(s=="Dodecahedron"){
            k+=12;
        }
        else k+=8;
    }
    cout<<k;
}