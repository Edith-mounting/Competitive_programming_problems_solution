#include <iostream>
#include <algorithm>
using namespace std;
int32_t main(){
    string s1;
    getline(cin,s1);
    int k1=s1[s1.size()-1]-'0';
    cout<<k1;
    string a[k1];
    for(int i=0;i<k1;i++){
        getline(cin,a[i]);
    }
    string s2;
    getline(cin,s2);
    int k2=s2[s2.size()-1]-'0';
    if(k1==k2){
        string b[k2];
        for(int i=0;i<k2;i++){
            getline(cin,b[i]);
        }
        /*for(int i=0;i<k2;i++){
            cout<<a[i]<<" ";
        }*/
        cout<<'[';
        for(int i=0;i<k1;i++){
            cout<<"('"<<a[i]<<"')"<<", "<<"('"<<b[i]<<"')";
            if(i!=k1-1){
                cout<<", ";
            }
        }
    }
    else{
        cout<<"number of students are not same"<<"\n";
    }
}