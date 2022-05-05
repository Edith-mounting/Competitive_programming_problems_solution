#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int j=0; j<n; j++){
        int a,b;
        int x;
        cin>>a>>b;
        x=min(a,b);
        int ar[a];
        int ak[b];
        int sum1=0, sum2=0;
        for(int i=0; i<a; i++){
            cin>>ar[i];
            sum1+=ar[i];

        }
        for(int i=0; i<b; i++){
            cin>>ak[i];
            sum2+=ak[i];
        }
        sort(ar, ar+a);
        sort(ak, ak+b, greater<int>());
        //cout<<sum1<<" "<<sum2<<endl;
        int i=0;
        bool bl=true;
        while(sum1<=sum2){
            int temp;
            temp=ar[i];
            ar[i]=ak[i];
            ak[i]=temp;
            sum1=sum1+ar[i]-ak[i];
            sum2=sum2+ak[i]-ar[i];
            i+=1;
            if(i==x){
                if(sum1<=sum2){
                    cout<<-1;
                }
                else{
                    cout<<i;
                }
                bl=false;
                break;
            }
        }
        //cout<<sum1<<" "<<sum2<<endl;
        if(bl){
            cout<<i;
        }
        cout<<"\n";

    }


    return 0;
}