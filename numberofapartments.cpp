#include <iostream>
#include <vector>
using namespace std;
struct test{
    int x,y,z;
};
int main(){
    int N=1e3+5;
    vector<test> v;
    v.push_back({0,0,0});
    v.push_back({-1,-1,-1});
    v.push_back({-1,-1,-1});
    v.push_back({1,0,0});
    v.push_back({-1,-1,-1});
    v.push_back({0,1,0});
    v.push_back({2,0,0});
    v.push_back({0,0,1});
    for(int i=8;i<=N;i++){
        if(v[i-3].x>=0){
            v.push_back({v[i-3].x+1,v[i-3].y,v[i-3].z});
        }
        else if(v[i-5].x>=0){
            v.push_back({v[i-5].x,v[i-5].y+1,v[i-5].z});
        }
        else if(v[i-7].x>=0){
            v.push_back({v[i-7].x,v[i-7].y,v[i-7].z +1});
        }
        else{
            v.push_back({-1,-1,-1});
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(v[n].x==-1){
            cout<<-1<<"\n";
        }else{
        cout<<v[n].x<<" "<<v[n].y<<" "<<v[n].z<<"\n";}
    }
}