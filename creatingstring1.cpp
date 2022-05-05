#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string> vs;
    do{
        vs.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout<<vs.size()<<"\n";
    for(string a:vs){
        cout<<a<<"\n";
    }
}