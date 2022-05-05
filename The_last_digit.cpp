#include <iostream>
#include <vector>
using namespace std; 
#define vi              vector<int>
#define int             long long

int32_t main(){
    int w;
    cin>>w;
    while(w--){
        int a,b;
        cin>>a>>b;
        if(a==0){
            cout<<0;
        }
        else if(b==0){
            cout<<1;
        }
        else{
            vi v;
            int x=a;
            while(true){
                v.push_back(x%10);
                x=x*a;
                bool bl=false;
                for(int i:v){
                    if(i==x%10){
                        bl=true;
                        break;
                    }
                }
                if(bl){
                    break;
                }
            }
            int k=b%(v.size());
            if(k==0){
                cout<<v[v.size()-1];
            }
            else{
                cout<<v[k-1];
            }
        }
        cout<<"\n";
    }
}