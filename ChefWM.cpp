#include <iostream>
#include <algorithm>
using namespace std;

int absk(int k){
    if(k<0){
        return -k;
    }
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int x = 0;
        for(int i = 2;i*i <= m;i++){
            if(m%i == 0){
                x++;
                while(m%i == 0){
                    m/=i;
                }
            }
        }
        if(m > 1){
            x++;
        }
        int ans = 0;
        for(int i = 2; i*i <=n;i++){
            if(n%i==0 && i<=x){
                ans = max(ans , i);
                if(n/i <= x){
                    ans = max(ans , n/i);
                }
            }
        }
        if(x == 0){
            ans = 0;
        }
        else if(ans == 0){
            ans = 1;
        }
        cout << ans <<"\n";
    }
}