#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int W,n;
    cin>>W>>n;
    int w[n];
    int val;
    for(int i=0;i<n;i++)cin>>w[i];
    int** value=new int*[n+1];
    for(int i=0;i<n+1;i++){
        value[i]=new int[W+1];
    }
    //ll value[n+1][W+1];
    for(int i=0;i<n+1;i++){
        value[i][0]=0;
    }
    for(int i=1;i<W+1;i++){
        value[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1] <=j){
                value[i][j]=max(w[i - 1] + value[i - 1][j - w[i - 1]],  value[i - 1][j]);
            }
            else{
                value[i][j]=value[i-1][j];
            }
        }
    }
    cout<<value[n][W];
}