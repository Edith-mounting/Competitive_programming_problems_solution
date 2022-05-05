#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int lambda;
    cin>>lambda;
    while(lambda--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> v[n];
        vector<double> tv[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i]!=a[j]){
                    double t=(double)(i-j)/(a[j]-a[i]);
                    if(t>0){
                        v[i].push_back(j);
                        tv[i].push_back(t);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(v[i].size()!=0){
                for(int j=0;j<v[i].size();j++){
                    for(int k=0;k<v[v[i][j]].size();k++){
                        if(v[v[i][j]][k]!=v[i][j]){
                            if((-tv[i][j]+tv[v[i][j]][k])>0){
                                bool bl=true;
                                for(int il=0;il<v[i].size();il++){
                                    if(v[i][il]==v[v[i][j]][k]){
                                        bl=false;
                                        break;
                                    }
                                }
                                if(bl){
                                    v[i].push_back(v[v[i][j]][k]);
                                    tv[i].push_back(tv[v[i][j]][k]);
                                }
                            }
                        }
                    }
                }
            }
        }
        int b[n];
        for(int i=0;i<n;i++){
            b[i]=v[i].size();
        }
        sort(b,b+n);
        cout<<b[0]+1 <<" "<<b[n-1]+1<<"\n";
    }
}