#include <iostream>
#define ll long long
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++){
           cin>>a[i];
       }
       int k=0;
       if(a[0]==1){k=1;}
       int x=1;
       //cout<<k<<"\n";
       int y=0;
       for(int i=1;i<n;i++){
           if(a[i]==0){
               if(x<2){
                   x++;
                   y=0;
               }else{
                   y++;
                   x=0;
               }
           }else{
               if(y<2){
                   y++;
                   x=0;
               }else{
                   k+=1;
                   y=0;
                   x++;
                   //cout<<k<<"\n";
               }
           }
       }
       cout<<k<<"\n";
   } 
}