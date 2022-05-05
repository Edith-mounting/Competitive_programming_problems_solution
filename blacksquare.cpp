#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,x=0;
    cin>>a>>b>>c>>d;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')x+=a;
        else if(s[i]=='2')x+=b;
        else if(s[i]=='3')x+=c;
        else x+=d;
    }
    cout<<x;
}