#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[5][5],p=0,q=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                p=i;
                q=j;
            }
        }
    }
    //cout<<abs(p-2)+abs(q-2)<<endl;
}