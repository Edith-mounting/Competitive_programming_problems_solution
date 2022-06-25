#include <bits/stdc++.h>
using namespace std;

void partitionIntoKSegments(int a[],
							int n, int k)
{
	
}
// Driver code
int main()
{
	int n, s;
	cin >> n >> s;
	int k = n/s;
	int a[n];
	for(int i =0; i < n; i++){
		cin >> a[i];
	}
	// Function call
	partitionIntoKSegments(a, n, k);
	return 0;
}
