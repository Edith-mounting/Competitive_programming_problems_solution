#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        vector<int> v;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            int k=1;
            for(int j=i;j>0;j--){
                if((a[j]-a[j-1])<=2)k++;
                else{
                    break;
                }
            }
            for(int j=i;j<n-1;j++){
                if((a[j+1]-a[j])<=2)k++;
                else{
                    break;
                }
            }
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        cout<<v[0]<<" "<<v[n-1]<<endl;
    }
}