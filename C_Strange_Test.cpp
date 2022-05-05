#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define double long double
using namespace std;

double rad(double angle){
    return (double)((double)angle * 3.14159)/(double)180;
}
void interpolation(){
    cout << "Calculating value corresponding to the x_k \n";
    cout <<"We are give two pairs (x_i, val_i) and (x_j, val_j)\n";
    double x_i, val_i, x_j, val_j, x_k, val_k;
    cout << "value of x_i: ";
    cin >> x_i;
    cout << "\n";
    cout << "value of val_i: ";
    cin >> val_i;
    cout << "\n";
    cout << "value of x_j: ";
    cin >> x_j;
    cout << "\n";
    cout << "value of val_j: ";
    cin >> val_j;
    cout << "\n";
    cout << "value of x_k: ";
    cin >> x_k;
    cout <<"\n";
    val_k = (((double)(val_j - val_i)*(x_k - x_i))/(double)(x_j - x_i)) + val_i;
    cout << val_k << "\n";
}
void H_nod(){
    int n;
    cout <<"value of n: ";
    cin >> n;
    cout << "\n";
    double I_sc = 1.367;
    double omega_s;
    double angle = rad((double)(360*n)/365);
    cout << "value of omega_s in rad: ";
    cin >> omega_s;
    cout << "\n";
    double phi;
    cout << "value of phi in deg: ";
    cin >> phi;
    phi = rad(phi);
    cout << "\n";
    double delta;
    cout << "value of delta in deg: ";
    cin >> delta;
    delta = rad(delta);
    cout << "\n";
    double H_nod = (double)3600.000*I_sc*(24/3.14159)*(1 + (double)(0.033*cos(angle)))*((double)omega_s*sin(phi)*sin(delta) + (double)cos(phi)*cos(delta)*sin(omega_s));
    cout << H_nod << "\n";
}
void cos_theta(){
    // number of days
    int n;
    cout <<"value of n: ";
    cin >> n;
    cout << "\n";
    // delta in degrees;
    double delta = (double)(23.45)*sin(((double)(2*3.14159*(284 + n)))/365);
    cout << "delta " << delta <<"\n";
    delta = rad(delta);
    double gama, phi, beta, omega;
    cout << "value of gama in deg: ";
    cin >> gama;
    gama = rad(gama);
    cout << "\n";
    cout << "value of phi in deg: ";
    cin >> phi;
    phi = rad(phi);
    cout << "\n";
    cout << "value of beta in deg: ";
    cin >> beta; 
    beta = rad(beta);
    cout << "\n";
    cout << "value of omega in deg: ";
    cin >> omega;
    omega = rad(omega);
    cout << "\n";
    double cos_theta = (double)sin(phi)*((sin(delta)*cos(beta)) + (cos(delta)*cos(gama)*cos(omega)*sin(beta))) + (double)cos(phi)*((cos(delta)*cos(omega)*cos(beta)) - (sin(delta)*cos(gama)*sin(beta))) + (double)(cos(delta)*sin(gama)*sin(omega)*sin(beta));
    cout << cos_theta << "\n";
    double theta = acos(cos_theta);
    theta = (double)((double)180*theta)/((double)3.14159);
    cout << "value of theta in deg is " << theta << "\n";
}
void equation_of_time(){
    double E;
    int n;
    cout <<"value of n: ";
    cin >> n;
    double B_indegrees = (double)(n - 1)*360/365;
    double B_inradian = rad(B_indegrees);
    cout << B_inradian << "\n";
    double c1 = 229.18;
    E = ((double)c1*0.000075 + ((double)0.001868*c1*cos(B_inradian)) - ((double)0.032077*c1*sin(B_inradian)) - ((double)0.014615*c1*(double)cos(2.0000*B_inradian)) - ((double)0.04089*c1*(double)sin(2.0000*B_inradian)));
    cout << E << "\n"; 
}
int32_t main()
{
    int t =1 ;
    while(t--){
        // cos_theta();
        // equation_of_time();
        // H_nod();
        interpolation();
    }
}