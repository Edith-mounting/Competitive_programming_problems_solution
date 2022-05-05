#include <iostream>
#define int long long 
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n, pHOUR, pMIN;
        char ch;
        string Tz;
        cin >> pHOUR >> ch >> pMIN >> Tz;
        if(Tz=="AM"){
            pHOUR=pHOUR%12;
        }
        if(Tz=="PM"){
            pHOUR=pHOUR%12 +12;
        }
        int ptime=pHOUR*100 + pMIN;
        cin>>n;
        int rHOUR, rMIN, lHOUR, lMIN;
        string Tz1, Tz2;
        for(int j=0; j<n; j++){
            cin >> rHOUR >> ch >> rMIN >> Tz1 >> lHOUR >> ch >> lMIN >> Tz2;
            //12:00 AM 11:42 PM
            if(Tz1=="AM"){
                rHOUR=rHOUR%12;
            }
            if(Tz2=="AM"){
                lHOUR=lHOUR%12;
            }
            if(Tz1=="PM"){
                rHOUR=rHOUR%12 +12;
            }
            if(Tz2=="PM"){
                lHOUR=lHOUR%12 +12;
            }
            int rtime =lHOUR*100 + lMIN;
            int ltime=rHOUR*100 + rMIN;
            
            if(ptime<=rtime && ptime>=ltime){
                cout<<1;
            }
            else if(rtime<ltime){
                if(ptime>=ltime){
                    cout<<1;
                }
                else if(ptime<=rtime){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0;
            }
        }
        cout<<"\n";
    }
}