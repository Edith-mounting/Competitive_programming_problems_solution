#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main(){
    string s="KICKXKICKXSTARTXKICKXSTART";
    //cin>>s;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<=s.length()-4;i++){
        string s1="";
        for(int j=i;j<i+4;j++){
            s1+=s[j];
        }
        if(s1=="KICK"){
            v1.push_back(i);
        }
    }
    for(int i=0;i<=s.length()-5;i++){
        string s1="";
        for(int j=i;j<i+5;j++){
            s1+=s[j];
        }
        if(s1=="START"){
            v2.push_back(i);
        }
    }
    int j=v1.size()-1;
    int n=1e5 +5;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=0;
    }
    int k=1;
    for(int i=v2.size()-1;i>=0;i--){
        a[v2[i]]=k;
        k++;
    }
    k=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0){
            k=a[i];
        }
        else{
            a[i]=k;
        }
    }
    ll sum=0;
    for(int i=0;i<v1.size();i++){
        sum+=a[v1[i]];
    }
    cout<<sum;
}