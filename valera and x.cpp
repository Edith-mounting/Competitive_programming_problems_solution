#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    char a[n][n];
    char ch;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    ch=a[0][0];
    if(n!=1){
        char ch2=a[0][1];
        if(ch==ch2){
            cout<<"NO";
        }
        else{
        bool b=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i || j==n-i-1){
                    if(a[i][j]!=ch){
                        b=false;
                        break;
                    }
                }
                else{
                    if(a[i][j]!=ch2){
                        b=false;
                        break;
                    }
                }
            }
        }
        if(b)cout<<"YES";
        else cout<<"NO";
    }
    }
    else cout<<"YES";
}