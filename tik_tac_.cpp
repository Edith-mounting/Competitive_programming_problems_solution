#include <bits/stdc++.h>
using namespace std;

bool ifWin( vector<vector<int>> &a, int n){
    for(int i = 0; i < n; i++){
        bool temp = true;
        if(a[i][0] == -1){
            continue;
        }
        for(int j = 1; j < n; j++){
            if(a[i][j] != a[i][0]){
                temp = false;
                break;
            }
        }
        if(temp){
            return true;
        }
    }
    // cout << "Here 1";
    for(int i = 0; i < n; i++){
        bool temp = true;
        if(a[0][i] == -1){
            continue;
        }
        for(int j = 1; j < n; j++){
            if(a[j][i] != a[0][i]){
                temp = false;
                break;
            }
        }
        if(temp){
            return true;
        }
    }
    // cout << "Here 2";
    // Main Diagonal
    bool bl = true;
    if(a[0][0] != -1){
        for(int i = 1; i < n; i++){
            if(a[i][i] != a[0][0]){
                bl = false;
                break;
            }
        }
        if(bl){
            return true;
        }
    }
    // cout << "Here 3";
    // Secondary Diagonal
    bl = true;
    if(a[0][n - 1] != -1){
        for(int i = 1; i < n; i++){
            if(a[i][n - i - 1] != a[0][n - 1]){
                bl = false;
                break;
            }
        }
        if(bl){
            return true;
        }
    }
    // cout << "Here 4";
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> a( n, vector<int>(n, -1));
    int x,y;
    int flag = 0;
    while(true){
        cin >> x >> y;
        if(a[x][y] != -1){
            cout << "Invalid move! \n";
            cout << "Please Input valid move \n";
            continue;
        }
        a[x][y] = flag;
        bool bl = ifWin( a, n);
        if(bl){
            cout << "Player "<< flag << "won";
            break;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == -1){
                    bl = true;
                    break;
                }
            }
        }
        if(!bl){
            cout << "Game Draw!";
            break;
        }
        flag = 1 - flag;
    }
}