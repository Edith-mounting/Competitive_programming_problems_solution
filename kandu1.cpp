#include <bits/stdc++.h>
using namespace std;
const int n = 11, m = 11;
double del_x = 0.1, del_y = 0.1;
double psi_pre[n][m];
double omega[n][m];
int main(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            psi_pre[i][j] = 0.0;
            omega[i][j] =  (double)((double)-2*((double)j + (double)1)/((double)del_y*(double)m));
        }
    }
    double chi = 0.2;
    int var = n*m;
    double a[var][var];
    double s[var];
    double psi[n][m];
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            s[m*(j - 1) + i] = - (del_x*del_x)*(omega[j][i]);
        }
    }
    int temp1 = 0, temp2 = m - 1;
    double eta = (double)(del_x/del_y);
    for(int i = 0; i < var; i++){
        if(i != temp1 && i != temp2 && i >= m && i <= var - m){
            
        }
    }
}