#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
void dfs(string a[], int i, int j, int n, int m){
    a[i][j] = '1';
    int temp_x, temp_y;
    for(int k = 0; k < 4; k++){
        temp_x = i + x[k];
        temp_y = j + y[k];
        if(temp_x >= 0 && temp_x < n && temp_y >= 0 && temp_y < m && a[temp_x][temp_y] == '0'){
            dfs(a, temp_x, temp_y, n, m);
        }
    }
}
int countIslands(string a[], int n)
{

    int m = a[0].size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '0') {
                res++;
                dfs(a, i, j, n, m);            
			}
		}
	}
	return res;
}

// main function
int main()
{
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << countIslands(a, n);
}
