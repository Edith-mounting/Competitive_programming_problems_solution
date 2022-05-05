#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        string a[k];
        for(int i=0;i<k;i++){
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            a[i]=s;
        }
        int j=0;
        int x=0;
        for(int i=0;i<k;i++){
            while(true){
                if(j<k-1){
                    if(a[j]<a[j+1]){
                        x++;
                        j=j+1;
                    }    
                }
                else{
                    break;
                }
            }
        }
        if(x==(k-1)*k){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}