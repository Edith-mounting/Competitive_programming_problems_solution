#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	while(n--){
	    int x,y,z=0,p=0,q=0;
	    cin>>x>>y;
	    int a[x];
	    int b[y];
	    for(int i=0;i<x;i++)cin>>a[i];
	    for(int i=0;i<y;i++)cin>>b[i];
	    sort(a,a+x);
	    sort(b,b+y);
	    for(int i=0;i<x;i++){
	        if(a[i]>0){
	            p=i;
	            break;}
	    }
	    for(int i=0;i<y;i++){
	        if(b[i]>0){q=i;
	        break;}
	    }
	    for(int i=0;i<p;i++){
	        for(int j=p;j<x;j++){
	            for(int k=0;k<y;k++){
	                if(abs(a[i])*a[j]==abs(b[k])*abs(b[k]))z++;
	            }
	        }
	    }
	    for(int i=0;i<q;i++){
	       for(int j=q;j<y;j++){
	           for(int k=0;k<x;k++){
	               if(abs(b[i])*b[j]==abs(a[k])*abs(a[k]))z++;
	           }
	       }
	   } 
	   cout<<z<<"\n"; 
	}
	return 0;
}
