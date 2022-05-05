#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	char sl[n];
	if(n%2==1){
        sl[n/2]=s[0];
        for(int i=1;i<n;i+=2){
            sl[n/2 -i/2-1]=s[i];
            sl[n/2 +i/2+1]=s[i+1];
        }
	}
	else{
		for(int i=0;i<n;i+=2){
            sl[n/2 -i/2-1]=s[i];
            sl[n/2 +i/2]=s[i+1];
        }
	}
    for(int i=0;i<n;i++){
        cout<<sl[i];
    }
}