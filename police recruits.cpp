#include <iostream>
using namespace std;
int main(){
    int n,x=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int y=0;
    for(int i=0;i<n;i++){
        if(a[i]==-1 && y==0)x++;
        else if(a[i]==-1 && y!=0){
            y=y+a[i];
        }
        else{
            y+=a[i];
        }
    }
    cout<<x;
}