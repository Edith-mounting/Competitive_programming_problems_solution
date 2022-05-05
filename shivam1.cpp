#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

int c3(int k){
    if(k<3){
        return 0;
    }
    return (k*(k-1)*(k-2))/6 ;
}
int32_t main(){
    int n;
    cin>>n;
    int al[n];
    for(int i=0;i<n;i++){
        cin>>al[i];
    }
    vector<vector<int>> v(n,vector<int>(4,0));
    for(int i=0;i<n;i++){
        int q=al[i];
        while(q>0){
            int r=q%10;
            if(r==2){
                v[i][0]++;
            }
            else if(r==3){
                v[i][1]++;
            }
            else if(r==5){
                v[i][2]++;
            }
            else if(r==7){
                v[i][3]++;
            }
            q/=10;
        }
    }
    int a=0,b=0,c=0,d=0,aUb=0,aUc=0,aUd=0,bUc=0,bUd=0,cUd=0,aUbUc=0,aUbUd=0,aUcUd=0,bUcUd=0,aUbUcUd=0;
    for(int i=0;i<n;i++){
        if(v[i][0]>0){
            a++;
        }
        if(v[i][1]>0){
            b++;
        }
        if(v[i][2]>0){
            c++;
        }
        if(v[i][3]>0){
            d++;
        }
        if(v[i][0]>0 && v[i][1]>0){
            aUb++;
        }
        if(v[i][0]>0 && v[i][2]>0){
            aUc++;
        }
        if(v[i][0]>0 && v[i][3]>0){
            aUd++;
        }
        if(v[i][1]>0 && v[i][2]>0){
            bUc++;
        }
        if(v[i][1]>0 && v[i][3]>0){
            bUd++;
        }
        if(v[i][2]>0 && v[i][3]>0){
            cUd++;
        }
        if(v[i][0]>0 && v[i][1]>0 && v[i][2]>0){
            aUbUc++;
        }
        if(v[i][0]>0 && v[i][1]>0 && v[i][3]>0){
            aUbUd++;
        }
        if(v[i][0]>0 && v[i][2]>0 && v[i][3]>0){
            aUcUd++;
        }
        if(v[i][1]>0 && v[i][2]>0 && v[i][3]>0){
            bUcUd++;
        }
        if(v[i][0]>0 && v[i][1]>0 && v[i][2]>0 && v[i][3]>0){
            aUbUcUd++;
        }
    }
    int ans=0;
    ans=c3(a)+c3(b)+c3(c)+c3(d)-c3(aUb)-c3(aUc)-c3(aUd)-c3(bUc)-c3(bUd)-c3(cUd)+c3(aUbUc)+c3(aUbUd)+c3(aUcUd)+c3(bUcUd)-c3(aUbUcUd);
    cout<<ans<<"\n";
}