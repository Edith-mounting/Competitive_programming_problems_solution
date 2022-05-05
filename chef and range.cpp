#include <iostream>
#include <algorithm>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll a[n];
	    for(ll i=0;i<n;i++)cin>>a[i];
	    sort(a,a+n);
	    a[n-1]=a[0];
	    a[n-2]=a[0];
	    a[n-3]=a[0];
        sort(a,a+n);
	    cout<<a[n-1]-a[0]<<endl;
	}
	return 0;
}
