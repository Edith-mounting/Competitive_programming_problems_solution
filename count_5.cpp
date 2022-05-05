#include <iostream>
#include <vector>
using namespace std;


void build( int a[], int v, int tl, int tr,vector<int> &segt){
    if(tl == tr){
        if(a[tl]%5 ==0){
            segt[v]=1;
        }
    }
    else{
        int tm= (tl+tr)/2;
        build( a, 2*v, tl, tm, segt);
        build( a, 2*v +1, tm+1, tr , segt);
        segt[v]= segt[2*v] + segt[2*v +1];
    }
}
int query(int v, int tl, int tr, int l, int r, vector<int> segt){
    if(l>r){
        return 0;
    }
    if(l==tl && r==tr){
        return segt[v];
    }
    int tm= (tl+tr)/2;
    return query(2*v, tl , tm, l, min(r, tm), segt) + query(2*v +1, tm+1, tr, max(l,tm+1), r, segt);
}
void update(int v , int tl , int tr , int pos , int new_val , vector<int> segt){
    if(tl==tr){
        segt[v]=new_val;
    }
    else{
        int tm=(tl+ tr)/2;
        if(pos<=tm){
            update(v*2, tl , tm , pos , new_val, segt);
        }
        else{
            update(v*2 +1 ,tm+1 , tr , pos , new_val , segt);
        }
        segt[v] = segt[v*2] + segt[v*2 +1];
    }
}
int32_t main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    int a[n];
	    vector<int> segt(4*n +5,0);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    build(a,1,0,n-1,segt);
	    // for(int i=1;i<=9;i++){
	    //     cout<<segt[i]<<" ";
	    // }
	    while(q--){
	        int l,r;
	        cin>>l>>r;
	       l--,r--;
	       cout<<query(1 ,0 , n-1 , l, r, segt)<<"\n";
	    }
	}
	return 0;
}