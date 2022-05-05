#include <iostream>
#include <algorithm>

using namespace std;

void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}
int32_t main(){
    int n;
    cin>>n;
    int a[n];
    int neg=0,pos=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            neg++;
        }
        else{
            pos++;
        }
    }
    //cout<<neg<<" "<<pos<<"\n";
    if(neg<pos){
        int x=1;
        for(int i=0;i<n;i++){
            if(a[i]<0 && (i%2==0)){
                while(a[x]<0){
                    x+=2;
                }
                swap(a[i],a[x]);
            }
            else if(a[i]<0 && (i%2==1)){
                while(a[x]<0){
                    x+=2;
                }
                if(x<i){
                    swap(a[x],a[i]);
                }
            }
        }
    }
    else{
        int x=1;
        for(int i=0;i<n;i++){
            if(a[i]>=0 && (i%2==0)){
                while(a[x]>=0){
                    x+=2;
                }
                swap(a[i],a[x]);
            }
            else if(a[i]>=0 && (i%2==1)){
                while(a[x]>=0){
                    x+=2;
                }
                if(x<i){
                    swap(a[x],a[i]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}