#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<int> v;
        char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(int i=0;i<26;i++){
            int k=0;
            for(int j=0;j<n;j++){
                if(s[j]==a[i])k++;
            }
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        while(q--){
            long long c;
            cin>>c;
            if(c>=v[25])cout<<0<<endl;
            else{
                long long kl=0;
                for(int i=0;i<v.size();i++){
                    if(v[i]>c){
                        kl+=v[i]-c;
                    }
                }
                cout<<kl<<endl;
            }
        }
    }
}