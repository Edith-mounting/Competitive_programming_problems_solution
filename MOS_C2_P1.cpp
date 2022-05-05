#include <iostream>
#include <iomanip>
using namespace std;
int32_t main(){
    int n;
    cout<<"Enter the number of components ";
    cin>>n;
    cout<<"\n";
    double p[n],l[n],a[n],E[n];
    double P=0;
    cout<<"Enter the values in this format:load(kN),length(m),area of cross-section(mm^2)";
    cout<<"modulus of elasticity(GPa) respec. (with spacing)"<<"\n";
    for(int i=0;i<n;i++){
        cout<<"Enter values for "<<i+1<<" components: ";
        double x;
        cin>>x;
        P+=x;
        p[i]=P;
        cin>>l[i];
        cin>>a[i];
        cin>>E[i];
    }
    double d=0;
    cout<<"-------------------------------------------------------------------"<<"\n";
    cout<<"Element       "<<"Stress(MPa)        "<<"Deformation(mm)"<<"\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"             ";
        cout<<setprecision(4)<<((p[i]*1000)/a[i]);
        d+=((p[i]*l[i])/(a[i]*E[i]*1000));
        cout<<"               ";
        cout<<setprecision(4)<<((p[i]*l[i])/(a[i]*E[i]*1000))*(1000000)<<"\n";
        cout<<"-------------------------------------------------------------------"<<"\n";
    }
    cout<<"The net deformation is ";
    cout<<setprecision(4)<<d*1000000<<"\n";
}