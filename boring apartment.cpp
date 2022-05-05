#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
#define M 1e9 +7
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,count=0;
        cin>>n;
        int k=n%10;
        count+=(k-1)*(10);
        while(n>0){
            count++;
            n=n/10;
        }
        cout<<count<<"\n";
    }
}