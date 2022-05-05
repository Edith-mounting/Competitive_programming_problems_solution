#include <iostream>
using namespace std;
int32_t main(){
    int r , c;
    cin >> r >> c;
    int matrix[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> matrix[i][j];
        }
    }
    int x[r*c];
    int p = 0;
    int start_i = 0, start_j = 0;
    int tem_r = r, tem_c = c;
    while(p < tem_r*tem_c){
        for(int i = start_i; i < c; i++){
            x[p++] = matrix[start_i][i];
        }
        start_i++;
        if(p >= tem_r*tem_c){
            break;
        }
        for(int i = start_i; i < r; i++){
            x[p++] = matrix[i][c - 1];
        }
        if(p >= tem_r*tem_c){
            break;
        }
        c--;
        for(int i = c - 1; i >= start_j; i--){
            x[p++] = matrix[r - 1][i];
        }
        if(p >= tem_r*tem_c){
            break;
        }
        r--;
        for(int i = r - 1; i >= start_i ;i--){
            x[p++] = matrix[i][start_j];
        }
        start_j++;
    }
    for(int i = 0;i< tem_r*tem_c ;i++){
        cout<<x[i]<<" ";
    }
    cout<<"\n";
}