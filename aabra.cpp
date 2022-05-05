#include <iostream>
#include <vector>
using namespace std;
int32_t main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    for(int i:v){
        cout<<i<<" ";
    }
    
}