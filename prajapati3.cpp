
#include <bits/stdc++.h>

using namespace std;

int numOfIncSubseqOfSizeK(int n, int m, vector<int> p)
{
	int dp[m][n], sum = 0;
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++)
		dp[0][i] = 1;

	for (int l = 1; l < m; l++) {
		for (int i = l; i < n; i++) {
			dp[l][i] = 0;
			for (int j = l - 1; j < i; j++) {
				if (p[j] < p[i])
					dp[l][i] += dp[l - 1][j];
			}
		}
	}
	for (int i = m - 1; i < n; i++)
		sum += dp[m - 1][i];

	return sum;
}

// Driver program to test above
int main()
{
	int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
	cout << numOfIncSubseqOfSizeK( n, m, p);

	return 0;
}
