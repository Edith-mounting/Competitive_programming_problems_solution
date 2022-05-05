#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int k=n;
    int kml=0;
    if((n*(n+1)/2)%2==0){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int b[k+1];
            b[0]=0;
            for(int lm=1;lm<=k;lm++){
                b[lm]=lm;
            }
            //swap(b[i],b[j]);
            int ml=b[i];
            b[i]=b[j];
            b[j]=ml;
            int k=0;
            int sum=0;
            for(int lm=1;lm<=k;lm++){
                sum+=b[lm];
                if(sum==n*(n+1)/4){
                    kml++;
                    k++;
                    break;
                }
            }
        }
    }
    cout<<k<<"\n";
    }
    else{
        cout<<0<<"\n";
    }}
}