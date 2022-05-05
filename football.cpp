#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,c=1;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    string s=a[0];
    for(int i=0;i<n-1;i++){
        int k=1;
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])k++;
        }
        if(k>c){
            c=k;
            s=a[i];
        }
    }
    cout<<s;
}