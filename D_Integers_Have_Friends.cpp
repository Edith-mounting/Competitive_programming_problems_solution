#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string.h>
#define int long long

#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int absk(int k){
	if(k<0){
		return -k;
	}
	return k;
}

void build_segtree(int segtree[], int a[], int index, int start, int end){
  if(start==end){
    segtree[index] = a[start];
    return;
  }
  int mid = (start+end)/2;
  build_segtree(segtree,a,2*index,start,mid);
  build_segtree(segtree,a,2*index+1,mid+1,end);
  segtree[index] = __gcd(segtree[2*index], segtree[2*index+1]);

}
int query(int segtree[], int l, int r, int index, int start, int end){
  if(l>r){
    return 0;
  }
  if(l==start && end==r){
    return segtree[index];
  }
  int mid = (start+end)/2;
  int tmp1 = query(segtree, l, min(r, mid), 2*index, start, mid);
  int tmp2 = query(segtree, max(mid+1, l), r, 2*index+1, mid+1, end);
  return __gcd(tmp1, tmp2);
}

void solve(){
	int n;
	cin>>n;
	int v[n];
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<1<<"\n";
		return ;
	}
	if(n==2){
		int temp=absk(v[0]-v[1]);
		if(temp==1){
			cout<<1<<"\n";
		}
		else{
			cout<<2<<'\n';
		}
		return ;
	}
	int ans =0;
	int dif[n-1];
	for(int i=1; i<n; i++){
		dif[i-1] = absk(v[i] - v[i-1]);
	}
	int segtree[4*n+4];
	build_segtree(segtree, dif, 1, 0, n-2);
	int low,high,mid,tmp;
	for(int i=0; i<n-1; i++){
		low = 0;
		high = n-2-i;
		int mx = -1;
		while(low<=high){
			mid = (low+high)/2;
			tmp = query(segtree,i,i+mid,1,0,n-2);
			if(tmp>1){
				mx = mid;
				low = mid+1;
			}else{
				high = mid-1;
			}
		}
		ans= max(ans, mx+1);
	}
	cout << ans+1 << '\n';
}
int32_t main(){
	FIO;
	int w;
	cin >> w;
	while(w--){
		solve();
	}
}