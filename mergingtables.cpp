#include <iostream>
using namespace std;
int find(int x,int parent[]){
    if(x!=parent[x]){
        parent[x]=find(parent[x],parent);
    }
    return parent[x];
}
int main(){
    int n,m,s=0;
    cin>>n>>m;
    int parent[n+1];
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
    int rank[n+1];
    rank[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>rank[i];
        if(rank[i]>s){
            s=rank[i];
        }
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        int k1,k2;
        k1=find(a,parent);
        k2=find(b,parent);
        if(k1==k2){
            cout<<s<<"\n";
        }
        else{
            rank[k1]+=rank[k2];
            rank[k2]=0;
            parent[k2]=k1;
            if(rank[k1]>s){
                s=rank[k1];
            }
            cout<<s<<"\n";
        }
    }
}