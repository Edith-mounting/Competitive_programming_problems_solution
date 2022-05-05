#include <iostream>
#include <set>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int tes=0;tes<t;tes++){
        cout<<"Case #"<<tes+1<<": ";
        int n;
        cin>>n;
        int a[n][n],x=0,r=n,c=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(i==j)x+=a[i][j];
            }
        }
        set<int> s1[n],s2[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s1[i].insert(a[i][j]);
                s2[j].insert(a[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(s1[i].size()==n)r--;
            if(s2[i].size()==n)c--;
        }
        cout<<x<<" "<<r<<" "<<c<<endl;
        
    }
}