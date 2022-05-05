#include <iostream>
#include <iomanip>
using namespace std;
int32_t main(){
    int n;
    cout<<"Enter the number of components ";
    cin>>n;
    cout<<"\n";
    double delta0;
    cout<<"Enter the length of gap between the wall and free end in mm: ";
    cin>>delta0;
    double l[n],a[n],E[n],alpha[n];
    cout<<"Enter the values in this format:length(mm),area of cross-section(mm^2),modulus of elasticity(GPa) and heat-transfer coefficient(10^(-6)/degreeC) respec. (with spacing)"<<"\n";
    for(int i=0;i<n;i++){
        cout<<"Enter values for "<<i+1<<" components: ";
        cin>>l[i];
        cin>>a[i];
        double e,al;
        cin>>e>>al;
        E[i]=e;
        alpha[i]=(al);
    }
    double T;
    cout<<"Enter the rise in Temperature(in C): ";
    cin>>T;
    cout<<"\n";
    double deltaB=0,unitdeltaB=0;
    for(int i=0;i<n;i++){
        deltaB+=(alpha[i]*l[i]*T)/1000000000;
        unitdeltaB+=l[i]/(a[i]*E[i]*1000000);
    }
    bool ansk=true;
    if(deltaB-(delta0/1000)<0){
        ansk=false;
        cout<<"magnitude of reations :"<<0<<" kPa"<<"\n";
    }
    double Rb=(deltaB-(delta0/1000))/(unitdeltaB);
    double Ra=(-1)*Rb;
    if(ansk){
        cout<<"magnitude of reations :"<<Rb/1000<<"kN"<<"\n";
    }
    cout<<"-------------------------------------------------------------------"<<"\n";
    cout<<"Element       "<<"Stress(MPa)        "<<"Deformation(mm)"<<"\n";
    for(int i=0;i<n && ansk;i++){
        cout<<i+1<<"            ";
        cout<<(-1)*(Rb/a[i]);
        cout<<"             ";
        cout<<(alpha[i]*l[i]*T)/1000000-((Rb*l[i])/(a[i]*E[i]*1000))<<"\n";
        cout<<"-------------------------------------------------------------------"<<"\n";
    }
    if(!ansk){
        for(int i=0;i<n;i++){
        cout<<i+1<<"              ";
        cout<<0;
        cout<<"                ";
        cout<<(alpha[i]*l[i]*T)/1000000<<"\n";
        cout<<"-------------------------------------------------------------------"<<"\n";
        }
    }
}