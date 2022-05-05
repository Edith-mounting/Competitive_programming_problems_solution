#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    bool a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            a[i][j]=false;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char kl;
            cin>>kl;
            if(kl=='X'){
                a[r][c]=true;
            }
        }
    }
    for(int j=1;j<c-1;j++){
        if(a[0][j]==true){
            if((a[0][j-1]==false) && a[0][j+1]==false){
                if(r>1){
                    if(a[1][j]==false){
                        a[0][j]=false;
                    }
                }
            }
        }
    }
    for(int j=1;j<c-1;j++){
        if(a[r-1][j]==true){
            if((a[r-1][j-1]==false) && (a[r-1][j+1]==false)){
                if(r>=2){
                    if(a[r-2][j]==false){
                        a[r-1][j]=false;
                    }
                }
            }
        }
    }
    for(int i=1;i<r-1;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]==true){
                if(j==0 && j==c-1){
                    if((a[i-1][j]==false) && (a[i+1][j]==false)){
                        if(j==0){
                            if(a[i][j+1]==false){
                                a[i][j]=false;
                            }
                        }else{
                            if(a[i][j-1]==false){
                                a[i][j]=false;
                            }
                        }
                    }
                }
                else{
                    int count=0;
                    if(!a[i][j-1]){
                        count++;
                    }
                    if(!a[i][j+1]){
                        count++;
                    }
                    if(!a[i-1][j]){
                        count++;
                    }
                    if(!a[i+1][j]){
                        count++;
                    }
                    if(count>=3){
                        a[i][j]=false;
                    }
                }
            }
        }
    }
    vector<int> v1,v2;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]){
                v1.push_back(i);
                v2.push_back(j);
            }
        }
    }
    //sort(v1.begin(),v1.end());
    //sort(v2.begin(),v2.end());
    /*for(int i=v1[0];i<=v1[v1.size()-1];i++){
        for(int j=v2[0];j<=v2[v2.size()-1];j++){
            if(a[i][j]){
                cout<<'X';
            }
            else{
                cout<<'.';
            }
        }
        cout<<"\n";
    }*/
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}