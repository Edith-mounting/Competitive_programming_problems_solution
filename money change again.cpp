#include <iostream>
using namespace std;
int DPmoney(int money,int a[]){
    int minnumcoins[money+1];
    minnumcoins[0]=0;
    for(int m=1;m<=money;m++){
        minnumcoins[m]=10000;
        for(int i=0;i<3;i++){
            if(m>=a[i]){
                int numcoins=minnumcoins[m-a[i]]+1;
                if(numcoins<minnumcoins[m]){
                    minnumcoins[m]=numcoins;
                }
            }
        }
    }
    return minnumcoins[money];
}
int main(){
    int x;
    cin>>x;
    int n=3;
    int a[n]={1,3,4};
    int y;
    y=DPmoney(x,a);
    cout<<y<<endl;

}