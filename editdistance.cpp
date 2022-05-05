#include <iostream>
#include <algorithm>
using namespace std;
void editdistance(string a,string b){
    int n,m;
    n=a.length();
    m=b.length();
    int d[n+1][m+1];
    int insertion,deletion,match,mismatch;
    for(int i=0;i<n+1;i++)d[i][0]=i;
    for(int j=0;j<m+1;j++)d[0][j]=j;
    for(int j=1;j<m+1;j++){
        for(int i=1;i<n+1;i++){
            insertion=d[i][j-1]+1;
            deletion=d[i-1][j]+1;
            match=d[i-1][j-1];
            mismatch=d[i-1][j-1]+1;
            if(a[i-1]==b[j-1]){
                d[i][j]=min(min(insertion,deletion),match);
            }
            else{
                d[i][j]=min(min(insertion,deletion),mismatch);
            }
        }
    }
    cout<<d[n][m];
}
int main(){
    string a,b;
    cin>>a>>b;
    editdistance(a,b);   
}