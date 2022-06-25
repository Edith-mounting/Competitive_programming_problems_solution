#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector< int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> v( 10, 0);
    for(int i:a){
        v[i%10]++;
    }
    if( v[9]>=2 && v[5]>=1) return true;
    else if(v[9]>=1 && v[8]>=1 && v[6]>=1) return true;
    else if(v[9]>=1 && v[7]>=2) return true;
    else if(v[8]>=2 && v[7]>=1)return true;
    else if(v[9]>=1 && v[3]>=1 && v[1]>=1)return true;
    else if(v[9]>=1 && v[2]>=2) return true;
    else if(v[8]>=1 && v[4]>=1 && v[1]>=1) return true;
    else if(v[8]>=1 && v[3]>=1 && v[2]>=1)return true;
    else if(v[7]>=1 && v[4]>=1 && v[2]>=1) return true;
    else if(v[7]>=1 && v[5]>=1 && v[1]>=1) return true;
    else if(v[7]>=1 && v[3]>=2) return true;
    else if(v[6]>=2 && v[1]>=1)return true;
    else if(v[6]>=1 && v[5]>=1 && v[2]>=1) return true;
    else if(v[6]>=1 && v[4]>=1 && v[3]>=1)return true;
    else if(v[5]>=2 && v[3]>=1)return true;
    else if(v[5]>=1 && v[4]>=2)return true;
    else if(v[3]>=1 && v[0]>=2)return true;
    else if(v[1]>=3)return true;
    else if(v[9]>=1 && v[4]>=1 && v[0]>=1) return true;
    else if(v[8]>=1 && v[5]>=1 && v[0]>=1)return true;
    else if(v[7]>=1 && v[6]>=1 && v[0]>=1)return true;
    else if(v[2]>=1 && v[1]>=1 && v[0]>=1)return true;
    else return false;
    return false;
}

int32_t main(){
    int w;
    cin >> w;
    while (w--)
    {
        /* code */
        if(solve()){
            cout << "YES";
        }
        else cout << "NO";
        cout << "\n";
    }
}