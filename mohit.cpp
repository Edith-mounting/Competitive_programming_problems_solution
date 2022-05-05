 
#include <bits/stdc++.h>
#include <vector> 
#include <set>
using namespace std;
vector<string> v;
void printAllKLengthRec(char set[], string prefix, 
									int n, int k) 
{ 
	if (k == 0) 
	{ 
		//cout << (prefix) << endl;
        v.push_back(prefix); 
		return; 
	} 

	for (int i = 0; i < n; i++) 
	{ 
		string newPrefix;  
		newPrefix = prefix + set[i];  
		printAllKLengthRec(set, newPrefix, n, k - 1); 
	} 

} 

void printAllKLength(char set[], int k,int n) 
{ 
	printAllKLengthRec(set, "", n, k); 
}
int main() 
{ 
	
	//cout << "First Test" << endl; 
	//char set1[] = {'a', 'b'}; 
	int k,n;
    cin>>k>>n;
    char set1[n];
    for(int i=0;i<n;i++){
        cin>>set1[i];
    }
	printAllKLength(set1, k, n);
    //n=number of characters
    //k=size of cell
    set<string> se;
    for(int i=0;i<v.size();i++){
        //cout<<v[i]<<endl;
        se.insert(v[i]);
    }
    cout<<se.size(); 
} 
